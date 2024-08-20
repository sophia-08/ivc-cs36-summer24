#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    char data;
    struct ListNode* nextPtr;
} ListNode;

typedef struct Stack {
    int count;
    struct ListNode* start;
} Stack;

Stack* push(Stack*, char);
Stack* pop(Stack*);
void printStack(Stack*);

int main(){
    //create stack
    Stack* stackPtr = (Stack*)malloc(sizeof(Stack));
    if (!stackPtr) puts("error in creation :(");
    else{
        stackPtr->count = 0;
        stackPtr->start = NULL;
    }

    //insert several nodes
    stackPtr = push(stackPtr, 'a');
    stackPtr = push(stackPtr, 'b');
    stackPtr = push(stackPtr, 'c');
    stackPtr = push(stackPtr, 'd');

    //print
    printStack(stackPtr);

    //delete
    stackPtr = pop(stackPtr);
    stackPtr = pop(stackPtr);

    //print
    printStack(stackPtr);
    puts("");
}

Stack* push(Stack* s_push, char to_be_added){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (!newNode) puts("error with pushing :(");
    else{
        newNode->data = to_be_added;
        newNode->nextPtr = s_push->start;

        s_push->start = newNode;
        s_push->count++;

        newNode = NULL;
    }
    return s_push;
}

Stack* pop(Stack* s_pop){
    // ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (s_pop->start == NULL){
        return s_pop;
    }
    else{
        ListNode* old_ptr = s_pop->start;
        s_pop->start = old_ptr->nextPtr;
        s_pop->count--;
        old_ptr = NULL;
        free(old_ptr);
        return s_pop;
    }
}

void printStack(Stack* s_print){
    ListNode* printPtr = s_print->start;
    printf("Stack with %d elements: ", s_print->count);
    while (printPtr != NULL){
        printf("%c -> ", printPtr->data);
        printPtr = printPtr->nextPtr;
    }
    puts("NULL");
}