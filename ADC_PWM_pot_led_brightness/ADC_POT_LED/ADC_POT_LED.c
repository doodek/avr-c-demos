/*
 * ADC_POT_LED.c
 *
 * Created: 23.01.2017 18:47:59
 *  Author: github.com/doodek
 */ 


#include <avr/io.h>  
#include <math.h>
#include <util/delay.h>

#define ADCIN PC5   //def ADCIN as ADC input
#define LED PB3  	//LED (OC2) pin

int main(void)
{
	//ADC config	
	ADCSRA	|= (1<<ADEN)   	//Enable ADC
			|(1<<ADPS2)
			|(1<<ADPS1)
			|(1<<ADPS0);     //Set prescaler  128,  (2^8/2) (111 = 8)	/2 
			
	
	ADMUX	|= (1<<MUX2)
			| (1<<MUX0);    //MUX = 0101 (5) = ADC 5 PIN SELECTED
			
	DDRB |= (1<<LED);  		//LED pin OUT
	DDRC &= ~(1<<ADCIN); 	//Potentiometer pin IN

	//Timer config	
	TCCR2 |= (1<<CS21);  //Prescaler 8
	TIMSK |= (1<<TOIE2); //Enable timer overflow interrupt

    while(1)
    {
        ADCSRA |= (1<<ADSC); 		//Uruchom pomiar		
		while(ADCSRA & (1<<ADSC)); 	//Czekaj na zak. pomiaru
		OCR2 = (floor) ADC / 4;  	//can't remember this, maybe floor(ADC/4)
									//still should be int tho
		_delay_ms(1);
    }
}