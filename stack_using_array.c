//Implementation of stack using array
#include <stdio.h>
#include <stdlib.h>

int top = -1;
int n;
int *stack;

void push()
{
    int element;
    printf("Enter the value to push: ");
    scanf("%d", &element);
    if (top == n - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = element;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("%d popped from the stack\n", stack[top]);
    top--;
}

void peek()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("Peek element of the stack is %d\n", stack[top]);
}

int isempty()
{
    return top == -1;
}

void size()
{
    int count = 0;
    int temp = top;  
    while (temp != -1)
    {
        count++;
        temp--;
    }
    printf("Size of the stack is %d\n", count);
}

void display()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    for (int i = 0; i <= top; i++)  
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter the size of the stack: ");
    scanf("%d", &n);
    stack = (int *)malloc(n * sizeof(int));

    if (stack == NULL)  
    {
        printf("Memory allocation failed\n");
        return 1;
    }

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
                free(stack);  
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    free(stack);  
    return 0;
}
