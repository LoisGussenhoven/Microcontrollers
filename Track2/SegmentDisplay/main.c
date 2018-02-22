/*
 * SegmentDisplay.c
 *
 * Created: 21-2-2018 14:01:17
 * Author : Lois Gussenhoven
 * Implementeer een functie waarmee een 7 segment display kan worden aangestuurd. Bijvoorbeeld:
 * void display(int digit){…}.
 * Als 0 <= digit <= 15 dan wordt ‘digit’ hexadecimaal weergegeven op het 7 segment display, als ‘digit’
 * > 15 verschijnt op het display de ‘E’ van Error. Tip: maak gebruik van een lookup-table.
 * Implementeer ook de functionaliteit dat de waarde op het display steeds met 1 wordt verhoogd /
 * verlaagd bij het indrukken van toetsen (up / down). Als je op beide toetsen tegelijk drukt wordt het
 * display gereset naar ‘0’.
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

const char numbers[15] = {
	/0/	0b00111111,
	/1/	0b00000110,
	/2/	0b01011011,
	/3/	0b01001111,
	/4/	0b01100110,
	/5/	0b01101101,
	/6/	0b01111101,
	/7/	0b00000111,
	/8/	0b01111111,
	/9/	0b01101111,
	/A/	0b01110111,
	/B/	0b01111100,
	/C/	0b00111001,
	/D/	0b01011110,
	/E/	0b01111001
};

const char segments[7] = {
	0b00000001, // BOVEN
	0b00000010, // RECHTS BOVEN
	0b00000100, // ONDER
	0b00001000, // RECHTS ONDER
	0b00010000, // LINKS ONDER
	0b00100000, // LINKS BOVEN
	0b01000000  // MIDDEN
};

int current;

void display( int digit )
{
	PORTC = numbers[digit];
}

ISR( INT1_vect )
{
	if(current < (sizeof(numbers) - 1)){
		current = current + 1;
		display(current);
	}
}

ISR( INT2_vect )
{
	if(current > 0){
		current = current - 1;
		display(current);
	}
}


int main(void)
{
	current = 0;
	
	DDRD = 0x00;
	DDRC = 0xFF;
	
	EICRA |= 0x3C;
	EIMSK |= 0x06;

	sei();

	display(current);
	
	while (1)
	{
	}
}

