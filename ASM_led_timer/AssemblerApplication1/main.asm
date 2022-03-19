;
; AssemblerApplication1.asm
;
; Created: 21.05.2017 14:53:47
; Author : github.com/doodek
;


; Replace with your application code

.include "m8def.inc"

.org $000 rjmp main
.org $009 rjmp TIM0_OVF ; Timer0 Overflow


TIM0_OVF:

eor r17, r16
out PORTB, r17

reti



main:
	cli
	ldi r16, (1<<CS02) | (1<<CS00);   PRESCALER = 1024
	out TCCR0, r16

	clr r16
	ldi r16, 0x01

	out TCNT0, r16
	out TIMSK, r16
	out DDRB, r16
	out PORTB, r16

	sei

	loop:
	nop
	rjmp loop
	


