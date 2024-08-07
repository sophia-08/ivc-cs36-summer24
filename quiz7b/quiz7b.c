#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    char data;
    struct ListNode* nextPtr;
} ListNode;

int main() {
    ListNode* startPtr = NULL;

    //insert a node to new list
    char val = 'a';
    ListNode* newPtr = (ListNode*)malloc(sizeof(ListNode));
    if (newPtr == NULL) return 1;

    newPtr->data = val;
    newPtr->nextPtr = NULL;
    startPtr = newPtr;
    newPtr = NULL;

    //insert a node to existing list
    val = 'b';
    newPtr = (ListNode*)malloc(sizeof(ListNode));
    if (newPtr == NULL) return 1;

    newPtr->data = val;
    newPtr->nextPtr = startPtr;
    startPtr = newPtr;
    // startPtr --> b --> a --> NULL

    //print a linked list
    printf("%s", "List is: ");
    ListNode* printPtr = startPtr;

    while (printPtr != NULL){
        printf("%c -> ", printPtr->data);
        printPtr = printPtr->nextPtr;
    }
    puts("null");

    // delete first node
    char vToDel = 'b';

    if (vToDel == startPtr->data){
        ListNode* tempPtr = startPtr;
        startPtr = startPtr->nextPtr;
        free(tempPtr);
        tempPtr = NULL;
    }

    //delete not first node
    else {
        ListNode* prevPtr = startPtr;
        ListNode* currPtr = startPtr->nextPtr;
        
        while(currPtr != NULL && currPtr->data != vToDel){
            prevPtr = currPtr;
            currPtr = currPtr->nextPtr;
        }

        if (currPtr != NULL){
            ListNode* tempPtr = currPtr;
            prevPtr->nextPtr = currPtr->nextPtr;
            currPtr = currPtr->nextPtr;
            free(tempPtr);
            tempPtr = NULL;
        }
    }

    //print again
    printf("%s", "List w/o b is: ");
    printPtr = startPtr;

    while (printPtr != NULL){
        printf("%c -> ", printPtr->data);
        printPtr = printPtr->nextPtr;
    }
    puts("null");
}