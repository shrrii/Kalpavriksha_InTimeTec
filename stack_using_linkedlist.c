//Implementation of stack using linked list
#include <stdio.h>
#include <stdlib.h>
struct stack{
    int data;
    struct stack* next;
};
struct stack* top=NULL;
struct stack* create_stack(int element)
{
    struct stack* newnode=(struct stack*)malloc(sizeof(struct stack));
    if(!newnode)
    {
        printf("memory allocation failed.\n");
        return NULL;
    }
    newnode->data=element;
    newnode->next=NULL;
    return newnode;
}
void push()
{
    int element;
    printf("Enter the value to push: ");
    scanf("%d", &element);
    struct stack* newnode=create_stack(element);
    if(top==NULL)
    {
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}
void pop()
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    struct stack* temp=top;
    printf("%d pop from the stack\n",temp->data);
    top=temp->next;
    free(temp);
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("Peek element of the stack is %d\n", top->data);
}

int isempty()
{
    return top == NULL;
}

void size()
{
    int count = 0;
    struct stack* temp=top;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    printf("Size of the stack is %d\n", count);
}

void display()
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    struct stack* temp=top;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    printf("---MENU---\n");
    printf("1. Push operation\n2. Pop operation\n3. Peek operation\n4. Is empty operation\n5. Size of operation\n6. Display\n7. Exit\n");

    int no_of_operation, choice;
    printf("Enter the number of operations: ");
    scanf("%d", &no_of_operation);

    while (no_of_operation--)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isempty())
                {
                    printf("Stack is empty\n");
                }
                else
                {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                size();
                break;
            case 6:
                display();
                break;
            case 7:  
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}

