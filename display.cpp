/*
 * display.cpp
 *
 *  Created on: 17 oct. 2018
 *      Author: Valentin
 */


#include "NeoNextion/Nextion.h"
#include "NeoNextion/NextionPage.h"
#include "NeoNextion/NextionPicture.h"
#include "NeoNextion/NextionText.h"

#include "NeoNextion/NextionButton.h"

#include <stdio.h>
#include <string.h>

#include "encoder.h"
#include "regulation.h"

#include "hardware/EEPROM.h"
#include "hardware/SoftwareSerial.h"

#define BAUD 9600

SoftwareSerial nextionSerial(10, 11); // RX (blue), TX(yellow)


Nextion nex(nextionSerial);
//Page 0
#define petit_feu	0
#define grand_feu	1
#define recuit		2

#define nb_program	        recuit + 1

NextionPage             accueil_pg          (nex, 0, 0, "accueil");
NextionPage             prepare_feu_pg      (nex, 1, 0, "prepare_feu");
NextionPage             phase1_pg           (nex, 2, 0, "phase1");
NextionPage             phase2_pg           (nex, 3, 0, "phase2");
NextionPage             cooked_pg           (nex, 4, 0, "cooked");

NextionButton 			petit_feu_bt        (nex, 0, 2, "t0");
NextionButton 			grand_feu_bt		(nex, 0, 3, "t1");
NextionButton 			recuit_bt			(nex, 0, 4, "t2");

//page 1,2,3

NextionButton 			bt_palier1_txt		(nex, 1, 9, "bt5");
NextionButton 			bt_palier2_txt		(nex, 1, 6, "bt2");
NextionButton			bt_pente1_txt	    (nex, 1, 8, "bt4");
NextionButton 			bt_pente2_txt	    (nex, 1, 7, "bt3");
NextionButton 			bt_temp_1_txt	    (nex, 1, 5, "bt1");
NextionButton 			bt_temp_2_txt	    (nex, 1, 4, "bt0");
NextionText 			time_total_txt		(nex, 1, 12, "t4");
NextionButton 			bt_start			(nex, 1, 5, "button_start");
NextionPicture          bt_return           (nex, 1, 10, "button_return");

//page 4

NextionText 			palier1_txt			(nex, 2, 5, "t2");
NextionText 			palier2_txt			(nex, 2, 6, "t3");
NextionText 			temp_1_txt			(nex, 2, 4, "t1");
NextionText 			temp_2_txt			(nex, 2, 3, "t0");
NextionText 			temp_reel_txt		(nex, 2, 7, "t4");
NextionText 			time_reel_txt		(nex, 2, 8, "t5");
NextionButton 			bt_stop				(nex, 2, 9, "button_stop");

#define no_button_index 	0
#define time_palier1_index 	1
#define time_palier2_index 	2
#define pente1_index 		3
#define pente2_index 		4
#define temp_1_index 		5
#define temp_2_index 		6

#define nb_variable	(temp_2_index + 1)

int variable[nb_program][nb_variable] = {
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

static void display_refresh_value(int forced,int program);
static void display_encoder(int index,int program);
static void display_refresh_fire_value(uint8_t program);
static void check_value(int index, int program);
static void save_value(int index, int program);
static void read_value(int index, int program);
static void burn_variable_init(int program);

static uint8_t button_index, program_index;


void init_variable(void)
{
    uint8_t tmp;
    int i, j, add;

    tmp = EEPROM.read(0);
    if (tmp == 0xA5) {
        add = 0;
        for (i = 0; i < nb_program; i++) {
            for (j = 0; j < nb_variable; j++) {
                read_value(j, i);
            }
        }
    } else {
        add = 0;
        for (i = 0; i < nb_program; i++) {
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
	    prepare_feu_pg.show();
		program_index = petit_feu;
    button_index = 0;
		display_refresh_value(true, program_index);
	}
}

void page2_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH) {
	    prepare_feu_pg.show();
		program_index = grand_feu;
		button_index = 0;
		display_refresh_value(true, program_index);
	}
}

