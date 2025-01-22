//Q.1 Write an algorithm to implement ascending priority queue using singular linear linked list which has insert() function such that 
//queue remains ordered list. Implement remove() function too.
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
        exit(1);
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
    free(temp);
}
void sort(struct Node* head)
{
    struct Node* temp=head;
    while(temp->next!=NULL)
    {
        struct Node* ptr=temp->next;
        while(ptr!=NULL){
        if(temp->data>ptr->data)
        {
            int temp1=temp->data;
            temp->data=ptr->data;
            ptr->data=temp1;
        }
        ptr=ptr->next;
        }
        temp=temp->next;
    }
}
void insert_element(struct Node** head,int element)
{
    struct Node* newnode=create_node(element);
    if(*head==NULL)
    {
      *head=newnode;   
      return;
    }
    struct Node* prev=NULL;
    struct Node* temp=*head;
    while(temp!=NULL){
    if(prev==NULL&&temp->data>element)
    {
        newnode->next=*head;
        *head=newnode;
        return;
    }
    else if(prev!=NULL&&temp->data>element){
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
    free(temp);
    return 1;
}
int main() 
{
    int n,value,op,choice,element;
    scanf("%d",&n);
    struct Node* head=NULL;
    struct Node* temp=NULL;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&value);
        struct Node* newnode=create_node(value);
        if(head==NULL)
        {
            head=newnode;
        }else{
            temp->next=newnode;
        }
        temp=newnode;
    }
    sort(head);
    printf("priority queue.\n");
    print_list(head);
    printf("-----MENU-----\n");
    printf("1. insert any element.\n");
    printf("2.remove any element.\n");
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
                   printf("enter element to insert.\n");
                   scanf("%d",&element);
                   insert_element(&head,element);
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
                   break;
            default:
                   printf("invalid choice.\n");
                   break;
        }
        op--;
    }
    return 0;
}
