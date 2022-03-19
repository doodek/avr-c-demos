/*
 * Analog to Digital Converter.c
 *
 * Created: 15.11.2016 16:49:56
 * Author : GANDUD
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define		SERVO_MIN	600UL
#define		SERVO_MAX	2500UL

int main(void)
{	//niohohohohohoho
	
	
	signed	int	krok;
	
	ADMUX	|=	(1<<REFS0);	//wybierz napiêcie odniesienia z pinu avcc
	ADCSRA	|=	(1<<ADEN);	//w³¹cz modu³ adc
	ADCSRA	|=	(1<<ADPS2)	|	(1<<ADPS1)	|	(1<<ADPS0);	//ustaw prescaler 128
	
	//LEDY
	DDRB	|=	(1<<PB7) | (1<<PB0);
	
//CZWARTEK SUCKS
	
	TCCR1B	|=	(1<<WGM13)	|	(1<<WGM12);
	TCCR1A	|=	(1<<WGM11);						//ustaw tryb Fast PWM 
	ICR1	= 19999;
	TCCR1A	|=	(1<<COM1A1) |	(1<<COM1B1); //non inverting mode
	DDRB	|=	(1<<PB1)	|	(1<<PB2);
	TCCR1B	|=	(1<<CS10);
	
	//CZWARTEK SUCKS AGAIN
	
	OCR1A	=	1500;
	
    while (1) 
    {
		
		
		ADMUX	|=	(1<<MUX0);	//wybierz kana³ pomiarowy adc1
		ADCSRA	|=	(1<<ADSC);	//Wystartuj pomiar	
		while (ADCSRA	&	(1<<ADSC));	//poczekaj na zakoñcznie pomiaru
		//OCR1A	=	SERVO_MIN + ((SERVO_MAX - SERVO_MIN) * ADC) / 1024UL;
		
		
		krok	=	(ADC	-	512)	/ 10;
		
		OCR1A	=	OCR1A	+	krok;
		
		
		if (OCR1A < SERVO_MIN)
		{
			OCR1A	=	SERVO_MIN;			
		}
		
		if (OCR1A > SERVO_MAX)
		{
			OCR1A	=	SERVO_MAX;			
		}
		//goatu
		
		
		//bekspejs
		
		
		ADMUX	&=~	(1<<MUX0);	//wybierz kana³ pomiarowy adc0
		ADCSRA	|=	(1<<ADSC);	//Wystartuj pomiar
		while (ADCSRA	&	(1<<ADSC));	//poczekaj na zakoñcznie pomiaru
		OCR1B	=	SERVO_MIN + ((SERVO_MAX - SERVO_MIN) * ADC) / 1024UL;	

		_delay_ms(1000);
			
	}
		
}

