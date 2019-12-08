/*
 * display.cpp
 *
 *  Created on: 17 oct. 2018
 *      Author: Valentin
 */


#include "src/NeoNextion/Nextion.h"
#include "src/NeoNextion/NextionPage.h"
#include "src/NeoNextion/NextionPicture.h"
#include "src/NeoNextion/NextionText.h"

#include "src/NeoNextion/NextionButton.h"
#include "src/NeoNextion/NextionDualStateButton.h"

#include <stdio.h>
#include <string.h>

#include "encoder.h"
#include "regulation.h"
#include "display.h"
#include "temperature.h"

#include "src/hardware/EEPROM.h"
#include "src/hardware/SoftwareSerial.h"

#define BAUD 19200

SoftwareSerial nextionSerial(10, 11); // RX (blue), TX(yellow)


Nextion nex(nextionSerial);
//Page 0
#define petit_feu	1
#define grand_feu	2
#define recuit		3

#define nb_program	        recuit

NextionPage             accueil_pg          (nex, 0, 0, "accueil");
NextionPage             prepare_feu_pg      (nex, 1, 0, "prepare_feu");
NextionPage             phase1_pg           (nex, 2, 0, "phase1");
NextionPage             phase1_pause_pg     (nex, 3, 0, "phase1_pause");
NextionPage             phase2_pg           (nex, 4, 0, "phase2");
NextionPage             phase2_pause_pg     (nex, 5, 0, "phase2_pause");
NextionPage             cooked_pg           (nex, 6, 0, "cooked");

NextionButton 			norm_bt             (nex, 0, 2, "t0");
NextionButton 			trempe_bt			(nex, 0, 3, "t1");
NextionButton 			recuit_bt			(nex, 0, 4, "t2");
NextionText 			temp_pg0_txt	    (nex, 0, 6, "t4");
//page 1,2,3

NextionButton  			bt1_start			(nex, 1, 2, "button_start");
NextionButton 			bt_temp_2_txt	    (nex, 1, 4, "bt0");
NextionButton 			bt_temp_1_txt	    (nex, 1, 5, "bt1");
NextionButton 			bt_palier2_txt		(nex, 1, 6, "bt2");
NextionButton 			bt_pente2_txt	    (nex, 1, 7, "bt3");
NextionButton			bt_pente1_txt	    (nex, 1, 8, "bt4");
NextionButton 			bt_palier1_txt		(nex, 1, 9, "bt5");
NextionPicture          bt_return           (nex, 1, 10, "button_return");
NextionText 			temp_txt			(nex, 1, 11, "t4");
NextionText 			time_total_txt		(nex, 1, 13, "t1");

//page 4
NextionText 			temp_2_txt			(nex, 2, 1, "t0");
NextionText 			temp_1_txt			(nex, 2, 2, "t1");
NextionText 			palier1_txt			(nex, 2, 3, "t2");
NextionText 			palier2_txt			(nex, 2, 4, "t3");
NextionText 			temp_reel_txt		(nex, 2, 5, "t4");
NextionText 			time_reel_txt		(nex, 2, 6, "t5");
NextionButton 		    bt_stop_p1			(nex, 2, 7, "t6");
NextionText 			pente1_txt			(nex, 2, 8, "t7");
NextionText 			pente2_txt			(nex, 2, 9, "t8");
NextionDualStateButton 	heat_txt	        (nex, 2, 11, "bt20");
NextionDualStateButton  button		        (nex, 2, 10, "bt666");

NextionButton           bt_stop_p3          (nex, 3, 7, "t6");
NextionButton           bt_stop_p4          (nex, 4, 7, "t6");
NextionButton           bt_stop_p5          (nex, 5, 7, "t6");
//page 6
NextionText 			temp_finish_txt	    (nex, 6, 1, "t4");
NextionButton 			return_txt			(nex, 6, 2, "t1");

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
	30,
	60,
	200,
	800},
	{0,
	5,
	90,
	60,
	120,
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


static void display_refresh_value(int forced,int program);
static void display_encoder(int index,int program);
static void display_refresh_fire_value(uint8_t program, int step);
static void refresh_temp(void);
static void check_value(int index, int program);
static void save_value(int index, int program);
static void read_value(int index, int program);
static void burn_variable_init(int program);



static uint8_t button_index, program_index;
static uint8_t run_flag;

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
	    Serial.println("petit feu");
	    prepare_feu_pg.show();
	    Serial.println(nex.getCurrentPage());
		program_index = petit_feu;
		button_index = 0;
		display_refresh_value(true, program_index);
	}
}

