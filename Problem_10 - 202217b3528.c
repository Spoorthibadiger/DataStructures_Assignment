#include <stdio.h>

void merge(int arr[], int beg, int mid, int end) {
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int left_half[n1], right_half[n2];

    for (int i = 0; i < n1; i++)
        left_half[i] = arr[beg + i];
    for (int j = 0; j < n2; j++)
        right_half[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = beg;
    while (i < n1 && j < n2) {
        if (left_half[i] <= right_half[j]) {
            arr[k] = left_half[i];
            i++;
        } else {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_half[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int beg, int end) {
    if (beg < end) {
        int mid = beg + (end - beg) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

int main() {
    int arr[] = {12, 31, 25, 8, 32, 17, 40, 42};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting array elements are -\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    merge_sort(arr, 0, n - 1);

    printf("After sorting array elements are -\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
