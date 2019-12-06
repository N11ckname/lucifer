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

#define ambiant_temp  30

void burn_regulation(void)
{
     static int temp = 20;
     static uint32_t run_time, next_time = 0, time_step_two, time_step_four;
     static bool on_off_heat;
     int temp_consigne;
     char tmp[20];

     if (!timeout_1s_flag)
         return;

     //temp = int(read_temp());
     temp = temp + 1;

     run_time = millis() -  start_time;
     refresh_temp(temp, int(run_time/60000), step);

     switch(step) {
     case step_one :
         temp_consigne = (int)((float)(temp_1_extern) * (float)(run_time)/((float)(pente1_extern)*60000)) + ambiant_temp;

         if (temp > temp_1_extern)
         {
             time_step_two = run_time + (time_palier1_extern * 60000); //en ms
             step = step_two;
             change_page(step);
             Serial.print(F("step Two !!"));
             Serial.println(time_step_two);
         }
         break;

     case step_two :
         temp_consigne = temp_1_extern;

         if (run_time > time_step_two)
         {
             step = step_three;
             Serial.println(F("step Three !!"));
             start_time = millis();
             change_page(step);
         }

         break;

     case step_three :
         temp_consigne = (int)((float)(temp_2_extern-temp_1_extern) * (float)(run_time)/((float)(pente1_extern)*60000)) + temp_1_extern;

         if (temp > temp_2_extern)
         {
             time_step_four = run_time + (time_palier2_extern * 60000); //en ms
             step = step_four;
             change_page(step);
             Serial.print(F("step four !!"));
             Serial.println(time_step_four);
         }

         break;

     case step_four :
         temp_consigne = temp_2_extern;

         if (run_time > time_step_four)
         {
             step = step_five;
             change_page(step);
             Serial.println(F("step Five !!"));
         }
         break;

     case step_five :
         on_off_heat = false;
         break;
     default:
         break;
     }
     if (temp > (temp_consigne))
     {
         on_off_heat = false;
     }
     if (temp < (temp_consigne))
     {
         on_off_heat = true;
     }
     Serial.print(F("run time "));
     Serial.print(run_time);
     Serial.print(F(" Heat :"));
     Serial.print(on_off_heat);
     Serial.print(F(" T :"));
     Serial.print(temp);
     Serial.print(F(" Tc :"));
     Serial.println(temp_consigne);

     digitalWrite(5, on_off_heat);
     flamme_display(on_off_heat);
     timeout_1s_flag = false;
}


void burn_stop(void)
{
    digitalWrite(5, false);
}
