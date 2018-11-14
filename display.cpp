/*
 * display.cpp
 *
 *  Created on: 17 oct. 2018
 *      Author: Devialet
 */

//#define NEOSWSERIAL_EXTERNAL_PCINT

#include <Nextion.h>
#include <NextionPage.h>
#include <NextionText.h>
#include <NextionVariableNumeric.h>
#include <NextionVariableString.h>
//#include <NeoSWSerial.h>
#include <SoftwareSerial.h>
#include <NextionButton.h>

#include <stdio.h>
#include <string.h>

#include "encoder.h"

#define BAUD 9600

//NeoSWSerial nextionSerial(10, 11); // RX (blue), TX(yellow)
SoftwareSerial nextionSerial(10, 11); // RX (blue), TX(yellow)


Nextion nex(nextionSerial);

#define page_petit_feu	0
#define page_grand_feu	1
#define page_recuit		2

#define nb_page	page_recuit + 1

NextionVariableNumeric 	bt_palier1[nb_page]			{{nex, 1, 7, "bt2"},{nex, 2, 7, "bt2"},{nex, 3, 7, "bt2"}};
NextionButton 			bt_palier1_txt[nb_page]		{{nex, 1, 7, "bt2"},{nex, 2, 7, "bt2"},{nex, 3, 7, "bt2"}};
NextionVariableNumeric 	bt_palier2[nb_page]			{{nex, 1, 10, "bt5"},{nex, 2, 10, "bt5"},{nex, 3, 10, "bt5"}};
NextionButton 			bt_palier2_txt[nb_page]		{{nex, 1, 10, "bt5"},{nex, 2, 10, "bt5"},{nex, 3, 10, "bt5"}};

NextionVariableNumeric bt_pente1(nex, 2, 9, "bt4");
NextionButton bt_pente1_txt(nex, 2, 9, "bt4");
NextionVariableNumeric bt_pente2(nex, 2, 8, "bt3");
NextionButton bt_pente2_txt(nex, 2, 8, "bt3");

NextionVariableNumeric bt_temp_1(nex, 2, 6, "bt1");
NextionButton bt_temp_1_txt(nex, 2, 6, "bt1");
NextionVariableNumeric bt_temp_2(nex, 2, 5, "bt0");
NextionButton bt_temp_2_txt(nex, 2, 5, "bt0");

NextionText time_total_txt(nex, 2, 2, "t4");

#define time_palier1_index 	0
#define time_palier2_index 	1
#define pente1_index 		2
#define pente2_index 		3
#define temp_1_index 		4
#define temp_2_index 		5

#define nb_variable	(temp_2_index + 1)

#define page_petit_feu	0
#define page_grand_feu	1
#define page_recuit		2

#define nb_page	page_recuit + 1

long variable[nb_page][nb_variable] = {
	{20,
	90,
	100,
	500,
	400,
	800},
	{5,
	90,
	200,
	500,
	400,
	1200},
	{60,
	120,
	10,
	50,
	200,
	500}
};

static void display_refresh_value(int forced,int page);
static void display_encoder(int index,int page);
static void check_value(int index, int page);

void init_nextion(void){
	nextionSerial.begin(BAUD);
	nex.init();
	delay(2000);
}

static void display_refresh_value(int forced,int page){

	static long previous_variable[nb_page][nb_variable];
	int i;
	char tmp[10];
	long time_total_value;

	for(i = 0; i < nb_variable;i++){
		if(( variable[page][i] != previous_variable[page][i] ) || forced){
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
				bt_pente1_txt.setText(tmp);
				break;
			case pente2_index :
				sprintf(tmp,"%d °C/h",variable[page][i]);
				bt_pente2_txt.setText(tmp);
				break;
			case temp_1_index :
				sprintf(tmp,"%d °C",variable[page][i]);
				bt_temp_1_txt.setText(tmp);
				break;
			case temp_2_index :
				sprintf(tmp,"%d °C",variable[page][i]);
				bt_temp_2_txt.setText(tmp);
				break;
			default :
				break;
			}
			previous_variable[page][i] = variable[page][i];
			time_total_value = 	variable[page][time_palier1_index] +
								variable[page][time_palier2_index] +
								(variable[page][temp_1_index]/variable[page][pente1_index])*60 +
								((variable[page][temp_2_index] - variable[page][temp_1_index])/variable[page][pente2_index])*60;
			sprintf(tmp,"%dh%02d",(int)(time_total_value/60),(int)(time_total_value%60));
			time_total_txt.setText(tmp);
		}
	}
}

void display_refresh(void){
	int page;
	static int previous_page;

	page = nex.getCurrentPage();

	Serial.println(page);

	if((page> 0) && (page < 3)){
		//page -= 1;
		if(page != previous_page){
			previous_page = page;
			display_refresh_value(true,page);
		}
	//	if(page == 1){

			if(bt_palier1[page].getValue())
				display_encoder(time_palier1_index,page);
			if(bt_palier2[page].getValue())
				display_encoder(time_palier2_index,page);
			if(bt_pente1.getValue())
				display_encoder(pente1_index,page);
			if(bt_pente2.getValue())
				display_encoder(pente2_index,page);
			if(bt_temp_1.getValue())
				display_encoder(temp_1_index,page);
			if(bt_temp_2.getValue())
				display_encoder(temp_2_index,page);
		}
		display_refresh_value(false,page);
	//}
}

static void display_encoder(int index,int page){
	static int newPos;
	int current_position,delta = 0;
	static bool first_time_flag = 1;


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
		delta = 50;
		break;
	default :
		break;
	}
	current_position = position_encoder();
	variable[page][index] = variable[page][index] + (current_position - newPos) * delta;
	newPos = current_position;

	check_value(index,page);

	Serial.println("coucou");
	Serial.println(index);
	Serial.println(page);
	Serial.println(variable[page][index]);
	Serial.println("end");
}

static void check_value(int index, int page){
	if(( variable[page][temp_1_index] > variable[page][temp_2_index] ) && ( index == temp_1_index))
		variable[page][temp_1_index] = variable[page][temp_2_index];
	if(( variable[page][temp_2_index] < variable[page][temp_1_index] ) && ( index == temp_2_index))
		variable[page][temp_2_index] = variable[page][temp_1_index];
}


