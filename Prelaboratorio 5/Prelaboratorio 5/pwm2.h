/*
 * pwm2.h
 *
 * Created: 11/04/2025 05:36:34 p. m.
 *  Author: David Carranza
 */ 


#ifndef PWM2_H_
#define PWM2_H_

#include <avr/io.h>
#include <stdint.h>

// Inicializa los temporizadores PWM (Timer1 para servos, Timer0 para LED)
void PWM2_Init();

// Define la posición del servo 2 conectado a PB2
void setServo2(uint16_t pulseWidth);


#endif /* PWM2_H_ */