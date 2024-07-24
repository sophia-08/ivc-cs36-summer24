#include <stdio.h>
#include <limits.h>

int main(void){
    //part 1
    int user_input = 0;
    int largest = 0;
    int largest_2nd = 0;
    int smallest = INT_MAX;
    int smallest_2nd = INT_MAX;
    printf("\n\n--part 1--\n");
    printf("please enter 10 integers\n");
    for (int counter=0; counter<10; counter++){
        printf("enter %i of 10 non-negative numbers: ", counter+1);
        scanf("%i", &user_input);
        if (user_input > largest){
            largest_2nd = largest;
            largest = user_input;
        }
        else if (user_input > largest_2nd){
            largest_2nd = user_input;
        }
        if (user_input < smallest){
            smallest_2nd = smallest;
            smallest = user_input;
        }
        else if (user_input < smallest_2nd){
            smallest_2nd = user_input;
        }
    }
    printf("largest number: %i\n", largest);
    printf("second largest number: %i\n", largest_2nd);
    printf("smallest number: %i\n", smallest);
    printf("second smallest number: %i\n", smallest_2nd);

    //part 2
    printf("\n--part 2--\n");
    printf("enter a number between 1-10 to find the factorial: ");
    scanf("%i", &user_input);
    int factorial = 1;
    for (int counter =1; counter <= user_input; counter++){
        factorial*=counter;
    }
    printf("factorial of %i is %i\n\n", user_input, factorial);
}