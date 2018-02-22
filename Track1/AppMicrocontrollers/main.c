/*
 * AppMicrocontrollers.c
 *
 * Created: 18-2-2018 12:56:02
 * Author : Lois Gussenhoven
 * Maak een nieuwe applicatie die beurtelings de LED op PORTD, pin 7 (PORTD.7) en de LED op PORTD, pint 6 (PORTD.6) 
 * om de 500ms laat oplichten. Ontwikkel de applicatie in de simulator en programmeer daarna het board (gaat veel sneller!)
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
	DDRD = 0xFF;		//All pins PORTD are set to output
	
    while (1) 
    {
		PORTD = 0x80;
		wait( 500 );
		PORTD = 0x40;
		wait( 500 );
    }
	return 1;
}

