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
//Q.2 Implement double linked list: insert at beginning, at end, at middle. delete from beginning,last, middle, traverse list 
//from left to right,right to left. count number of nodes in list.
#include <stdio.h>
#include<stdlib.h>
int element,middle;
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
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
    newnode->prev=NULL;
    return newnode;
}
void insert_at_beginning(struct Node** head)
{
    printf("enter element to insert\n");
    scanf("%d",&element);
    struct Node* newnode=create_node(element);
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    struct Node* temp=*head;
    newnode->next=temp;
    temp->prev=newnode;
    *head=newnode;
}
void insert_at_end(struct Node** head)
{
    printf("enter element to insert\n");
    scanf("%d",&element);
    struct Node* newnode=create_node(element);
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode->prev=temp;
    temp->next=newnode;
}
void insert_at_middle(struct Node** head)
{
    struct Node* temp=*head;
    if(temp->next==NULL)
    {
        insert_at_end(head);
        return;
    }
    int count=0,middle;
    printf("enter element to insert\n");
    scanf("%d",&element);
    struct Node* newnode=create_node(element);
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    if(count%2==0)
    {
        middle=count/2;
    }else if(count%2!=0)
    {
        middle=(count/2)+1;
    }
    temp=*head;
    for(int i=1;i<middle;i++)
    {
       temp=temp->next;   
    }
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
}
int delete_at_beginning(struct Node** head)
{
    struct Node* temp=*head;
    if(temp==NULL)
    {
        return 0;
    }
    if(temp->next==NULL)
    {
        *head=NULL;
        return 1;
    }
    *head=temp->next;
    temp->next->prev=NULL;
    free(temp);
    return 1;
}
int delete_at_end(struct Node** head)
{
    struct Node* temp=*head;
    if(temp==NULL)
    {
        return 0;
    }
    if(temp->next==NULL)
    {
        *head=NULL;
        return 1;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    temp->prev=NULL;
    free(temp);
    return 1;
}
int delete_at_middle(struct Node** head)
{
    int count=0;
    struct Node* temp=*head;
    if(temp==NULL)
    {
        return 0;
    }
    if(temp->next==NULL)
    {
        *head=NULL;
        return 1;
    }
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    middle=(count/2)+1;
    temp=*head;
    for(int i=1;i<middle;i++)
    {
       temp=temp->next;   
    }
    if(temp->next==NULL)
    {
        delete_at_end(head);
        return 1;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp);
    return 1;
}
void left_to_right(struct Node* head)
{
    if(head==NULL)
    {
        printf("list is empty.\n");
        return;
    }
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void right_to_left(struct Node* head)
{
    if(head==NULL)
    {
        printf("list is empty.\n");
        return;
    }
    struct Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp->prev!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("%d ",temp->data);
    printf("\n");
}
void count_nodes(struct Node* head)
{
    int count=0;
    struct Node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("%d",count);
}
int main() 
{
    int n,value,op,choice;
    printf("enter number of nodes.\n");
    scanf("%d",&n);
    struct Node* temp=NULL;
    struct Node* head=NULL;
    printf("enter elements.\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        struct Node* newnode=create_node(value);
        if(head==NULL)
        {
            head=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
        }
        temp=newnode;
    }
    printf("doubly linked list is:\n");
    left_to_right(head);
    printf("-----MENU-----\n");
    printf("1.insert at beginning.\n");
    printf("2.insert at end.\n");
    printf("3.insert at middle.\n");
    printf("4.delete at beginning.\n");
    printf("5.delete at end.\n");
    printf("6.delete at middle.\n");
    printf("7.print list left to right.\n");
    printf("8.print list right to left.\n");
    printf("9.count number of nodes.\n");
    printf("10.exit.\n");
    printf("enter number of operations.\n");
    scanf("%d",&op);
    while(op)
    {
        printf("enter your choice.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                  insert_at_beginning(&head);
                  printf("element inserted.\n");
                  break;
            case 2:
                  insert_at_end(&head);
                  printf("element inserted.\n");
                  break;
            case 3:
                  insert_at_middle(&head);
                  printf("element inserted.\n");
                  break;
            case 4:
                  if(delete_at_beginning(&head)==1)
                  {
                      printf("element deleted.\n");
                  }
                  else{
                      printf("list is empty.\n");
                  }
                  break;
            case 5:
                  if((delete_at_end(&head))==0)
                  {
                      printf("list is empty.\n");
                  }
                  else{
                      printf("element deleted.\n");
                  }
                  break;
            case 6:
                  if((delete_at_middle(&head))==0)
                  {
                      printf("list is empty.\n");
                  }
                  else{
                      printf("element deleted.\n");
                  }
                  break;
            case 7:
                  printf("left to right list is:-\n");
                  left_to_right(head);
                  break;
            case 8:
                  printf("right to left list is:-\n");
                  right_to_left(head);
                  break;
            case 9:
                  printf("number of nodes is:-\n");
                  count_nodes(head);
                  break;
            case 10:
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
