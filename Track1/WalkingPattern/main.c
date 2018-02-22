/*
 * WalkingPattern.c
 *
 * Created: 18-2-2018 13:21:40
 * Author : Lois Gussenhoven
 * Implementeer een looplicht applicatie op de LED’s van PORTD. Tussen elke verandering van output zit
 * 50ms (milliseconden). Hoe zou je dit kunnen meten?. Om een eenvoudig looplicht te maken kun je
 * gebruik maken van de shift operatoren in C (de >> en de <<). Dit heb je ook al gedaan in periode TI1.1
 * op het GUI board.
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
	PORTC = 0;
	
	int b = 0x01;
	int d = 0; 

    while (1) 
    {
		PORTD = b;
		if(b & 0x01;){
			d = 0;}
			
		if(b & 0x80){
			d = 1;}
			
		if(d == 0){
			b = b << 1;}
			
		if(d == 1){
			b = b >> 1;}
			
		wait(500;)
    }
	return 1;
}

