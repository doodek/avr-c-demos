/*
 * functions.c
 *
 * Created: 17/08/2017 21:59:38
 *  Author: TheeD
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "bajty_znaku.h"


unsigned char column = 0;


	




void sendCommand(unsigned char quantity, unsigned char c1, unsigned char c2, unsigned char c3)
{
		
	writeStartCondition();
	
	sendSLA_W();
	
	sendControlByteCommand();
	sendByte(c1);
	
	if(quantity > 1)
	{
		sendControlByteCommand();
		sendByte(c2);
	}
	
	if(quantity > 2)
	{
		sendControlByteCommand();
		sendByte(c3);
		
	}
	
	
	writeStopCondition();
	
}


void init(void)
{
	
	
	TWBR = 0x02;  //Bitrate 240
	
	
	DDRC |= (1<<PC5) | (1<<PC4);
	DDRB |=  (1<<PB5) | (1<<PB3) | (1<<PB1);
	//PORTB |= (1<<PB0);

	
	//????UART????
	/*
	 UCSRB	|=	(1<<RXEN)	|	(1<<RXCIE)	|	(1<<TXEN);
	UCSRC |= (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);  //Packet 8b
	

	UBRRL = 207;
	
	

	*/
	
	/*
	//???? SPI ????

	// MX25L8006
	
	SPCR |= (1<<CPHA) | (1<<CPOL);	
	SPSR	|=	(1<<SPI2X);	//Prescaler 2
	SPCR |= (1<<MSTR);	//MASTER MODE
	SPCR 	|=	(1<<SPE); //SPI ENABLE


	//RDID

	
	_delay_ms(100);
	
	
	uart_sendbyte(0xff);
	
	
	
	PORTB &= ~(1<<PB0);
	SPDR = 0x9F;				//ID READ //RDID
	while(!(SPSR & (1<<SPIF)));
	char jedec = SPDR;

		
	SPDR = 0x00;
	while(!(SPSR & (1<<SPIF)));
	char manid = SPDR;
	
	
	SPDR = 0x00;
	while(!(SPSR & (1<<SPIF)));
	char devid = SPDR;

	

	PORTB |= (1<<PB0);

	_delay_ms(5000);
	
		
		uart_sendbyte(jedec);
		uart_sendbyte(manid);
		uart_sendbyte(devid);
		

				PORTB |= (1<<PB1);
		*/
	
	
	//////////////ADC
	
	
	ADCSRA |= (1<<ADPS1); //(1<<ADPS1) | (1<<ADPS2) | (1<<ADPS0);
	
	ADMUX |= (1<<REFS0);
	ADMUX |= (1<<MUX0);
	ADMUX |= (1<<ADLAR);

	ADCSRA |= (1<<ADEN);

	


	
	
	
}


void displaySetup(void)
{
	
	sendCommand(2, SET_CONTRAST_CONTROL, CONTRAST_H, 0);	
	//sendCommand(1, ENTIRE_DISPLAY_ON, 0, 0);
	sendCommand(2, SET_ADRESSING_MODE, 0, 0);
	sendCommand(1, SET_NORMAL_DISPLAY, 0, 0);
	sendCommand(1, SET_DISPLAY_ON, 0, 0);
	sendCommand(3, SET_COLUMN_ADDRESS, 0, 127);
	sendCommand(3, SET_PAGE_ADDRESS, 0, 7);
	sendCommand(3, CHARGE_PUMP_SET, CHARGE_PUMP_ON, DISPLAY_ON);	

}


void writeStartCondition(void)
{

	
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN); //WRITE START CONDITION

	
	while(!(TWCR & (1<<TWINT)));

	while(!((TWSR & 0x08) || (TWSR & 0x10)));
	
	
}

void sendSLA_W(void)
{
	
	
	TWDR = SLA_W;
	TWCR &= ~(1<<TWSTA);
	TWCR |= (1<<TWINT);
	while(!(TWCR & (1<<TWINT)));
	while(!(TWSR & 0x18));//ACK+SLAW CHECK
	
}

void sendControlByteCommand(void)
{
	
	
	

	TWDR = 0b10000000;
	TWCR |= (1<<TWINT);
	while(!(TWCR & (1<<TWINT)));
	while(!(TWSR & 0x28));//ACK+DATA CHECK
	
}

void sendByte(unsigned char data)
{
	
	
	TWDR = data;
	TWCR |= (1<<TWINT);
	while(!(TWCR & (1<<TWINT)));
	while(!(TWSR & 0x28));//ACK+DATA CHECK
	
}

void writeStopCondition(void)
{
	
	while(!(TWCR & (1<<TWINT)));
	TWCR |= (1<<TWINT) | (1<<TWEN) |(1<<TWSTO);
	//_delay_ms(20);
}

void sendControlByteData(void)
{
	
	
	

	TWDR = 0b01000000;
	TWCR |= (1<<TWINT);
	while(!(TWCR & (1<<TWINT)));
	while(!(TWSR & 0x28));//ACK+DATA CHECK
	
}

