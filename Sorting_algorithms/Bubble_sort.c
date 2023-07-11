#include<stdio.h>

void swap(int * a, int *b )
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void Bubble_sort (int a[], int n)
{
  int i,j;
  for (i=0;i<n-1;i++)
   {
    int flag =0;
    for (j=0;j<n-i-1;j++)
   // n-i-1 (-i ) is because after each itaration the higest element is going to the last , so we can skip the last element because it's already gone its right postion
   
    {
        if (a[j]>a[j+1])
        swap (&a[j], &a[j+1]);
        flag = 1;
        // here the importance of flag is when there is no swap that means the elements are alreday sorted so, why looping further
    }
    if (flag == 0) break;
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

    Bubble_sort (arr, n);
    /* For Bubble Sort, the worst-case scenario has a time complexity of O(n^2), 
    where n is the number of elements. The number of iterations can be roughly n-1 in the worst-case scenario.*/
    printf("After sorting:\n");
    print_array(arr, n);
}