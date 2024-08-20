#include <stdio.h>
#include "stack.h"

int main(void) {

    Stack s1, s2;
    char* s1_n = "s1";
    char* s2_n = "s2";
    int n = 0;

    s1 = create();
    puts("\nStack s1 created");
    s2 = create();
    puts("Stack s2 created\n");

    push(s1, 1);
    printf("%s", "Push 1 on s1\n");
    
    push(s1, 2);
    printf("%s", "Push 2 on s1\n");
    printStack(s1, s1_n);

    
    n = pop(s1);
    printf("\n\nPopped %d from s1\n", n);
    printStack(s1, s1_n);

    push(s2, n);
    printf("%s", "\n\nPush 2 on s2\n");
    printStack(s2, s2_n);

    n = pop(s1);
    printf("\n\nPopped %d from s1\n", n);
    printStack(s1, s1_n);
    
    push(s2, n);
    printf("%s", "\nPush 1 on s2\n");
    printStack(s2, s2_n);

    destroy(s1);
    puts("\n\ns1 destroyed\n");

    while (!is_empty(s2)) {
        printf("Popped %d from s2\n", pop(s2));
    }

    destroy(s2);
    puts("\ns2 destroyed\n");
}