#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Global variables
int my_list[MAX_SIZE];
int size = 0;

// Function declarations
void insert_element(int number, int position);
void delete_element(int number);
void display_list();

int main() {
    int option, number, position;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &number);
                if (size == 0) {
                    my_list[0] = number;
                    size++;
                    printf("Inserted %d as the first element.\n", number);
                } else if (size >= MAX_SIZE) {
                    printf("The list is full.\n");
                } else {
                    printf("Enter the position to insert (0 to %d): ", size);
                    scanf("%d", &position);
                    insert_element(number, position);
                }
                break;
            case 2:
                if (size == 0) {
                    printf("The list is empty.\n");
                } else {
                    printf("Enter the number to delete: ");
                    scanf("%d", &number);
                    delete_element(number);
                }
                break;
            case 3:
                display_list();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}

// Function definitions

void insert_element(int number, int position) {
    if (position < 0 || position > size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = size; i > position; i--) {
        my_list[i] = my_list[i - 1];
    }
    my_list[position] = number;
    size++;
    printf("Inserted %d at position %d.\n", number, position);
}

void delete_element(int number) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (my_list[i] == number) {
            found = 1;
            for (int j = i; j < size - 1; j++) {
                my_list[j] = my_list[j + 1];
            }
            size--;
            printf("Deleted %d from the list.\n", number);
            break;
        }
    }
    if (!found) {
        printf("%d not found in the list.\n", number);
    }
}

void display_list() {
    if (size == 0) {
        printf("The list is empty.\n");
    } else {
        printf("List elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", my_list[i]);
        }
        printf("\n");
    }
}