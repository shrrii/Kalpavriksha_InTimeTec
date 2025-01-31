//Implementation of queue using array
#include <stdio.h>
#define MAX_SIZE 1000
typedef struct{
    int front;
    int rear;
    int items[MAX_SIZE];
}queue;
void initialize_queue(queue* q)
{
    q->front=-1;
    q->rear=0;
}
int isfull(queue* q)
{
    return (q->rear==MAX_SIZE);
}
int isempty(queue* q)
{
    return (q->front==q->rear-1);
}
void enqueue(queue* q)
{
    if(isfull(q))
    {
        printf("queue overflow\n");
        return;
    }
    int element;
    printf("enter value.\n");
    scanf("%d",&element);
    q->items[q->rear]=element;
    q->rear++;
}
void dequeue(queue* q)
{
    if(isempty(q))
    {
        printf("queue underflow\n");
        return;
    }
    q->front++;
}
void peek(queue* q)
{
    if(isempty(q))
    {
        printf("queue underflow\n");
        return;
    }
    printf("peek element is : %d\n",q->items[q->front+1]);
}
void display(queue* q)
{
    if(isempty(q))
    {
        printf("queue underflow\n");
        return;
    }
    for(int i=q->front+1;i<q->rear;i++)
    {
        printf("%d ",q->items[i]);
    }
    printf("\n");
}
void size(queue* q)
{
     if(isempty(q))
    {
        printf("queue underflow\n");
        return;
    }
    int count=0;
    for(int i=q->front+1;i<q->rear;i++)
    {
        count++;
    }
    printf("size of the queue is %d \n",count);
}
int main()
{
    queue q;
    initialize_queue(&q);
    int no_of_operations,choice;
    printf("enter number of operations.\n");
    scanf("%d",&no_of_operations);
    while(no_of_operations)
    {
        printf("enter your choice.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   enqueue(&q);
                   break;
            case 2:
                   dequeue(&q);
                   break;
            case 3:
                   peek(&q);
                   break;
            case 4:
                   if(isempty(&q))
                   {
                     printf("queue is empty\n");   
                   }
                   else{
                       printf("queue is not empty.\n");
                   }
                   break;
            case 5:
                   size(&q);
                   break;
            case 6:
                   display(&q);
                   break;
            case 7:
                   return 0;
            default:
                   printf("invalid choice\n");
                   break;
        }
        no_of_operations--;
    }

    return 0;
}
