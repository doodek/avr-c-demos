/*
 * pamiece.c
 *
 * Created: 04.05.2017 16:26:29
 * Author: n00b
 *  Sorry for polish comments. They do't mean much
 *	Notice: this is only able to save "one byte at once" somehow.
 */

#include <avr/io.h>
#include <avr/pgmspace.h>	
#include <avr/interrupt.h>
#include <util/delay.h>
#include "gandud_SSD1306.h"
#include "gandud_w25q32bv.h"

int main(void)
{
	
	//####INICJACJA####

	DDRD |= (1<<PD4);

	ssd1306_reset();
	SPI_inicjuj();
	ssd1306_SPI_wyczysc_cale();
	obszar(1, 127, 0, 7);
	usart_init();
	_delay_ms(500);
	
	
	//####KONIEC INICJACJI####
	
	
	w25q32bv_write_enable();				//wlacz zapis
	w25q32bv_erase_sector(0x200000);		//wyczysc sektor 4kb
	
	sei();								//wlacz przerwania globalne
	
	//PORTD |= (1<<PD4);
	
	
	_delay_ms(5000);
	
	unsigned long adres = 0x200000;
	
	for(unsigned int x = 0; x < 256; x++)
	{
		while (!(UCSRA&(1<<UDRE)));
		UDR	=	w25q32bv_odczytaj_dane(adres + x);		//wyslij dan� odczytana z pamieci				
	}
	

	while (1) 
	{



	}
		
}

