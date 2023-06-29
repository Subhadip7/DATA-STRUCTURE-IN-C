#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node * next;
};
typedef struct {
    struct node * f;
    struct node *r ;
}CQueue;

void init (CQueue * q){
    q->f = q->r = NULL;
}


int insert (CQueue *q , int d)
{
   struct node * cur;
   cur = malloc (sizeof(struct node));
   if (cur == NULL) return 1;
   cur->val=d;
   if (q->r== NULL) 
   {
    cur->next=cur;
    q->r = cur;
   } 
   else 
   {
    cur->next = q->r->next;
    q->r->next = cur;
    q->r = cur;
   }
  
   q->f = q->r->next;
    return 0;
}
int delete (CQueue *q , int * d)
{
    if (q->r== NULL) return 1;
   
       else if (q->f == q->r) // (q->r->next == q->r)
        {
        *d = q->f->val;
        free (q->f);
        q->f= q->r = NULL;
        }
   
   else 
   {
    struct node * ptr = q->f;
    *d = ptr->val;
    q->r->next = q->f->next;
    free(ptr);
    q->f =  q->r->next;
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
