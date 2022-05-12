/*
 * w25q32bv.c
 *
 * Created: 30.05.2017 17:10:57
 *  Author: noob
 */ 


#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include <avr/interrupt.h>

#include "czcionki.h"
#include "gandud_SSD1306.h"
#include "gandud_w25q32bv.h"

 void w25q32bv_czekaj_flage_busy(void)
 {
	 //czekaj na zak. poprzedniego zapisu sprawdzajac flage busy
	 while (w25q32bv_odczytaj() & (1<<0));
 }
 void w25q32bv_ss2_low(void)
 {
	 PORTB &= ~(1<<SS2);  //rozpocznij zapis
 }
 void w25q32bv_ss2_high(void)
 {
	 PORTB |= (1<<SS2);  //rozpocznij zapis
 }
 void w25q32bv_erase_sector(long addr)
 {
	 w25q32bv_ss2_low();
	 
	 //rozkaz zapisu danych
	 SPDR	=	0x20;
	 while(!(SPSR & (1<<SPIF)));
	 //wyslij adres
	 SPDR	=	(addr >> 16) ;
	 while(!(SPSR & (1<<SPIF)));		//ADRES = 20 00 00h
	 SPDR	=	(addr >> 8);
	 while(!(SPSR & (1<<SPIF)));
	 SPDR	=	addr;
	 while(!(SPSR & (1<<SPIF)));
	 
	 w25q32bv_ss2_high();
	 w25q32bv_czekaj_flage_busy();
 }
 void w25q32bv_odczytaj_jedec(void)
 {
	 unsigned char jedec[4];
	 PORTB |=   (1<<DC);
	 PORTB &= ~(1<<SS2);
	 
	 
	 SPDR	=	0x9F;
	 while(!(SPSR & (1<<SPIF)));
	 jedec[0]	=	SPDR;
	 
	 SPDR = 0;
	 while(!(SPSR & (1<<SPIF)));
	 jedec[1]	=	SPDR;
	 
	 SPDR = 0;
	 while(!(SPSR & (1<<SPIF)));
	 jedec[2]	=	SPDR;
	 
	 SPDR = 0;
	 while(!(SPSR & (1<<SPIF)));
	 jedec[3]	=	SPDR;
	 
	 PORTB |= (1<<SS2);

 }
 void w25q32bv_write_enable(void)
 {
	 
	 
	 

	 w25q32bv_wyslij_1b(0x06);
	 
 }
 void w25q32bv_wyslij_1b(unsigned char bajt1)
 {
	 
		 PORTB &= ~(1<<SS2);
	 
	 	SPDR	=	bajt1;
	 	while(!(SPSR & (1<<SPIF)));

		 PORTB |= (1<<SS2);
 }
 void w25q32bv_wyswietl_jedec(void)
 {
	 
	 char buff[10];
	 int jedec[4];
	 //PORTB |=   (1<<DC);
	 PORTB &= ~(1<<SS2);
	 
	 
	 SPDR	=	0x9f;
	 while(!(SPSR & (1<<SPIF)));
	 SPDR	=	0;
	 jedec[0]	=	SPDR;
	 while(!(SPSR & (1<<SPIF)));
	 jedec[1]	=	SPDR;
	 
	 PORTB |= (1<<SS);
	 PORTB &= ~(1<<SS);
	 
	 SPDR	=	0;
	 while(!(SPSR & (1<<SPIF)));
	 jedec[2]	=	SPDR;
	 SPDR	=	0;
	 while(!(SPSR & (1<<SPIF)));
	 jedec[3]	=	SPDR;
	 

	 
	 PORTB |= (1<<SS2);
	 PORTB &= ~(1<<SS);
	 
	 
	 itoa(jedec[0], buff, 16);
	 print(0, 0, buff, strlen(buff));
	 
	 itoa(jedec[1], buff, 16);
	 print(0, 0, buff, strlen(buff));
	 
	 itoa(jedec[2], buff, 16);
	 print(0, 0, buff, strlen(buff));
	 
	 itoa(jedec[3], buff, 16);
	 print(0, 0, buff, strlen(buff));
	 SPDR	=	0x9f;
	 while(!(SPSR & (1<<SPIF)));
	 SPDR	=	0;
	 jedec[0]	=	SPDR;	 
	 PORTB |= (1<<SS);
 }
 char w25q32bv_odczytaj(void)
  {
	  
	  
	  char sreg;

	  PORTB &= ~(1<<SS2);
	  
	  
	  SPDR	=	0x05;
	  while(!(SPSR & (1<<SPIF)));
	  SPDR	=	0;
	  while(!(SPSR & (1<<SPIF)));
	  sreg	=	SPDR;
	  
	  
	  PORTB |= (1<<SS2);

	  
	  
	return sreg;
	
	  
 
  }
 char w25q32bv_odczytaj_dane(unsigned long addr)
 {
	 

			
	
			 
			 w25q32bv_czekaj_flage_busy();
			 
		w25q32bv_ss2_low();
			 
	 		//rozkaz zapisu danych
	 		SPDR	=	0x03;
	 		while(!(SPSR & (1<<SPIF)));
	 		//wyslij adres
	 		SPDR	=	(addr >> 16);
	 		while(!(SPSR & (1<<SPIF)));		
	 		SPDR	=	(addr >> 8);
	 		while(!(SPSR & (1<<SPIF)));
	 		SPDR	=	addr;
	 		while(!(SPSR & (1<<SPIF)));
	 		SPDR	=	0;
			while(!(SPSR & (1<<SPIF)));
			
		w25q32bv_ss2_high(); 
			 
	 return SPDR;
 }
 void w25q32bv_write_bajt(unsigned long addr, unsigned char bajt)
 {
	 
	 	 w25q32bv_czekaj_flage_busy();
	 	 
	
	 	 w25q32bv_write_enable(); //wlacz zapis
	 	 w25q32bv_ss2_low();
	 	
	 	 
	 	 
	 	 
	 	
	 	 SPDR	=	0x02;
	 	 while(!(SPSR & (1<<SPIF)));
	 	
	 	 SPDR	=	(addr >> 16) ;
	 	 while(!(SPSR & (1<<SPIF)));		
	 	 SPDR	=	(addr >> 8);
	 	 while(!(SPSR & (1<<SPIF)));
	 	 SPDR	=	addr;
	 	 while(!(SPSR & (1<<SPIF)));
	 	 
	 	 //wyslij dana
	 	 SPDR	=	0x55;
	 	 while(!(SPSR & (1<<SPIF)));
	 	 
	 	 

	 	 w25q32bv_ss2_high();
	 
	 
 }
 
 
 /*
 
 ISR(USART_RXC_vect)		
 {
	 
	 
	 //ZAPIS BAJTU ODEBRANEGO PRZEZ USART
	 
	 
	 
	 PORTD ^= (1<<PD4); 
	 
	 char recieved = UDR;
	 
	 static unsigned long adres = 0x200000;
	 static unsigned char licznik_bajtow	=	0;
	 
	
	 
	// w25q32bv_czekaj_flage_busy();
	 

	// if(licznik_bajtow == 0)
	// {	
		
		
		w25q32bv_write_enable();		//wlacz zapis
		w25q32bv_ss2_low();				//rozpocznij transmisje
		
			 //rozkaz zapisu danych
			 SPDR	=	0x02;
			 while(!(SPSR & (1<<SPIF)));
			 //		wyslij adres
			 SPDR	=	(adres >> 16) ;
			 while(!(SPSR & (1<<SPIF)));		//ADRES = 20 00 00h
			 SPDR	=	(adres >> 8);
			 while(!(SPSR & (1<<SPIF)));
			 SPDR	=	adres;
			 while(!(SPSR & (1<<SPIF)));
			 
	 //}
	 
	

	 //wyslij dana
	 SPDR	=	recieved;
	 while(!(SPSR & (1<<SPIF)));
	 
	 

	 
	 
	// if(licznik_bajtow == 255)		//koniec page'a
	// {
		 
		 w25q32bv_ss2_high();								//Zakoncz transmisje
		 licznik_bajtow = 0;								//Zeruj licznik bajtow  *******
		w25q32bv_czekaj_flage_busy();						
		ssd1306_SPI_wyczysc_cale();							//Prze³adowanie ekranu
		printchar(recieved,  0);							//wyswietl bajt z USART
		printchar(w25q32bv_odczytaj_dane(adres), 50);		//wyswietl zapisane dane
		
		
		//#### WYSY£ANIE DO USART ####
		
					
					BAJT 1 - BAJT 1 ADRESU
					BAJT 2 - BAJT 2 ADRESU
					BAJT 3 - BAJT 3 ADRESU
					BAJT 4 - DANA ODCZYTANA Z PAMIECI
					BAJT 5 - DANA ODEBRANA Z USART
					BAJT 6 - BAJT NA ZAKOÑCZENIE
		
					BAJTY 4 I 5 POWINNY BYÆ RÓWNE
					BAJT 6 POWINIEN WYNOSIÆ 1
		
					
		
				while (!(UCSRA&(1<<UDRE)));					//wyslij 24 bitowy adres
				UDR	=	(adres >> 16) ;					
				while (!(UCSRA&(1<<UDRE)));
				UDR	=	(adres >> 8);	
				while (!(UCSRA&(1<<UDRE)));
				UDR	=	adres;

		
				while (!(UCSRA&(1<<UDRE)));	
				UDR	=	w25q32bv_odczytaj_dane(adres);		//wyslij dan¹ odczytana z pamieci
		
				while (!(UCSRA&(1<<UDRE)));					//wyslij bajt odebrany przez USART
				UDR	=	recieved;
		
		
				while (!(UCSRA&(1<<UDRE)));					//Bajt 0x01 na zakonczenie
				UDR	=	0x01;

	// }
	 
	 


		  licznik_bajtow++;
		  adres++;


	
	 
 } */
 
 
