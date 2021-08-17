 /**
	@author Thomas Grunenberg and Anmol Singh.
	@author TODO
	@version 0.1
	@file one.c
	@brief Seven segment display
*/

#define F_CPU 8000000UL

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
/**
	@brief Init input and output
*/
void init(void)
{	
	// Input

	/* All LED's of the display(a,b,c,d,e,f,g) are connected in series with resistors via output 
	channels in order to prevent damaging of LED's due to high current. */
	
	DDRC &= ~(1 << DDC2);   // Key1 to PC2.
	DDRC &= ~(1 << DDC3);	// Key2 to PC3.
	PORTC |= (1 << PC2);	// Pullup for PC2.
	PORTC |= (1 << PC3);	// Pullup for PC3.
	
	// Output
	DDRB |= (1 << DDB0);	// PB0 to Pin 5(LED: D , Display: 2).
	DDRB |= (1 << DDB1);	// PB1 to Pin 4(LED: E , Display: 2).
	DDRB |= (1 << DDB2);	// PB2 to Pin 2(LED: F , Display: 2).
	DDRB |= (1 << DDB3);	// PB3 to Pin 1(LED: G , Display: 2).
	DDRB |= (1 << DDB4);	// PB4 to Pin 5(LED: D , Display: 1).
	DDRB |= (1 << DDB5);	// PB5 to Pin 4(LED: E , Display: 1).
	
	DDRC |= (1 << DDC0);	// PC0 to Pin 2(LED: F , Display: 1).
	DDRC |= (1 << DDC1);	// PC1 to Pin 1(LED: G , Display: 1).

	DDRD |= (1 << DDD2);	// PD2 to Pin 7(LED: C , Display: 2).
	DDRD |= (1 << DDD3);	// PD3 to Pin 9(LED: B , Display: 2).
	DDRD |= (1 << DDD4);	// PD4 to Pin 10(LED: A , Display: 2).
	DDRD |= (1 << DDD5);	// PD5 to Pin 7(LED: C , Display: 1).
	DDRD |= (1 << DDD6);	// PD6 to Pin 9(LED: B , Display: 1).
	DDRD |= (1 << DDD7);	// PD7 to Pin 10(LED: A , Display: 1).

}
/******************************************************************************/

void sevensegment10(int8_t value)
{
	static int8_t last = 100;
	
	// stop here if no change
	if (value == last)
		return;
	
	last = value;


	// Disable all LEDs (Device: SC39)
	PORTB &= ~(1 << PB4);
	PORTB &= ~(1 << PB5);
	PORTC &= ~(1 << PC0);
	PORTC &= ~(1 << PC1);		
	PORTD &= ~(1 << PD5);		
	PORTD &= ~(1 << PD6);
	PORTD &= ~(1 << PD7);

		
	// Enable LEDs for value
	switch(value)
	{
		case(0):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTB |= (1 << PB5); // E
			PORTC |= (1 << PC0); // F
			//PORTC |= (1 << PC1); // G
		break;
		case(1):
			//PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			//PORTB |= (1 << PB4); // D
			//PORTB |= (1 << PB5); // E
			//PORTC |= (1 << PC0); // F
			//PORTC |= (1 << PC1); // G
		break;
		case(2):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			//PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTB |= (1 << PB5); // E
			//PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
		break;
		case(3):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			//PORTB |= (1 << PB5); // E
			//PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
		break;
		case(4):
			//PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			//PORTB |= (1 << PB4); // D
			//PORTB |= (1 << PB5); // E
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
		break;
		case(5):
			PORTD |= (1 << PD7); // A
			//PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			//PORTB |= (1 << PB5); // E
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
		break;
		case(6):
			PORTD |= (1 << PD7); // A
			//PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTB |= (1 << PB5); // E
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
		break;
		case(7):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			//PORTB |= (1 << PB4); // D
			//PORTB |= (1 << PB5); // E
			//PORTC |= (1 << PC0); // F
			//PORTC |= (1 << PC1); // G
		break;
		case(8):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTB |= (1 << PB5); // E
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
		break;
		case(9):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			//PORTB |= (1 << PB5); // E
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
		break;
		default:
			//PORTD |= (1 << PD7); // A
			//PORTD |= (1 << PD6); // B
			//PORTD |= (1 << PD5); // C
			//PORTB |= (1 << PB4); // D
			//PORTB |= (1 << PB5); // E
			//PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
		break;	
	}
}
	
