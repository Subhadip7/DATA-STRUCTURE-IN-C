#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* next;
    int data;
    struct node* prev;
};

struct node* head = NULL;

void CreateLinkedlist(struct node** h, int n)
{
    struct node* cur;
    for (int i = 0; i < n; i++)
    {
        cur = malloc(sizeof(struct node));
        cur->next = cur->prev = NULL;
        printf("Enter the  %d data: ", i);
        scanf("%d", &cur->data);
        if (*h == NULL)
        {
            *h = cur;
            cur->prev = cur->next = cur;
        }
        else
        {
            cur->prev = (*h)->prev;
            cur->next = *h;
            (*h)->prev->next = cur;
            (*h)->prev = cur;
        }
    }
}

void Insert(struct node** h, int v, int pos)
{
    struct node* cur = malloc(sizeof(struct node));
    cur->data = v;
    struct node* ptr;

    if (pos == 0)
    {
        cur->next = *h;
        cur->prev = (*h)->prev;
        (*h)->prev = cur;
        cur->prev->next = cur;
        *h = cur;
    }
    else
    {
        ptr = *h;
        int i = 0;
        while (i < pos - 1 && ptr->next != *h)
        {
            i++;
            ptr = ptr->next;
        }

        if (ptr->next == *h)
        {
            cur->prev = (*h)->prev;
            cur->next = *h;
            cur->prev->next = cur;
            (*h)->prev = cur;
        }
        else
        {
            cur->prev = ptr;
            cur->next = ptr->next;
            ptr->next = cur;
            ptr->next->prev = cur;
        }
    }
}

void Display(struct node* h)
{
    struct node* tmp = h;
    do {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    } while (tmp != h);
}

void Delete (struct node **h, int v)
{
    struct node * ptr;
    if (*h == NULL)
    {
        printf("Insert Node\n");
    }
 ptr = *h;
 // while loop for getting where deletion takes place
 while (ptr->next!=*h)
 {
    if (ptr->data == v)
    break;
    ptr = ptr->next;
 }
 if (ptr->next == *h && ptr->data!= v)
 printf("The data is not found \n");
 // For one node is present
 else if (*h == ptr && ptr->next == *h)
 {
    *h = NULL;
    free (ptr);
 }
 // Deleting first node , here many nodes present

 else if ( *h == ptr )

 {
    ptr->next->prev = ptr->prev;
    ptr->prev->next = ptr->next;
    *h = ptr->next;
    free (ptr);
 }

 else 
 {
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free (ptr);
 }
}

int main() {
    int no,del,del_no,ins_no,ins, ins_po;
    printf("Enter how many nodes you want to create: ");
    scanf("%d", &no);
    CreateLinkedlist(&head, no);
    printf("THE ELEMENTS ARE:\n");
    Display(head);
    printf("How many positions you want to insert \n");
    scanf("%d", &ins_no);

     for (int j=0;j<ins_no;j++){
    printf("Which %dth element you want to insert and which position : \n", j);
    scanf("%d %d",&ins,&ins_po);
    Insert(&head, ins, ins_po);
    }


    printf("After Insertion:\n");
    Display(head);
    printf("Enter how many numbers you want to delete : \n");
    scanf("%d", &del_no);

    for (int j=0;j<del_no;j++){
    printf("Which element you want to delete %d : \n", j);
    scanf("%d",&del);
    Delete (&head, del);
    }

    printf("After deletion :\n");
     Display(head);

    return 0;
}
