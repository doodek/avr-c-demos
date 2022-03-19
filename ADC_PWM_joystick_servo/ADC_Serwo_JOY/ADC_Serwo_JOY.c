/*
 * Analog to Digital Converter
 *
 * Created: 15.11.2016 16:49:56
 * Author : doodek
 */ 

/*
	This program takes two ADC inputs from a joystick,
	and changes position of two servos according to the
	change of value of joystick axes.
	
	If the servos are connected, something like a
	two-axis pan tilt an be created, steered with
	a joystick.
	
	Set F_CPU in global symbols as 1000000
	Use clk 1MHz or change timer register values
		to appropriate
*/


#include <avr/io.h>
#include <util/delay.h>

#define	SERVO_MIN	600UL
#define	SERVO_MAX	2500UL
#define SERVO_INIT	1500UL

/* IMPORTANT
	JOYSTICK INPUT A: ADC1 PIN
	SERVO OUTPUT A: OC1A PIN (PB1)
	JOYSTICK INPUT B: ADC0 PIN 
	SERVO OUTPUT B: OC1B PIN (PB2)
	
	BE CAREFUL WITH DDRx/PORTx OF THESE
*/

int main(void)
{	
	
	signed int step;
	
	ADMUX	|=	(1<<REFS0);	//Reference voltage: AVCC
	ADCSRA	|=	(1<<ADEN);	//Enable ADC
	ADCSRA	|=	(1<<ADPS2)	|	(1<<ADPS1)	|	(1<<ADPS0);	//Prescaler 128
	
	
	//Fast PWM
	TCCR1B	|=	(1<<WGM13)	|	(1<<WGM12);
	TCCR1A	|=	(1<<WGM11);						//ustaw tryb Fast PWM 
	
	//PWM period value 19 999 us = 20ms
	
	ICR1	= 19999;
	TCCR1A	|=	(1<<COM1A1) |	(1<<COM1B1);	//Output mode: non-inverting mode
	DDRB	|=	(1<<PB1)	|	(1<<PB2);		//Set pins as output
	TCCR1B	|=	(1<<CS10);						//Prescaler 1 (enable timer clock)
	
	OCR1A =	SERVO_INIT;							//Set servo position to default val.
	
    while (1) 
    {
		
		
		ADMUX	|=	(1<<MUX0);			//Chose ADC1 as ADC input channel
		ADCSRA	|=	(1<<ADSC);			//Start a conversion	
		while (ADCSRA	&	(1<<ADSC));	//Wait until the end of the conversion
	
		step = (ADC - 512) / 10;		//The joystick should be near 512 if not moved. 
										//Step is given by difference between ADC val (0 to 1024) and 512
		if((OCR1A >= SERVO_MIN) && (OCR1A <= SERVO_MAX))
		{
			OCR1A =	OCR1A +	step;			//duty cycle is changed by step (remember, step may be negative)
		}
		
		
	
		ADMUX	&=~	(1<<MUX0);	//Disable ADC1 => choose ADC0
		ADCSRA	|=	(1<<ADSC);	//Start a conversion
		while (ADCSRA	&	(1<<ADSC));	//Wait till the end of the conversion
		
		//Calculate val of OCR1B, duty cycle, in different method than for OCR1A (this one is more fancy)
		OCR1B	=	SERVO_MIN + ((SERVO_MAX - SERVO_MIN) * ADC) / 1024UL;	

		//Wait 1000ms
		_delay_ms(1000);
			
	}
		
}

