#include<stdio.h>


void swap(int * a, int *b )
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition (int *a, int i, int j)
{   
    int l = i;
    int u = j;
    int piv = a[l];
    while (l<u)
    {
        while (a[l]<= piv && l<j)
        {
            l++;
        }
        while (a[u]>=piv && u>i) // add this condition
        {
           u--;
        }
       if (l<u)
       {
        swap (&a[l],&a[u]);
       }    
    }
// when l>u  then swap u and pivot which is basically a[i]
  swap (&a[i],&a[u] );

  return u; // return the partitioning position


}


void Quick_sort (int *a, int l , int u)
{
    if (l<u) //Quick_sort works when its greater than 2 elements
    {
        int pos = partition (a,l,u);
        Quick_sort (a,l,pos-1);
        Quick_sort(a,pos+1,u);
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

  Quick_sort (arr, 0, n-1);
    
    printf("After sorting:\n");
    print_array(arr, n);
    printf("\n");
    return 0;
}