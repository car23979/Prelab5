/*
 * pwm_servo.h
 *
 * Created: 11/04/2025 12:33:41 p. m.
 *  Author: Admin
 */ 

#ifndef PWM_SERVO_H
#define PWM_SERVO_H

#include <stdint.h>

void PWM_Init();
void PWM_SetPulseWidth(uint16_t pulseWidth);

#endif
