#include <stdint.h>

#define NR_MATRIX_ROWS 13
#define NR_MATRIX_COLS 13
#define NR_MATRIX_ELEMENTS 169

void setup() {
  // put your setup code here, to run once:
  // initialize serial:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //
  unsigned long startTime = micros();

  uint8_t matrixX[NR_MATRIX_ROWS][NR_MATRIX_COLS] =
  {{28,  122,  80,   42,   54,   122,  98,   42,   99,   58,   124,  29,   21},
  {113, 85,   30,   35,   41,   98,   103,  68,   15,   50,   31,   80,   54},
  {47,  37,   23,   96,   59,   47,   84,   26,   84,   72,   51,   118,  119},
  {38,  121,  45,   21,   87,   91,   20,   69,   98,   119,  15,   89,   47},
  {40,  71,   105,  76,   31,   65,   109,  30,   127,  110,  17,   64,   64},
  {45,  20,   113,  86,   86,   51,   104,  115,  61,   103,  60,   113,  44},
  {101, 107,  33,   63,   39,   47,   120,  20,   41,   64,   102,  59,   86},
  {9,   42,   118,  26,   83,   123,  10,   82,   47,   108,  127,  4,    66},
  {75,  26,   117,  80,   47,   111,  38,   22,   98,   101,  92,   100,  48},
  {90,  9,    71,   36,   90,   95,   4,    94,   72,   29,   77,   118,  78},
  {81,  75,   97,   127,  22,   8,    96,   80,   100,  88,   69,   114,  16},
  {25,  109,  74,   3,    126,  56,   99,   15,   69,   73,   76,   19,   97},
  {59,  84,   102,  53,   30,   34,   33,   105,  75,   102,  60,   121,  93}};
  
  uint8_t matrixY[NR_MATRIX_ROWS][NR_MATRIX_COLS] =
  {{102,  61,   111,  79,   99,   3,    25,   50,   33,   48,   5,    94,   28},
  {106, 89,   35,   37,   112,  51,   13,   70,   3,    110,  31,   7,    99},
  {65,  115,  94,   68,   95,   114,  34,   34,   64,   1,    11,   66,   126},
  {114, 37,   42,   3,    88,   35,   124,  50,   74,   95,   25,   34,   24},
  {25,  111,  4,    116,  54,   90,   11,   32,   121,  20,   26,   62,   60},
  {45,  41,   20,   33,   89,   75,   89,   2,    28,   19,   96,   46,   119},
  {39,  68,   87,   59,   33,   82,   94,   14,   115,  0,    0,    92,   85},
  {58,  62,   122,  106,  93,   39,   86,   80,   75,   23,   57,   89,   7},
  {119, 75,   20,   42,   1,    120,  83,   24,   62,   78,   20,   25,   126},
  {121, 42,   78,   45,   8,    17,   52,   38,   44,   13,   104,  57,   62},
  {29,  96,   0,    64,   47,   50,   22,   17,   88,   63,   108,  78,   101},
  {70,  108,  69,   12,   0,    80,   115,  107,  71,   54,   5,    57,   3},
  {123, 72,   56,   5,    30,   45,   2,    11,   124,  84,   63,   47,   104}};
  
  uint32_t matrixR[NR_MATRIX_ROWS][NR_MATRIX_COLS] = {0};

  uint8_t *x = (int8_t*)matrixX;
  uint8_t *y = (int8_t*)matrixY;
  uint32_t *r = (int32_t*)matrixR;

  register uint8_t nrRows = NR_MATRIX_ROWS;
  register uint8_t nrCols = NR_MATRIX_COLS;
  register uint8_t nrElements = NR_MATRIX_ELEMENTS;

  register uint8_t i;
  register uint8_t j;
  register uint8_t k;

  for(i = 0; i < NR_MATRIX_ROWS; i++)
  {
    for(j = 0; j < NR_MATRIX_COLS; j++)
    {
      x += (NR_MATRIX_COLS * i);
      y += j;
      for(k = 0; k < NR_MATRIX_COLS; k++)
      {
        *r += *x * *y;
        x++;
        y += NR_MATRIX_COLS;
      }
      r++;
      x = (int8_t*)matrixX;
      y = (int8_t*)matrixY;
    }
  }


//  for(nrRows=0; nrRows<NR_MATRIX_ROWS; nrRows++){
//        for(nrCols=0; nrCols<NR_MATRIX_COLS; nrCols++){
//          for(i = 0; i < NR_MATRIX_ROWS; i++){
//
//            *r = *x * *y;
//            //*r += *(x+a) * *(y+b);
//
//            /*Multiplication.*/
////            *r += *x * *y;
////            *r += *(x+1) * *(y+13);
////            *r += *(x+2) * *(y+26);
////            *r += *(x+3) * *(y+39);
////            *r += *(x+4) * *(y+52);
////            *r += *(x+5) * *(y+65);
////            *r += *(x+6) * *(y+78);
////            *r += *(x+7) * *(y+91);
////            *r += *(x+8) * *(y+104);
////            *r += *(x+9) * *(y+117);
////            *r += *(x+10) * *(y+130);
////            *r += *(x+11) * *(y+143);
////            *r += *(x+12) * *(y+156);
//
//            ++a;
//            b += 13;
//            ++y;
//            ++r;
//          }
//        }
//        x+=13;
//        y=(int8_t*)matrixY;
//    }

    /*Matrices back to base address*/
    x = (int8_t*)matrixX;
    y = (int8_t*)matrixY;
    r = (int32_t*)matrixR;

    while(nrElements>0){
        *r++ += *x++ + *y++;
        nrElements--;
    }

  
  //
  unsigned long currentTime = micros();
  unsigned long elapsedTime = currentTime - startTime;

  //
  Serial.write("Elapsed time(us): ");
  Serial.println(elapsedTime);
}

