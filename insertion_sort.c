#include <stdio.h>

/**
 * Sorts an array in ascending order using the insertion sort algorithm.
 *
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void insertionSort(int arr[], int n) {
  
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

/**
 * Prints the elements of an array.
 *
 * @param arr The array to be printed.
 * @param n The number of elements in the array.
 */
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/**
 * The main function.
 */
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Array after sorting: \n");
    printArray(arr, n);

    return 0;
}
