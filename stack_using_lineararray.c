#include <stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int capacity;
    int* arr;
};
struct stack* create_stack(int capacity)
{
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->capacity=capacity;
    s->arr=(int*)malloc(s->capacity*sizeof(int));
    return s;
}
void isempty(struct stack* s)
{
    if(s->top==-1)
    {
        printf("stack is empty.\n");
    }
    else{
        printf("stack is not empty.\n");
    }
    return;
}
void isfull(struct stack* s)
{
    if(s->top==s->capacity-1)
    {
        printf("stack is full.\n");
    }else{
        printf("stack is not full.\n");
    }
    return;
}
void push(struct stack* s)
{
    if(s->top==s->capacity-1)
    {
        printf("stack overflow.\n");
        return;
    }
    int value;
    printf("enter element to push.\n");
    scanf("%d",&value);
    s->arr[++s->top]=value;
    printf("%d pushed into stack.\n",value);
}
void pop(struct stack* s)
{
    if(s->top==-1)
    {
        printf("stack underflow.\n");
        return;
    }
    int data=s->arr[s->top--];
    printf("%d pop from stack.\n",data);
}
void peek(struct stack* s)
{
    if(s->top==-1)
    {
        printf("stack underflow.\n");
        return;
    }
    int data=s->arr[s->top];
    printf("peek element is %d.\n",data);
}
void print_stack(struct stack* s)
{
    if(s->top==-1)
    {
        printf("stack is empty.\n");
        return;
    }
    int ind=s->top;
    printf("stack elements is :-\n");
    while(s->top!=-1)
    {
        printf("%d ",s->arr[s->top]);
        s->arr[s->top--];
    }
    s->top=ind;
    printf("\n");
}
int main()
{
    int capacity,op,choice;
    printf("enter the capacity of stack.\n");
    scanf("%d",&capacity);
    struct stack* s=create_stack(capacity); 
    printf("----MENU----\n");
    printf("1 for push.\n");
    printf("2 for pop.\n");
    printf("3 for peek.\n");
    printf("4 for check isempty.\n");
    printf("5 for check isfull.\n");
    printf("6 for print stack.\n");
    printf("7 for exit.\n");
    printf("enter number of operation.\n");
    scanf("%d",&op);
    while(op)
    {
        printf("enter your choice.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   push(s);
                   break;
            case 2:
                   pop(s);
                   break;
            case 3:
                   peek(s);
                   break;
            case 4:
                   isempty(s);
                   break;
            case 5:
                   isfull(s);
                   break;
            case 6:
                   print_stack(s);
                   break;
            case 7:
                   return 0;
            default:
                   printf("invalid choice.\n");
                   break;
        }
        op--;
    }
    return 0;
}
