/*
 * display.h
 *
 *  Created on: 17 oct. 2018
*      Author: Valentin
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_


void init_nextion(void);
void display_refresh(void);
void refresh_temp(int temp, int time, int step);
void change_page(int step);

extern bool run_flag;

#endif /* DISPLAY_H_ */
