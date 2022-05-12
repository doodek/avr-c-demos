/*
 * ULN2003.c
 *
 * Created: 10.03.2017 17:22:11
 * Author : TheeD
 */ 

#include <avr/io.h>
#include "ULN2003.h"
#include <util/delay.h>

void rotate(unsigned int t0, unsigned char t2);

int main(void)
{
    DDRC = 0xFF;
	
	
	
    while (1) 
    {
		PORTC = 0b00000001;
		_delay_us(DEL1);
		PORTC = 0b00000010;
		_delay_us(DEL1);
		PORTC = 0b00000100;
		_delay_us(DEL1);
		PORTC = 0b00001000;
		_delay_us(DEL1);
		
    }
}

void rotate(unsigned int t0, unsigned char t2){
	
	

	for(int t11 = 0; t11 <= t0; t11++);
	
	for(int t10 = 0; t10 <= t2; t10++){
		
		PORTC = 0b0001;
		PORTC = 0b0010;
		PORTC = 0b0100;
		PORTC = 0b1000;
		
	}
	
	
	
}