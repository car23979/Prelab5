/*
 * pwm_init.h
 *
 * Created: 24/04/2025 12:23:28 p. m.
 *  Author: Admin
 */ 


#ifndef LED_PWM_H_
#define LED_PWM_H_

#include <stdint.h>

void LED_PWM_Init(void);          // Inicializa Timer2 y el pin del LED
void LED_Update_Duty(uint8_t dc); // Actualiza el duty cycle del LED (0-255)

#endif
