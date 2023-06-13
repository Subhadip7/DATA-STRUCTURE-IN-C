#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node * cur ;
struct node * ptr;
struct node * head = NULL;
struct node * tail = NULL;


void createLinkedlist( struct node **h , int n)
{
 for (int i=0;i<n;i++)
 {
   cur = malloc (sizeof (struct node));
   printf("Enter the %d data : ", i);
   scanf ("%d",&cur->data);
   cur->next = NULL;
   if (*h == NULL)
   {
       *h= tail = cur;
   }
   else 
   {
     tail->next = cur;
     tail = cur;
   }
 }
}


void insertLinkedlist (struct node **h, int data , int pos)
{
  cur = malloc(sizeof(struct node));
  cur->data = data;
  cur->next = NULL;
  if (*h == NULL)
  {
    *h=cur;
  }
  else if (pos == 0)
  {
    cur->next = *h;
    *h = cur;
  }
  else
  {
    ptr=*h;
    int i=0;
    while (i<pos-1 && ptr->next != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    cur->next = ptr ->next;
    ptr -> next = cur;
  }
}

void delete (struct node **h, int v)
{
  struct node *ptr, * prev;
  if (*h == NULL)
  {
    printf("The Linked list is empty ");
  }
  else 
  {
    ptr = *h;
    while (ptr!=NULL)
    {
      if (ptr->data == v)
      break;
      else 
      prev = ptr;
      ptr = ptr->next;
    }
  }
  if (ptr == NULL)
  printf("Data is not found \n");
  else if (ptr == *h)
  {
    *h = ptr->next;
    free (ptr);
  }
  else
  {
    prev->next = ptr->next;
    free(ptr);
  }
}

void display (struct node **h)
{
 for (ptr=*h; ptr!=NULL;ptr=ptr->next)
 {
    printf("%d\n", ptr->data);
 }
 
}
int main(){
    int no,data;
    printf("Enter how many nodes you want to create : ");
    scanf("%d",&no);
    createLinkedlist(&head,no);
      insertLinkedlist (&head, 0, 0);
    insertLinkedlist (&head, 34, 2);
   printf("After insertion :\n");
    display (&head);
    printf ("which element you want to delete :\n");
    scanf("%d", &data);
    delete (&head,data);
    printf("After deletion :\n");
    display (&head);
    
}