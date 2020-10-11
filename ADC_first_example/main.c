/*
 * adc.c
 *
 * Created: 15.11.2016 16:49:56
 * Author : GANDUD
 */ 

/*If voltage on ADC0 is higher than half of AVCC
voltage, the LED is on. */


#include <avr/io.h>

int main(void)
{	
	
	ADMUX	|=	(1<<REFS0);	//Reference voltage: AVCC
	ADCSRA	|=	(1<<ADEN);	//ADC ON
	ADMUX	|=	(1<<MUX0);	//Select channel ADC1
	ADCSRA	|=	(1<<ADPS2)	|	(1<<ADPS1)	|	(1<<ADPS0);	//ADC Prescaler: 128
	DDRD	|=	(1<<PB0);	//PB0 AS OUT

	
    while (1) 
    {
		ADCSRA	|=	(1<<ADSC);			//Begin measure
		while (ADCSRA	&	(1<<ADSC));	//Wait till end
		
		if (ADC	>	512)
		{
			PORTB	|=	(1<<PB0);
		}
		else
		{
			PORTB	&=	(1<<PB0);
		}	
	}
		
}



