
/*
 * functions.c
 *
 * Created: 2018?
 *  Author: github.com/doodek
 * 
 *  Probably a software PWM RGB fade? Including a timer, but no hardware PWM
*/ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>

//macros simplyfing port access
#define BLUE (1<<PB0)
#define GREEN (1<<PB1)
#define RED (1<<PB2)
#define LED_PORT PORTB
#define LED_DIR DDRB

volatile uint8_t pwm_green, pwm_blue, pwm_red; //PWM timer value storage
uint8_t i; 

int main(void) {
	
	DDRB |= GREEN | BLUE | RED; 	//set pin mode output
	PORTB &= ~(GREEN | BLUE | RED); //preventionally disable all diodes
	
	PORTB |= (1<<PB3) | (1<<PB4); 	//set pull-ups 
	DDRB &= ~((1<<PB3) | (1<<PB4)); //set inputs 
	
	TCCR0 |= (1 << WGM01); 				//timer mode CTC
	TCCR0 |= (1 << CS01) | (1 << CS00); //prescaler 64
	TIMSK |= (1 << OCIE0A); 			//enable interrupt for timer 0
	ACSR  |= (1<<ACD); 	//disable  analog comparator -- save energy!
	
	sei(); //enable global interrupts
	

	//Adjust the pwm values, they are read by timer
	while (1) {
		for (i = 0; i < 255; i++) { //lighten up green
			pwm_green++; 			//increment the green pwm val
			_delay_ms(2); 			//2ms delay (util/delay)
		}
		for (i = 0; i < 255; i++) { //darken green
			pwm_green--; 			
			_delay_ms(2); 
		}
		for (i = 0; i < 255; i++) { //lighten blue
			pwm_blue++; 
			_delay_ms(2); 
		}
		for (i = 0; i < 255; i++) { //darken blue
			pwm_blue--;  
			_delay_ms(2); 
		}
		for (i = 0; i < 255; i++) { //lighten red
			pwm_red++; 
			_delay_ms(2); 
		}
		for (i = 0; i < 255; i++) { //darken red
			pwm_red--; 
			_delay_ms(2); 
		}
	}
	
}

ISR(TIM0_COMPA_vect) { 		//interrupt at frequency approx 18750Hz
	static uint8_t cnt = 0; //define interrupt counter variable
	cnt++;
	
	if (pwm_green > cnt) 	//if the green pwm var is greater than counter
	PORTB |= GREEN; 		//enable the output (turn on led)
	else PORTB &= ~GREEN; 	//else disable (turn off)
	
	if (pwm_red > cnt) 
	PORTB |= RED; 
	else PORTB &= ~RED; 
	
	if (pwm_blue > cnt) 
	PORTB |= BLUE; 
	else PORTB &= ~BLUE; 

	if (cnt > 255) cnt = 0; //counter reset
}