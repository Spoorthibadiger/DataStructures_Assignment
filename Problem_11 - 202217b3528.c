#include <stdio.h>

// Function to perform linear search
int linearSearch(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    int array[] = {10, 2, 8, 5, 17};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 8;

    int result = linearSearch(array, size, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
        printf("The element '%d' was found in this instance by the linear search technique at index %d of the array.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}