#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* create_node(int value)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    if(!newnode)
    {
        printf("memory allocation failed.\n");
        return NULL;
    }
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
void print_list(struct Node* head)
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void insert_element(struct Node** head)
{
    int element;
    printf("enter element to insert.\n");
    scanf("%d",&element);
    struct Node* newnode=create_node(element);
    if(*head==NULL)
    {
      *head=newnode;   
      return;
    }
    struct Node* prev=NULL;
    struct Node* temp=*head;
    while(temp!=NULL){
    if(prev==NULL && temp->data>element)
    {
        newnode->next=*head;
        *head=newnode;
        return;
    }
    else if(prev!=NULL && temp->data>element){
        prev->next=newnode;
        newnode->next=temp;
        return;
    }
    prev=temp;
    temp=temp->next;
    }
    if(prev->next==NULL)
    {
        prev->next=newnode;
    }
}
int remove_element(struct Node** head)
{
    if(*head==NULL)
    {
        return 0;
    }
    struct Node* temp=*head;
    *head=temp->next;
    return 1;
}
int main() 
{
    int value,op,choice;
    struct Node* head=NULL;
    printf("-----MENU-----\n");
    printf("1. insert element.\n");
    printf("2.remove smallest element.\n");
    printf("3.print the queue.\n");
    printf("4.exit.\n");
    printf("enter number of operation.\n");
    scanf("%d",&op);
    while(op)
    {
        printf("enter your choice.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   insert_element(&head);
                   printf("element inserted.\n");
                   break;
            case 2:
                   if(remove_element(&head)==1)
                        printf("element removed.\n");
                   else 
                        printf("list is empty.\n");
                   break;
            case 3:
                   printf("priority queue is:\n");
                   print_list(head);
                   break;
            case 4:
                   return 0;
            default:
                   printf("invalid choice.\n");
                   break;
        }
        op--;
    }
    return 0;
}