void sendDataByte(unsigned char data)
{
	
	writeStartCondition();
	sendSLA_W();
	
	sendControlByteData();
	sendByte(data);
	
	
	writeStopCondition();
	
}

void clearDisplay(void)
{
	area(0, 0, 127, 7);
	
	writeStartCondition();
	sendSLA_W();
	
	sendControlByteData();
	
	
	
	for(int i = 0; i < 1024; i++)
	{
		
		sendByte(0xff);
	}
	
}


void area(unsigned char sX, unsigned char sY, unsigned char eX, unsigned char eY)
{
		sendCommand(3, SET_PAGE_ADDRESS, sY, eY);
		sendCommand(3, SET_COLUMN_ADDRESS, sX, eX);
	
}
/*
void usart_sendstr(char arr[])
{


	for(unsigned char i = 0; i < strlen(arr); i++)
	{
		
			while(!(UCSRA & (1<<UDRE)));
			UDR = arr[i];

			
	}
	

		
	
}

void uart_sendbyte(char data)
{
	
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
	
}
*/

void oscilloscope_singlevert(unsigned char x)
{
	
	

	
		if(column == 128)
		{
			
			writeStopCondition();
			column = 0;
			clearDisplay();
		}
	
		
		
			
			
		
		
	
	unsigned char byte = (0x80>>(x % 8));
	unsigned char page = 7 - (x / 8);
	sendCommand(3, SET_PAGE_ADDRESS, page, 7);
	sendDataByte(byte);
	
	column++;
	

	
	
	
	
}

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}




unsigned char leftADC	= 28;
unsigned char rightADC	= 28;


unsigned char rightY;
unsigned char leftY;

signed char rightMovY;
signed char leftMovY;

signed int ballX = 63;
signed int ballY = 29;

signed char movX	= 1;
signed char movY	= -1;

unsigned int pointsR = 2;
unsigned int pointsL = 2;

unsigned char gddram[8][128];

unsigned char mode;
unsigned char modeR;
unsigned char modeL;

void oscilloscope_singlescreen(void)
{
	
	
		DDRD = 0x00;
		PORTD = 0xff;
		_delay_us(55);
	
	
		mode = PIND;
		
		modeL = mode >> 2;
		modeR = mode << 6;
		modeR >>= 6;
		
	
		
		ADCSRA &= ~(1<<ADEN);
		ADMUX  |= (1<<MUX0);
		ADCSRA |= (1<<ADEN);
		
		ADCSRA |= (1<<ADSC);
		while(ADCSRA & (1<<ADSC));
		
		
		leftADC = ADCH >> 2;
		
		
	
		ADCSRA &= ~(1<<ADEN);
		ADMUX &= ~(1<<MUX0);
		ADCSRA |= (1<<ADEN);
		ADCSRA |= (1<<ADSC);
		while(ADCSRA & (1<<ADSC));
		
		rightADC = ADCH >> 2;
		
		
		
			
					
		
		
		
			
			
			if(mode == 0b00000100) leftADC	= rightADC;
			if(mode == 0b00000001) rightADC	= leftADC;
			
			
			//AI
			
			if(modeR == 3) 		rightADC = ballY + 3 * movY ;
			if(modeL == 3)		leftADC = ballY + 3 *movY  ;
			
				//AI		
			
			
			
			if(rightY < rightADC && rightY < 63)
			{
				rightMovY = 1;
			
			}
			else if(rightY > rightADC && rightY > 7)
			{
				rightMovY = -1;
			}
			else
			{
				rightMovY = 0;
			}
			
			
			
			if(leftY < leftADC && leftY < 63)
			{
				leftMovY = 1;
				
			}
			else if(leftY > leftADC && leftY > 7)
			{
				leftMovY = -1;
			}
			else
			{
				leftMovY = 0;
			}
					
			
			
	

			
			rightY += rightMovY;
			leftY += leftMovY;
			
			if(modeR == 0) rightY = rightADC;
			if(modeL == 0) leftY  = leftADC;
			
			
			//AI 
			
			//rightY = ballY + 5;
			//leftY = ballY + 5;
			
			
			//AI
			
			
	
			
			
			ballX += movX;
			ballY += movY;
		
		
			if((ballX + movX >= 127 && ballY+movY > rightY - 12 && ballY+movY < rightY + 2) || (ballX+movX <= 1 && ballY+movY > leftY - 12 && ballY+movY < leftY+2))
			{
		
				
				/*
				if(ballX + movX >= 127)
				{
					movY += rightMovY;
				}
				if(ballX + movX <= 0)
				{
					movY += leftMovY;
				}
				*/
				
				ballX -= movX;
				
				movX = -movX;
				if(movX < 3 && movX > (-2))
				{
					movX = floor(1.001 * movX);
				}
				ballX += movX;
				
				
			}
			else if(ballX+movX >= 127)
			{
				
				
				gameover();
			
				
			}
			else if(ballX+movX <= 0)
			{
				
				gameover();
			
		
			}
			
			
			if(ballY + movY >= 63 || ballY + movY <= 1)
			{
				
				ballY -= movY;
				//movY = (-2) * movY;
				movY = floor((-1) * movY);
				
				ballY += movY;
				
			}
			
		
						
			gddramSinglePoint(ballX,ballY);
			gddramSinglePoint(ballX-1,ballY);
			gddramSinglePoint(ballX,ballY-1);
			gddramSinglePoint(ballX-1,ballY-1);
	
			
		
			for(unsigned char i = 0; i < 12; i++)
			{
				gddramSinglePoint(0, leftY - i);
				gddramSinglePoint(127, rightY - i);
				
			}
		
		
		
			//printRAM("LOLOLO", 1);
		
			vidOut();
			
			//clearDisplay();
			
			
		
		
			
	
}

