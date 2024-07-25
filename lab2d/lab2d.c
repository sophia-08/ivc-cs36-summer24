#include <stdio.h>

void printSquare(int);
void printSquare_char(char, int);
void printWeirdSquare(int);

int main(void){
    int dimension = 0;
    printf("\nenter dimensions of a * square: ");
    scanf("%i", &dimension);
    printWeirdSquare(dimension);

    char symbol = ' ';
    printf("\nenter a character and the dimensions of a square made from said char: ");
    scanf(" %c %i", &symbol, &dimension);
    printSquare_char(symbol, dimension);
    printf("\n");
}

void printSquare(int dim){
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++){
            printf("* ");
        }
        printf("\n");
    }
}

void printSquare_char(char sym, int dim){
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++){
            printf("%c ", sym);
        }
        printf("\n");
    }
}

void printWeirdSquare(int dim){
    int mod = 0;
    for (int i=0; i<dim; i++){
        mod++;
        mod %=2;
        for (int j=0; j<dim; j++){
            if (j%2 == mod) printf("▼ ");
            else printf("▲ ");
        }
        printf("\n");
    }
}