#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int top;
} CircularStack;

void init(CircularStack *stack) {
    stack->top = -1;
}

int isEmpty(CircularStack *stack) {
    return (stack->top == -1);
}

int isFull(CircularStack *stack) {
    return ((stack->top + 1) % MAX_SIZE == 0 && stack->top != -1);
}

void push(CircularStack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top = (stack->top + 1) % MAX_SIZE;
    stack->data[stack->top] = value;
}

int pop(CircularStack *stack) {
    int value;
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    value = stack->data[stack->top];
    stack->top = (stack->top - 1 + MAX_SIZE) % MAX_SIZE;
    return value;
}

int main() {
    CircularStack stack;
    init(&stack);
    int choice, value;

    do {
        printf("\nCircular Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 3);

    return 0;
}