ISR(USART_RXC_vect)		
 {
	 
	 
	 //ZAPIS BAJTU ODEBRANEGO PRZEZ USART
	 
	 
	w25q32bv_czekaj_flage_busy();
	
	 PORTD ^= (1<<PD4); 
	 
	 char recieved = UDR;
	 
	 static unsigned long adres = 0x200000;
	 static unsigned char licznik_bajtow	=	0;
	 
	
	 

	 

	 if(licznik_bajtow == 0)
	{	
		
		
		w25q32bv_write_enable();		//wlacz zapis
		w25q32bv_ss2_low();				//rozpocznij transmisje
		
			 //rozkaz zapisu danych
			 SPDR	=	0x02;
			 while(!(SPSR & (1<<SPIF)));
			 //		wyslij adres
			 SPDR	=	(adres >> 16) ;
			 while(!(SPSR & (1<<SPIF)));		//ADRES = 20 00 00h
			 SPDR	=	(adres >> 8);
			 while(!(SPSR & (1<<SPIF)));
			 SPDR	=	adres;
			 while(!(SPSR & (1<<SPIF)));
			 
	 }
	 
	

	 //wyslij dana
	 SPDR	=	recieved;
	 while(!(SPSR & (1<<SPIF)));
	 



	 
	 
	 if(licznik_bajtow == 255)		//koniec page'a
	 {
		 
		 w25q32bv_ss2_high();								//Zakoncz transmisje
		 
		w25q32bv_czekaj_flage_busy();						
		ssd1306_SPI_wyczysc_cale();							//Prze³adowanie ekranu

		
		
		//#### WYSY£ANIE DO USART ####
		
		
		
				

		licznik_bajtow = 0;								//Zeruj licznik bajtow  *******
				
	 }
	 
	 


	
	 	 
	 	 
	 	 licznik_bajtow++;
	 	// adres++;
 }