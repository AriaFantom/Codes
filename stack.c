#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int value) {
    if (is_full(s)) {
        printf("Error: stack is full\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Error: stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

int main() {
    Stack s;
    init(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    while (!is_empty(&s)) {
        printf("%d\n", pop(&s));
    }

    return 0;
}
