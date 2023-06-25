#include<stdlib.h>
#include<stdio.h>
struct node {
    int val;
    struct node * next;
};
 typedef struct 
 {
    struct node * top;
 }STACK;
 int push (STACK * , int );
 int pop (STACK * , int * );
 void init (STACK *);

 void init (STACK *s)
 {
    s->top = NULL;
 }

 int push (STACK *s , int v)
 {
    struct node * cur;
    cur = malloc (sizeof (struct node));
    if (cur == NULL)
    {
        printf("Over-flow\n");
        return 1;
    }
    else 
    cur->val = v;
    cur->next = s->top;
    s->top = cur;
    return 0;
 }

int pop (STACK * s , int * data)
{
    if (s->top == NULL)
    {
        printf("Under-flow\n");
        return 1;
    }
    struct node * ptr;
    ptr = s->top ;
    s->top = s->top->next;
    *data = ptr->val;
    free (ptr);
    return 0;
}

int main()
{
    STACK s1;
    int t, nu,num;
    init (&s1);
    printf("How many values you want to insert: ");
    scanf("%d ", &nu);
    for (int i=0;i<nu;i++) 
    {
    printf("Enter the number : \n");
    scanf ("%d", &num);
    int k = push (&s1, num);
    if (k== 0 )
    {
        printf("Value is successfuly inserted \n");
    }
    }
    int j = pop (&s1, &t);
    if (j == 0)
    {
        printf("Deleted element is %d\n", t);
    }
}