void print(char arr[])
{
	
			
			writeStartCondition();
			sendSLA_W();
			sendControlByteData();
			
		
		for(unsigned char letter = 0; letter < strlen(arr); letter++)
		{
			
			
				
		
				if(arr[letter] == ' ')
				{
					for(unsigned char i = 0; i < 6; i++)
					{
						
						sendByte(0x00);
						
						
					}
					
					
				}
				
				
				unsigned char character = (arr[letter]) - '!';
				
				

				for(unsigned char bajt = 0; bajt < dlugosc_indeks_znaku[character][0]; bajt++)
				{
					
					unsigned char data = bajty_znaku[(dlugosc_indeks_znaku[character][1]) + bajt] ;
					sendByte(data);
					
					
				}
				
				sendByte(0x00);
		}
		
		
		writeStopCondition();
		
	}

		
	
	
void printRAM(char arr[], unsigned char page)
	{
		
	unsigned char count = 0;	
	
		
		
		for(unsigned char letter = 0; letter < strlen(arr); letter++)
		{
			
			
			
			
			
			
	
			if(arr[letter] == ' ') arr[letter] = '~';
			
			unsigned char character = (arr[letter]) - '!';
			
			

			for(unsigned char bajt = 0; bajt < dlugosc_indeks_znaku[character][0]; bajt++)
			{
				
				unsigned char data = bajty_znaku[(dlugosc_indeks_znaku[character][1]) + bajt] ;
				gddram[page][count] = data;
				
				count++;
				
			}
			
			gddram[page][count] = 0x00;
			count++;						//LetterSpacing
			
			
		}
		
		count = 0;
		
		
	}

	/*

void printRAMpointers(char * napis, unsigned char page)
{
	unsigned char count = 0;
	
	
	
	for(unsigned int letter = 0; letter < strlen(napis); letter++)
	{
		
		
		
		
			
		if(napis[letter] == ' ') napis[letter] = '~';
		
		unsigned char character = ((napis[letter])) - '!';
		
		

		for(unsigned char bajt = 0; bajt < dlugosc_indeks_znaku[character][0]; bajt++)
		{
			
			unsigned char data = bajty_znaku[(dlugosc_indeks_znaku[character][1]) + bajt] ;
			gddram[page][count] = data;
			
			count++;
			
		}
		
		gddram[page][count] = 0x00;
		count++;						//LetterSpacing
		
		
	}
	
	count = 0;
	
	
	
	
	
}

*/
	
	
void gddramSinglePoint(unsigned char x, unsigned char y)
{
	unsigned char page = 0;
	
	page = (7-(y/8));
	unsigned char byte;// = gddram[page][x];
	
	byte = (0x80 >> (y % 8));
	
	
	gddram[page][127-x] |= byte;
	
}


void vidOut(void)
{
				writeStartCondition();
				sendSLA_W();
				sendControlByteData();
				
				
				
				
				
				
				
				
				for(unsigned char iPage = 0; iPage < 8; iPage++)
				{
					
					for(unsigned char iCol = 0; iCol < 128; iCol++)
					{
						
						
						//sendByte(gddram[iPage][iCol]);
						//gddram[iPage][iCol] = 0xff;
						
						sendByte(gddram[iPage][iCol]);								//Wysy³anie 1 bajtu z GDDRAMu
						//FIX
						gddram[iPage][iCol] = 0;									//Zerowanie GDDRAMu
						
						
						//_delay_ms(100);
						
					}
					
					
					
				}
				writeStopCondition();
	
	
}

void gameover(void)
{
		ballX = 63;
		ballY = randY();
		
		movX = (-movX  / movX);
		movY = (-movY  / movY);
		
		//sprintf(,"&d", pointsL)
		//sprintf(,"&d", pointsR)
		
		//printRAM(, 0);
		//printRAM(, 1);
		
		vidOut();
			
		_delay_ms(300);
		
	
}


int randY(void)
{
	return 0x20;
	
}