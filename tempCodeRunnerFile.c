#include<stdio.h>
void rightShiftArray(int arr[], int n, int shift) {
    // Shift the elements by "shift" positions to the right
    for (int i = n-1; i >= shift; i--) {
        arr[i] = arr[i-shift];
    }

    // Fill the empty spaces at the beginning of the array with 0's
    for (int i = 0; i < shift; i++) {
        arr[i] = 0;
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int shift = 2;

    rightShiftArray(arr, n, shift);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
