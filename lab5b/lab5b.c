#include <stdio.h>

int main(){
    //part 1
    int hex = 0;
    char s[20] = "";
    printf("input a hexadecimal: ");
    scanf("%x", &hex);
    printf("input a string: ");
    scanf(" %19[^a]", s);
    puts("");
    
    //part 2
    printf("hex is: %#x\n", hex);
    printf("s is: %s\n\n", s);
}