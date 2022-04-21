/*
 * ISR.c
 *
 * Created: 30.04.2017 21:29:12
 * Author : github.com/doodek
 * Check if your timer works?
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_OVF_vect)
{
  PORTB ^=	(1<<PB0);
}
 

int main(void)
{
	
  DDRB|=(1<<PB0); 
  
  sei();
  
  TCCR0|=(1<<CS00) | (1<<CS02); 
  TIMSK|=(1<<TOIE0);
  
    while (1) 
    {
		
	  }
}

