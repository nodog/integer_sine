
/* c
   nodog
   2015-03-21  

   fast_array_copy.c
   testing quicker copies in C
*/

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#define LIMITHIGH 3000 /* How many do I print? */
#define ARDIM1 2
#define ARDIM2 4


void print_array(int ar_dim1, int ar_dim2, int ar[ARDIM1][ARDIM2]) {
  printf("---------------\n");
  for (int i = 0; i < ar_dim1; i++) {
    for (int j = 0; j < ar_dim2; j++) {
      printf( "%d,", ar[i][j] );
    }
    printf("\n");
  }
  printf("---------------\n");
}

int main() {
  srand(time(NULL));

  // make a 2-D array
  int ar1[ARDIM1][ARDIM2] = 
  { { 0, 1, 2, 3 },
    { 4, 5, 6 ,7 } };

  print_array(ARDIM1, ARDIM2, ar1);

  for (int i = 0; i < LIMITHIGH; i++) {
    int ar2[ARDIM2];
    for (int j = 0; j < ARDIM2; j++) {
      ar1[1][j] = rand() % 89 + 10;
    }
   // int ar3[ARDIM2] = { 10, 11, 12, 13 };
   // *ar1[1] = *ar3;
    print_array(ARDIM1, ARDIM2, ar1);
  }

  return 0;
}


