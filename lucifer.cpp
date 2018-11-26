#include <Arduino.h>
#define __AVR_ATmega328P__

#include "encoder.h"
#include "display.h"


void setup()
{
	Serial.begin(9600);
	Serial.println("Lucifer init");
	init_nextion();
	init_encoder();
	pinMode(7,OUTPUT);
	pinMode(5,OUTPUT);

} // setup()




boolean toggle = false;
// Read the current position of the encoder and print out when changed.
void loop()
{
	uint8_t page;

	  toggle = !toggle;
	  digitalWrite(7,toggle);
	  page = display_refresh();
	  if (page ==  4)
		  Serial.print("start");

} // loop ()

// The End
