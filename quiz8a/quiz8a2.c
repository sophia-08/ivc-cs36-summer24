#include <stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    char data;
    struct ListNode* nextPtr;
} ListNode;

typedef struct Queue {
    int count;
    ListNode* start;
    ListNode* end;
} Queue;

Queue* enqueue(Queue*, char);
Queue* dequeue(Queue*);
void printQueue(Queue*);

int main(){
    //create queue
    Queue* qPtr = (Queue*)malloc(sizeof(Queue));
    if (qPtr == NULL) puts("error while creating");
    else{
        qPtr->start = NULL;
        qPtr->count = 0;
        qPtr->end = NULL;
    }

    //insert
    qPtr = enqueue(qPtr, 'w');
    qPtr = enqueue(qPtr, 'x');
    qPtr = enqueue(qPtr, 'y');
    qPtr = enqueue(qPtr, 'z');

    //print
    printQueue(qPtr);

    //delete
    qPtr = dequeue(qPtr);
    qPtr = dequeue(qPtr);

    //print
    printQueue(qPtr);
    puts("");
}

Queue* enqueue(Queue* q_insert, char to_be_added){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (!newNode) {puts("error in inserting");}
    else{
        newNode->data = to_be_added;
        newNode->nextPtr = NULL;

        if(q_insert->end == NULL){
            q_insert->start = newNode;
        }
        else{
            q_insert->end->nextPtr = newNode;
        }
        q_insert->end = newNode;
        q_insert->count++;

        newNode = NULL;
    }
    return q_insert;
}

Queue* dequeue(Queue* q_delete){
    if (q_delete->count == 0){
        return q_delete;
    }
    ListNode* old_top = q_delete->start;
    q_delete->start = old_top->nextPtr;
    q_delete->count--;
    free(old_top);
    old_top = NULL;
    if (q_delete->count == 0){
        q_delete->start = NULL;
        q_delete->end = NULL;
    }
    return q_delete;
}

void printQueue(Queue* q_print){
    ListNode* printPtr = q_print->start;
    printf("Queue with %d elements: ", q_print->count);
    while(printPtr != NULL){
        printf("%c -> ", printPtr->data);
        printPtr = printPtr->nextPtr;
    }
    puts("NULL");
}