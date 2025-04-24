/*
 * pwm2.c
 *
 * Created: 11/04/2025 05:37:03 p. m.
 *  Author: David Carranza
 */ 

#include <avr/io.h>
#include "timer1_servo2.h"

void Timer1_Servo2_Init(void) {
	DDRB |= (1 << PINB2); // PB2 como salida
	// Solo habilita el pin, Timer1 debe estar configurado antes
}

void SERVO2_set(uint16_t pulso) {
	OCR1B = pulso;
}