void page3_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH){
	    prepare_feu_pg.show();
		program_index = recuit;
		button_index = 0;
		display_refresh_value(true, program_index);
	}
}


void bt_palier1_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		button_index = time_palier1_index;
		Serial.println(button_index);
	}
}

void bt_palier2_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		button_index = time_palier2_index;
		Serial.println(button_index);
	}
}


void bt_pente1_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		button_index = pente1_index;
		Serial.println(button_index);
	}
}

void bt_pente2_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		button_index = pente2_index;
		Serial.println(button_index);
	}
}

void bt_temp_1_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
	    Serial.println("coucou");
		button_index = temp_1_index;
		Serial.println(button_index);
	}
}


void bt_temp_2_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
  Serial.println("toto");
		button_index = temp_2_index;
		Serial.println(button_index);
	}
}


void bt_start_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
	    Serial.print("Start :");
	    phase1_pg.show();
	    button_index = 0;
	    display_refresh_fire_value(program_index);
	    burn_variable_init(program_index);
		program_index = 4;
		run_flag = true;
	}
}

void bt_return_Callback(NextionEventType type, INextionTouchable *widget)
{
    if (type == NEX_EVENT_PUSH)
    {
        button_index = 0;
        program_index = 0;
        burn_stop();
        run_flag = false;
        accueil_pg.show();
        Serial.println("return");
    }
}

void bt_stop_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
	    button_index = 0;
		program_index = 0;
		burn_stop();
		run_flag = false;
        Serial.println("stop");
	}
}

void init_nextion(void)
{
	int i;

	init_variable();
	nextionSerial.begin(BAUD);
	nex.init();

	petit_feu_bt.attachCallback(&page1_Callback);
	grand_feu_bt.attachCallback(&page2_Callback);
	recuit_bt.attachCallback(&page3_Callback);

	bt_palier1_txt.attachCallback(&bt_palier1_Callback);
	bt_palier2_txt.attachCallback(&bt_palier2_Callback);
	bt_pente1_txt.attachCallback(&bt_pente1_Callback);
	bt_pente2_txt.attachCallback(&bt_pente2_Callback);
	bt_temp_1_txt.attachCallback(&bt_temp_1_Callback);
	bt_temp_2_txt.attachCallback(&bt_temp_2_Callback);
	bt_start.attachCallback(&bt_start_Callback);
	bt_return.attachCallback(&bt_return_Callback);
	bt_stop.attachCallback(&bt_stop_Callback);

}

static void display_refresh_value(int forced,int program){

	static int previous_variable[nb_program][nb_variable];
	int i;
	char tmp[10];
	long time_total_value;

	if(program == 0)
		return;
	else
		program = program - 1;

	for(i = 0; i < nb_variable;i++){
		if(( variable[program][i] != previous_variable[program][i] ) || forced) {
			switch(i){
			case time_palier1_index :
				sprintf(tmp,"%dh%02d",(int)(variable[program][i]/60),(int)(variable[program][i]%60));
				bt_palier1_txt.setText(tmp);
				break;
			case time_palier2_index :
				sprintf(tmp,"%dh%02d",(int)(variable[program][i]/60),(int)(variable[program][i]%60));
				bt_palier2_txt.setText(tmp);
				break;
			case pente1_index :
				sprintf(tmp,"%d �C/h",variable[program][i]);
				bt_pente1_txt.setText(tmp);
				break;
			case pente2_index :
				sprintf(tmp,"%d �C/h",variable[program][i]);
				bt_pente2_txt.setText(tmp);
				break;
			case temp_1_index :
				sprintf(tmp,"%d �C",variable[program][i]);
				bt_temp_1_txt.setText(tmp);
				break;
			case temp_2_index :
				sprintf(tmp,"%d �C",variable[program][i]);
				bt_temp_2_txt.setText(tmp);
				break;
			default :
				break;
			}
			//Serial.println(tmp);
			previous_variable[program][i] = variable[program][i];
			time_total_value = 	variable[program][time_palier1_index] +
								variable[program][time_palier2_index] +
								(variable[program][temp_1_index]/variable[program][pente1_index])*60 +
								((variable[program][temp_2_index] - variable[program][temp_1_index])/variable[program][pente2_index])*60;
			sprintf(tmp,"%dh%02d",(int)(time_total_value/60),(int)(time_total_value%60));
			time_total_txt.setText(tmp);
			save_value(i, program);
		}
	}
}

