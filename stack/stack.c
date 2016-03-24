#include <stdio.h>

#define MAXSIZE 10

int stack[MAXSIZE];
int top;


void init_stack () {
    top = -1;
}

int push(unsigned int val) {
    if (top >= MAXSIZE-1) {
        printf("Stack Overflow\n");
        return -1;
    }
    stack[++top] = val;
    return val;
}

int pop(void) {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void print_stack() {
    int i;
    printf ("Stack From Top-----> To Bottom\n");
    for (i = top; i>=0; i--)
        printf ("%-6d", stack[i]);
    puts("");
}

int main()
{
    int i;
    init_stack();

    printf("Push 5, 4, 7, 8, 2, 1\n");
    push(5);
    push(4);
    push(7);
    push(8);
    push(2);
    push(1);
    print_stack();

    puts("");
    printf("Pop\n");
    i = pop();
    print_stack();
    printf("popped value is %d\n", i);

    puts("");
    printf("Push 3, 2, 5, 7, 2\n");
    push(3);
    push(2);
    push(5);
    push(7);
    push(2);
    print_stack();

    puts("");
    printf("Now Stack is full, push 3\n");
    push(3);
    print_stack();

    puts("");
    printf("Initialize stack\n");
    init_stack();
    print_stack();

    puts("");
    printf("Now Stack is empty, pop\n");
    i = pop();
    print_stack();
    printf("popped value is %d\n", i);

    return 0;
}
