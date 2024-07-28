#include <stdio.h>
#include <ctype.h>

void square (int, int*);
void toUpperCase(char*);

int main(){
    int *xPtr = NULL; //initialize to null...
    int y = 7;
    int *yPtr = &y; //...or to an existing value when creating
    int a = *yPtr; //a = 7 (* dereferrences the pointer)
    char z = 'G';
    char *zPtr = &z;

    int num = 5;
    int sq = 0;
    square(num, &sq);

    char aString[] = "cHaRhH";
    toUpperCase(aString); //don't have to pass in *aString because technically aString points to the location of the first char
    printf(aString);

    //non-const pointer at non-const data
    int e1 = 5;
    int *ePtr1 = &e1; //self explanatory

    //non-const pointer at const data


    //const pointer at non-const data
    int e3 = 5;
    int* const ePtr3 = &e3; //read from left to right:
    //this is a constant pointer to an int, so e3 itself can change values, but the ePtr3 can ONLY point at the location initially of e3

    //const pointer at const data
    int e4 = 5;
    const int* const ePtr4 = &e4;
    //can't do *ePtr4 = 5 or ePtr = &e4 because they are both constant

    const char* suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    //in the code above, read from right to left
    //it's an array of size 4 holding pointer to chars that doesn't change
    //the array holes char POINTERS meaning it doesn't hold the value "Hearts" or "Diamonds" or etc...
    //it instead holds pointers to the first char (so index 0 holds a pointer to "H", index 1 holds a pointer to "D", etc.)
}

void square(int n, int *sPtr){
    *sPtr = n*n; //updates sq in main()
}

void toUpperCase(char* sPtr){
    while (*sPtr != '0'){
        *sPtr = toupper(*sPtr);
        sPtr++;
    }
}