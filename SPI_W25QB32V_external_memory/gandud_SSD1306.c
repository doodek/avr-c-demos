/*
* gandud_SSD1306.c
*
* Created: 23.02.2017 16:45:30
*  Author: Gandud
*/

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <avr/interrupt.h>

#include "czcionki.h"
#include "gandud_SSD1306.h"
#include "gandud_w25q32bv.h"




const __flash char napis2[] = "dobre i tyle";

void ssd1306_SPI_wyslij_komende_1b(unsigned char bajt1)
{
	
	PORTB &= ~(1<<DC);
	PORTB &= ~(1<<SS);
	
	SPDR	=	bajt1;
	while(!(SPSR & (1<<SPIF)));

	PORTB |= (1<<SS);
}
void ssd1306_SPI_wyslij_komende_2b(unsigned char bajt1, unsigned char bajt2)
{
	
	PORTB &= ~(1<<DC);
	PORTB &= ~(1<<SS);
	
	SPDR	=	bajt1;
	while(!(SPSR & (1<<SPIF)));
	
	SPDR	=	bajt2;
	while(!(SPSR & (1<<SPIF)));
	
	
	PORTB |= (1<<SS);
}
void ssd1306_SPI_wyslij_komende_3b(unsigned char bajt1, unsigned char bajt2, unsigned char bajt3)
{
	

	
	PORTB &= ~(1<<DC);
	PORTB &= ~(1<<SS);
	
	SPDR	=	bajt1;
	while(!(SPSR & (1<<SPIF)));

	
	SPDR	=	bajt2;
	while(!(SPSR & (1<<SPIF)));

	
	SPDR = bajt3;
	while(!(SPSR & (1<<SPIF)));
	
	PORTB |= (1<<SS);
}
void ssd1306_SPI_wyslij_dana_1b(unsigned char bajt1)
{
	
	PORTB |=   (1<<DC);
	PORTB &= ~(1<<SS);
	
	
	SPDR	=	bajt1;
	while(!(SPSR & (1<<SPIF)));
	
	PORTB |= (1<<SS);
}
void ssd1306_SPI_wyslij_dana_3b(unsigned char bajt1, unsigned char bajt2, unsigned char bajt3)
{
	
	PORTB |=	(1<<DC);
	PORTB &=    ~(1<<SS);
	
	
	SPDR	=	bajt1;
	while(!(SPSR & (1<<SPIF)));

	
	SPDR	=	bajt2;
	while(!(SPSR & (1<<SPIF)));
	
	
	SPDR = bajt3;
	while(!(SPSR & (1<<SPIF)));
	

	PORTB |= (1<<SS);
}
void ssd1306_SPI_wyslij_dana_2b(unsigned char bajt1, unsigned char bajt2)
{
	
	PORTB |= (1<<DC);
	PORTB &= ~(1<<SS);
	
	SPDR	=	bajt1;
	while(!(SPSR & (1<<SPIF)));
	
	SPDR	=	bajt2;
	while(!(SPSR & (1<<SPIF)));
	
	
	PORTB |= (1<<SS);
}
void SPI_inicjuj	(void)
{
	
	DDRB	|=	(1<<SS)	|	(1<<DC)	|	(1<<SCK)	|	(1<<MOSI)		//DISPLAY
			|	(1<<SS2);												//FLASH	
	
	PORTB |= (1<<SS)													//Display
			|(1<<SS2);													//Flash
	
	
	SPCR	|=	(1<<CPHA);	//Nieaktywny na wysokim
	SPCR	|=	(1<<CPOL);	//Sample na zboczu narastaj¹cym,
	
	SPSR	|=	(1<<SPI2X);	//Prescaler 2
	
	SPCR	|=	(1<<MSTR);	//mastere mode spedre
	SPCR	|=	(1<<SPE);	//w³¹cz modu³ SPI


	_delay_ms(200);  //aby LCD zd¹¿y³ siê w³¹czyæf
	
	ssd1306_SPI_wyslij_komende_2b(CHARGE_PUMP_KOMENDA, CHARGE_PUMP_ON);
	ssd1306_SPI_wyslij_komende_2b(CONTRAST_CONTROL_KOMENDA,	CONTRAST_CONTROL_MAX);
	//ssd1306_SPI_wyslij_komende_1b(ENTIRE_DISPLAY_ON_KOMENDA);
	//ssd1306_SPI_wyslij_komende_1b(NORMAL_DISPLAY_MODE);
	ssd1306_SPI_wyslij_komende_2b(SET_MEMORY_ADDRESSING_MODE, HORIZONTAL_ADDRESSING_MODE);
	ssd1306_SPI_wyslij_komende_1b(DISPLAY_ON);
	
	ssd1306_SPI_wyslij_komende_3b(SET_COLUMN_ADDRESS, 0, 127);
	ssd1306_SPI_wyslij_komende_3b(SET_PAGE_ADDRESS, 0, 7);
}
void ssd1306_SPI_ustaw_page_kolumna(unsigned char page, unsigned char kolumna)
{
	ssd1306_SPI_wyslij_komende_3b(SET_PAGE_ADDRESS, page, 7);
	ssd1306_SPI_wyslij_komende_3b(SET_COLUMN_ADDRESS, kolumna, 127);
}
void ssd1306_reset(void)
{
	
	DDRD |= (1<<RESET_PIN);
	PORTD &= ~(1<<RESET_PIN);
	_delay_ms(10);
	PORTD |= (1<<RESET_PIN);
	_delay_ms(200);
	
}
void ssd1306_SPI_wyczysc_cale(void)
{
	obszar(0, 127, 0, 7);
	ssd1306_SPI_ustaw_page_kolumna(0, 0);
	unsigned int t1	= 0;
	while(t1 < 1024)
	{
		
		ssd1306_SPI_wyslij_dana_1b(0);
		t1 ++;
		
	}

	
	
}
void ssd1306_SPI_wyczysc(unsigned char x,	unsigned char y,	unsigned int z)
{
	ssd1306_SPI_ustaw_page_kolumna(y, x);
	unsigned int t1	= 0;
	while(t1 < z)
	{
		
		ssd1306_SPI_wyslij_dana_1b(0);
		t1 ++;
		
	}

	ssd1306_SPI_ustaw_page_kolumna(y, x);
	
}
void ssd1306_SPI_kropka(unsigned char page, unsigned char kolumna)
{
	ssd1306_SPI_ustaw_page_kolumna(page, kolumna);
	ssd1306_SPI_wyslij_dana_1b(0x01);

}
void ssd1306_SPI_kropka_xy(unsigned char x, unsigned char y)
{
	unsigned char h = y % 8;
	unsigned char page = y/8;
	unsigned char column = x;
	
	ssd1306_SPI_ustaw_page_kolumna(page, column);

	ssd1306_SPI_wyslij_dana_1b(1<<h);

}
void ssd1306_SPI_xy(unsigned char x, unsigned char y){
	
	ssd1306_SPI_ustaw_page_kolumna(y,x);
	
		for( int t1 = 8; t1<13; t1++)
		{
			ssd1306_SPI_wyslij_dana_1b(czcionki[t1]);
		}
	
	
} void ssd1306_SPI_napis(unsigned char x, unsigned char y)
 {
	 
	//ta funkcja Ÿle wyœwietla znaki
	
	// for(int t0 = 0; t0 < strlen_P(napis2); t0++){

	//int indexKodAscii = napis2[t0] - '!';   //33 bo zaczynamy od !, a kod ascii '!' = 33
		 
	int indexKodAscii	=	3;
	for(int t1 = 0; t1 < czcionki_ascii_info[indexKodAscii][0]; t1++)
	{
			 
		ssd1306_SPI_ustaw_page_kolumna(y, x);
		//ssd1306_SPI_wyslij_dana_1b(ascii_znaki[ascii_info[indexKodAscii][1]] + t1);
		ssd1306_SPI_wyslij_dana_1b(24 + t1);
		x++;
	}
	
	 

		//}
 }
