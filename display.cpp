/*
 * display.cpp
 *
 *  Created on: 17 oct. 2018
 *      Author: Valentin
 */


#include <Nextion.h>
#include <NextionPage.h>
#include <NextionText.h>
#include <SoftwareSerial.h>
#include <NextionButton.h>

#include <stdio.h>
#include <string.h>

#include "encoder.h"
#include "regulation.h"

#include <EEPROM.h>

#define BAUD 9600

SoftwareSerial nextionSerial(10, 11); // RX (blue), TX(yellow)


Nextion nex(nextionSerial);
//Page 0
#define page_petit_feu	0
#define page_grand_feu	1
#define page_recuit		2

#define nb_page	page_recuit + 1

NextionButton 			petit_feu					{nex, 0, 2, "t0"};
NextionButton 			grand_feu					{nex, 0, 3, "t1"};
NextionButton 			recuit						{nex, 0, 4, "t2"};

//page 1,2,3

NextionButton 			bt_palier1_txt[nb_page]		{{nex, 1, 10, "bt5"},{nex, 2, 10, "bt5"},{nex, 3, 10, "bt5"}};
NextionButton 			bt_palier2_txt[nb_page]		{{nex, 1, 7, "bt2"},{nex, 2, 7, "bt2"},{nex, 3, 7, "bt2"}};
NextionButton			bt_pente1_txt[nb_page]		{{nex, 1, 9, "bt4"},{nex, 2, 9, "bt4"},{nex, 3, 9, "bt4"}};
NextionButton 			bt_pente2_txt[nb_page]		{{nex, 1, 8, "bt3"},{nex, 2, 8, "bt3"},{nex, 3, 8, "bt3"}};
NextionButton 			bt_temp_1_txt[nb_page]		{{nex, 1, 6, "bt1"},{nex, 2, 6, "bt1"},{nex, 3, 6, "bt1"}};
NextionButton 			bt_temp_2_txt[nb_page]		{{nex, 1, 5, "bt0"},{nex, 2, 5, "bt0"},{nex, 3, 5, "bt0"}};
NextionText 			time_total_txt[nb_page]		{{nex, 1, 2, "t4"},{nex, 2, 2, "t4"},{nex, 3, 2, "t4"}};
NextionButton 			bt_start[nb_page]			{{nex, 1, 3, "button_start"},{nex, 2, 3, "button_start"},{nex, 3, 3, "button_start"}};
NextionButton           bt_return[nb_page]           {{nex, 1, 11, "button_return"},{nex, 2, 11, "button_return"},{nex, 3, 11, "button_return"}};

//page 4

NextionText 			palier1_txt					{nex, 4, 6, "t2"};
NextionText 			palier2_txt					{nex, 4, 7, "t3"};
NextionText 			temp_1_txt					{nex, 4, 5, "t1"};
NextionText 			temp_2_txt					{nex, 4, 4, "t0"};
NextionText 			temp_reel_txt				{nex, 4, 8, "t4"};
NextionText 			time_reel_txt				{nex, 4, 9, "t5"};
NextionButton 			bt_stop						{nex, 4, 10, "button_stop"};

#define no_button_index 	0
#define time_palier1_index 	1
#define time_palier2_index 	2
#define pente1_index 		3
#define pente2_index 		4
#define temp_1_index 		5
#define temp_2_index 		6

#define nb_variable	(temp_2_index + 1)

int variable[nb_page][nb_variable] = {
	{0,
	20,
	90,
	100,
	500,
	200,
	800},
	{0,
	5,
	90,
	200,
	500,
	400,
	1200},
	{0,
	60,
	120,
	10,
	50,
	200,
	500}
};

bool run_flag;

static void display_refresh_value(int forced,int page);
static void display_encoder(int index,int page);
static void display_refresh_fire_value(uint8_t page);
static void check_value(int index, int page);
static void save_value(int index, int page);
static void read_value(int index, int page);
static void burn_variable_init(int page);

static uint8_t button_index,page_index;


void init_variable(void)
{
    uint8_t tmp;
    int i, j, add;

    tmp = EEPROM.read(0);
    if (tmp == 0xA5) {
        add = 0;
        for (i = 0; i < nb_page; i++) {
            for (j = 0; j < nb_variable; j++) {
                read_value(j, i);
            }
        }
    } else {
        add = 0;
        for (i = 0; i < nb_page; i++) {
            for (j = 0; j < nb_variable; j++) {
                save_value(j, i);
            }
        }
        EEPROM.write(0, 0xA5);
    }

}

void page1_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH) {
		page_index = 1;
		display_refresh_value(true,page_index);
	}
}

void page2_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH) {
		page_index = 2;
		display_refresh_value(true,page_index);
	}
}

void page3_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH){
		page_index = 3;
		display_refresh_value(true,page_index);
	}
}


void bt_palier1_page1_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 1;
		button_index = time_palier1_index;
	}
}