void page2_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH) {
	    Serial.println("grand feu");
	    prepare_feu_pg.show();
	    Serial.println(nex.getCurrentPage());
		program_index = grand_feu;
		button_index = 0;
		display_refresh_value(true, program_index);
	}
}

void page3_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH){
	    Serial.println("recuit");
	    prepare_feu_pg.show();
	    Serial.println(nex.getCurrentPage());
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
		button_index = temp_1_index;
		Serial.println(button_index);
	}
}


void bt_temp_2_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		button_index = temp_2_index;
		Serial.println(button_index);
	}
}


void bt_start_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
		Serial.println(F("start"));
		button_index = 0;
		change_page(step_one);
		burn_variable_init(program_index);
		run_flag = 1;
	}
}

void bt_return_Callback(NextionEventType type, INextionTouchable *widget)
{
    if (type == NEX_EVENT_PUSH)
    {
        button_index = 0;
        program_index = 0;
        burn_stop();
        run_flag = 0;
        accueil_pg.show();
        Serial.println(F("return"));
    }
}

void bt_stop_Callback(NextionEventType type, INextionTouchable *widget)
{
	if (type == NEX_EVENT_PUSH)
	{
	    button_index = 0;
		program_index = 0;
		burn_stop();
		run_flag = 0;
		accueil_pg.show();
        Serial.println("stop");
	}
}

void init_nextion(void)
{
	int i;

	init_variable();
	nextionSerial.begin(BAUD);
	nex.init();

	norm_bt.attachCallback(&page1_Callback);
	trempe_bt.attachCallback(&page2_Callback);
	recuit_bt.attachCallback(&page3_Callback);

	bt_palier1_txt.attachCallback(&bt_palier1_Callback);
	bt_palier2_txt.attachCallback(&bt_palier2_Callback);
	bt_pente1_txt.attachCallback(&bt_pente1_Callback);
	bt_pente2_txt.attachCallback(&bt_pente2_Callback);
	bt_temp_1_txt.attachCallback(&bt_temp_1_Callback);
	bt_temp_2_txt.attachCallback(&bt_temp_2_Callback);
	bt1_start.attachCallback(&bt_start_Callback);
	bt_return.attachCallback(&bt_return_Callback);
	bt_stop_p1.attachCallback(&bt_stop_Callback);
	bt_stop_p3.attachCallback(&bt_stop_Callback);
	bt_stop_p4.attachCallback(&bt_stop_Callback);
	bt_stop_p5.attachCallback(&bt_stop_Callback);
	return_txt.attachCallback(&bt_stop_Callback);
	Serial.println(F("init nextion end"));

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
			    sprintf(tmp,"%dh%02d",(int)(variable[program][i]/60),(int)(variable[program][i]%60));
				bt_pente1_txt.setText(tmp);
				break;
			case pente2_index :
			    sprintf(tmp,"%dh%02d",(int)(variable[program][i]/60),(int)(variable[program][i]%60));
				bt_pente2_txt.setText(tmp);
				break;
			case temp_1_index :
				sprintf(tmp,"%d°C",variable[program][i]);
				bt_temp_1_txt.setText(tmp);
				break;
			case temp_2_index :
				sprintf(tmp,"%d°C",variable[program][i]);
				bt_temp_2_txt.setText(tmp);
				break;
			default :
				break;
			}
			//Serial.println(tmp);
			previous_variable[program][i] = variable[program][i];
			time_total_value = 	variable[program][time_palier1_index] +
								variable[program][time_palier2_index] +
								variable[program][pente1_index] +
								variable[program][pente2_index];

			sprintf(tmp,"%dh%02d",(int)(time_total_value/60),(int)(time_total_value%60));
			time_total_txt.setText(tmp);
			save_value(i, program);
		}
	}
}

