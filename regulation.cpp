/*
 * regulation.c
 *
 *  Created on: 18 sept. 2019
 *      Author: Valentin
 */

#include "temperature.h"
#include "regulation.h"
#include <avr/interrupt.h>

int time_palier1_extern;
int time_palier2_extern;
int pente1_extern;
int pente2_extern;
int temp_1_extern;
int temp_2_extern;
unsigned long start_time;
int step;

typedef enum {
    step_one,
    step_two,
    step_three,
    step_four,
};

void burn_regulation(void)
{
    float temp;
    if (timeout_1s_flag) {
        temp = read_temp();
        cli();
        timeout_1s_flag = false;
        sei();
    }
    switch(step) {
    case step_one :
        break;
    case step_two :
        break;
    case step_three :
        break;
    case step_four :
        break;
    default:
        break;
    }




}


void burn_stop(void)
{

}
