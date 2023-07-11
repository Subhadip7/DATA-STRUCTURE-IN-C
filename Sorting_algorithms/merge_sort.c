#include<stdio.h>
#include<stdlib.h>

void merge_sort(int a[], int l, int u)
{
    if (l<u)
    {
        int m = (l+u)/2;
        merge_sort (a,l,m);
        merge_sort (a, m+1, u);

        merge(a,l,m,u);
    }
}
void merge (int *a, int l, int m, int u)
{
    int i, j;
    int * out = malloc(sizeof(int) * (u-l+1));
    i=l;
    j=m+1;
    int k=0;
    while (i<=m && i<=u)
    {
        if (a[i]<a[j])
        {
            out[k++]= a[i++];
        }
        else 
        {
            out[k++]=a[j++];
        }
    } 
    while (i<=m)
    {
        out[k++]=a[i++];
    }
    while (j<=u)
    {
        out[k++]=a[j++];
    }
    
    for (int x=0;x<k;x++)
    {
        a[l+x]=out[x];
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

   merge_sort (arr, 0, n-1);
    
    printf("After sorting:\n");
    print_array(arr, n);
}