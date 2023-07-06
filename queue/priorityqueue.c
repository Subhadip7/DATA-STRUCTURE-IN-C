#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    int priority;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void create(struct node** h, int n) {
    struct node* cur;
    for (int i = 0; i < n; i++) {
        cur = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d", &cur->data);
        printf("Enter the priority: ");
        scanf("%d", &cur->priority);
        cur->prev = cur->next = NULL;
        if (*h == NULL) {
            *h = tail = cur;
        } else {
            cur->prev = tail;
            tail->next = cur;
            tail = cur;
        }
    }
}

void display(struct node* h) {
    struct node* tmp = h;
    while (tmp != NULL) {
        printf("Data: %d\tPriority: %d\n", tmp->data, tmp->priority);
        tmp = tmp->next;
    }
}

void insert(struct node** h, int val, int priority) {
    struct node* cur, * ptr;
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data = val;
    cur->priority = priority;
    cur->prev = cur->next = NULL;
    if (*h == NULL) {
        *h = cur;
    } else if (priority < (*h)->priority) {
        cur->next = *h;
        (*h)->prev = cur;
        *h = cur;
    } else {
        ptr = *h;
        while (ptr->next != NULL && priority >= ptr->next->priority) {
            ptr = ptr->next;
        }
        cur->prev = ptr;
        cur->next = ptr->next;
        if (ptr->next != NULL) {
            ptr->next->prev = cur;
        }
        ptr->next = cur;
    }
}

void delete(struct node** h) {
    if (*h == NULL) {
        printf("The list is empty.\n");
    } else {
        struct node* temp = *h;
        *h = (*h)->next;
        if (*h != NULL) {
            (*h)->prev = NULL;
        } else {
            tail = NULL;
        }
        free(temp);
    }
}

int main() {
    int no, data, priority;
    printf("Enter how many nodes you want to create: ");
    scanf("%d", &no);

    create(&head, no);
    printf("Original Priority Queue:\n");
    display(head);

    printf("Enter the value and priority to insert: ");
    scanf("%d %d", &data, &priority);
    insert(&head, data, priority);
    printf("Priority Queue after insertion:\n");
    display(head);

    printf("Deleting the highest priority element.\n");
    delete(&head);
    printf("Priority Queue after deletion:\n");
    display(head);

    return 0;
}
