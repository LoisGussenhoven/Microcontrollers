/*
 * b2.c
 *
 * Created: 7-3-2018 15:01:30
 * Author : Lois Gussenhoven
 */ 

#define F_CPU 8000000
#define Vref 5120

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdio.h>

typedef unsigned long int u_int32;
typedef unsigned int u_int16;
typedef unsigned char u_char;

u_int16 voltage = 0x0000;
int vFlag = 0;

ISR(ADC_vect)
{
	u_int32 result = ADCH << 2; // Take most important 8 bits
	result *= Vref;
	result /= 1023;
	
	voltage = result;
	vFlag = 1; 
}

int main(void)
{
	DDRA = DDRB = 0xFF;
	DDRF &= ~0x08;	// PF3(ADC3) Read
	
	ADMUX = 0x23;	
	ADCSRA = 0x8A;
	
	sei();	

	ADCSRA |= 0x40;
	
	while (1)
	{
		if (vFlag)
		{
			vFlag = 0;
			_delay_ms(50);
			ADCSRA |= 0x40; 
			PORTA = PORTB = (0xFF << (8 - voltage * 8 / Vref));
		}
		
		asm(""); 
	}
}