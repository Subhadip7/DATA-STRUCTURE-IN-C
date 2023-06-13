#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
void insert (struct node ** h , int d){
    struct node * cur;
    struct node * ptr;
    cur = malloc (sizeof (struct node));
    cur->next = NULL;
    cur->data = d;
 if ( *h == NULL)
 {
    *h=cur;
 }
 else 
 {
    ptr = *h;
    while (ptr-> next !=NULL) 
    {
     ptr = ptr -> next;
    }
    ptr->next = cur;
  }
 }
 void display (struct node *h)
 {
  for ( ;h!=NULL; h=h->next)
  {
    printf("%d\n", h->data);
  }
 }

int main(){
 struct node * head = NULL;
 int i, no;
 printf("Enter how many nodes you want to create : ");
 scanf("%d",&no);
 for (i=0;i<no;i++){
    insert (&head, i+1);
 }
 display (head);
}
