/*
* gandud_SSD1306.h
*
* Created: 23.02.2017 16:45:47
*  Author: gr8 b8 m8
*/


#ifndef GANDUD_SSD1306_H_
#define GANDUD_SSD1306_H_

#include <avr/io.h>
#include <avr/pgmspace.h>						//nag³ówek do funkcji obs³ugi danych w pamiêci flash (pamiêæ programu)

	
#define DC			PB1
#define	SS			PB2
#define	MOSI		PB3
#define MISO		PB4
#define	SCK			PB5
#define RESET_PIN   PD7
#define	LED			PD4

#define RXD			PD0
#define TXD			PD1

#define	CHARGE_PUMP_KOMENDA			0x8D
#define CHARGE_PUMP_ON				0x14
#define CHARGE_PUMP_OFF				0x13

#define CONTRAST_CONTROL_KOMENDA	0x81
#define CONTRAST_CONTROL_MAX		255

#define ENTIRE_DISPLAY_ON_KOMENDA	0xA5
#define DISPLAY_ON					0xAF

#define NORMAL_DISPLAY_MODE			0xA6

#define SET_MEMORY_ADDRESSING_MODE	0x20
#define HORIZONTAL_ADDRESSING_MODE	0
#define VERTICAL_ADDRESSING_MODE	1

#define SET_COLUMN_ADDRESS 0x21
#define SET_PAGE_ADDRESS 0x22

//###################


extern void	SPI_inicjuj	(void);
extern void	ssd1306_SPI_wyslij_komende_1b(unsigned char bajt1);
extern void	ssd1306_SPI_wyslij_komende_2b(unsigned char bajt1, unsigned char bajt2);
extern void	ssd1306_SPI_wyslij_komende_3b(unsigned char bajt1, unsigned char bajt2, unsigned char bajt3);
extern void	ssd1306_SPI_wyslij_dana_1b(unsigned char bajt1);
extern void	ssd1306_SPI_wyslij_dana_2b(unsigned char bajt1, unsigned char bajt2);
extern void	ssd1306_SPI_wyslij_dana_3b(unsigned char bajt1, unsigned char bajt2, unsigned char bajt3);
extern void	ssd1306_SPI_ustaw_page_kolumna(unsigned char page, unsigned char kolumna);
extern void ssd1306_SPI_wyczysc_cale(void);
extern void ssd1306_reset(void);
extern void ssd1306_SPI_kropka(unsigned char page, unsigned char kolumna);
extern void ssd1306_SPI_kropka_xy(unsigned char x, unsigned char y);
extern void ssd1306_SPI_xy(unsigned char x, unsigned char y);
extern void ssd1306_SPI_napis(unsigned char x, unsigned char y);
extern void ssd1306_SPI_napis(unsigned char x, unsigned char y);
extern void print(char x, char y, char * napis, int ilosc_znakow);
extern void obszar(char kolumna_start, char  kolumna_koniec, char page_start, char page_koniec);
extern void adc_init(void);
extern const __flash char napis2[];
extern void szum (void);
extern void ssd1306_SPI_wyczysc(unsigned char x,	unsigned char y,	unsigned int z);
extern void usart_init(void);
extern void printchar( int znak, char x);

//extern void ssd1306_SPI_(unsigned char)


// Font data for Comic Sans MS 8pt
extern const __flash unsigned char comicSansMS_8ptBitmaps[];
//extern const FONT_INFO comicSansMS_8ptFontInfo;
//extern const FONT_CHAR_INFO comicSansMS_8ptDescriptors[];


#endif /* GANDUD_SSD1306_H_ */