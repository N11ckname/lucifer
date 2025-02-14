#include <Arduino.h>
#define __AVR_ATmega328P__

#include "encoder.h"
#include "display.h"
#include "temperature.h"
#include "regulation.h"

void setup()
{
	Serial.begin(115200);
	Serial.println(F("Lucifer init"));
	init_nextion();
	init_encoder();
	init_temp_sensor();
	init_temp_irq();
	pinMode(7,OUTPUT);
	pinMode(5,OUTPUT);

} // setup()

// Read the current position of the encoder and print out when changed.
void loop()
{
	display_refresh();
} // loop ()

// The End
