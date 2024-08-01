#include <stdio.h>

struct card {
    char* face; //defines a pointer
    char* suit;
}; //remember a semicolon!!

struct employee {
    char first[20];
    char last[20];
    double hourlySalary;
    struct employee* teamLeaderPtr; //self-referential struct
    struct { //anonymous struct - a "variable" inside another struct
        int deptID;
        int workHours;
    };
};
typedef struct employee Employee; //allows an alias for "struct employee"
//you can just say Employee instead of "struct employee"
//convention is to captilize aliases

typedef struct {
    char firstName[20];
} Manager;
//^most common way of merging aliases and struct def

typedef union {
    int x;
    double y;
} Number;
//unions are the same as structs except the variables share one memory loc
//unions can be assigned to another union of the same type
//can be accessed the same way as structs
//can't be compared with ==

typedef struct {
    int x;
    int y;
    int z;
} Point;

struct listNode {
    int data;
    struct listNode* nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode* ListNodePtr;

int main(){
    struct card aCard; //defines a "struct card" variable
    aCard.face = "Ace"; //dot notation
    aCard.suit = "Spades";

    struct card* cardPtr = &aCard; //assign address of acard to cardPtr
    printf("%s, %s\n%s, %s\n%s, %s\n", aCard.face, aCard.suit, cardPtr->face, cardPtr->suit, (*cardPtr).face, (*cardPtr).suit);
    // ^ three different ways to access face and suit

    struct employee susan = {"Susan", "Bop", 55.0};
    Employee tony = {"Tony"}; //initializes the other stuff to null or 0 or whatever

    Number value; //8 bytes (as big as the biggest type (double))
    value.x = 100;
    value.y = 123.0; //now that y has been set, x is now undefined    

    Point origin = {0, 0, 0}; //struct variables are created on the stack
    //we want them in the heap tho since they can get very big
    //so instead...
    Point* pointPtr = malloc(sizeof(Point));
    //can be accessed the same way with -> and (*ptr).

    ListNodePtr startPtr = NULL;
    ListNodePtr newPtr = malloc(sizeof(ListNode));
    newPtr->data = 5;
    newPtr->nextPtr = NULL;
    startPtr = newPtr;
}