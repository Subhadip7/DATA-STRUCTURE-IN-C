#include<stdio.h>


int LS (int a[], int size , int v )
{
    for (int j=0;j<size;j++)
    {
        if (a[j]== v)
        return j;
    }
    return -1;
}
int main(){
    int MAX;
    int value;
    printf("How many elements you want to store in this array\n");
    scanf("%d", &MAX);
    int arr[MAX];
    int i;
    for (i=0;i<MAX;i++)
    {
        printf("Enter the %d th number:", i);
        scanf("%d", &arr [i]);
    }
    printf("Enter the value which element you want to search :\n");
    scanf("%d", &value);
   int x= LS(arr, MAX, value);
   if (x==-1 )
   {
    printf("The element is not found \n");
   }
   else
   {
    printf("Value is found in %d index location ", x);
   }
}