void sevensegment1(int8_t value)
{
	static int8_t last = 100;
	
	// stop here if no change
	if (value == last)
		return;
	
	last = value;


	// Disable all LEDs (Device: SC39)
	PORTB &= ~(1 << PB0);
	PORTB &= ~(1 << PB1);
	PORTB &= ~(1 << PB2);
	PORTB &= ~(1 << PB3);		
	PORTD &= ~(1 << PD2);		
	PORTD &= ~(1 << PD3);
	PORTD &= ~(1 << PD4);

		
	// Enable LEDs for value
	switch(value)
	{
	
		case(0):
			PORTD |=  (1 << PD4); // A
			PORTD |=  (1 << PD3); // B
			PORTD |=  (1 << PD2); // C
			PORTB |=  (1 << PB0); // D
			PORTB |=  (1 << PB1); // E
			PORTB |=  (1 << PB2); // F
			//PORTB |=  (1 << PB3); // G
		break;
		case(1):
			//PORTD |=  (1 << PD4); // A
			PORTD |=  (1 << PD3); // B
			PORTD |=  (1 << PD2); // C
			//PORTB |=  (1 << PB0); // D
			//PORTB |=  (1 << PB1); // E
			//PORTB |=  (1 << PB2); // F
			//PORTB |=  (1 << PB3); // G
		break;
		case(2):
			PORTD |=  (1 << PD4); // A
			PORTD |=  (1 << PD3); // B
			//PORTD |=  (1 << PD2); // C
			PORTB |=  (1 << PB0); // D
			PORTB |=  (1 << PB1); // E
			//PORTB |=  (1 << PB2); // F
			PORTB |=  (1 << PB3); // G
		break;
		case(3):
			PORTD |=  (1 << PD4); // A
			PORTD |=  (1 << PD3); // B
			PORTD |=  (1 << PD2); // C
			PORTB |=  (1 << PB0); // D
			//PORTB |=  (1 << PB1); // E
			//PORTB |=  (1 << PB2); // F
			PORTB |=  (1 << PB3); // G
		break;
		case(4):
			//PORTD |=  (1 << PD4); // A
			PORTD |=  (1 << PD3); // B
			PORTD |=  (1 << PD2); // C
			//PORTB |=  (1 << PB0); // D
			//PORTB |=  (1 << PB1); // E
			PORTB |=  (1 << PB2); // F
			PORTB |=  (1 << PB3); // G
		break;
		case(5):
			PORTD |=  (1 << PD4); // A
			//PORTD |=  (1 << PD3); // B
			PORTD |=  (1 << PD2); // C
			PORTB |=  (1 << PB0); // D
			//PORTB |=  (1 << PB1); // E
			PORTB |=  (1 << PB2); // F
			PORTB |=  (1 << PB3); // G
		break;
		case(6):
			PORTD |=  (1 << PD4); // A
			//PORTD |=  (1 << PD3); // B
			PORTD |=  (1 << PD2); // C
			PORTB |=  (1 << PB0); // D
			PORTB |=  (1 << PB1); // E
			PORTB |=  (1 << PB2); // F
			PORTB |=  (1 << PB3); // G
		break;
		case(7):
			PORTD |=  (1 << PD4); // A
			PORTD |=  (1 << PD3); // B
			PORTD |=  (1 << PD2); // C
			//PORTB |=  (1 << PB0); // D
			//PORTB |=  (1 << PB1); // E
			//PORTB |=  (1 << PB2); // F
			//PORTB |=  (1 << PB3); // G
		break;
		case(8):
			PORTD |=  (1 << PD4); // A
			PORTD |=  (1 << PD3); // B
			PORTD |=  (1 << PD2); // C
			PORTB |=  (1 << PB0); // D
			PORTB |=  (1 << PB1); // E
			PORTB |=  (1 << PB2); // F
			PORTB |=  (1 << PB3); // G
		break;
		case(9):
			PORTD |=  (1 << PD4); // A
			PORTD |=  (1 << PD3); // B
			PORTD |=  (1 << PD2); // C
			PORTB |=  (1 << PB0); // D
			//PORTB |=  (1 << PB1); // E
			PORTB |=  (1 << PB2); // F
			PORTB |=  (1 << PB3); // G
		break;
		default:
			//PORTD |=  (1 << PD4); // A
			//PORTD |=  (1 << PD3); // B
			//PORTD |=  (1 << PD2); // C
			//PORTB |=  (1 << PB0); // D
			//PORTB |=  (1 << PB1); // E
			//PORTB |=  (1 << PB2); // F
			PORTB |=  (1 << PB3); // G
		break;
	
	}
}
/******************************************************************************/



/******************************************************************************/

void sevensegment(int8_t value)
{
	int decimalpos = value%10;
	int tenspos = value/10;
	sevensegment1(decimalpos);
	sevensegment10(tenspos);	
}
/******************************************************************************/


/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void)
{
	int8_t value = 0;
	init(); 	// Function to initialise I/Os
	
	
	// Loop forever
	while (1)
	{
		if(~PINC & (1 << PC2))
		{
		if((~PINC & (1 << PC2)) && (~PINC & (1 << PC3)))
		{
			value = 0;
			sevensegment(value);
			_delay_ms(75);
			while((~PINC & (1 << PC2)) && (~PINC & (1 << PC3)))
			{
				_delay_ms(75);
			}
		}
		    if(value == 100)
			{
				value = 0;
			}
			sevensegment(value);
			value++;
			_delay_ms(75);
			while(~PINC & (1 << PC2))
			{
				_delay_ms(75);
			}
		}
		if(~PINC & (1 << PC3))
		{
			if((~PINC & (1 << PC2)) && (~PINC & (1 << PC3)))
		{
			value = 0;
			sevensegment(value);
			_delay_ms(75);
			while((~PINC & (1 << PC2)) && (~PINC & (1 << PC3)))
			{
				_delay_ms(75);
			}
		}
			value--;
			if(value == -1)
			{
				value = 99;
			}
			sevensegment(value);
			_delay_ms(75);
			while(~PINC & (1 << PC3))
			{
				_delay_ms(75);
			}
		}
		_delay_ms(75);
	}
	return 0;
}
/******************************************************************************/
