#include<stdio.h>
#include<stdlib.h>
#define MAX 6
typedef struct {
    int data [MAX];
    int top;
} STACK;
int push (STACK * , int);
int pop (STACK * , int *);

int push (STACK *s , int val )
{
    if (s->top == MAX-1)
    {
        printf("Overflow \n");
        return 1;
    }
    s->top ++;
    s->data[s->top]= val;
    return 0;
}

int pop (STACK *s , int *val)
{
 if (s->top == -1)
  {
    printf("Under-flow\n");
    return 1;
  }
  *val = s->data[s->top];
  s->top --;
  return 0;
}

int main()
{
    STACK s1;
    s1.top = -1;
    int k, v, nu,num;
    printf ("How many numbers you want to push : \n");
    scanf("%d", &nu);
    for (int j =0;j<nu;j++)
    {
        printf ("Enter the number :\n");
        scanf("%d" , &num);
    k = push (&s1,num);
    }
    k = pop (&s1, &v);
    if (k==0){
        printf("Deleted element is %d", v );
    }

}