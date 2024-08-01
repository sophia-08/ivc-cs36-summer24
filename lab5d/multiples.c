#include <stdio.h>

int multiple(int);

int main(void) {
   int y = 0; 

   printf("%s", "\nEnter an integer between 1 and 32000: ");
   scanf("%d", &y);
   puts("");

   // if the inputed number 7 is a multiple of X or 1024, the code prints that it is a multiple
   // else it prints that its not a multiple
   if (multiple(y)) {
      printf("%d is a multiple of X\n\n", y);
   }
   else {
      printf("%d is not a multiple of X\n\n", y);
   }
}

// funtion takes in an int and 
// returns an int
int multiple(int num) {
   // initialize & declare two ints
   int mask = 1;
   int mult = 1;

   // for loop that either iterates 10 times or stops as soon as num's not a multiple (mult = 0)
   // after each iteration, the mask shifts one to the left (it doubles)
   // and if the num and mask both have 1s at the same location in binary, it's not a multiple
   for (int i = 1; (i <= 10) && (mult != 0); ++i) {
      if ((num & mask) != 0) { 
         mult = 0;
      }
      mask <<= 1;
   }
   return mult;
}
