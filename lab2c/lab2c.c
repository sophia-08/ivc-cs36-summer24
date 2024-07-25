#include <stdio.h>

double toFarenheit(double);
double toCelsius(double);

int main(void){
    printf("\ncelsius to farenheit\n");
    printf("--------------------\n");
    for (double i=10.0; i<=100; i+=10){
        printf("%.1f° \t     %.1f°\n", i, toFarenheit(i));
    }
    printf("\n\nfarenheit to celsius\n");
    printf("--------------------\n");
    for (double i=32.0; i<=212; i+=20){
        printf("%.1f° \t     %.1f°\n", i, toCelsius(i));
    }
    printf("\n");
}

double toFarenheit(double temp){
    return (9.0/5.0 * temp) + 32;
}

double toCelsius(double temp){
    return (temp - 32) * 5.0/9.0;
}