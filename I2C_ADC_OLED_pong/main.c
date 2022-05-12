/*
* SSD1306_I2C.c
*
* Created: 17/08/2017 21:50:09
* Author : TheeD
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "functions.h"
#include "bajty_znaku.h"


int krok = 1;


int main(void)
{

	SMCR |= (1<<SM0);
	DDRB |= (1<<PB0);
	DDRD |= (1<<PD6);
	
	init();
	PORTB |= (1<<PB0);


	displaySetup();
		

	//oscilloscope_singlescreen();
	
	DDRB = 0xff;
	
	TCCR1A |= (1<<COM1A1);
	TCCR1A |= (1<<WGM11);
	TCCR1B |= (1<<WGM12);
	TCCR1B |= (1<<WGM13);

	TCCR1B |= (1<<CS12);
	
	

	ICR1 = 156;

	
	OCR1A =	156/2;
	
	
	
	
	
		
	//	sei();
	for(;;)
	 {
		oscilloscope_singlescreen();
		
		
		//_delay_ms(100);
	
	 }

	
	
	
	
	
	

	
}