void bt_palier1_page2_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 2;
		button_index = time_palier1_index;
	}
}

void bt_palier1_page3_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 3;
		button_index = time_palier1_index;
	}
}

void bt_palier2_page1_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 1;
		button_index = time_palier2_index;
	}
}

void bt_palier2_page2_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 2;
		button_index = time_palier2_index;
	}
}

void bt_palier2_page3_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 3;
		button_index = time_palier2_index;
	}
}

void bt_pente1_page1_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 1;
		button_index = pente1_index;
	}
}

void bt_pente1_page2_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 2;
		button_index = pente1_index;
	}
}

void bt_pente1_page3_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 3;
		button_index = pente1_index;
	}
}

void bt_pente2_page1_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 1;
		button_index = pente2_index;
	}
}

void bt_pente2_page2_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 2;
		button_index = pente2_index;
	}
}

void bt_pente2_page3_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 3;
		button_index = pente2_index;
	}
}

void bt_temp_1_page1_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 1;
		button_index = temp_1_index;
	}
}

void bt_temp_1_page2_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 2;
		button_index = temp_1_index;
	}
}


void bt_temp_1_page3_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 3;
		button_index = temp_1_index;
	}
}

void bt_temp_2_page1_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 1;
		button_index = temp_2_index;
	}
}

void bt_temp_2_page2_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 2;
		button_index = temp_2_index;
	}
}


void bt_temp_2_page3_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		page_index = 3;
		button_index = temp_2_index;
	}
}

void bt_start_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
	    button_index = 0;
	    display_refresh_fire_value(page_index);
	    burn_variable_init(page_index);
		page_index = 4;
		run_flag = true;
	}
}

void bt_return_Callback(NextionEventType type, INextionTouchable *widget)
{
    if (type == NEX_EVENT_PUSH)
    {
        button_index = 0;
        page_index = 0;
        burn_stop();
        run_flag = false;
    }
}

void bt_stop_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
	    button_index = 0;
		page_index = 0;
		burn_stop();
		run_flag = false;
	}
}

void init_nextion(void)
{
	int i;

	init_variable();
	nextionSerial.begin(BAUD);
	nex.init();

	petit_feu.attachCallback(&page1_Callback);
	grand_feu.attachCallback(&page2_Callback);
	recuit.attachCallback(&page3_Callback);

	bt_palier1_txt[0].attachCallback(&bt_palier1_page1_Callback);
	bt_palier1_txt[1].attachCallback(&bt_palier1_page2_Callback);
	bt_palier1_txt[2].attachCallback(&bt_palier1_page3_Callback);

	bt_palier2_txt[0].attachCallback(&bt_palier2_page1_Callback);
	bt_palier2_txt[1].attachCallback(&bt_palier2_page2_Callback);
	bt_palier2_txt[2].attachCallback(&bt_palier2_page3_Callback);

	bt_pente1_txt[0].attachCallback(&bt_pente1_page1_Callback);
	bt_pente1_txt[1].attachCallback(&bt_pente1_page2_Callback);
	bt_pente1_txt[2].attachCallback(&bt_pente1_page3_Callback);

	bt_pente2_txt[0].attachCallback(&bt_pente2_page1_Callback);
	bt_pente2_txt[1].attachCallback(&bt_pente2_page2_Callback);
	bt_pente2_txt[2].attachCallback(&bt_pente2_page3_Callback);

	bt_temp_1_txt[0].attachCallback(&bt_temp_1_page1_Callback);
	bt_temp_1_txt[1].attachCallback(&bt_temp_1_page2_Callback);
	bt_temp_1_txt[2].attachCallback(&bt_temp_1_page3_Callback);

	bt_temp_2_txt[0].attachCallback(&bt_temp_2_page1_Callback);
	bt_temp_2_txt[1].attachCallback(&bt_temp_2_page2_Callback);
	bt_temp_2_txt[2].attachCallback(&bt_temp_2_page3_Callback);

	bt_start[0].attachCallback(&bt_start_Callback);
	bt_start[1].attachCallback(&bt_start_Callback);
	bt_start[2].attachCallback(&bt_start_Callback);

    bt_return[0].attachCallback(&bt_return_Callback);
    bt_return[1].attachCallback(&bt_return_Callback);
    bt_return[2].attachCallback(&bt_return_Callback);

	bt_stop.attachCallback(&bt_stop_Callback);

}

