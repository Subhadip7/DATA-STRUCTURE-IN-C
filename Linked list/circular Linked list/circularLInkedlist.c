#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node * head = NULL;
/***
void createLinkedlist (struct node **h, int no)
{
    int val;
    struct node * cur, *ptr;
    for (int i =0 ;i<no ;i++)
    {
        cur = malloc (sizeof (struct node));
        cur->next=NULL;
        printf("Enter the data : ");
        scanf("%d", &val);

        cur->data = val;

        if (*h==NULL)
        {
            *h = cur;
            cur->next = *h;
        }
        else
        {
           ptr = *h;
           while (ptr->next!=*h)
           {
            ptr = ptr->next;
           }
           ptr->next = cur;
           cur->next = *h;
           *h = cur;
        }
    }
}** */

void createLinkedlist(struct node **h, int no) {
    int val;
    struct node *cur, *ptr;
    struct node *prev = NULL;  // track the previous node

    for (int i = 0; i < no; i++) {
        cur = malloc(sizeof(struct node));
        cur->next = NULL;
        printf("Enter the data: ");
        scanf("%d", &val);

        cur->data = val;

        if (*h == NULL) {
            *h = cur;
            cur->next = *h;
            prev = cur;  // set prev to the first node
        } else {
            prev->next = cur;
            cur->next = *h;
            prev = cur;  // update prev to the current node
        }
    }
}


void DisplayLinkedlist (struct node *h)
{
    struct node * ptr;
    ptr = h;
    while (ptr->next!=h)
    {
       printf("%d\n", ptr->data);
       ptr= ptr->next;
    }
    printf("%d\n", ptr->data);
}

void insert(struct node **h, int val, int pos)
{
    struct node *cur, *tmp;
    cur = malloc(sizeof(struct node));
    cur->next = NULL;
    cur->data = val;

    if (*h == NULL)
    {
        *h = cur;
        cur->next = cur;
    }
    else if (pos == 0)
    {
        tmp = *h;
        while (tmp->next != *h)
        {
            tmp = tmp->next;
        }
        cur->next = *h;
        *h = cur;
        tmp->next = cur;
    }
    else
    {
        tmp = *h;
        int i = 0;
        while (i < pos - 1 && tmp->next != *h)
        {
            tmp = tmp->next;
            i++;
        }
        cur->next = tmp->next;
        tmp->next = cur;
    }
}


  void Deletenode (struct node **h , int val)
   {
    struct node * ptr,*prev;
    if (*h== NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        /*This is to find In which node the particular vallue is present which
         is to be delete , that node is pointed by ptr and it's previous node is pointed by prev */
        ptr = *h;
        while (ptr->data != val && ptr->next !=*h)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        // Data is not found which said to be deleted
        if (ptr->next == *h && ptr ->data !=val)
        {
            printf("The data is not found \n");
        }
        // Only node node is present and that node is to deleted
        else if ((*h) == (*h)->next)
        {
            *h = NULL;
            free (ptr);
        }
        // many nodes present but we have to delete the first node 
        else if (ptr == *h )
        {
            struct node * tmp = *h;
            // this is circular list so we have to change last node's next to head. for that we have to find last node
            while (tmp->next !=*h)
            {
                tmp = tmp ->next;

            }
            * h = ptr->next;
            tmp ->next = *h;
            free (ptr);
        }
 // if that node which is to be deleted present in middle or last then 
        else{
            prev-> next = ptr->next;
            free (ptr);
        }

        
    }
   }


int main() {
    int n, nopos, v,v1, p;
    printf("Enter how many nodes you want to create: ");
    scanf("%d", &n);
    createLinkedlist(&head, n);
    DisplayLinkedlist(head);
    printf("How many positions do you want to change: ");
    scanf("%d", &nopos);
    for (int j = 0; j < nopos; j++) {
        printf("Enter the value you want to insert and the position: ");
        scanf("%d%d", &v, &p);
        insert(&head, v, p);
    }
    printf("After insertion:\n");
    DisplayLinkedlist(head);
    printf("Which element you want to delete: ");
    scanf("%d", &v1);
    printf("After deletion :\n");
    Deletenode (&head,v1 );
    DisplayLinkedlist(head);

    return 0;
}