void print(char x, char bajty_ramki,  char * napis, int ilosc_znakow)
 {
	 //char t2 = 0;
	 char spedre = 0;
	 //dla ka¿dego znaku ascii w tablicy
	 //ssd1306_SPI_ustaw_page_kolumna(y, x);
	 PORTB |=   (1<<DC);
	 PORTB &= ~(1<<SS);
	 
	 for(int t0 = 0; t0 < ilosc_znakow ; t0++)
	 {
		 int index_Ascii_Info = (* (napis + t0)) - '!';   //tutaj blad odczytu wartosci tablicy za pomoca wskaznika
		 
		 int ilosc_bajtow_litery = czcionki_ascii_info[index_Ascii_Info][0];  //5
		 int index_minecraftia = czcionki_ascii_info[index_Ascii_Info][1];   //59
		 
		 
		 
		 //poszczególne bajty znaku ascii
		 for(int t1 = index_minecraftia ; t1 < index_minecraftia + ilosc_bajtow_litery; t1++)
		 {
			 spedre = czcionki[t1];
			 
			 /*
			 if(t2 <= bajty_ramki)
			 {
				  spedre |= (1<<0);
				  t2++;
			 }
			 */
			SPDR = spedre;
			while(!(SPSR & (1<<SPIF)));		
			
			//_delay_ms(250)	;
			
			/* telewizorek
			 ADCSRA |= (1<<ADSC);
			 while(ADCSRA & (1<<ADIF));
	
			SPDR = ADC << 8;
			 while(!(SPSR & (1<<SPIF)));
			*/ 
		}
		 
		 //spacja z ramka 
		 SPDR	=	0  ;
		 while(!(SPSR & (1<<SPIF)));
	 }
	 
	 PORTB |= (1<<SS);
	 
 } void obszar(char kolumna_start, char  kolumna_koniec, char page_start, char page_koniec)
 {
	 
	 
	 
	 ssd1306_SPI_wyslij_komende_3b(SET_PAGE_ADDRESS, page_start , page_koniec );
	 ssd1306_SPI_wyslij_komende_3b(SET_COLUMN_ADDRESS, kolumna_start, kolumna_koniec);
	 
 }
void adc_init(void)
{
	
	 ADCSRA |= (1<<ADPS1) | (1<<ADPS0); //Prescaler
	 ADCSRA |= (1<<ADIE);
	  ADCSRA |= (1<< ADEN);
}
void szum (void)
{
	volatile unsigned char r;

	while(1)
	{
		r = rand();
		SPDR = r;
		while(!(SPSR & (1<<SPIF)));
		PORTB &= ~(1<<LED);
		//_delay_ms (10);
	}
}
void zero(unsigned char licznik)
 {
	 
	 for (unsigned char t = 0; t < licznik; t++)
	 {
	 
		//SPI_wyslij_odbierz_1b(0);
	
	 }
	 
 }
void usart_init (void)
 {
	 
	 UCSRB	|=	(1<<RXEN)	|	(1<<RXCIE)	|	(1<<TXEN);
	 
	 UCSRC |= (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
	 
	 UBRRH = 383 >> 8;
	 UBRRL = (unsigned char)383;	//2400 BPS
 }
void printchar( int znak, char x)
 {
	char bufor[4];
	ssd1306_SPI_wyslij_komende_3b(SET_COLUMN_ADDRESS, x+2, 127);
	itoa(znak, bufor, 16);
	print(x, 0, bufor, strlen(bufor));
	 
 
 }
