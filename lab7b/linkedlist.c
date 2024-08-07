#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    char data;
    struct ListNode* nextPtr;
} ListNode;

ListNode* insertNode(ListNode*, char);
ListNode* deleteNode(ListNode*, char);
void printList(ListNode*);

int main(void) {

    ListNode* startPtr = NULL;

    // Insert first node
    char value = 'e';
    ListNode* newPtr = (ListNode*)malloc(sizeof(ListNode));
    if (newPtr == NULL) { return 1; }

    newPtr->data = value;
    newPtr->nextPtr = NULL;
    startPtr = newPtr;
    newPtr = NULL;

    // Insert node into existing list
    startPtr = insertNode(startPtr, 'd');
    startPtr = insertNode(startPtr, 'c');
    startPtr = insertNode(startPtr, 'b');
    startPtr = insertNode(startPtr, 'a');

    // Print list
    // printf("\n            Full list: ");
    printList(startPtr);

    // Delete first node
    startPtr = deleteNode(startPtr, 'd');

    // Print list
    // printf("\nList with 'd' removed: ");
    printList(startPtr);
    puts("");
}
    
ListNode* insertNode(ListNode* startPtr, char value){
    ListNode* newPtr = (ListNode*)malloc(sizeof(ListNode));
    if (newPtr == NULL) {puts("error");}

    newPtr->data = value;
    newPtr->nextPtr = startPtr;
    startPtr = newPtr;
    newPtr = NULL;

    return startPtr;
}

ListNode* deleteNode(ListNode* startPtr, char vToDel){
    if (vToDel == startPtr->data) {
        ListNode* tempPtr = startPtr;
        startPtr = startPtr->nextPtr;
        free(tempPtr);
        tempPtr = NULL;
        return startPtr;
    }
        
    // Delete node if not first
    else {
        ListNode* prevPtr = startPtr;
        ListNode* currPtr = startPtr->nextPtr;

        while (currPtr != NULL && currPtr->data != vToDel) {
            prevPtr = currPtr;
            currPtr = currPtr->nextPtr;
        }
        if (currPtr != NULL) {
            ListNode* tempPtr = currPtr;
            prevPtr->nextPtr = currPtr->nextPtr;
            currPtr = currPtr->nextPtr;
            free(tempPtr);
            tempPtr = NULL;
        }
        return startPtr;
    }
}

void printList(ListNode* startPtr){
    ListNode* printerPtr = startPtr;
    printf("startPtr -> ");
    while (printerPtr != NULL) {
        printf("%c -> ", printerPtr->data);
        printerPtr = printerPtr->nextPtr;
    }
    puts("NULL");
}