/*
 * WithInputBlink.c
 *
 * Created: 18-2-2018 13:13:50
 * Author : Lois Gussenhoven
 * Maak een applicatie die de led op PORTD.7 laat knipperen als drukknop PORTC.0 laag (0) is
 * (ingedrukt) en stopt bij het loslaten van de drukknop.
 */ 

#include <avr/io.h>
#include <util/delay.h>

void wait( int ms ){
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}


int main(void)
{
	DDRD = 0x80;
	DDRC = 0x00;
	
    while (1) 
    {
		if(PINC & 0x10)
		{
			PORTD = 0x80;
			wait( 500 );
			PORTD = 0x00;
			wait( 500 );
		}
    }
	
	return 1;
}

