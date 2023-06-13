#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node * prev;
    int data;
    struct node * next;

};
struct node * head = NULL;
struct node * tail = NULL;
void create ( struct node ** h , int n)
{
    struct node * cur;
 for (int i=0;i<n;i++)
 {
   cur = malloc (sizeof(struct node));
   printf("Enter the value :");
   scanf("%d", &cur->data);
   cur->prev = cur->next = NULL;
   if (*h == NULL)
   {
    *h = tail = cur;
   }
   else 
   {
    cur->prev = tail;
    tail->next = cur;
    tail = cur;
   }
 }   
}


void display (struct node * h)
{
    struct node * tmp = h;
    while (tmp!=NULL){
        printf("%d\n",tmp->data);
        tmp=tmp->next;
    }
}

void insert (struct node ** h, int val, int pos)
{
  struct node * cur, *ptr;
  cur = malloc(sizeof (struct node));
  cur->data = val;
  cur->prev=cur->next=NULL;
  if (*h==NULL)
  {
    *h = cur;
  }
  else if (pos == 0)
  {
    cur->next = *h;
    (*h)->prev = cur;
    *h = cur;
  }
  else 
  {
    ptr = *h;
    int i = 0;
    while (i<pos-1 && ptr->next != NULL)
    {
        i++;
        ptr = ptr->next;
    }
    // if ptr goes at the last then 
    if (ptr->next == NULL)
    {
        cur->prev = ptr;
        ptr->next = cur;
    }
    else 
    // If ptr is not present at the last then 
    {
      cur->prev = ptr;
      cur->next = ptr->next;
      cur->next->prev = cur;
      ptr->next = cur;
    }
  }
}
void delete (struct node **h , int val )
{
    struct node * ptr;
    if (*h == NULL)
    printf("The list is empty\n");
    else {
        ptr = *h;
        while (ptr!=NULL)
        {
            if (ptr->data == val)
            break;
            ptr = ptr ->next;
        }
        if (ptr == NULL)
        printf("Data is not found \n");
        else if (*h == ptr && ptr->next == NULL) // if only one node is present
        {
            head = NULL;
            free (ptr);
        }
        else if ( *h == ptr) // first node 
        {
            *h = (*h)->next;
            (*h)->prev = NULL;
            free (ptr);
        }
        else if ( ptr ->next == NULL) // last node
        {
            ptr ->prev ->next = NULL;
            free (ptr);
        }
        else
        {
            // middle any node
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free (ptr);

        }
    }
}


int main(){
    int no,p,data,data1;
    printf("Enter how many nodes you want to create : ");
    
    scanf("%d", &no);
    printf("Enter the number you want to insert and which position ");
    scanf ("%d %d", &data, &p);


    create (&head, no);
    display (head);
    insert (&head,data,p);
    printf("AFter insertion:\n");
    display (head);
    printf("Which element you want to delete : \n");
    scanf("%d", &data1);
    delete (&head, data1);
    printf("After deletion \n");
    display(head);
}