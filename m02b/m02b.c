#include <stdio.h>

double square(double); //function prototype
// ^ must be placed before main
//alternate is to have the actual function listed above main
//instead of having prototype before + definition after

long factorial(int);

enum Status {CONTINUE, WIN, LOSS}; //custom data types
// constants use all caps
// under the hood, these are all ints, so technically you can do gameStatus++

int main(void){
    for (int i=1; i<=10; i++){
        printf("%f ", square(i)); //main() is the calling function of square()
    }

    int myPoint = 0;
    enum Status gameStatus = CONTINUE;
    if (myPoint == 4){
        gameStatus = WIN;
    }
    else{
        gameStatus = LOSS;
    }
}

double square(double x){ //function definition
    return x*x;
    //if an int is passed into a double, it's implicitly converted (no loss in accuracy)
    /*
    implicit type of conversion:
        - done by the compiler
        - types are promoted (upgraded to larger type)
        - order: bool, char, int, long, float, double (and some other stuff...)
            - so bool can be promoted to anything but double can't be implicitly converted to float
            - ie. if you add a char with an int, the char will implicitly become its ascii code int and then algrebra ensues
    explicit type of conversion:
        - done by programmer
        - casting
    */
}

long factorial (int number){ //recursive function :)
    if (number <= 1){ //base case
        return 1;
    }
    return (number * factorial(number - 1));
    //any problem that can be solved with recursion can be done with loops
}

/*
fuction call stack
    |  RAM  |
    +-------+
     KERNEL
     STACK
     HEAP
     STATIC
     PROGRAM
    -------------

    clang puts the main() into the PROGRAM
    ./main executes it
    this hands off the main() to the STACK
    the return location (Rl) and variables are saved in the main() STACK
    once square() is called, it forms a function at the top of the STACK
    square() is now the more precedent function to run
    square also has a Rl as well as all its local variables
    STACK can only access one "box" at a time so once inside square() it can't access main() stuff
    once square() is done, it passes back to main() and square() is popped off the stack
    printf() is typically ignored when tracing through the stack
    once main() is done, it hands back to the operating system and the program ends
*/

/*
storage classes
    - the variables and functions we create have...
        - storage duration (how long do they exist in memory)
            - automatic:
                - temporary vars (parameter & local) last as long as that block of code is active
                - ie. for loops, the i only exists for that loop and ends at the brackets {}
                - the keyword auto is implied but rarely used
            - static:
                - static variables last for the entire program
                - global variables are defined before main()
        - scope (where the variable can be referrenced/acessed)
            - block scope:
                - guess what: you can access that variable through a block
            - file scope:
                - even crazier: you can access that variable throughout the file. wo.

*/