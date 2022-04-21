/*
 * ADC_SERVO.c
 *
 * Created: 16/09/2017 15:57:34
 * Author : TheeD
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>

int adc_result;

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


int main(void)
{   
    DDRB |= (1<<PB1);  

    //ADC config. See other files for desc
    ADMUX |= (1<<REFS0);
    ADMUX |= (1<<MUX0);  
    ADCSRA |= (1<<ADPS1) | (1<<ADPS0);
    ADCSRA |= (1<<ADEN);

    //Timer config. See other files for desc
    TCCR1A |= (1<<COM1A1);
    TCCR1A |= (1<<WGM11);   
    TCCR1B |= (1<<WGM12) | (1<<WGM13); 
    TCCR1B |= (1<<CS10);

    ICR1 = 20000;
   
    while (1) 
    {

        ADCSRA |= (1<<ADSC);	
        while(ADCSRA & (1<<ADSC)); 
        adc_result = ADC;

        OCR1A = map(adc_result, 0, 1023, 500, 2500);
    }
}

