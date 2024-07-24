#include <stdio.h>

int main(void){
    //part 1
    int user_input = 0;
    int count = 0;
    int total = 0;
    printf("\n--part 1--\n");
    printf("enter integers, enter -1 when done\n");
    do{
        printf("enter an integer: ");
        scanf("%i", &user_input);
        if (user_input != -1){
            count++;
            total+= user_input;
        }
    } while (user_input != -1);
    double avg = (double) total/count;
    printf("here is the average of your inputs: %f\n", avg);

    //part 2
    printf("\n--part 2--\n");
    double price1 = 2.98;
    double price2 = 4.50;
    double price3 = 9.98;
    double price4 = 4.49;
    double price5 = 6.87;
    printf("product number \t\t retail price\n");
    printf("%i \t\t\t %.2f\n", 1, price1);
    printf("%i \t\t\t %.2f\n", 2, price2);
    printf("%i \t\t\t %.2f\n", 3, price3);
    printf("%i \t\t\t %.2f\n", 4, price4);
    printf("%i \t\t\t %.2f\n", 5, price5);
    int prod_number = 0;
    printf("enter a product number: ");
    scanf("%i", &prod_number);
    switch (prod_number){
        case 1:
            printf("you have chosen product %i, the price is $%.2f\n", 1, price1);
            break;
        case 2:
            printf("you have chosen product %i, the price is $%.2f\n", 2, price2);
            break;
        case 3:
            printf("you have chosen product %i, the price is $%.2f\n", 3, price3);
            break;
        case 4:
            printf("you have chosen product %i, the price is $%.2f\n", 4, price4);
            break;
        case 5:
            printf("you have chosen product %i, the price is $%.2f\n", 5, price5);
            break;
        default:
            printf("that product doesn't exist\n");
            break;
    }
    printf("\n\n");
}