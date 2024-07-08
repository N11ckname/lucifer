/*
 * temperature.c
 *
 *  Created on: 17 sept. 2019
 *      Author: Valentin
 */

#include "src/hardware/Adafruit_MAX31856.h"
#include "log.h"

// Use software SPI: CS, DI, DO, CLK
Adafruit_MAX31856 maxthermo = Adafruit_MAX31856(8, 9, 12, 13);

bool timeout_1s_flag;

void init_temp_sensor(void)
{

    maxthermo.begin();
    maxthermo.setThermocoupleType(MAX31856_TCTYPE_S);
    maxthermo.setNoiseFilter(MAX31856_NOISE_FILTER_50HZ);

}

void init_temp_irq(void)
{
    cli();
    //set timer1 interrupt at 1Hz
    TCCR1A = 0;// set entire TCCR1A register to 0
    TCCR1B = 0;// same for TCCR1B
    TCNT1  = 0;//initialize counter value to 0
    // set compare match register for 1hz increments
    OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 1024 prescaler
    TCCR1B |= (1 << CS12) | (1 << CS10);
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
    sei();
}


float read_temp(void)
{
    float temp;
    static float temp_lpf;
    uint8_t fault = maxthermo.readFault();

    if (fault) {
        logging::log_console("MSG_TEMP_READ", logging::severity::ERROR, fault);

        Serial.println(fault);
        if (fault & MAX31856_FAULT_CJRANGE)
        {
            logging::log_console("MSG_TEMP_READ", logging::severity::ERROR, "Cold Junction Range Fault");
        }

        if (fault & MAX31856_FAULT_TCRANGE)
        {
            logging::log_console("MSG_TEMP_READ", logging::severity::ERROR, "Thermocouple Range Fault");
        }
        
        if (fault & MAX31856_FAULT_CJHIGH)
        {
            logging::log_console("MSG_TEMP_READ", logging::severity::ERROR, "Cold Junction High Fault");
        }

        if (fault & MAX31856_FAULT_CJLOW) 
        {
            logging::log_console("MSG_TEMP_READ", logging::severity::ERROR, "Cold Junction Low Fault");
        }

        if (fault & MAX31856_FAULT_TCHIGH)
        {
            logging::log_console("MSG_TEMP_READ", logging::severity::ERROR, "Thermocouple High Fault");
        }

        if (fault & MAX31856_FAULT_TCLOW)  
        {
            logging::log_console("MSG_TEMP_READ", logging::severity::ERROR, "Thermocouple Low Fault");
        }

        if (fault & MAX31856_FAULT_OVUV)   
        {
            logging::log_console("MSG_TEMP_READ", logging::severity::ERROR, "Over/Under Voltage Fault");
        }

        if (fault & MAX31856_FAULT_OPEN)  
        {
            logging::log_console("MSG_TEMP_READ", logging::severity::ERROR, "Thermocouple Open Fault");
        }

        return (0.0);
    }
    else {
        temp = maxthermo.readThermocoupleTemperature();
        temp_lpf = temp;//temp_lpf - ((temp_lpf - temp) * 0.95);
//        Serial.print(millis());
//        Serial.print(" : ");
//        Serial.print(maxthermo.readCJTemperature());
//        Serial.print(" : ");
//        Serial.print(temp_lpf);
//        Serial.print(" : ");
//        Serial.println(temp);

    }
        return (temp_lpf);
}



ISR(TIMER1_COMPA_vect){
    timeout_1s_flag = true;
}
