#include <stdio.h>

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int n) {
    int i, j;
    int temp;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Flag to check if any swapping happened in this pass

        // Traverse the array from 0 to n-i-1
        for (j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set the flag to true, indicating a swap occurred
            }
        }

        // If no two elements were swapped by inner loop, then break
        if (swapped == 0) {
            break;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}