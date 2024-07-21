#include <stdio.h>

// Function to find the smallest element in the array from index i to n-1
int smallest(int arr[], int i, int n) {
    int small = arr[i];
    int pos = i;
    for (int j = i + 1; j < n; j++) {
        if (small > arr[j]) {
            small = arr[j];
            pos = j;
        }
    }
    return pos;
}

// Function to perform selection sort
void selection_sort(int arr[], int n) {
    int pos;
    for (int i = 0; i < n - 1; i++) {
        pos = smallest(arr, i, n);
        // Swap arr[i] with arr[pos]
        int temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 34};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting array elements are -\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    selection_sort(arr, n);

    printf("After sorting array elements are -\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
