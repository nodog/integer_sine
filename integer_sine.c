
/* c
   nodog
   2015-02-13  

   integer_sine.c
   uses some math I found on the internet to calculate sine with integers
*/

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

#define LIMITHIGH 3000 /* How many do I print? */

int int_sine_approx(int angle) {

  // angle is in a measurement from 0 to 28380 (don't ask me)
  // output is a number from 0 to 8192
  
  long x = (long) angle - 14192;

  // S(x) = x * ( (3<<p) - (x*x>>r) ) >> s     
  // n : Q-pos for quarter circle             13     
  // A : Q-pos for output                     12     
  // p : Q-pos for parentheses intermediate   15     
  // r = 2n-p                                 11     
  // s = A-1-p-n                              17

  static const int qN = 13, qA= 12, qP= 15, qR= 2*qN-qP, qS= qN+qP+1-qA;
  x= x<<(30-qN);          // shift to full s32 range (Q13->Q30)     
  if( (x^(x<<1)) < 0)     // test for quadrant 1 or 2         
    x= (1<<31) - x;     
  x= x>>(30-qN);     
  return (int) (x * ( (3<<qP) - (x*x>>qR) ) >> qS) + 4096; 
}

long int i_sine_2(int angle ) {
  long int x = angle;
  return 16384 - 16384*x^2/(2*2609^2) + 16384*x^4/(24*2609^4);
}

int sine_2_parabs(int angle) {
  long int x = angle;
  long y = 0;
  if (x < 8192) {
    y = -x*x/2048 + 4*x + 8192;
  } else {
    y = x*x/2048 -12*x + 73728;
  }
  return (int) y;
}

int sine_2_parabs2(int angle) {
  long x = abs(angle % 256);
  long y = 0;
  if (x < 128) {
    y = -x*x/32 + 4*x + 127;
  } else {
    y = x*x/32 -12*x + 1152;
  }
  return (int) y;
}

int main()
{

   /* variables */
   int index = 1;
   long int powerval = 1;

   for (int i = 0; i < 256; i=i+1)
   {
      printf("%d, %d\n", i, sine_2_parabs2(i));
   }

   return 0;
}


