#include <stdio.h>

int main(void){
    double paper_width = 0.0001;
    long long moon_distance = 380000000;
    int count = 0;
    while (paper_width < moon_distance){
        paper_width *= 2;
        count++;
    }
    printf("amount of times needed to fold: %i times\n", count);
}