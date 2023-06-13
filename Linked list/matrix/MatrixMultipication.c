#include<stdio.h>
#include<stdlib.h>

struct node
{
    int r;
    int c;
    int v;
    struct node* next;
};

void create(struct node** h)
{
    struct node* cur;
    *h = malloc(sizeof(struct node));
    printf("Enter the total number of rows, columns, and values present in this matrix:\n");
    scanf("%d %d %d", &(*h)->r, &(*h)->c, &(*h)->v);
    (*h)->next = NULL;
    struct node* ptr = *h;
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
/*

void display(struct node* matrix)
{
    printf("Rows: %d, Columns: %d, Non-zero values: %d\n", matrix->r, matrix->c, matrix->v);
    struct node* ptr = matrix->next;
    while (ptr != NULL)
    {
        printf("Row: %d, Column: %d, Value: %d\n", ptr->r, ptr->c, ptr->v);
        ptr = ptr->next;
    }
}
*/
void display(struct node* matrix)
{
    // Find the maximum row and column values in the matrix
    int maxRow = 0;
    int maxCol = 0;
    struct node* ptr = matrix->next;
    while (ptr != NULL)
    {
        if (ptr->r > maxRow)
            maxRow = ptr->r;
        if (ptr->c > maxCol)
            maxCol = ptr->c;
        ptr = ptr->next;
    }

    // Create a 2D array to store the resulting matrix
    int rows = maxRow + 1;
    int cols = maxCol + 1;
    int matrixData[rows][cols];

    // Initialize matrixData with zeros
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrixData[i][j] = 0;
        }
    }

    // Populate matrixData with values from the matrix
    ptr = matrix->next;
    while (ptr != NULL)
    {
        matrixData[ptr->r][ptr->c] += ptr->v;
        ptr = ptr->next;
    }

    // Display the resulting matrix
    printf("Resulting Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrixData[i][j]);
        }
        printf("\n");
    }
}


void multi(struct node* f, struct node* g, struct node** h)
{
    if (f->c != g->r) // f's column should be equal to g's row and the value will be stored at (f's row, g's column)
    {
        printf("Matrices cannot be multiplied.\n");
        return;
    }
    
    *h = malloc(sizeof(struct node));
    (*h)->r = f->r;
    (*h)->c = g->c;
    (*h)->v = 0;
    (*h)->next = NULL;
    struct node* ptr = *h;

    for (struct node* ptrF = f->next; ptrF != NULL; ptrF = ptrF->next)
    {
        for (struct node* ptrG = g->next; ptrG != NULL; ptrG = ptrG->next)
        {
            if (ptrF->c == ptrG->r)
            {
                struct node* cur = malloc(sizeof(struct node));
                cur->r = ptrF->r;
                cur->c = ptrG->c;
                cur->v = ptrF->v * ptrG->v;
                cur->next = NULL;
                (*h)->v++;
                ptr->next = cur;
                ptr = cur;
            }
        }
    }
}

int main()
{
    struct node* f, *g, *h;
    f = g = h = NULL;
    create(&f);
    create(&g);
    multi(f, g, &h);

    if (h != NULL)
    {
        display(h);
        free(h);
    }

    free(f);
    free(g);

    return 0;
}
