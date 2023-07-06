#include <stdio.h>
#include <stdlib.h>

int BS(int *a, int l, int u, int v) {
    int m;
    while (l <= u) {
        m = (l + u) / 2;
        if (a[m] == v)
            return m;

        if (v < a[m]) {
            u = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1; // if value not found
}

int main() {
    int MAX;
    printf("How many elements do you want to store in this array?\n");
    scanf("%d", &MAX);

    int *arr = (int *)malloc(MAX * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    int i;
    for (i = 0; i < MAX; i++) {
        printf("Enter the %dth number: ", i);
        scanf("%d", &arr[i]);
    }

    int value;
    printf("Enter the value you want to search for: ");
    scanf("%d", &value);

    int l = 0;
    int u = MAX - 1;
    int d = BS(arr, l, u, value);

    if (d == -1) {
        printf("The element is not found.\n");
    } else {
        printf("Value is found at index %d.\n", d);
    }

    free(arr);
    return 0;
}
