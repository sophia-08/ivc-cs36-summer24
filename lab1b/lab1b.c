#include <stdio.h>

int main(void){
    //p1
    printf("--part 1--\n  *  \n *** \n*****\n");

    //p2
    int variable1 = 17/5;
    int variable2 = 17%5;
    printf("\n--part 2--\n");
    printf("17 / 5 = %i remainder %i\n", variable1, variable2);

    //p3
    printf("\n--part 3--\n");
    int radius = 0;
    printf("enter a radius: ");
    scanf("%i", &radius);
    printf("\nradius: %i\n", radius);
    printf("diameter: %i\n", radius*2);
    printf("circumference: %f\n", 2*3.14*radius);
    printf("area: %f\n\n", 3.14*radius*radius);
}