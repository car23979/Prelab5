/*
 * pwm.h
 *
 * Created: 11/04/2025 01:35:17 p. m.
 *  Author: Admin
 */ 

// pwm.h
#ifndef PWM_H
#define PWM_H

#include <avr/io.h>

void PWM_Init();
void PWM_SetDutyCycle(uint16_t duty);

#endif