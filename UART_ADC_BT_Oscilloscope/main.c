/*
 * Bluetooth0.c
 *
 * Created: 02/10/2017 19:54:56
 * Author : doodek/theed
 */ 

#define F_CPU 20000000UL //this is too high but works
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

#define C_sendADCH_once 0x01
#define C_ADC_SETDELAY	0x02

unsigned char commandMode = 1;
unsigned char command = 0;
unsigned int  delayCycles = 255;
unsigned char delayCyclesL = 255;
unsigned char delayCyclesH = 0;
unsigned char amountH = 0;
unsigned char amountL = 0;

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void uart_at(char string[])
{
	
	UCSRB	&=	~(1<<TXEN);		
	UCSRB	&=	~(1<<RXEN);		
	unsigned char ubrrl = UBRRL;
	//unsigned char ubrrh = UBRRH;
	
	//UBRRH = 0;
	UBRRL = 32;
	
	UCSRB	|=	(1<<TXEN)	|	(1<<RXEN);		
	for(unsigned char i = 0; i < strlen(string); i++)
	{
		
		while(!(UCSRA & (1<<UDRE)));
		UDR = string[i];
		
	}
	
		UCSRB	&=	~(1<<TXEN);
		UCSRB	&=	~(1<<RXEN);
	
	 UBRRL = ubrrl;
	// UBRRH = ubrrh;
	UCSRB	|=	(1<<TXEN)	|	(1<<RXEN);		
}

int main(void)
{
    /* 
	HC_05 SETTINGS
	PIN- 1234
	*/

	DDRD	|=	(1<<PD1);									//Set TXD pin as an output.
	UBRRL	=	0b00010101;					//9600BAUD.
	//UBRRH	=   0b00000001;
	UCSRC	|=	(1<<URSEL)	|	(1<<UCSZ1)	|	(1<<UCSZ0); //Word = 8b
	UCSRA	|=	(1<<U2X);									//2X speed
	UCSRB	|=	(1<<TXEN)	|	(1<<RXEN);					//Enable recieving
	UCSRB	|=	(1<<RXCIE);									//Enable RXC Interrupt 
	

	ADMUX	|=	(1<<REFS0)	|	(1<<ADLAR);
	ADCSRA	|=	(1<<ADFR)	|	(1<<ADPS1);
	ADCSRA	|=	(1<<ADEN);
	ADCSRA	|=	(1<<ADSC);


	sei();													//Enable global interrupts

	//run only first use
	//_delay_ms(1000);
	//uart_at("AT+NAME=BTSCOPE");

		while(1)		
		{
			//debug
			//while(!(UCSRA & (1<<UDRE)));					//Wait until data register is empty
			//UDR = 0x55;										//Send decoy
		}
}

ISR(USART_RXC_vect)
{
	command = UDR;

	switch(command)
	{
		case C_sendADCH_once:
			while(!(UCSRA & (1<<UDRE)));					//Wait until data register is empty
			UDR = ADCH;										//Send ACK
			break;
		case C_ADC_SETDELAY:
			while(!(UCSRA & (1<<RXC)));
			delayCyclesL = UDR;
			while(!(UCSRA & (1<<RXC)));
			amountH = UDR;
			while(!(UCSRA & (1<<RXC)));
			amountL = UDR;

			delayCycles = (delayCyclesH << 8) | delayCyclesL;

			int amount = (amountH << 8) | amountL;
			unsigned char adcram[500];

			//measure
			for(int i = 0; i <= amount; i++)
			{
				_delay_loop_1(delayCyclesL);
				adcram[i] = ADCH;
			}

			//send
			for(int i = 0; i <= amount; i++)
			{
					while(!(UCSRA & (1<<UDRE)));					//Wait until data register is empty
					UDR = adcram[i];//adcram[i];
			}
			break;
		default:
		break;
	}
}
