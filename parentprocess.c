#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int size, arr[20];
    char *p[25], buff[20];

    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        snprintf(buff, 20, "%d", arr[i]);
        p[i + 1] = strdup(buff);  // Convert to string for child
    }
    p[0] = "childprocess";  // Name of the child process executable
    p[size + 1] = NULL;     // End of arguments

    execv("./childprocess", p);  // Execute child process

    return 0;
}
