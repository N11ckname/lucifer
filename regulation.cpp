/*
 * regulation.c
 *
 *  Created on: 18 sept. 2019
 *      Author: Valentin
 */

#include "temperature.h"
#include "regulation.h"
#include "display.h"
#include <arduino.h>

int time_palier1_extern;
int time_palier2_extern;
int pente1_extern;
int pente2_extern;
int temp_1_extern;
int temp_2_extern;
unsigned long start_time;
int step;

#define threshold_high  15 //°C
#define threshold_low   10 //°C
#define time_regulation 30000 //ms

void burn_regulation(void)
{
    static int temp = 100;
    static uint32_t run_time, next_time = 0, time_step_two, time_step_four;
    static bool on_off_heat;
    char tmp[20];

    pente1_extern = 20; //en %
    pente2_extern = 80; //en %

    if (!timeout_1s_flag)
        return;

    //temp = int(read_temp());
    temp += 5;
    run_time = millis() -  start_time;
    refresh_temp(temp, int(run_time/60000), step);

    switch(step) {
    case step_one :
        if (run_time > next_time)
        {
            if (on_off_heat)
            {
                next_time = run_time + ((time_regulation / 100) * (100 - pente1_extern) ); //en ms
                on_off_heat = false;

            } else
            {
                next_time = run_time + ((time_regulation / 100) * pente1_extern ); //en ms
                on_off_heat = true;
            }
        }

        if (temp > temp_1_extern)
        {
            time_step_two = run_time + (time_palier1_extern * 60000); //en ms
            step = step_two;
            Serial.print("step Two !!");
            Serial.println(time_step_two);
        }
        sprintf(tmp,"run time %lu next : %lu heat : %d T %d°C", run_time, next_time, on_off_heat, temp );
        Serial.println(tmp);

        break;

    case step_two :
        if (temp > (temp_1_extern + threshold_high))
        {
            on_off_heat = false;
        }
        if (temp < (temp_1_extern - threshold_low))
        {
            on_off_heat = true;
        }
        if (run_time > time_step_two)
        {
            step = step_three;
            Serial.println("step Three !!");
            change_page(step);
        }

        break;

    case step_three :
        if (run_time > next_time)
        {
            if (on_off_heat)
            {
                next_time = run_time + ((time_regulation / 100) * (100 - pente2_extern) ); //en ms
                on_off_heat = false;

            } else
            {
                next_time = run_time + ((time_regulation / 100) * pente2_extern ); //en ms
                on_off_heat = true;
            }
        }

        if (temp > temp_2_extern)
        {
            time_step_four = run_time + (time_palier2_extern * 60000); //en ms
            step = step_four;
            Serial.print("step four !!");
            Serial.println(time_step_four);
        }
        sprintf(tmp,"run time %lu next : %lu heat : %d T %d°C", run_time, next_time, on_off_heat, temp );
        Serial.println(tmp);
        break;

    case step_four :
        if (temp > (temp_2_extern + threshold_high))
        {
            on_off_heat = false;
        }
        if (temp < (temp_2_extern - threshold_low))
        {
            on_off_heat = true;
        }
        if (run_time > time_step_four)
        {
            step = step_five;
            Serial.println("step Five !!");
        }
        break;

    case step_five :
        change_page(step);
        on_off_heat = false;
        break;
    default:
        break;
    }

    timeout_1s_flag = false;


}


void burn_stop(void)
{

}
