#include <array>
#include <stdio.h>
#include <stdlib.h>

bool swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return true;
}

int* bubbleSort(int arr[], int size) { //O(n^2)
    bool swapped; // we use a flag variable to check if a swap has been made in the current iteration

    for (int i = 0; i < size - 1; i++) {
        swapped = false;

        for (int j = 0; j < size - i- 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapped = swap( &arr[j], &arr[j + 1]); // call the swap function, set the flag as the return value which tells you if it was successful
            }
        }

        if (!swapped)
            break;
    }

    return arr;
}

int* selectionSort(int arr[], int size) { //O(n^2)
    int min;

    for (int i = 0; i < size - 1; i++) {
        min = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;    //if a new maximum is found, set the minimum pointer to equal 'j'
            }
        }

        swap(&arr[min], &arr[i]); //call the swap function, swaps the minimum pointer with the pointer set by 'i'
    }

    return arr;
}

int* insertionSort(int arr[], int size) {   //O(n^2)
    int temp = 0;
    int j = 0;

    for (int i = 0; i < size; i++) {    //the forwards loop checks each element of the array
        temp = arr[i];
        j = i;
        while (j > 0 && arr[j - 1] > temp) {    //the backwards loop steps back through the array and checks the preceeding elements for swaps
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }

    return arr;
}

int main() {
    int arr[] = { 0, 10, 9, -1, 2, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int* barr = insertionSort(arr, size);

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", barr[i]);
    }

    return 0;
}