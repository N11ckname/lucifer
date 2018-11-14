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


} // setup()





// Read the current position of the encoder and print out when changed.
void loop()
{
  display_refresh();

} // loop ()

// The End
