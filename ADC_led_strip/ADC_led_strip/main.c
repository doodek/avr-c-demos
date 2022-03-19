/*
 * PhotoAnalyzer.c
 *
 * Created: 17.02.2017 19:17:50
 * Author : dooodek@protonmail.com
 * Presents the ADC readings (in this case - photoresistor) on a led strip (47HC595)
 */ 

#include <avr/io.h>
#include "m8_pindef.h"

void hc595_send(unsigned char data);
void measurement_send(void);
void adc_init(void);					
void hc595_init(void);

int main(void)
{
	hc595_init();
	hc595_send(0xFF);
	adc_init();
		
    while (1) 
    {
		measurement_send();		
    }
}

void adc_init(){
	 ADMUX	|=	(1<<REFS0);				//CHOOSE REFERENCE VOTLAGE - AVCC PIN
	 ADMUX |= (1<<MUX3) | (1<<MUX2);	//CHOOSE CHANNEL
	 ADCSRA |= (1<<ADEN); 				//ADC ON
	 ADCSRA	|=	(1<<ADPS2)	|	(1<<ADPS1)	|	(1<<ADPS0);	//SET PRESCALER TO 128
 }

void measurement_send(void){	

	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));				//WAIT FOR THE MEASUREMENT


	//CHOOSE THE VALUE TO BE SENT TO HC595 FOR LED STRIP
	if(ADC  < 128){
		SPDR = 0b00000001;
	}
	else if(ADC < 256){
		SPDR = 0b00000011;
	}
	else if(ADC < 384){
		SPDR = 0b00000111;
	}
	else if(ADC < 512){
		SPDR = 0b00001111;
	}
	else if(ADC < 640){
		SPDR = 0b00011111;
	}
	else if(ADC < 768){
		SPDR = 0b00111111;
	}
	else if(ADC < 896){
		SPDR = 0b01111111;
	}
	else{
		SPDR = 0xFF;
	}
	
	while(!(SPSR & (1<<SPIF)));				//WAIT TILL THE END OF TRANSMISSION
	PORTB |= (1<<STCP);
	PORTB &= ~(1<<STCP);
}

void hc595_send(unsigned char data){
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));				//WAIT TILL THE END
	PORTB |= (1<<STCP);
	PORTB &= ~(1<<STCP);
}

void hc595_init(void){
	
	//CPOL = 0
	//CPHA = 0
	//DORD = 0 LITTLE ENDIAN GOES FIRST
	
	DDRB |= (1<<PB3);
	DDRB |= (1<<PB5);
	DDRB |= (1<<PB0);
	SPCR |= (1<<MSTR);
	SPSR |= (1<<SPI2X);					//PRESCALER 64

	SPCR |= (1<<SPE); //SPI enable   - ALWAYS LAST
}
