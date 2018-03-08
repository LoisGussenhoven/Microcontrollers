/*
 * lcd.h
 *
 * Created: 8-3-2018 14:38:23
 *  Author: Lois Gussenhoven
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000

#define LCD_E 	3
#define LCD_RS	2

typedef int bool;
#define true 1
#define false 0

#include <avr/io.h>
#include <util/delay.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lcd_init();
void lcd_clear();
void lcd_command ( unsigned char, bool);
void lcd_display_text(char *);
void lcd_set_cursor(int, int);

#endif /* LCD_H_ */