static void display_refresh_fire_value(uint8_t program, int step)
{
	char tmp[10];

    if(program == 0)
        return;
    else
        program = program - 1;

    sprintf(tmp,"%dh%02d",(int)(variable[program][time_palier1_index]/60),(int)(variable[program][time_palier1_index]%60));
    palier1_txt.setText(tmp);
    sprintf(tmp,"%dh%02d",(int)(variable[program][time_palier2_index]/60),(int)(variable[program][time_palier2_index]%60));
    palier2_txt.setText(tmp);
    sprintf(tmp,"%d°C",variable[program][temp_1_index]);
    temp_1_txt.setText(tmp);
    sprintf(tmp,"%d°C",variable[program][temp_2_index]);
    temp_2_txt.setText(tmp);

    if (step == step_one) {
        sprintf(tmp,"%dh%02d",(int)(variable[program][pente1_index]/60),(int)(variable[program][pente1_index]%60));
        pente1_txt.setText(tmp);
    }
    if (step == step_three) {
        sprintf(tmp,"%dh%02d",(int)(variable[program][pente2_index]/60),(int)(variable[program][pente2_index]%60));
        pente2_txt.setText(tmp);
    }
}

void display_refresh(void){
    static bool toggle = false;
    static uint8_t previous_page = 0x0F;

	nex.poll();

    toggle = !toggle;
    digitalWrite(7,toggle);
    if (run_flag) {
        burn_regulation();
    } else {
        display_encoder(button_index, program_index);
        display_refresh_value(false, program_index);
        refresh_temp();
	}


}

static void refresh_temp(void) {
    int temp, page;
    char tmp0[10];

    if (!timeout_1s_flag)
         return;
    temp = int(read_temp());
    page = nex.getCurrentPage();
    //Serial.println(page);
    sprintf(tmp0,"%d°C", temp);
    switch (page) {
    case 0:
        temp_pg0_txt.setText(tmp0);
        break;
    case 1:
        temp_txt.setText(tmp0);
        break;
    default:
        break;
    }
    timeout_1s_flag = false;
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
		delta = 1;
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

    int add;char tmp[20];

    cli();
    add = program * nb_variable + index << 1;
    EEPROM.write(add, (uint8_t)(variable[program][index] & 0xFF));
    EEPROM.write(add + 1, (uint8_t)((variable[program][index] & 0xFF00) >> 8));
    sei();
    //sprintf(tmp,"save %d %d %d %d",program, index, add, variable[program][index]);
    //Serial.println(tmp);
}

static void read_value(int index, int program)
{
    int add;
    uint8_t tmp0, tmp1;
    char tmp[20];

    cli();
    add = program * nb_variable + index << 1;
    tmp0 = EEPROM.read(add);
    tmp1 = EEPROM.read(add + 1);
    variable[program][index] = tmp0 + (tmp1 << 8);
    sei();
    //sprintf(tmp,"read %d %d %d %d",program, index, add, variable[program][index]);
    //Serial.println(tmp);
    check_value(index, program);
}

static void burn_variable_init(int program)
{

    if(program == 0)
        return;
    else
        program = program - 1;

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

void refresh_temp_burn(int temp, int time, int step)
{
    char tmp0[10], tmp1[10];

    sprintf(tmp0,"%d°C", temp);
    sprintf(tmp1,"%dh%02d",(int)(time/60),(int)(time%60));
    if (step < step_five)
    {
        temp_reel_txt.setText(tmp0);
        time_reel_txt.setText(tmp1);
    } else {
        temp_finish_txt.setText(tmp0);
    }
}

void change_page(int step)
{
    switch (step) {
    case step_one:
        phase1_pg.show();
        display_refresh_fire_value(program_index, step);
        break;
    case step_two:
        phase1_pause_pg.show();
        display_refresh_fire_value(program_index, step);
        break;
    case step_three:
        phase2_pg.show();
        display_refresh_fire_value(program_index, step);
        break;
    case step_four:
        phase2_pause_pg.show();
        display_refresh_fire_value(program_index, step);
        break;
    case step_five:
        cooked_pg.show();
        break;
    default :
        break;
    }
}

void flamme_display(int on_off_flag) {
    button.setActive(on_off_flag);
}
