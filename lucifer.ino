#include <Arduino.h>
#define __AVR_ATmega328P__

#include "encoder.h"
#include "display.h"
#include "temperature.h"
#include "regulation.h"

static int i = 0;

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

  Serial.print("\nburn_regulation");
  Serial.print(",");
  Serial.print("run_time");
  Serial.print(",");
  Serial.print("temp");
  Serial.print(",");
  Serial.print("temp_consigne");
  Serial.print(",");
  Serial.print("output");
  Serial.print(",");
  Serial.print("Kp");
  Serial.print(",");
  Serial.print("Ki");
  Serial.print(",");
  Serial.print("Kd");
  Serial.print("\n");
  
  Serial.print("compute_pid");
  Serial.print(",");
  Serial.print("run_time");
  Serial.print(",");
  Serial.print("output");
  Serial.print(",");
  Serial.print("window");
  Serial.print(",");
  Serial.print("on_off_heat");
  Serial.print("\n");

} // setup()

// Read the current position of the encoder and print out when changed.
void loop()
{ 
	display_refresh();
} // loop ()

// The End
