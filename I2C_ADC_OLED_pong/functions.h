/*
 * functions.h
 *
 * Created: 17/08/2017 23:03:57
 *  Author: TheeD
 */ 


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_


#define SLA_W 0b01111000 //RW = 0

#define SET_CONTRAST_CONTROL 0x81
#define CONTRAST_M 0x7F
#define CONTRAST_H 0xFF
#define CONTRAST_L 0x00

#define ENTIRE_DISPLAY_ON 0xA5

#define SET_NORMAL_DISPLAY 0xA6
#define SET_INVERSE_DISPLAY 0xA7

#define SET_DISPLAY_ON 0xAF
#define SET_DISPLAY_OFF 0xAE

#define NOP 0xE3

#define SET_ADRESSING_MODE 0b00100000
#define HORIZONTAL_ADDRESSING_MODE 0b00000000;


#define SET_COLUMN_ADDRESS 0b00100001
#define SET_PAGE_ADDRESS 0b00100010


#define CHARGE_PUMP_SET 0x8d
#define CHARGE_PUMP_ON	0x14
#define DISPLAY_ON 0xAF






extern void sendCommand(unsigned char quantity, unsigned char c1, unsigned char c2, unsigned char c3);
extern void init(void);
extern void displaySetup(void);
extern void sendByte(unsigned char data);
extern void sendControlByteCommand(void);
extern void writeStopCondition(void);
extern void writeStartCondition(void);
extern void sendSLA_W(void);
extern void area(unsigned char sX, unsigned char sY, unsigned char, unsigned char eY);
extern void sendControlByteData(void);
extern void sendDataByte(unsigned char data);
extern void clearDisplay(void);
extern void usart_sendstr(char arr[]);
extern void uart_sendbyte(char data);
extern void oscilloscope_singlevert(unsigned char x);
extern long map(long x, long in_min, long in_max, long out_min, long out_max);
extern void oscilloscope_singlescreen(void);
extern void print(char arr[]);
extern void printRAM(char arr[], unsigned char page);
extern void gddramSinglePoint(unsigned char x, unsigned char y);
extern void vidOut(void);

//extern char voltageString[5];



#endif /* FUNCTIONS_H_ */