
/* c
   nodog
   2015-02-15  

   fn_oscillator.c
   oscillates a given fn.
*/

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

#define LIMITHIGH 3000 /* How many do I print? */

int fnosc(int angle) {
  int x = abs(angle) % 256;
  if (x > 128) {
    x = 256 - x;
  }
  // here's the fn
  int y = 255 - 1.9*x;
  return y;
}

int main()
{

   /* variables */
   int index = 1;
   long int powerval = 1;

   for (int i = 0; i < LIMITHIGH; i=i+1)
   {
     unsigned long tempr = fnosc(i) * fnosc(3*i + 128);
      printf("%d, %d, %d, %d\n", i, fnosc(i), (unsigned char) (tempr/512), fnosc(i)/4);
   }

   return 0;
}


