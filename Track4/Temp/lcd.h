/*
 * lcd.h
 *
 * Created: 29-3-2018 11:36:52
 *  Author: Lois Gussenhoven
 */ 


#ifndef LCD_H_
#define LCD_H_

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

void lcd_init(void);
void lcd_display_text(char*);
void lcd_set_cursor(int, int);
void lcd_clear(void);


#endif /* LCD_H_ */