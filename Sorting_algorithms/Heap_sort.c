#include<stdio.h>

void swap (int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void max_heapify (int * a, int i, int n)
{
   int lc = 2*i + 1;
   int rc = 2*i + 2;
   int max = i;
   if (lc < n && a[max] < a[lc])
    max = lc;
   if (rc < n && a[max] < a[rc])
    max = rc;
 if (i!=max)
 {
    swap (&a[i], &a[max]);
    max_heapify(a, max, n);
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
    int arr[]={4, 6, 1, 0, 5, 2, 432};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array is: \n");
    printArray(arr, n);

    for (int i=n/2;i>=0;i--)
    {
          max_heapify(arr, i, n);
    }
 
 while (n>1) // till last element 
 {
    swap (&arr[0],&arr[n-1]);
    //after max_heap the first element is the highest among all 
    max_heapify(arr,0,n-1);
    n--;
    // Because after each itaration the last element is going at the last where it deseves.
 }

    printf("After sorting: \n");
    printArray(arr, sizeof(arr));
}