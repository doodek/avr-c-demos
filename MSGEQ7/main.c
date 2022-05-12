/*
 * MSGEQ7.c
 *
 * Created: 16/01/2018 19:06:21
 * Author : TheeD
 * 
 * Attempts to receive data from MSGEQ7 IC and pass them to
  UART. Never tested  due to damaged IC.  If you find it
  useful or working please let me know.
 */ 


/*

MSGEQ7 

	63Hz, 160Hz, 400Hz, 1kHz, 2.5kHz, 6.25kHz, 16kHz,
RST


*/


#define	MSGEQ7_RST		PB1
#define	MSGEQ7_STROBE	PB0

#define LEDR			PB2

#include <avr/io.h>
#include <util/delay.h>


unsigned int strobeMemory[7];
unsigned char red;
unsigned char green;
unsigned char blue;
unsigned char whiteC;
unsigned int whiteI;


int main(void)
{
	DDRB |= (1<<MSGEQ7_STROBE);
	DDRB |= (1<<MSGEQ7_RST);
	DDRB |= (1<<LEDR);
	DDRD |= (1<<PD1);
	
	PORTB |= (1<<MSGEQ7_STROBE);

	TCCR1A |= (1<<COM1B1);
	TCCR1A |= (1<<WGM11);
	
	TCCR1B |= (1<<WGM12) | (1<<WGM13);
	
	TCCR1B |= (1<<CS10);
	
	ICR1L = 0xff;
	
	ADMUX |= (1<<REFS0);
	ADMUX |= (1<<MUX1);
	ADMUX |= (1<<ADLAR);
	
	ADCSRA |= (1<<ADPS1);
	
	ADCSRA |= (1<<ADEN);
	
	
	UCSR0A |= (1<<U2X0);
	UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);

	
	UBRR0L = 103;
	
	UCSR0B |= (1<<TXEN0);
	
    while (1) 
    {
		
		
		PORTB |= (1<<MSGEQ7_RST);							//RESET STROBE.
		PORTB &= ~(1<<MSGEQ7_RST);
		
		
		_delay_us(80);
		
		for(unsigned char i = 0; i < 7; i++)		//7 TIMES 
		{
			
	
			PORTB &= ~(1<<MSGEQ7_STROBE);
			_delay_us(30);
			
			ADCSRA |= (1<<ADSC);
			while(ADCSRA & (1<<ADSC));
			
			strobeMemory[i] = ADCH;
			whiteI += strobeMemory[i];
		
			
					
				PORTB |= (1<<MSGEQ7_STROBE);
				_delay_us(40);
		}
		
			while(!(UCSR0A & (1<<UDRE0)));
			UDR0 = 0x0d;
			while(!(UCSR0A & (1<<UDRE0)));
			UDR0 = 0x0a;

		
		
		for(unsigned char i1 = 0; i1 < 7; i1++)
		{
			
			while(!(UCSR0A & (1<<UDRE0)));
			UDR0 = strobeMemory[i1];

		}
		
		
		whiteI /= 7;
		whiteC = whiteI;													//	AVERAGE
	
		
		red		=	(strobeMemory[4] + strobeMemory[5] + strobeMemory[6]);	//	HIGH
		green	=	(strobeMemory[2] + strobeMemory[3] + strobeMemory[4]);	//	MID
		blue	=	(strobeMemory[0] + strobeMemory[1] + strobeMemory[2]);	//	BASS
		
		
		
		OCR1B = strobeMemory[5];
		
		
	//	_delay_ms(1000);
		
    }
	
}

