/*
 * Track3.c
 *
 * Created: 8-3-2018 10:52:10
 * Author : Lois Gussenhoven
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#include <stdio.h>
#include <stdlib.h>

#include "lcd.h"


int main(void)
{
     lcd_init();
     
     lcd_set_cursor(0, 1);
     lcd_display_text("Lois Gussenhoven");
	 
	 lcd_set_cursor(0,2);
	 lcd_display_text("Gussenhoven Lois");
}

