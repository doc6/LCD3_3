/*
 * Program: my_LCD3_3_TEST.c
 * Author:  D. O. Corlett
 *
 * This program is used to test an LCD.
 * It displays various text strings to
 * the LCD to test the my_lcd library.
 *
 */


#include <util/delay.h>
#include "my_lcd.h"
#include <stdio.h>

int main(void)
{
	my_lcd_process_delayTime(50, 2000); 		// Sets delay times for LCD to process instructions.
	my_lcd_init(4, 0);							// Initialise LCD, argument: 8 for 8 bit mode, 4 for 4 bit mode.


	char con[33];

	while (1)
    {

		// Demonstrate concatenation of character string with number:
		for(int num=0; num <=3 ; num++)
		{
			snprintf(con, 33, "%s%c%i", "COUNT:", '\n', num);		// Create a concatenated string with text string and number.
			my_lcd_display(con);								// Display concatenated string on LCD.
			_delay_ms(500);										// wait for 0.1 seconds to display the number.
		}

		// Demonstrate long string followed by short string:
		my_lcd_display("Longer String.");													// Display concatenated string on LCD.
		_delay_ms(2000);																	// wait for 2 second to display text
		my_lcd_display("Short string.");													// Display concatenated string on LCD.
		_delay_ms(2000);																	// wait for 2 second to display text

		// Demonstrate auto wrap:
		my_lcd_display("Automatic wrap is off.");											// Display concatenated string on LCD without auto wrap.
		_delay_ms(2000);																	// wait for 2 second to display text
		my_lcd_display_AutoWrap(sizeof("Automatic wrap is on."), "Automatic wrap is on.");		// Display concatenated string on LCD with auto wrap.
		_delay_ms(2000);																	// wait for 2 seconds to display text

    }

    return 0;
}
