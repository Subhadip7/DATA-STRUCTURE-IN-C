#include<stdio.h>
#define MAX 8
#include<stdlib.h>
typedef struct {
    int data[MAX];
    int f;
    int R;
} CQueue;

void init (CQueue *q)
{
    q->f = q->R = -1;
}

int insert (CQueue *q , int v)
{
    // this is the case when queue is full
    if (q->f == (q->R+1)%MAX)
    return 1;
    // This is the case when queue is empty
    if (q->R == -1)
    {
        q->f = q->R = 0;
        q->data[q->R]=v;
    }
    else
    { 
        // Normal case but when R is at the last then next time it will come at the front 
        q->R = (q->R+1)% MAX;
        q->data[q->R]= v;
    }
    return 0;
}
int delete (CQueue *q, int *d)
{
    // This is the case no element is present
    if (q->f == -1)
    return 1;
    // This is the case where one element is present
    if (q->f == q->R)
    {
        *d = q->data[q->f];
        q->f = q->R = -1;
    }
    else //Normal case but suppose f is at the last node after last node deletion f has to come at the begining
    {

        *d = q->data[q->f];
        q->f = (q->f+1)%MAX;
    }
    return 0;
}

int main(){
    CQueue q1;
    int d,no,val;
    init (&q1);
   printf("how many values you want to insert : \n");
   scanf("%d", &no);
   for (int j=0;j<no;j++){
    printf("Enter the %d value \n", j);
    scanf("%d", &val);
    int k = insert (&q1, val);
    if (k==0)
      printf("the value is successfuly inserted\n");
    else
      printf("The value is not inserted\n");
   }
    int p = delete (&q1, &d);
    if (p==0){
     printf("Deleted element is %d ", d );
    }

}