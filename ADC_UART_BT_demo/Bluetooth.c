/*
 * Bluetooth.c
 *
 * Created: 2016-12-01 17:13:11
 *  Author: goto
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>		//yee	
#include <util/delay.h>

#define MAX 2200UL
#define MIN 800UL


ISR(USART_RXC_vect)
{
	//funkcja przerwania wykonywana przy otrzymaniu jednego bajtu
	
	static unsigned char numerBajtu = 0;
	static unsigned char pierwszyBajt;
	
	if(numerBajtu == 0){
		numerBajtu++;
		pierwszyBajt = UDR;
	}
	else
	{
		numerBajtu = 0;	
		OCR1B	=	 ( 256 * UDR + pierwszyBajt ) * (MAX - MIN) / 1024 + MIN;
		PORTB	^=	(1<<PB0);	/
	}
}

ISR(ADC_vect)
{
	unsigned int pomiar;
	ADMUX	^=	(1<<MUX0);	//zmie� kana�
	pomiar	=	ADC;
	while(!(UCSRA & (1<<UDRE)));
	UDR	=	pomiar;	
	while(!(UCSRA & (1<<UDRE)));
	UDR = pomiar >> 8;
}


int main(void)
{
	DDRB	|=	(1<<PB0);	
	PORTB	|=	(1<<PB0);
	
	//ustawienia do komunikacji z modu�em Bluetooth HC-05
	UCSRC	|=	(1<<URSEL)	|	(1<<UCSZ0)	|	(1<<UCSZ1); //
	UCSRA	|=	(1<<U2X);	//ustaw baudrate na 9600 bit�w na sekund�
	UBRRL	=	12;		
	UCSRB	|=	(1<<RXEN)	|	(1<<TXEN);	//w��cz odbiornik i nadajnik
	UCSRB	|=	(1<<RXCIE);	//w��cz przewani odbioru danych
	DDRD	|=	(1<<PD1);	//ustaw pin nadaj�cy (TXD) na wyj�cie
	
	
	//SERVO
	
	DDRB	|=	(1<<PB2);	//Ustaw pin OC1A na wyjscie	
	TCCR1A	|=	(1<<WGM11);	//W��cz tryb Fast PWM
	TCCR1B	|=	(1<<WGM12)	|	(1<<WGM13);  //W��cz tryb Fast PWM
	TCCR1A	|=	(1<<COM1B1);	//Ustaw non-inverting mode
	TCCR1B	|=	(1<<CS10); //Ustaw prescaler na 1.
	ICR1	=	19999;
	OCR1B	=	1500;
	
	
	//ADCOSU
	
	ADMUX	|=	(1<<REFS0);		//wybierz �r�d�o napi�cia odniesienia
	ADMUX	|=	(1<<MUX0)	|	(1<<MUX1);	//wybierz pin pomiarowy ADC3
	ADCSRA	|=	(1<<ADEN);	//w��cz ADC bitem ADEN
	ADCSRA	|=	(1<<ADPS0)	|	(1<<ADPS1)	|	(1<<ADPS2);
	ADCSRA	|=	(1<<ADIE);	//w��cz przerwania ADC
	

	
	sei();
	
    while(1)
    {
		

		ADCSRA	|= (1<<ADSC);	
		_delay_ms(100);
   
    }
}