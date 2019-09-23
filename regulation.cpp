/*
 * regulation.c
 *
 *  Created on: 18 sept. 2019
 *      Author: Valentin
 */

#include "temperature.h"
#include "regulation.h"
#include <arduino.h>

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
    step_five
};

#define threshold_high  15 //°C
#define threshold_low   10 //°C
#define time_regulation 60000 //ms

void burn_regulation(void)
{
    float temp;
    uint32_t run_time, next_time_on, next_time_off, time_step_two, time_step_four;
    bool on_off_heat;

    pente1_extern = 20; //en %

    if (timeout_1s_flag) {
        temp = read_temp();
        cli();
        timeout_1s_flag = false;
        sei();
    }
    run_time = millis() -  start_time;

    switch(step) {
    case step_one :
        if (run_time > next_time_on)
        {
            next_time_off = run_time + (time_regulation * pente1_extern / 100 ); //en ms
            next_time_on = next_time_off + time_regulation;
            on_off_heat = false;
        }

        if (run_time > next_time_off)
        {
            next_time_on = run_time + (time_regulation * (100 - pente1_extern) / 100 ); //en ms
            next_time_off = next_time_on + time_regulation;
            on_off_heat = true;
        }

        if (temp > temp_1_extern)
        {
            time_step_two = run_time + (time_palier1_extern * 60000); //en ms
            step = step_two;
            Serial.println("step Two !!");
        }

        Serial.print("run time : ");
        Serial.print(run_time);
        Serial.print(" on time : ");
        Serial.print(next_time_on);
        Serial.print(" off time : ");
        Serial.print(next_time_on);
        Serial.print(" Heat : ");
        Serial.println(on_off_heat);
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
        }
        break;

    case step_three :
        if (run_time > next_time_on)
        {
            next_time_off = run_time + (time_regulation * pente2_extern / 100 ); //en ms
            next_time_on = next_time_off + time_regulation;
            on_off_heat = false;
        }

        if (run_time > next_time_off)
        {
            next_time_on = run_time + (time_regulation * (100 - pente2_extern) / 100 ); //en ms
            next_time_off = next_time_on + time_regulation;
            on_off_heat = true;
        }

        if (temp > temp_1_extern)
        {
            time_step_four = run_time + (time_palier2_extern * 60000); //en ms
            step = step_four;
            Serial.println("step Four !!");
        }
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
        on_off_heat = false;
        break;
    default:
        break;
    }




}


void burn_stop(void)
{

}
