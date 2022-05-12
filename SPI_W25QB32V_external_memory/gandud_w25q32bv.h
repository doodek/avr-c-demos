/*
 * gandud_w25q32bv.h
 *
 * Created: 30.05.2017 17:11:39
 *  Author: noob
 */ 


#ifndef GANDUD_W25Q32BV_H_
#define GANDUD_W25Q32BV_H_

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#define SS2			PB0

extern void w25q32bv_wyslij_1b(unsigned char bajt1);
extern void w25q32bv_write_enable(void);
extern char w25q32bv_odczytaj(void);
extern char w25q32bv_odczytaj_dane(unsigned long addr);
extern void w25q32bv_erase_sector(long addr);
extern void	w25q32bv_odczytaj_jedec(void);
extern void	w25q32bv_wyswietl_jedec(void);

extern  void w25q32bv_czekaj_flage_busy(void);
extern  void w25q32bv_ss2_low(void);
extern	void w25q32bv_ss2_high(void);
extern void w25q32bv_write_bajt(unsigned long addr, unsigned char bajt);
#endif /* GANDUD_W25Q32BV_H_ */