
/* c
   nodog
   2015-02-15  

   integer_cos.c
   uses some math I found on the internet to calculate cosine with integers
*/

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

#define LIMITHIGH 3000 /* How many do I print? */

int cos2p(int angle) {
  long x = abs(angle) % 256;
  if (x > 128) {
    x = 256 - x;
  }
  long y = 0;
  if (x < 64) {
    y = -x*x/32 + 255;
  } else {
    y = x*x/32 -8*x + 512;
  }
  return (int) y;
}

int main()
{

   /* variables */
   int index = 1;
   long int powerval = 1;

   for (int i = 0; i < 2048; i=i+1)
   {
     unsigned long tempr = cos2p(i) * cos2p(3*i + 128);
      printf("%d, %d, %d, %d\n", i, cos2p(i), (unsigned char) (tempr/512), cos2p(i)/4);
   }

   return 0;
}


