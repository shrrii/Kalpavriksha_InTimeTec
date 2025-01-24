#include <stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack* next;
};
struct stack* create_node(int data)
{
    struct stack* newnode=(struct stack*)malloc(sizeof(struct stack));
    if(!newnode)
    {
        return NULL;
    }
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
int insert_at_head(struct stack** s)
{
    int data;
    printf("enter value.\n");
    scanf("%d",&data);
    struct stack* newnode=create_node(data);
    if(!newnode)
    {
        return -1;
    }
    if(*s==NULL)
    {
        *s=newnode;
        return 0;
    }else{
        newnode->next=*s;
        *s=newnode;
        return 0;
    }
}
int delete_head(struct stack** s)
{
    struct stack* temp=*s;
    *s=temp->next;
    return 0;
}
void isempty(struct stack** s)
{
    if((*s)==NULL)
    {
        printf("stack is empty.\n");
    }
    else{
        printf("stack is not empty.\n");
    }
    return;
}
void push(struct stack** s)
{
    if(insert_at_head(s))
    {
        printf("stack overflow\n");
    }
}
void pop(struct stack** s)
{
    if((*s)==NULL)
    {
        printf("stack underflow.\n");
        return;
    }
    delete_head(s);
}
void peek(struct stack** s)
{
    if((*s)==NULL)
    {
        printf("stack underflow.\n");
        return;
    }
    printf("peek element - %d\n",(*s)->data);
}
void print_stack(struct stack** s)
{
    if((*s)==NULL)
    {
        printf("stack is empty.\n");
        return;
    }
    struct stack* temp = *s;
    printf("element is:- \n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int op,choice;
    struct stack* s=NULL;
    printf("----MENU----\n");
    printf("1 for push.\n");
    printf("2 for pop.\n");
    printf("3 for peek.\n");
    printf("4 for check isempty.\n");
    printf("5 for print stack.\n");
    printf("6 for exit.\n");
    printf("enter number of operation.\n");
    scanf("%d",&op);
    while(op)
    {
        printf("enter your choice.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   push(&s);
                   break;
            case 2:
                   pop(&s);
                   break;
            case 3:
                   peek(&s);
                   break;
            case 4:
                   isempty(&s);
                   break;
            case 5:
                   print_stack(&s);
                   break;
            case 6:
                   return 0;
            default:
                   printf("invalid choice.\n");
                   break;
        }
        op--;
    }
    return 0;
}
