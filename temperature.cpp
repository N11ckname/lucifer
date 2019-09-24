/*
 * temperature.c
 *
 *  Created on: 17 sept. 2019
 *      Author: Valentin
 */

#include "hardware/Adafruit_MAX31856.h"

// Use software SPI: CS, DI, DO, CLK
Adafruit_MAX31856 maxthermo = Adafruit_MAX31856(8, 9, 12, 13);

bool timeout_1s_flag;

void init_temp_sensor(void)
{

    maxthermo.begin();
    maxthermo.setThermocoupleType(MAX31856_TCTYPE_K);
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
        Serial.println(fault);
        if (fault & MAX31856_FAULT_CJRANGE) Serial.println("Cold Junction Range Fault");
        if (fault & MAX31856_FAULT_TCRANGE) Serial.println("Thermocouple Range Fault");
        if (fault & MAX31856_FAULT_CJHIGH)  Serial.println("Cold Junction High Fault");
        if (fault & MAX31856_FAULT_CJLOW)   Serial.println("Cold Junction Low Fault");
        if (fault & MAX31856_FAULT_TCHIGH)  Serial.println("Thermocouple High Fault");
        if (fault & MAX31856_FAULT_TCLOW)   Serial.println("Thermocouple Low Fault");
        if (fault & MAX31856_FAULT_OVUV)    Serial.println("Over/Under Voltage Fault");
        if (fault & MAX31856_FAULT_OPEN)    Serial.println("Thermocouple Open Fault");
        return (0.0);
    }
    else {
        temp = maxthermo.readThermocoupleTemperature();
        temp_lpf = temp_lpf - ((temp_lpf - temp) * 0.25);
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
