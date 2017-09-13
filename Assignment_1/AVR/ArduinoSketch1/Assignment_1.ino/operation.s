
/*
 * operation.s
 *
 * Created: 12-9-2017 22:41:36
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

.macro ldi16
	ldi @0, high(@2)
	ldi @1, low(@2)
.endmacro

.macro clr16
	clr @0
	clr @1
.endmacro


.global operation_loop

operation_loop:
	 ;call stack contains matX, matY, matR

	 ;load variables
	ldi VAR_E, NR_MATRIX_ELEMENTS_MINUS_ONE

	;while(e >= 0)
	outer_while:
		;int mBuffer = 0;
		clr16 VAR_BUFFER_LO,VAR_BUFFER_HI
		ldi VAR_K, NR_MATRIX_COLS_MINUS_ONE

		inner_while:
			;update addresses in YP and XP (todo)
			;LD VAR_Y, YP
			;LDD VAR_X, XP-

		;check inner
		dec VAR_K
		brne inner_while
		;end inner

	;check outer
	dec VAR_E
	brne outer_while			;branch non-zero, maar dan de arduino variant
	;end outer

	ret