#include<stdio.h>
#include<stdlib.h>
struct  node
{
 int data;
 struct node * next;
};
struct node * head = NULL;
struct node * tail = NULL;
int main(){
    struct node * cur;
    int no;
    int i;
    printf("Enter how many nodes you want to create:");
    scanf("%d", &no);
    for (i=0;i<no;i++){
        cur=malloc(sizeof (struct node));
        printf("Enter the %d number :", i);
        scanf("%d", &cur->data);
        cur->next = NULL;
        if (head == NULL){
            head = tail = cur; // If only one node is present
        }
        else // More than one node is present
        {
            tail->next= cur;
            tail=cur;
        } 
    }
    cur=head;
    while (cur!=NULL) // For display the elements
    {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    
} // end of main