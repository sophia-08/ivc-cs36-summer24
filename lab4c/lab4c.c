#include <stdio.h>
#include <string.h>

int main(){
    char source[] = "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness...";
    char input[80] = "";
    printf("input the word to find: ");
    fgets(input, 80, stdin);
    input[strcspn(input, "\n")] = '\0';
    char* searchPtr = source;
    int count = 0;

    while ((searchPtr = strstr(searchPtr, input)) != NULL){
        count++;
        printf("\n\"%s\" was found %i time(s)\n%s\n", input, count, searchPtr);
        searchPtr+=1;
    }
    printf("\n");
}