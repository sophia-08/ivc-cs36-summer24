#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct node {
    int data;
    struct node* next;
} Node;

struct stack {
    Node* top;
};

static void terminate(const char* message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(void) {
    Stack s = (Stack)malloc(sizeof(struct stack));
    if (s == NULL) {
        terminate("Error");
    }
    s->top = NULL;
    return s;
}

void destroy(Stack s) {
    make_empty(s);
    free(s);
}

void make_empty(Stack s) {
    while (!is_empty(s)) {
        pop(s);
    }
}
bool is_empty(Stack s) {
    return s->top == NULL;
}

bool is_full(Stack s) {
    return false; // only full if heap is full!
}

void push(Stack s, int i) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        terminate("Stack Full, cannot push\n");
    }
    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(Stack s) {
    Node* old_top;
    int i = 0;

    if (is_empty(s)) {
        terminate("Stack is empty, cannot pop\n");
    }

    old_top = s->top;
    i = old_top->data;
    s->top = old_top->next;
    free(old_top);
    return i;
}

void printStack(Stack s, char* n) {
    // First check if Stack is empty
    if (is_empty(s)){
        printf("%c%c -> empty\n", *n, n[1]);
        return;
    }

    // if not, create pointer to traverse a linked list
    Node* temp_node = (Node*)malloc(sizeof(Node));
    temp_node = s->top;

    // print name of stack char* n
    printf("%c%c", n[0], n[1]);

    // traverse linked list, printing all data values
    while(temp_node != NULL){
        printf(" -> %d", temp_node->data);
        temp_node=temp_node->next;
    }

    // you may need to print one last node's data
    free(temp_node);

}