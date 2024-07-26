//Sophia Dai - Project 1
#include <stdio.h>
#include <limits.h>
#include <float.h>

void printMathTable();
void printName();
void numberCalculator();

int main(void){
    printMathTable();
    printName();
    numberCalculator();
}

// part 1
void printMathTable(){
    printf("\n\nmath table:\n");
    printf("----------------------\n");
    printf("number   square  cube\n");
    printf("----------------------\n");

    for (int i=1; i<=10; i++){
        printf("%i \t %i \t %i\n", i, i*i, i*i*i);
    }

    printf("----------------------\n");
}

//part 2
void printName(){
    printf("\n\nname characters: \n");
    printf("-----------------\n");

    printf("S - %i\n", 'S');
    printf("o - %i\n", 'o');
    printf("p - %i\n", 'p');
    printf("h - %i\n", 'h');
    printf("i - %i\n", 'i');
    printf("a - %i\n", 'a');
}

//part 3
void numberCalculator(){
    printf("\n\nnumber calculator: \n");
    printf("-----------------------\n");

    float num1 = 0.0;
    float num2 = 0.0;
    float num3 = 0.0;
    double small = DBL_MAX;
    double large = 0.0;

    printf("enter the first of three float-pointing nums: ");
    scanf(" %f", &num1);
    if (num1 > large){
        large = num1;
    }
    if (num1 < small){
        small = num1;
    }

    printf("enter the second of three float-pointing nums: ");
    scanf(" %f", &num2);
    if (num2 > large){
        large = num2;
    }
    if (num2 < small){
        small = num2;
    }

    printf("enter the third of three float-pointing nums: ");
    scanf(" %f", &num3);
    if (num3 > large){
        large = num3;
    }
    if (num3 < small){
        small = num3;
    }

    double sum = num1 + num2 + num3;
    double product = num1 * num2 * num3;
    double average = sum/3;

    printf("-------------------------\n");
    printf("sum: %f\n", sum);
    printf("average: %f\n", average);
    printf("product: %f\n", product);
    printf("smallest number: %f\n", small);
    printf("largest number: %f\n\n", large);
}