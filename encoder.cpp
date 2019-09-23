/*
 * encoder.cpp
 *
 *  Created on: 17 oct. 2018
*      Author: Valentin
 */

#include "encoder.h"
#include "hardware/RotaryEncoder.h"


// Setup a RoraryEncoder for pins A2 and A3:
RotaryEncoder encoder(A2, A3);

void init_encoder(void){
	 // You may have to modify the next 2 lines if using other pins than A2 and A3
	  PCICR |= (1 << PCIE1);    // This enables Pin Change Interrupt 1 that covers the Analog input pins or Port C.
	  PCMSK1 |= (1 << PCINT10) | (1 << PCINT11);  // This enables the interrupt for pin 2 and 3 of Port C.

}

// The Interrupt Service Routine for Pin Change Interrupt 1
// This routine will only be called on any signal change on A2 and A3: exactly where we need to check.
ISR(PCINT1_vect) {
  encoder.tick(); // just call tick() to check the state.
}


long position_encoder(void){
	return(encoder.getPosition());
}
