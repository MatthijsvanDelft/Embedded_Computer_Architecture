
/*
 * Assembler1.s
 *
 * Created: 13-9-2017 13:00:21
 *  Author: heijd
 */ 


#include <avr/io.h>



#define NR_MATRIX_ROWS 0x0D
#define NR_MATRIX_COLS 0x0D
#define NR_MATRIX_COLS_MINUS_ONE 0x0C
#define NR_MATRIX_ELEMENTS 0xA9
#define NR_MATRIX_ELEMENTS_MINUS_ONE 0xA8

#define VAR_E r18
#define VAR_K r19

#define XP Z
#define YP Y

#define VAR_X r0
#define VAR_Y r1

#define VAR_BUFFER r23:22
#define VAR_BUFFER_LO r22
#define VAR_BUFFER_HI r23

#define VAR_VALUE_ONE r20
#define VAR_VALUE_TWO r21

;.include "m328Pdef.inc"

.macro ldi16
	ldi @0, high(@2)
	ldi @1, low(@2)
.endmacro

.macro clr16
	clr @0
	clr @1
.endmacro

.global addition

addition:
	
	push rbp
	pop VAR_VALUE_ONE
	pop VAR_VALUE_TWO
	adc VAR_VALUE_ONE, VAR_VALUE_TWO

	ret VAR_VALUE_ONE