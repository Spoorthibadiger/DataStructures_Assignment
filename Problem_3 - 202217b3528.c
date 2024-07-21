#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

// Function declarations
void push(int stack[], int *top, int element);
int pop(int stack[], int *top);
void display_stack(int stack[], int top);

int main() {
    int stack[STACK_SIZE];
    int top = -1;
    int choice, element;

    while (1) {
        printf("\nSTACK OPERATIONS USING ARRAY\n");
        printf("-------------------------------\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        printf("Enter the Choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to be pushed:");
                scanf("%d", &element);
                push(stack, &top, element);
                break;
            case 2:
                element = pop(stack, &top);
                if (element != -1) {
                    printf("The popped elements is %d\n", element);
                }
                break;
            case 3:
                display_stack(stack, top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to push an element onto the stack
void push(int stack[], int *top, int element) {
    if (*top == STACK_SIZE - 1) {
        printf("Stack overflow! Cannot push %d onto the stack.\n", element);
    } else {
        stack[++(*top)] = element;
        printf("%d pushed onto the stack.\n", element);
    }
}

// Function to pop an element from the stack
int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack underflow! Cannot pop from the stack.\n");
        return -1;
    } else {
        return stack[(*top)--];
    }
}

// Function to display the elements of the stack
void display_stack(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("The elements in STACK\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
        printf("Press Next Choice\n");
    }
}