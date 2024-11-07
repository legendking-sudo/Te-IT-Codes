#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int start, int end, int key) {
    if (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) return mid;
        if (arr[mid] > key) return binary_search(arr, start, mid - 1, key);
        return binary_search(arr, mid + 1, end, key);
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No array passed from parent process\n");
        return 0;
    }

    // Convert the passed arguments to integers and store them in an array
    int size = argc - 1;
    int arr[size];
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    printf("Received Sorted Array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    // Get the number to search
    int key;
    printf("Enter the number to search: ");
    scanf("%d", &key);

    // Perform binary search
    int result = binary_search(arr, 0, size - 1, key);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
