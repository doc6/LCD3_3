/*
 * Program: my_LCD3_3.c
 * Author:  D. O. Corlett
 *
 * Initialises, and displays text
 * for dot matrix LCD with 4 and 8
 * bit interface and text wrapping.
 * Displays example strings
 */


#include <util/delay.h>
#include "my_lcd.h"

int main(void)
{
	my_lcd_init(4);			// Initialise LCD, argument: 8 for 8 bit mode, 4 for 4 bit mode.

	char con[32];

	while (1)
    {

		// Demonstrate concatenation of character string with number:
		for(int num=0; num <=3 ; num++)
		{
			sprintf(con, "%s%c%i", "COUNT:", '\n', num);		// Create a concatenated string with text string and number.
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
