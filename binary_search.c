#include <stdio.h>

/**
 * Performs a binary search on a sorted array to find the index of a given element.
 *
 * @param arr The sorted array to search in.
 * @param first The index of the first element in the array.
 * @param last The index of the last element in the array.
 * @param x The element to search for.
 * @return The index of the element if found, -1 otherwise.
 */
int binarySearch(int arr[], int first, int last, int x)
{
    /**
     * Performs binary search on a sorted array to find the index of a given element.
     *
     * @param arr The sorted array to search in.
     * @param first The starting index of the search range.
     * @param last The ending index of the search range.
     * @param x The element to search for.
     * @return The index of the element if found, -1 otherwise.
     */
    while (first <= last)
    {
        // Calculate the middle index of the search range
        int mid = first + (last - first) / 2;

        // If the middle element is equal to the target element, return its index
        if (arr[mid] == x)
            return mid;

        // If the middle element is less than the target element, update the search range to the right half
        if (arr[mid] < x)
        {
            first = mid + 1;
        }
        // If the middle element is greater than the target element, update the search range to the left half
        else
        {
            last = mid - 1;
        }
    }

    return -1;
}

int main()
{
    /**
     * @brief An array of integers used for binary search.
     */
    int arr[] = {2, 3, 4, 10, 40};

    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    /**
     * This code snippet prompts the user to enter an element and stores it in the variable 'x'.
     *
     * @param x The variable to store the user input.
     */
    int x;
    printf("Enter the element");
    scanf("%d", &x);

    /**
     * Performs a binary search on a sorted array to find the index of a given element.
     *
     * @param arr The sorted array to search in.
     * @param first The index of the first element in the array.
     * @param last The index of the last element in the array.
     * @param x The element to search for.
     * @return The index of the element if found, -1 otherwise.
     */
    int last = n - 1;
    int first = 0;
    int result = binarySearch(arr, first, last, x);

    // Check if the result of the binary search is -1 or not
    if (result == -1)
    {
        printf("Element is not present in array");
    }
    else
    {
        printf("Element is present at index %d", result);
    }
    return 0;
}
