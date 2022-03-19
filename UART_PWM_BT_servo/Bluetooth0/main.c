/*
 * Bluetooth0.c
 *
 * Created: 02/10/2017 19:54:56
 * Author : github.com/doodek
 * 
 * MIT App Inventor 2 Bluetooth app driven servo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define C_LED0_ON			0x01
#define C_LED0_OFF			0x02
#define C_LED0_CHANGE		0x03
#define C_SERVO0_SETPOS		0x10
#define C_SERVO1_SETPOS		0x11
#define SERVO_MAX			2250
#define SERVO_MIN			750

unsigned char commandMode = 1;
unsigned char command = 0;
unsigned int servo0_pos = 0;
unsigned int servo1_pos = 0;

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main(void)
{
    /* 
	HC_05 SETTINGS
	PIN- 1234
	*/
	
	DDRD	|=	(1<<PD1);									//Set TXD pin as an output.
	DDRB	|=	(1<<PB1)	|	(1<<PB2);					//SERVO
	UCSRC	|=	(1<<URSEL)	|	(1<<UCSZ1)	|	(1<<UCSZ0); //Word = 8b
	
	UCSRA	|=	(1<<U2X);	//2X speed
	UBRRL	=	103; 		//9600BAUD.
	
	UCSRB	|=	(1<<TXEN)	|	(1<<RXEN); 	//Enable UART 
	UCSRB	|=	(1<<RXCIE);					//...with interrupts
	
	sei();
	
	
	//SERVO - timer conf. See other files for description
	TCCR1A	|=	(1<<COM1A1)	|	(1<<COM1B1)	|	(1<<WGM11);
	TCCR1B	|=	(1<<WGM12)	|	(1<<WGM13);
	TCCR1B	|=	(1<<CS11);
	ICR1	=	19999;
	OCR1A	=	1150;
	OCR1B	=	1150;
	while(1)		
	{
		//EMPTY! Everything is done in the INTERRUPTS
	}
}

//USART RECEIVED INTERRUPT
ISR(USART_RXC_vect)
{
	unsigned char data = UDR;
	if(commandMode == 1)
	{
		switch(data)
		{
			
			case C_LED0_ON:
				PORTB	|=	(1<<PB0);
			break;
			
			case C_LED0_OFF:
				PORTB	&=	~(1<<PB0);	
			break;
			
			case C_LED0_CHANGE:
				PORTB	^=	(1<<PB0);
			break;
			
			case C_SERVO0_SETPOS:
				command		= C_SERVO0_SETPOS;
				commandMode = 0;
			break;
			
			case C_SERVO1_SETPOS:
				command		= C_SERVO1_SETPOS;
				commandMode = 0;
			break;
			default:
			break;
		}
	}
		
	else
	{	
		switch(command)
		{
			case C_SERVO0_SETPOS:
				servo0_pos = map(data, 0, 255, SERVO_MIN, SERVO_MAX);
				OCR1A = servo0_pos;
				commandMode = 1;
			break;
			
			case C_SERVO1_SETPOS:
				servo1_pos = map(data, 0, 255, SERVO_MIN, SERVO_MAX);
				OCR1B = servo1_pos;
				commandMode = 1;
				PORTB |= (1<<PB0);
			break;	
		}
	}
}