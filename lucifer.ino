#include <Arduino.h>
#define __AVR_ATmega328P__

#include "encoder.h"
#include "display.h"
#include "temperature.h"
#include "regulation.h"
#include "log.h"

static int i = 0;

void setup()
{
	Serial.begin(115200);
  logging::log_console_header("MSG_GENERAL");
  logging::log_console("MSG_GENERAL", logging::severity::INFO, "Lucifer init");

	// Serial.println(F("Lucifer init"));
	init_nextion();
	init_encoder();
	init_temp_sensor();
	init_temp_irq();
	pinMode(7,OUTPUT);
	pinMode(5,OUTPUT);

  logging::log_header("REGULATION",
                      "runtime_us",
                      "temp",
                      "temp_consigne",
                      "out",
                      "Kp",
                      "Ki",
                      "Kd");

  logging::log_header("ACTUATOR",
                      "runtime_us",
                      "out_pid",
                      "out_pid_cons",
                      "w_start_ms",
                      "w_thresh_ms",
                      "on_off");

  logging::log_console_header("MSG_REGULATION");
  logging::log_console_header("MSG_BUTTON");
  logging::log_console_header("MSG_TEMP_READ");

} // setup()

// Read the current position of the encoder and print out when changed.
void loop()
{ 
	display_refresh();
} // loop ()

// The End
