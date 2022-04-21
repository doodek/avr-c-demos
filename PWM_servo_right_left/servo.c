/*
 * Servo.c
 *
 * Created: 27.12.2016 19:41:06
 *  Author: github.com/doodek
 */ 


#include <avr/io.h>			//Standard I/O lib
#include <util/delay.h>    	//Delay lib

#define SERVO_MIN 600		//0 deg		
#define SERVO_MAX 2400		//180 deg 
#define SERVO_90 1500     	//90 deg 
           

int main(void)
{
	
	int step = 20; //step = 6/1000 * 180deg =  1.08 deg
	
	//IO
	DDRB |= (1<<PB2);  //Servo pin as output
	
	//PWM config
	
	TCCR1A |= (1<<COM1B1) | (1<<WGM11);					 //Non inv. mode.
	TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS10)  ;     //Fast PWM, mode 14, prescaler = 1;
	ICR1 = 19999;  									 	 //one cycle - 19999 us
	OCR1B = 1200; 										 //Move servo to initial position
	
	
    while(1)
    {
       OCR1B = OCR1B + step;							//Add the step
	   
	   if(OCR1B >= SERVO_MAX){
		   step = -step; 								//Trick - change sign of step if approaches
	   }												//limit
	   
	   if(OCR1B <= SERVO_MIN){
		   step = -step;   // -step = step
	   }
	   
	   _delay_ms(10); 
    }
}