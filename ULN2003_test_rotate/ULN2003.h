/*
 * IncFile1.h
 *
 * Created: 10.03.2017 17:22:38
 *  Author: TheeD
 */ 


#ifndef ULN2003_H
#define ULN2003_H

#define OUT1 PC3
#define OUT2 PC2
#define OUT3 PC1
#define OUT4 PC0

#define FULL 32
#define HALF 16
#define QUAT 8
#define OCTA 4
#define HEXA 2
#define BTDC 1

#define DEL1 2500

extern void full_rotate(unsigned int t0, unsigned int t11);

#endif /* INCFILE1_H_ */