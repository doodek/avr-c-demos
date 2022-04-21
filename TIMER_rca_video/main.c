/*
 * RCAvideo.c
 *
 * Created: 15/09/2017 19:54:51
 * Author : github.com/doodek
 * PROBABLY NOT WORKING
 * RCA VIDEO SOMETHING
 * I MADE ANOTHER ON STM32
 * BUT LOST THE CODE
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned char interrupt_counter = 0;

#define GRAY 0b00000010
#define BLACK 0b00000001
#define WHITE 0b00000011
#define HSYNC 0x00

void hsync(void)
{
	
		PORTB = 0x00;
		_delay_us(8);
		PORTB = 0b00000011;
		_delay_us(16);
	
}


int main(void)
{
   DDRB = 0xFF;
   
   /*
   
   PORTB 00 - SYNC  (black on steroids)  
   PORTB 01 - BLACK
   PORTB 10 - 50%
   PORTB 11 - WHITE
   
	SEQUENCE:
	
	4uS SYNC
	8uS BLACK ---- MISTAKE! COLORBURST SHOULD BE WHITE IN MONOCHROMATIC MODE!
	52uS DATA
	
	all is 64ms (63.5) 

	RET.
	
	*/
   
	//TIMER 0 (HSYNC) configuration
	
	
	TCCR0A |= (1<<WGM01) | (1<<WGM00);	//CTC MODE
	TCCR0B |= (1<<CS01);
	OCR0A = 52;  //52us. PRESC = 8 (for 8mhz) | 16 (for 16mhz)
	
	sei();
  
    while (1) 
    {
		PORTB ^= (1<<PB1);			
		_delay_us(1);
    }

}

ISR(TIMER0_OVF_vect)
{

	hsync();
	if(interrupt_counter == 0)
	{
		interrupt_counter++;	
		hsync();
	}
	else
	{
		interrupt_counter--;
	}
		
}