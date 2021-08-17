/**
	@author Thomas Grunenberg
	@author TODO
	@version 0.1
	@file init.c
	@brief Init fuunction for the I/O
*/


/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include "init.h"
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Init the PORTx and DDRx register for the I/O setup
*/
void init(void){
	
	// Digital input
	DDRB &= ~(1 << DDB2);		// PB0 as Input
	DDRB &= ~(1 << DDB3);		// PB1 as Input
	PORTB |= ( 1 << PB0);		// Pullup PB0
	PORTB |= ( 1 << PB1);		// Pullup PB1

	// ADC
	DDRC &= ~(1 << DDC0);		// PC0 as Input (ADC0)
	PORTC &= ~( 1 << PC0);		// Pullup PC0 off

	ADMUX = (1 << REFS0); // AVCC as reference
	ADCSRA = (1 << ADPS2)|(1 << ADPS1); // ADC Prescale by 64
	ADCSRA |= (1 << ADSC)|(1 << ADATE)|(1 << ADEN); // Start conversion
												//Free running, Enalbe ADC


}
/******************************************************************************/
