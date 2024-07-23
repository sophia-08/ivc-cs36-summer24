#include <stdio.h> //preprocessor directive

// clang m01.c -o out
// ./out
// ^^ out is file name you're outputting to

int main(void){
    /*
    variable rules:
    - letters, digits, _
    - can't start with digit

    define (int num) vs initialize (num = 9)
    */
   int number = 0;
   printf("hi");
   scanf("%i", &number); 
   // %i means data type is an int (or %d), %c = char, %f = float, %l = long, %s = string
   // &number is a pointer to where to store this input
   printf("you entered %i\n", number);
   // \n is an escape sequence
}