#include<stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *a, int l, int u)
{
    int piv = a[u];
    int i = l - 1;

    for (int j = l; j <= u - 1; j++) {
        if (a[j] < piv) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[u]);

    return i + 1;
}

void quickSort(int *a, int l, int u)
{
    if (l < u) {
        int pos = partition(a, l, u);
        quickSort(a, l, pos - 1);
        quickSort(a, pos + 1, u);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {4, 6, 1, 0, 5, 2, 432};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array is: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("After sorting: \n");
    printArray(arr, n);

    return 0;
}
