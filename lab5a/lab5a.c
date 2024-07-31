#include <stdio.h>

int main(){
    //part 1
    printf("\n--part 1--\n");
    int a = 1427;
    double b = 1427.0;
    printf("a in octal is: %#o\n", a);
    printf("a in hexadecimal is: %#x\n", a);
    printf("a in hexadecimal is also: %#X\n", a);
    puts("");
    printf("b without a decimal point is: %.0f\n", b);
    printf("b with two digits after the decimal point is: %.2f\n", b);

    //part 2
    printf("\n--part 2--\n");
    int c = 873;
    double d = 123.94536;
    char e[] = "Star Wars: A New Hope";
    printf("c with four digits of precision is: %.4i\n", c);
    printf("c with nine digits of precision is: %.9i\n", c);
    puts("");
    printf("d with three digits of precision is: %.3f\n", d);
    printf("d in scientific notation with three digits of precision is: %.3e\n", d);
    printf("d printed and rounded to: %.0f\n", d);
    puts("");
    printf("e but only the first 9 characters is: %.9s\n", e);
    puts("");
}