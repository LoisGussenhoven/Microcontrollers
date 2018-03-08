/*
 * Counter.c
 *
 * Created: 8-3-2018 14:36:04
 * Author : Lois Gussenhoven
 */ 

#define F_CPU 8000000
#define REACH_VALUE 1

#include <avr/io.h>
#include <avr/interrupt.h>

#include <util/delay.h>

#include "lcd.h"

int count = 0;

ISR( TIMER2_OVF_vect  )
{
	count++;
}

void timer2_init()
{
	OCR2 = REACH_VALUE; //klok tot hoelang die moet tikken
	TIMSK |= 0x08; 
	SREG  |= 0x08;		//interrupt enable
	TCCR2 = 0x1F;
}


int main(void)
{
   char buffer[20];
   DDRD = 0x00;
   
   DDRA = 0xFF;
   
   lcd_init();
   timer2_init();
   
   while (1)
   {
	   PORTA = TCNT2;
	   
	   lcd_set_cursor(7,1);
	   lcd_display_text(itoa(count, buffer, 10));
	   _delay_ms(10);
   }
}

