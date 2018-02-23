/*
 * PatternSegmentDisplay.c
 *
 * Created: 22-2-2018 16:14:20
 * Author : Lois Gussenhoven
 * Bestudeer de code uit de repository uit lesweek 1 (lookup.c) waarin met behulp van een lookup-table
 * een patronen op leds worden afgebeeld. Implementeer een ‘7 segment display lichteffect’ met behulp
 * van deze techniek. Zie presentatie voor de aansluiting van het 7 segment display.
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

typedef struct {
	int bits;
	int delay;
} PATTERN;

PATTERN pattern[] = {
	{0x00, 50},
	{0x01, 50}, {0x02, 50}, {0x04, 50}, {0x08, 50}, {0x10, 50}, {0x20, 50},
	{0x20,50}, {0x10, 50},{0x08,50},{0x04,50},{0x02, 50}, {0x01, 50},
	{0x7F, 250}, {0x00, 250}, {0x7F, 250}, {0x00, 250},
	{0x7F, 250}, {0x00, 250}, {0x7F, 250}, {0x00, 250},
	{0x20,50}, {0x10, 50},{0x08,50},{0x04,50},{0x02, 50}, {0x01, 50}
	{0x01, 50}, {0x02, 50}, {0x04, 50}, {0x08, 50}, {0x10, 50}, {0x20, 50},
	{0x08, 50}, {0x10, 50}, {0x20, 50},
	{0x01, 50}, {0x02, 50}, {0x04, 50},
	{0x00, 50}
};

void wait( int ms ){
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}

int main(void)
{
	DDRC = 0xFF;

	while (1)
	{
		int i = 0;
		while(pattern[i].delay != 0 ) {
			PORTC = pattern[i].bits;
			wait(pattern[i].delay);
			i++;
		}
	}
}

