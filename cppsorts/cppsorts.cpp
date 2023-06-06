#include <array>
#include <stdio.h>
#include <stdlib.h>

bool swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return true;
}

int* bubbleSort(int arr[], int size) {
    bool swapped; // we use a flag variable to check if a swap has been made in
                  // the current iteration

    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i- 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapped = swap(
                    &arr[j],
                    &arr[j + 1]); // call the swap function, set the flag as the return
                                  // value which tells you if it was successful
            }
        }

        if (!swapped)
            break;
    }

    return arr;
}

int* selectionSort(int arr[], int size) {
    int min;
    for (int i = 0; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }

    return arr;
}

int main() {
    int arr[] = { 0, 10, 9, -1, 2, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int* barr = selectionSort(arr, size);

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", barr[i]);
    }

    return 0;
}