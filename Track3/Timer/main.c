/*
 * Timer.c
 *
 * Created: 8-3-2018 16:15:11
 * Author : Lois Gussenhoven
 */ 

#define F_CPU 8 * 10 ^6
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int tick = 0;
int high = 1;

ISR( TIMER2_COMP_vect )
{
	tick++;
	if(high && 15 == tick){
		PORTD = 0x00;
		tick = 0;
		high = 0;
		}else if(25 == tick){
		PORTD = 0xFF;
		high = 1;
		tick = 0;
	}
}

int main(void)
{
	DDRD = 0xFF;

	OCR2 = 519;
	TCCR2 = 1<<WGM21;
	
	//enable interrupts
	TIMSK = TIMSK | 1<<TOIE1 | 1<<OCIE2;
	TCCR2 |= 1<<CS22 | 0<<CS21 | 1<<CS20;
	TCNT2 = 0;
	
	sei();
}