static void display_refresh_value(int forced,int page){

	static int previous_variable[nb_page][nb_variable];
	int i;
	char tmp[10];
	long time_total_value;

	if(page == 0)
		return;
	else
		page = page - 1;

	for(i = 0; i < nb_variable;i++){
		if(( variable[page][i] != previous_variable[page][i] ) || forced) {
			switch(i){
			case time_palier1_index :
				sprintf(tmp,"%dh%02d",(int)(variable[page][i]/60),(int)(variable[page][i]%60));
				bt_palier1_txt[page].setText(tmp);
				break;
			case time_palier2_index :
				sprintf(tmp,"%dh%02d",(int)(variable[page][i]/60),(int)(variable[page][i]%60));
				bt_palier2_txt[page].setText(tmp);
				break;
			case pente1_index :
				sprintf(tmp,"%d °C/h",variable[page][i]);
				bt_pente1_txt[page].setText(tmp);
				break;
			case pente2_index :
				sprintf(tmp,"%d °C/h",variable[page][i]);
				bt_pente2_txt[page].setText(tmp);
				break;
			case temp_1_index :
				sprintf(tmp,"%d °C",variable[page][i]);
				bt_temp_1_txt[page].setText(tmp);
				break;
			case temp_2_index :
				sprintf(tmp,"%d °C",variable[page][i]);
				bt_temp_2_txt[page].setText(tmp);
				break;
			default :
				break;
			}
			//Serial.println(tmp);
			previous_variable[page][i] = variable[page][i];
			time_total_value = 	variable[page][time_palier1_index] +
								variable[page][time_palier2_index] +
								(variable[page][temp_1_index]/variable[page][pente1_index])*60 +
								((variable[page][temp_2_index] - variable[page][temp_1_index])/variable[page][pente2_index])*60;
			sprintf(tmp,"%dh%02d",(int)(time_total_value/60),(int)(time_total_value%60));
			time_total_txt[page].setText(tmp);
			save_value(i, page);
		}
	}
}

static void display_refresh_fire_value(uint8_t page)
{
	char tmp[10];
	sprintf(tmp,"%dh%02d",(int)(variable[page][time_palier1_index]/60),(int)(variable[page][time_palier1_index]%60));
	palier1_txt.setText(tmp);
	sprintf(tmp,"%dh%02d",(int)(variable[page][time_palier2_index]/60),(int)(variable[page][time_palier2_index]%60));
	palier2_txt.setText(tmp);
	sprintf(tmp,"%d °C",variable[page][temp_1_index]);
	temp_1_txt.setText(tmp);
	sprintf(tmp,"%d °C",variable[page][temp_2_index]);
	temp_2_txt.setText(tmp);
}

uint8_t display_refresh(void){

	static uint8_t previous_page;

	nex.poll();

	if ((page_index > 0) || (page_index < 4)) {
		display_encoder(button_index, page_index);
		display_refresh_value(false, page_index);
		previous_page = page_index;
	}
	return page_index;

}

static void display_encoder(int index,int page){
	static int newPos;
	int current_position,delta = 0;
	static bool first_time_flag = 1;

	if(page == 0)
		return;
	else
		page = page - 1;

	if(first_time_flag){
		newPos = position_encoder();
		first_time_flag = 0;
	}

	switch(index){
	case time_palier1_index :
	case time_palier2_index :
		delta = 1;
		break;
	case pente1_index :
	case pente2_index :
		delta = 10;
		break;
	case temp_1_index :
	case temp_2_index :
		delta = 5;
		break;
	default :
		break;
	}
	current_position = position_encoder();
	variable[page][index] = variable[page][index] + (current_position - newPos) * delta;
	newPos = current_position;

	check_value(index, page);

//	Serial.println("coucou");
//	Serial.println(index);
//	Serial.println(page);
//	Serial.println(variable[page][index]);
//	Serial.println("end");
}

static void check_value(int index, int page) {

	if (variable[page][index] < 0)
		variable[page][index] = 0;

	if(( variable[page][temp_1_index] > variable[page][temp_2_index] ) && ( index == temp_1_index))
		variable[page][temp_1_index] = variable[page][temp_2_index];
	if(( variable[page][temp_2_index] < variable[page][temp_1_index] ) && ( index == temp_2_index))
		variable[page][temp_2_index] = variable[page][temp_1_index];
}

static void save_value(int index, int page) {

    int add;

    cli();
    EEPROM.write(add, (uint8_t)(variable[page][index] & 0xFF));
    EEPROM.write(add + 1, (uint8_t)((variable[page][index] & 0xFF00) >> 8));
    sei();
}

static void read_value(int index, int page)
{
    int add;
    uint8_t tmp0, tmp1;

    cli();
    add = page * nb_variable + index << 1;
    tmp0 = EEPROM.read(add);
    tmp1 = EEPROM.read(add + 1);
    variable[page][index] = tmp0 + (tmp1 << 8);
    sei();
    check_value(index, page);
}

static void burn_variable_init(int page)
{
    time_palier1_extern = variable[page][time_palier1_index];
    time_palier2_extern = variable[page][time_palier2_index];
    pente1_extern = variable[page][pente1_index];
    pente2_extern = variable[page][pente2_index];
    temp_1_extern = variable[page][temp_1_index];
    temp_2_extern = variable[page][temp_2_index];
    start_time = millis();
    step = 0;
}
