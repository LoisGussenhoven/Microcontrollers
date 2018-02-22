/*
 * FastAndSlowBlink.c
 *
 * Created: 18-2-2018 13:31:32
 * Author : Lois Gussenhoven
 * Toestanden. Maak een applicatie die de led op PORTD.7 laat knipperen met een frequentie van circa
 * 1Hz (1 keer per seconde). Als nu PORTC.0 kort wordt ingedrukt gaat (en blijft) de led sneller
 * knipperen (bijvoorbeeld 4H). Bij nogmaals kort drukken gaat (en blijft) de led weer knipperen met een
 * frequentie van 1Hz.
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
	DDRD = 0xFF;
	DDRC = 0x00;
	
	int i = 0;
	
	while(1)
	{
		if(PINC & 0x01){
			i++;
		}
		
		if(i%2 != 0)
		{
			PORTD = 0X80;
			wait(1000);
			PORTD =0x00;
			wait(1000);
		}
		else
		{
			PORTD = 0X80;
			wait(250);
			PORTD =0x00;
			wait(250);
		}
		
		
	}
}


