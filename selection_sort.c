// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    
    // Traverse through the array
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in the unsorted part of the array
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }    
        // Swap the minimum element with the first element of the unsorted part
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[100] = {64, 25, 12, 22, 11};
    
    /**
     * Calculates the size of the array and assigns it to the variable 'n'.
     * 
     * @param arr The array for which the size needs to be calculated.
     * @return The size of the array.
     */
    int n = sizeof(arr)/sizeof(arr[0]);
    
    selectionSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
