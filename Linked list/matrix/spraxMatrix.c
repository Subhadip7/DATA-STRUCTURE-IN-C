#include<stdio.h>
#include<stdlib.h>

struct node
{
    int r;
    int c;
    int v;
    struct node *next;
};

void create(struct node **h)
{
    struct node *cur;
    *h = malloc(sizeof(struct node));
    printf("Enter total numbers of rows, columns, and values present in this matrix:\n");
    scanf("%d %d %d", &(*h)->r, &(*h)->c, &(*h)->v);
    (*h)->next = NULL;
    struct node *ptr = *h;
    for (int i = 0; i < (*h)->v; i++)
    {
        cur = malloc(sizeof(struct node));
        printf("Enter the row, column, and the value: \n");
        scanf("%d %d %d", &cur->r, &cur->c, &cur->v);
        cur->next = NULL;
        ptr->next = cur;
        ptr = cur;
    }
}

void display(struct node *h)
{
    int rows = h->r;
    int columns = h->c;
    struct node *ptr = h->next;
    printf("Sparse Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (ptr != NULL && ptr->r == i && ptr->c == j)
            {
                printf("%d\t", ptr->v);
                ptr = ptr->next;
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

void add(struct node *h1, struct node *h2, struct node **h)
{
    if (h1->r != h2->r || h1->c != h2->c)
    {
        printf("Matrix dimensions are not compatible for addition.\n");
        return;
    }
    struct node *ptr, *ptr1;
    *h = malloc(sizeof(struct node));
    (*h)->r = h1->r;
    (*h)->c = h1->c;
    (*h)->v = 0;
    (*h)->next = NULL;

    for (ptr = h1->next; ptr != NULL; ptr = ptr->next)
    {
        struct node *cur = malloc(sizeof(struct node));
        cur->r = ptr->r;
        cur->c = ptr->c;
        cur->v = ptr->v;
        cur->next = NULL;
        if ((*h)->next == NULL)
        {
            (*h)->next = cur;
        }
        else
        {
            struct node *temp = *h;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = cur;
        }
        (*h)->v++;
    }

    for (ptr = h2->next; ptr != NULL; ptr = ptr->next)
    {
        struct node *cur = malloc(sizeof(struct node));
        cur->r = ptr->r;
        cur->c = ptr->c;
        cur->v = ptr->v;
        cur->next = NULL;
        if ((*h)->next == NULL)
        {
            (*h)->next = cur;
        }
        else
        {
            struct node *temp = *h;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = cur;
        }
        (*h)->v++;
    }

    for (ptr = (*h)->next; ptr != NULL; ptr = ptr->next)
    {
        struct node *prev = ptr;
        ptr1 = ptr->next;
        while (ptr1 != NULL)
        {
            if (ptr->r == ptr1->r && ptr->c == ptr1->c)
            {
                ptr->v += ptr1->v;
                prev->next = ptr1->next;
                free(ptr1);
                ptr1 = prev;
                (*h)->v--; // Because 1 value is deleted 
            }
            prev = ptr1;
            ptr1 = ptr1->next;
        }
    }
}

int main()
{
    struct node *h1, *h2, *h;
    h1 = h2 = NULL;
    h = NULL;

    printf("Enter the first sparse matrix:\n");
    create(&h1);

    printf("Enter the second sparse matrix:\n");
    create(&h2);

    printf("First sparse matrix:\n");
    display(h1);

    printf("Second sparse matrix:\n");
    display(h2);

    add(h1, h2, &h);

    printf("Addition of two sparse matrices:\n");
    display(h);

    return 0;
}
