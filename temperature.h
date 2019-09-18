/*
 * temperature.h
 *
 *  Created on: 17 sept. 2019
 *      Author: Valentin
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

extern bool timeout_1s_flag;

void init_temp_sensor(void);
void init_temp_irq(void);
float read_temp(void);



#endif /* TEMPERATURE_H_ */
