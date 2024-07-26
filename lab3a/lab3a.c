#include <stdio.h>
const int SIZE = 10;

int main(void){
    int array_values[SIZE] = {};
    for (size_t i=0; i<SIZE; i++){
        array_values[i] = i*i;
    }
    for (size_t i=0; i<SIZE; i++){
        printf("array_values[%zu] = %i\n", i, array_values[i]);
    }
    puts("");
}