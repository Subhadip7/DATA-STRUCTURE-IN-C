#include<stdio.h>
void insertion_sort (int arr[], int n)
{
    int i,tmp, j;
    for (i=1;i<n;i++)
    {
        tmp=arr[i];
        for (  j = i-1; j >= 0; j--)
        {
           if (arr[j]>tmp)
            arr[j+1]=arr[j];
            else 
            break;
        }
        arr[j+1]=tmp;
        
    }
}
void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main(){
    int arr[]={4,6,1,0,5,2,432};
    int n = sizeof (arr)/ sizeof (arr[0]);
    printf("Original array is : \n");
    print_array (arr, n);

    insertion_sort (arr, n);
    /* The time complexity of the Insertion Sort algorithm is O(n^2) in the worst-case scenario and average-case scenario.
     It has a best-case time complexity of O(n) when the array is already sorted or nearly sorted.*/
    printf("After sorting:\n");
    print_array(arr, n);
}