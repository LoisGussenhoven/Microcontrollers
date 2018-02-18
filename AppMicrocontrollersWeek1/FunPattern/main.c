/*
 * FunPattern.c
 *
 * Created: 18-2-2018 13:28:36
 * Author : Lois Gussenhoven
 * Een looplicht kun je implementeren met een schuifoperatie. Als het gewenste patroon niet zo
 * eenvoudig is kun je e.a. met een grote if-then-else of switch-case constructie implementeren.
 * Dit levert, in het algemeen, slecht onderhoudbare en starre implementaties op. Beter is om een
 * lichtpatroon te sturen vanuit een datastructuur, bijvoorbeeld een C array. Enig idee hoe dit moet? Zie
 * ook het voorbeeld in de code repository.
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

typedef struct {
	unsigned char data;
	unsigned int delay ;
} PATTERN_STRUCT;

PATTERN_STRUCT pattern[] = {
	{0x00, 100}, {0x01, 100}, {0x02, 100}, {0x04, 100}, {0x10, 100}, {0x20, 100}, {0x40, 100}, {0x80, 100},
	{0x00, 100},
	{0xAA,  50}, {0x55,  50},
	{0xAA,  50}, {0x55,  50},
	{0xAA,  50}, {0x55,  50},
	{0x00, 100},
	{0x81, 100}, {0x42, 100}, {0x24, 100}, {0x18, 100}, {0x0F, 200}, {0xF0, 200}, {0x0F, 200}, {0xF0, 200},
	{0x00, 0x00}
};

void wait( int ms ){
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main( void )
{
	DDRD = 0b11111111;					// PORTD all output

	while (1==1)
	{
		int index = 0;
		while( pattern[index].delay != 0 )
		{
			PORTD = pattern[index].data;
			wait(pattern[index].delay);
			index++;
		}
	}

	return 1;
}


