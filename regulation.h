/*
 * regulation.h
 *
 *  Created on: 18 sept. 2019
 *      Author: Valentin
 */

#ifndef REGULATION_H_
#define REGULATION_H_

extern int time_palier1_extern;
extern int time_palier2_extern;
extern int pente1_extern;
extern int pente2_extern;
extern int temp_1_extern;
extern int temp_2_extern;
extern unsigned long start_time;
extern int step;

typedef enum {
    step_one,
    step_two,
    step_three,
    step_four,
    step_five
};

void burn_regulation(void);
void burn_stop(void);

#endif /* REGULATION_H_ */