static void display_refresh_fire_value(uint8_t program)
{
	char tmp[10];
	sprintf(tmp,"%dh%02d",(int)(variable[program][time_palier1_index]/60),(int)(variable[program][time_palier1_index]%60));
	palier1_txt.setText(tmp);
	sprintf(tmp,"%dh%02d",(int)(variable[program][time_palier2_index]/60),(int)(variable[program][time_palier2_index]%60));
	palier2_txt.setText(tmp);
	sprintf(tmp,"%d �C",variable[program][temp_1_index]);
	temp_1_txt.setText(tmp);
	sprintf(tmp,"%d �C",variable[program][temp_2_index]);
	temp_2_txt.setText(tmp);
}

uint8_t display_refresh(void){
    static bool toggle = false;

	nex.poll();

    toggle = !toggle;
    digitalWrite(7,toggle);

	if ((program_index > 0) || (program_index < 4)) {
	    //Serial.println(button_index);
		display_encoder(button_index, program_index);
		display_refresh_value(false, program_index);
	}
	return program_index;

}

static void display_encoder(int index, int program){
	static int newPos;
	int current_position,delta = 0;
	static bool first_time_flag = 1;


	if(program == 0)
		return;
	else
		program = program - 1;

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
	variable[program][index] = variable[program][index] + (current_position - newPos) * delta;
	newPos = current_position;

	check_value(index, program);

}

static void check_value(int index, int program) {

	if (variable[program][index] < 0)
		variable[program][index] = 0;

	if(( variable[program][temp_1_index] > variable[program][temp_2_index] ) && ( index == temp_1_index))
		variable[program][temp_1_index] = variable[program][temp_2_index];
	if(( variable[program][temp_2_index] < variable[program][temp_1_index] ) && ( index == temp_2_index))
		variable[program][temp_2_index] = variable[program][temp_1_index];
}

static void save_value(int index, int program) {

    int add;

    cli();
    EEPROM.write(add, (uint8_t)(variable[program][index] & 0xFF));
    EEPROM.write(add + 1, (uint8_t)((variable[program][index] & 0xFF00) >> 8));
    sei();
}

static void read_value(int index, int program)
{
    int add;
    uint8_t tmp0, tmp1;

    cli();
    add = program * nb_variable + index << 1;
    tmp0 = EEPROM.read(add);
    tmp1 = EEPROM.read(add + 1);
    variable[program][index] = tmp0 + (tmp1 << 8);
    sei();
    check_value(index, program);
}

static void burn_variable_init(int program)
{
    time_palier1_extern = variable[program][time_palier1_index];
    time_palier2_extern = variable[program][time_palier2_index];
    pente1_extern = variable[program][pente1_index];
    pente2_extern = variable[program][pente2_index];
    temp_1_extern = variable[program][temp_1_index];
    temp_2_extern = variable[program][temp_2_index];
    start_time = millis();
    step = 0;
    Serial.println();
    Serial.print("Start time : ");
    Serial.println(start_time);
    Serial.print("Temp 1 : ");
    Serial.println(temp_1_extern);
    Serial.print("Pente 1 : ");
    Serial.println(pente1_extern);
    Serial.print("Time 1 : ");
    Serial.println(time_palier1_extern);
    Serial.print("Temp 2 : ");
    Serial.println(temp_2_extern);
    Serial.print("Pente 2 : ");
    Serial.println(pente2_extern);
    Serial.print("Time 2 : ");
    Serial.println(time_palier2_extern);
}
