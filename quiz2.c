#include <stdio.h>
#include <stdlib.h>

// Function to perform circular right shift on sorted array
void circularRightShift(int A[], int n, int k) {
    if (n <= 1) return;

    // Normalize k to be within the range [0, n)
    k = k % n;

    // Allocate memory for the shifted array
    int shiftedArray = (int)malloc(n * sizeof(int));
    if (shiftedArray == NULL) {
        printf("Memory allocation failed");
        return;
    }

    // Copy the last k elements to the beginning of the shifted array
    for (int i = 0; i < k; i++) {
        shiftedArray[i] = A[n - k + i];
    }

    // Copy the first n-k elements to the remaining positions of the shifted array
    for (int i = k; i < n; i++) {
        shiftedArray[i] = A[i - k];
    }

    // Copy the shifted array back to the original array
    for (int i = 0; i < n; i++) {
        A[i] = shiftedArray[i];
    }

    // Free dynamically allocated memory
    free(shiftedArray);
}

int main() {
    int A[] = {5, 15, 29, 35, 42};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 2;

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    circularRightShift(A, n, k);

    printf("Shifted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
