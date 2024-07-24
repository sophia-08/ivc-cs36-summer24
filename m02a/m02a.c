#include <stdio.h>

int main(void){
    //use for loops for counter-controlled iteration (know how many times will be used)
    for (unsigned int counter = 0; counter <=10; ++counter){
        //weird syntax,,..
        printf ("for loop %i\n", counter);
    }

    //use while loops for sentinel-controlled iteration 

    //secure C
    //sizeof() returns byte size of the datatype
    int size = sizeof(int); //4
    printf("int size: %i\n", size);
}