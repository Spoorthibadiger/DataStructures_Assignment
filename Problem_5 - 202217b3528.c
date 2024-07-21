#include <stdio.h>
#define SIZE 5

void insert(int queue[], int *rear, int element) {
    if (*rear < SIZE - 1) {
        *rear += 1;
        queue[*rear] = element;
    } else {
        printf("Queue is full\n");
    }
}

void delete(int queue[], int *front, int *rear) {
    if (*rear < *front) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted Element is %d\n", queue[*front]);
        for (int i = *front; i < *rear; i++) {
            queue[i] = queue[i + 1];
        }
        queue[*rear] = 0;
        *rear -= 1;
    }
}

void display(int queue[], int front, int rear) {
    if (front <= rear) {
        printf("Queue Elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    } else {
        printf("Queue is empty\n");
    }
}

int main() {
    int queue[SIZE] = {0};
    int front = 0;
    int rear = -1;
    int choice, element;

    while (1) {
        printf("\nQueue using Array\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter the Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rear < SIZE - 1) {
                    printf("Enter no %d: ", rear + 2);  // Display the next insertion position
                    scanf("%d", &element);
                    insert(queue, &rear, element);
                } else {
                    printf("Queue is full\n");
                }
                break;

            case 2:
                delete(queue, &front, &rear);
                break;

            case 3:
                display(queue, front, rear);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}