/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include <stdint.h>
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio



#define NR_MATRIX_ROWS 13
#define NR_MATRIX_COLS 13
#define NR_MATRIX_ELEMENTS 169
#define NR_MATRIX_ELEMENTS_MINUS_ONE 168

/**
 * Authors: Matthijs van Delft, Maikel Coenen.
 * Course: Embedded Computer Architecture.
 * Goal: Optimize this code based on speed as much as possible.
 * Tip: Compile with lever O1.
 */

void setup() {
  // put your setup code here, to run once:
  // initialize serial:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   
    int32_t matrixR[NR_MATRIX_ELEMENTS] = {0};

    static int8_t matrixX[NR_MATRIX_ELEMENTS] =
    {28,  122,  80,   42,   54,   122,  98,   42,   99,   58,   124,  29,   21,
    113, 85,   30,   35,   41,   98,   103,  68,   15,   50,   31,   80,   54,
    47,  37,   23,   96,   59,   47,   84,   26,   84,   72,   51,   118,  119,
    38,  121,  45,   21,   87,   91,   20,   69,   98,   119,  15,   89,   47,
    40,  71,   105,  76,   31,   65,   109,  30,   127,  110,  17,   64,   64,
    45,  20,   113,  86,   86,   51,   104,  115,  61,   103,  60,   113,  44,
    101, 107,  33,   63,   39,   47,   120,  20,   41,   64,   102,  59,   86,
    9,   42,   118,  26,   83,   123,  10,   82,   47,   108,  127,  4,    66,
    75,  26,   117,  80,   47,   111,  38,   22,   98,   101,  92,   100,  48,
    90,  9,    71,   36,   90,   95,   4,    94,   72,   29,   77,   118,  78,
    81,  75,   97,   127,  22,   8,    96,   80,   100,  88,   69,   114,  16,
    25,  109,  74,   3,    126,  56,   99,   15,   69,   73,   76,   19,   97,
    59,  84,   102,  53,   30,   34,   33,   105,  75,   102,  60,   121,  93};
  
    static int8_t matrixY[NR_MATRIX_ELEMENTS] =
    {102,  61,   111,  79,   99,   3,    25,   50,   33,   48,   5,    94,   28,
    106, 89,   35,   37,   112,  51,   13,   70,   3,    110,  31,   7,    99,
    65,  115,  94,   68,   95,   114,  34,   34,   64,   1,    11,   66,   126,
    114, 37,   42,   3,    88,   35,   124,  50,   74,   95,   25,   34,   24,
    25,  111,  4,    116,  54,   90,   11,   32,   121,  20,   26,   62,   60,
    45,  41,   20,   33,   89,   75,   89,   2,    28,   19,   96,   46,   119,
    39,  68,   87,   59,   33,   82,   94,   14,   115,  0,    0,    92,   85,
    58,  62,   122,  106,  93,   39,   86,   80,   75,   23,   57,   89,   7,
    119, 75,   20,   42,   1,    120,  83,   24,   62,   78,   20,   25,   126,
    121, 42,   78,   45,   8,    17,   52,   38,   44,   13,   104,  57,   62,
    29,  96,   0,    64,   47,   50,   22,   17,   88,   63,   108,  78,   101,
    70,  108,  69,   12,   0,    80,   115,  107,  71,   54,   5,    57,   3,
    123, 72,   56,   5,    30,   45,   2,    11,   124,  84,   63,   47,   104};

    int8_t *xM = matrixX + NR_MATRIX_ELEMENTS_MINUS_ONE;
    int8_t *xA = xM;
    int8_t *yM = matrixY + NR_MATRIX_ELEMENTS_MINUS_ONE;
    int8_t *yA = yM;
    int32_t *r = matrixR + NR_MATRIX_ELEMENTS_MINUS_ONE;
  
    register uint8_t e = NR_MATRIX_ELEMENTS;
    register uint8_t k = 0; 
  
    /*Start timer*/

	register int32_t mBuffer;

	register int8_t reg0 = *xM--;
	register int8_t reg1 = *xM--;
	register int8_t reg2 = *xM--;
	register int8_t reg3 = *xM--;
	register int8_t reg4 = *xM--;
	register int8_t reg5 = *xM--;
	register int8_t reg6 = *xM--;
	register int8_t reg7 = *xM--;
	register int8_t reg8 = *xM--;
	register int8_t reg9 = *xM--;
	register int8_t reg10 = *xM--;
	register int8_t reg11 = *xM--;
	register int8_t reg12 = *xM--;
	unsigned long startTime = micros();

    while(e>0){

		mBuffer = 0;

/*
        for(k = NR_MATRIX_COLS; k > 0; --k)
        {
            mBuffer += *xM * *yM;
            --xM;
            yM -= NR_MATRIX_COLS;
        }*/

		mBuffer += reg0 * *yM;
		yM -= NR_MATRIX_COLS;
		mBuffer += reg1 * *yM;
		yM -= NR_MATRIX_COLS;
		mBuffer += reg2 * *yM;
		yM -= NR_MATRIX_COLS;
		mBuffer += reg3 * *yM;
		yM -= NR_MATRIX_COLS;
		mBuffer += reg4 * *yM;
		yM -= NR_MATRIX_COLS;
		mBuffer += reg5 * *yM;
		yM -= NR_MATRIX_COLS;
		mBuffer += reg6 * *yM;
		yM -= NR_MATRIX_COLS;
		mBuffer += reg7 * *yM;
		yM -= NR_MATRIX_COLS;
		mBuffer += reg8 * *yM;
		yM -= NR_MATRIX_COLS;
		mBuffer += reg9 * *yM;
		yM -= NR_MATRIX_COLS;
		mBuffer += reg10 * *yM;
		yM -= NR_MATRIX_COLS;
		mBuffer += reg11 * *yM;
		yM -= NR_MATRIX_COLS;
		mBuffer += reg12 * *yM;
		yM -= NR_MATRIX_COLS;


        *r += *xA + *yA + mBuffer;

        yM += 168;

        --xA;
        --yA;
        --r;

        if(e%13 == 0){
			reg0 = *xM--;
			reg1 = *xM--;
			reg2 = *xM--;
			reg3 = *xM--;
			reg4 = *xM--;
			reg5 = *xM--;
			reg6 = *xM--;
			reg7 = *xM--;
			reg8 = *xM--;
			reg9 = *xM--;
			reg10 = *xM--;
			reg11 = *xM--;
			reg12 = *xM--;
            yM += 13;
        }

        --e;
    }
  
  //
  unsigned long currentTime = micros();
  unsigned long elapsedTime = currentTime - startTime;

  //
  Serial.write("Elapsed time(us): ");
  Serial.println(elapsedTime);
}

