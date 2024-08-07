#include <stdio.h>

int main(){
    int N, low, high;
    printf("Enter the value for N: ");
    scanf("%i", &N);
    printf("Enter the range (# and #): ");
    scanf(" %i %i", &low, &high);

    printf("Pairs (x, y) such that x*y+x+y = %i: \n", N);

    int count = 0;

    for (int x = low; x <= high; x++){
        for (int y = low; y <= high; y++){
            if ((x*y) + (x+y) == N){
                printf("(%i, %i)\n", x, y);
                count++;
            }
        }
    }
    if (count == 0){
        puts("N/A");
    }

    puts("");
}