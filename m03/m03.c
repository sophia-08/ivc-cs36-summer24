#include <stdio.h>
// #define SIZE 15
const int SIZE = 15; //this will lead to problem because it's a "variable" and not "constant"
//will throw a warning

int main(void){
    printf("size of int: %i\n", sizeof(int));
    printf("size of float: %i\n", sizeof(float));
    printf("size of double: %i\n", sizeof(double));

    int my_array[4] = {1, 2, 3, 4}; //array of 4 ints
    //^ the 4 ints are in contiguous (right next to each other) memory locations
    //if default (int arr[4] = {}), naturally filled with 0 (so {0, 0, 0, 0})

    int size = sizeof(my_array);
    printf("size of my array: %i\n", size); //16 (because 4 ints means 4*4)
    printf("index 3 has: %i\n", my_array[2]); //start at 0, yada yada

    int for_array[SIZE];

    for (int i=0; i<SIZE; i++){
        for_array[i] = i+2;
    }
    for (size_t i=0; i<SIZE; i++){ //technically size_t is better but like....why
    //size_t is technically better for trasversing an array
        printf("array[%zu] = %i\n", i, for_array[i]);
    }

    printf("my array is: %zu\n", my_array); //%zu is for size_t (can be int or unsigned long)
    printf("my array address is: %zu\n", &my_array); //& means address of
    printf("my array [1] address is: %zu\n", &my_array[1]); //4 "addresses" after bc ints are sizeof() 4

    char string1[SIZE];
    char string2[] = "string literal";

    printf("%s", "enter a string (<= 19 characters): ");
    scanf("%19s", string1); //19s means right align by 19 "slots" or "spaces"
    //when scanf, the input ends at the next space

    printf("string1 is %s\n", string1);
    printf("string2 is %s\n", string2);
    //array always ends with \0 (to signal when ends)

    //when you pass an array into a function, they are pointing at the same address (referencing the same point of memory)
    //so when you edit an array in a function, THE ACTUAL ARRAY CHANGES TOO
    //think java

    //sorting arrays
    //can you,,,,can you just look at the notes. i dont care.

    int two_d[2][3] = {{11, 12, 13}, {21, 22, 23}};
}