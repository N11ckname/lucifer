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
#include "src/hardware/PID_v1.h"

int time_palier1_extern;
int time_palier2_extern;
int pente1_extern;
int pente2_extern;
int temp_1_extern;
int temp_2_extern;
unsigned long start_time;
int step;

#define ambiant_temp  30
#define relais_pin     5



//Specify the links and initial tuning parameters
double Setpoint, Input, Output;
double Kp=2, Ki=5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
int WindowSize = 2000;
unsigned long windowStartTime;

void init_pid(void) {
    myPID.SetOutputLimits(0, WindowSize);
    windowStartTime = millis();
    //turn the PID on
    myPID.SetMode(AUTOMATIC);
}

void burn_regulation(void)
{
     static int temp;
     static uint32_t run_time, next_time = 0, time_step_two, time_step_four;
     int temp_consigne;
     char tmp[20];

     if (!timeout_1s_flag)
         return;

     temp = int(read_temp());
     //temp = temp + 10;

     run_time = millis() -  start_time;
     refresh_temp_burn(temp, int(run_time/60000), step);

     switch(step) {
     case step_one :
         if (pente1_extern)
             temp_consigne = (int)((float)(temp_1_extern) * (float)(run_time)/((float)(pente1_extern)*60000)) + ambiant_temp;
         if (temp_consigne > temp_1_extern)
             temp_consigne = temp_1_extern;

        Setpoint = (double)(temp_consigne);
        Input = (double)(temp);
        myPID.Compute();

         if ((temp > temp_1_extern) || (pente1_extern == 0))
         {
             time_step_two = run_time + (time_palier1_extern * 60000); //en ms
             step = step_two;
             change_page(step);
             refresh_temp_burn(temp, int(run_time/60000), step);
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
             change_page(step);
             refresh_temp_burn(temp, int(run_time/60000), step);
         }

         break;

     case step_three :
         if (pente2_extern)
             temp_consigne = (int)((float)(temp_2_extern-temp_1_extern) * (float)(run_time)/((float)(pente2_extern)*60000)) + temp_1_extern;
         if (temp_consigne > temp_2_extern)
             temp_consigne = temp_2_extern;

         if ((temp > temp_2_extern) || (pente2_extern == 0))
         {
             time_step_four = run_time + (time_palier2_extern * 60000); //en ms
             step = step_four;
             change_page(step);
             refresh_temp_burn(temp, int(run_time/60000), step);
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
             refresh_temp_burn(temp, int(run_time/60000), step);
             Serial.println(F("step Five !!"));
         }
         break;

     case step_five :
         burn_stop();
         flamme_display(false);
         break;
     default:
         break;
     }

     Serial.print(F("time "));
     Serial.print(run_time);
     Serial.print(F(";T :"));
     Serial.print(temp);
     Serial.print(F(";Tc :"));
     Serial.println(temp_consigne);

     timeout_1s_flag = false;
}

void compute_pid(void) {
    
    static bool on_off_heat;

    if ((millis() - windowStartTime) > WindowSize)
    { //time to shift the Relay Window
      windowStartTime += WindowSize;
    }

    if (Output < (millis() - windowStartTime))
      on_off_heat = 0;
    else
      on_off_heat = 1;

    digitalWrite(relais_pin, on_off_heat);
    flamme_display(on_off_heat);

}

void burn_stop(void)
{
    digitalWrite(relais_pin, false);
}

