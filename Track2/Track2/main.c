/*
 * Track2.c
 *
 * Created: 21-2-2018 13:40:31
 * Author : Lois Gussenhoven
 * Implementeer een looplicht applicatie waarbij de main() bestaat uit een initialisatie gedeelte met
 daarna een lege while(true) loop. In ISR_INT1 en ISR_INT2 maakt het looplicht steeds 1 stap. Het
 looplicht wordt dus gestuurd vanuit de ISR’s, niet vanuit de main().
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
    DDRD = 0x00;
    DDRC = 0xFF;

    EICRA |= 0x3C;			
    EIMSK |= 0x06;			
    
    sei();
    
    PORTC = 0x01;

    while (1)
    {

    }

    return 1;
}

ISR( INT1_vect )
{
	PORTC = PORTC << 1;
}

ISR( INT2_vect )
{
	PORTC = PORTC >> 1;
}