#include <stdio.h>
#include <stdbool.h>

int main(void){
    
    int numToCheck = 0;
    int divisor = 0;
    bool isPrime = 1; // 0 = false and 1 = true

    printf("%s", "\nThe prime numbers from 3 to 100 are:\n\n");

    // outer for loop
    // test each number to see if it prime
    
    for ( numToCheck = 3; numToCheck <= 100; numToCheck+=2 ){
        isPrime = 1; // reset, assume it is prime to start

        // inner for loop
        // divide number by all integers from 2 -> number - 1
        // if dividing and no remainder...number is not prime
        
        for ( divisor = 3; divisor < numToCheck; divisor+=2 ){
            if ( numToCheck % divisor == 0 ){
                isPrime = 0;
                break;
            }
        } // end inner for loop

        if (isPrime == 1){
            printf("%i ", numToCheck);
        }
        
    } // end outer for loop
    
    puts("\n");
    return 0;
}