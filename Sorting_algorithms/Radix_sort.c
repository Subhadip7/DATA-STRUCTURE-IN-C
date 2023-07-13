#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum element from the array
int getMax(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Using counting sort to sort the elements based on significant place
void countingSort(int array[], int size, int place) {
    const int max = 10; // Radix of decimal number system
    int* output = (int*)malloc(size * sizeof(int));
    int* count = (int*)malloc(max * sizeof(int));

    for (int i = 0; i < max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[(array[i] / place) % 10]++;
    }

    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(output);
    free(count);
}

// Radix Sort function
void radixSort(int array[], int size) {
    int max = getMax(array, size);

    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(array, size, place);
    }
}

// Function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Test the radix sort algorithm
int main() {
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    printArray(array, size);

    radixSort(array, size);

    printf("Sorted array: ");
    printArray(array, size);

    return 0;
}
