/*
 * lamper.c
 *
 * Created: 8/1/2018 2:35:12 PM
 * Author : TheeD
 * Clap detector! Turn your light on
 * by hitting the light switch
 * with ULN2003!
 * (they didnt let me use relays for 230v).
 *
 *
 *
 * DISCLAIMER
 * i could not use enum by then, so it is based on 1,2,3...
 */ 

#include <avr/io.h>
#include <util/delay.h>

unsigned int thresholdHigh = 750;
unsigned int thresholdLow = 400;
signed char lightstatus = 0;

unsigned int conversion()
{
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	unsigned int result = ADC;
	return result;
}


int main(void)
{
	DDRB = 0b00111110;
    /* Replace with your application code */
	
	ADMUX |= (1<<MUX1);
	ADMUX |= (1<<REFS0);
	//ADMUX |= (1<<ADLAR);
	ADCSRA |= (1<<ADPS2);
	ADCSRA |= (1<<ADEN);
	
	//TCCR1A |= (1<<COM1A1);
	//TCCR1A |= (1<<WGM11);
	//TCCR1B |= (1<<WGM13) | (1<<WGM12) | (1<<CS10);
	
	//ICR1 = 19999;
	//OCR1A = 1700;
	
	/* DISCLAIMER
	 * THIS IF-TOWER BELOW IS A ML WITHOUT ML ALGORITHM DETECTING
	 * CLAPPING FROM ADC
	 * IT JUST WORKS
	*/

    while (1) 

	{
		if(lightstatus != 2 && lightstatus != -1)
		{

			if(conversion() > thresholdHigh)
			{
				for(unsigned char i = 0; i < 10; i++)
				{
					_delay_ms(10);
					if(conversion() < thresholdLow)
					{

						for(unsigned char i0 = 0; i < 300; i0++)
						{
							if(conversion() > thresholdHigh)
							{
								for(unsigned char i = 0; i < 10; i++)
								{
									_delay_ms(10);
									if(conversion() < thresholdLow)
									{

										if(lightstatus == 1) lightstatus = -1;
										if(lightstatus == 0) lightstatus = 2;
										break;
									}
								}
								break;
							}
						}
						break;
					}
				}
			}
		}
		


		if(lightstatus == 2)
		{

			for(unsigned char i3 = 0; i3 < 30; i3++)
			{
				PORTB = 0b00000010;
				_delay_ms(10);
				PORTB = 0b00000100;
				_delay_ms(10);
				PORTB = 0b00001000;
				_delay_ms(10);
				PORTB = 0b00010000;
				_delay_ms(10);
			}

			lightstatus = 1;
			PORTB = 0x00;
		}
		else if (lightstatus == -1)
		{
				for(unsigned char i4 = 0; i4 < 30; i4++)
				{
				PORTB = 0b00010000;
				_delay_ms(10);
				PORTB = 0b00001000;
				_delay_ms(10);
				PORTB = 0b00000100;
				_delay_ms(10);
				PORTB = 0b00000010;
				_delay_ms(10);


				}
			lightstatus = 0;
			PORTB = 0x00;
		}
    }
}

