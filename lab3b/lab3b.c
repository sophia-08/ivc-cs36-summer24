#include <stdio.h>
#include <limits.h>

#define SIZE 20

int sumArray(const int[], size_t);
void sortArray(int[], size_t);
int findLargest(const int[], size_t);
void printArray(const int[], size_t);

int main(void){

    int theArray[SIZE] = {5, 8, 3, 9, 14, 2, 5, 1, 15, 0,
                          5, 7, 2, 8, 11, 10, 9, 2, 1, 7};                                             

    // Print array
    puts("\n--------------------------------------\n");
    puts("The original array: ");
    printArray(theArray, SIZE);
    puts("\n--------------------------------------\n");


    // Sum the array
    int sum = sumArray(theArray, SIZE);
    printf("The sum of all elements in the array is: %i", sum);
    puts("\n\n--------------------------------------\n");


    // Find largest
    int largest = findLargest(theArray, SIZE);
    printf("The largest number in the array is: %i", largest);
    puts("\n\n--------------------------------------\n");
    
    // Sort the array
    puts("Let's sort the array");
    sortArray(theArray, SIZE);
    printArray(theArray, SIZE);
    puts("\n--------------------------------------\n");
}

int sumArray(const int toSum[], size_t theSize){

    //
    // TO DO - return the sum of all values in the array
    //  

    int total = 0;
    for (size_t i =0; i<theSize; i++){
        total += toSum[i];
    }
    return total;
}

int findLargest(const int toFind[], size_t theSize){

    //
    // TO DO - return the largest value in the array
    //         

    int max = INT_MIN;
    for (size_t i=0; i<theSize; i++){
        if (toFind[i] > max){
            max = toFind[i];
        }
    }
    return max;
}

void sortArray(int toSort[], size_t theSize){

    //
    // TO DO - sort the array, smallest to largest
    //

    for (int i=1; i< theSize; i++){
        for (size_t j=0; j<theSize-i; j++){
            int curr = toSort[j];
            int next = toSort[j+1];
            if (curr > next){
                toSort[j+1] = curr;
                toSort[j] = next;
            }
        }
    }
}

void printArray(const int toPrint[], size_t theSize){

    printf("\n%s%9s\t|\t%s%9s\n", "Element", "Value", "Element", "Value");

    size_t halfSize = theSize / 2;
    for (size_t j = 0; j < halfSize; ++j) {
        printf("%7lu%9d    |", j, toPrint[j]);
        printf("%10lu%9d\n", (j + halfSize), toPrint[j+halfSize]);
     } 
}
