;
; asm_exercises.asm
;
; Created: 09/01/2018 19:21:09
; Author : github.com/doodek
; probably just a "set led on"
;


; Replace with your application code

start:
	
	.include "m328pdef.inc"

	ldi r16, 0xff
	push r16


	pop r16
	out portb, r16