/*
 * lcd.c
 *
 * Created: 8-3-2018 10:58:40
 * Author: Lois Gussenhoven
 */ 

#include "lcd.h"

void lcd_init(){
	DDRC = 0xFF;
	PORTC = 0x00;
	
	lcd_clear();
	
	lcd_command(0x02, false); //return home: cursor to or position
	lcd_command(0x28, false); //function set: data length naar 8 bit, 2 lines en 5x11 font size
	lcd_command(0x0e, false); // display ON , cursor ON, cursor blink OFF
	lcd_command(0x06, false); // Entrymode set: Direction to right, blinking display OFF
	lcd_command(0x80, false); // Set DDRAM naar 0 (begin)
}

void lcd_clear(){
	lcd_command(0x01, false); //clear display
	lcd_command(0x08, false); // Display ON, de rest OFF
}

void lcd_command ( unsigned char dat, bool isChar)
{
	char type;
	if(isChar)
		type = 0x0C; //set input for char
	else
		type = 0x08; //set input for a command
	
	PORTC = dat & 0xF0;
	PORTC = PORTC | type;
	_delay_ms(1);
	PORTC = 0x04;
	
	PORTC = (dat & 0x0F) << 4;
	PORTC = PORTC | type;
	_delay_ms(1);
	PORTC = 0x00;
}

void lcd_display_text(char *str){
	for (int i=0; i < strlen(str); i++)
	lcd_command( str[i], true );
}

void lcd_set_cursor(int position, int line){
	if(line == 2)
	lcd_command(0xC0, false);
	else
	lcd_command(0x80, false);
	
	for(int i=0; i < position; i++)
	lcd_command(0x14, false);
	
}