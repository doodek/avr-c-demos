/*
 * m8_pindef.h
 *
 * Created: 24.02.2017 18:33:17
 *  Author: github.com/doodek
 * 
 * Contains pin definitions for Atmel ATMega8
 */ 


#ifndef M8_PINDEF_H_
#define M8_PINDEF_H_

//PORT B
#define ICP1 PB0	
#define OC1A PB1
#define OC1B PB2
#define SS PB2
#define OC2 PB3
#define MOSI PB3
#define MISO PB4
#define SCK PB5
#define XTAL1 PB6
#define TOSC1 PB6
#define XTAL2 PB7
#define TOSC2 PB7

//PORT C
#define ADC0 PC0
#define ADC1 PC1
#define ADC2 PC2
#define ADC3 PC3
#define ADC4 PC4
#define ADC5 PC5
#define SDA  PC4
#define SCL  PC5

//PORT D
#define RESET PD6
#define RXD PD0
#define TXD PD1
#define XCK PD4
#define T0 PD4
#define T1 PD5
#define AIN0 PD6
#define AIN1 PD7

//CNTRL
#define LED PB0

//SPI
#define SLAVE0 PB1
#define SLAVE1 PD7
#define SLAVE2 PD6

#endif /* M8_PINDEF_H_ */