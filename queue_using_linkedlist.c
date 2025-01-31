//Implementation of queue using linked list
#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
typedef struct queue{
    node* front;
    node* rear;
}queue;
node* create_node(int element)
{
    node* newnode=(node *)malloc(sizeof(node));
    if(!newnode)
    {
        printf("memory allocation failed.\n");
        return NULL;
    }
    newnode->data=element;
    newnode->next=NULL;
    return newnode;
}
queue* create_queue()
{
    queue* newqueue=(queue*)malloc(sizeof(queue));
    if(!newqueue)
    {
        printf("memory allocation failed.\n");
        return NULL;
    }
    newqueue->front=NULL;
    newqueue->rear=NULL;
    return newqueue;
}int isempty(queue* q)
{
    return q->front==NULL;
}
void enqueue(queue* q)
{
    int element;
    printf("enter value\n");
    scanf("%d",&element);
    node* newnode=create_node(element);
    if(q->rear==NULL)
    {
        q->front=newnode;
        q->rear=newnode;
        return;
    }
    q->rear->next=newnode;
    q->rear=newnode;
}
void dequeue(queue* q)
{
    if(isempty(q))
    {
        printf("queue underflow\n");
        return;
    }
    node* temp=q->front;
    q->front=q->front->next;
    if(q->front==NULL)
    {
        q->rear=NULL;
    }
    free(temp);
}
void peek(queue *q)
{
    if(isempty(q))
    {
        printf("queue underflow\n");
        return;
    }
    printf("%d is peek element\n",q->front->data);
}
void size(queue* q)
{
    if(isempty(q))
    {
        printf("queue underflow\n");
        return;
    }
    int count=0;
    node* temp=q->front;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("size of the queue is %d\n",count);
}
void display(queue* q)
{
    if(isempty(q))
    {
        printf("queue underflow\n");
        return;
    }
    node* temp=q->front;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    
    queue* q=create_queue();
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
                   enqueue(q);
                   break;
            case 2:
                   dequeue(q);
                   break;
            case 3:
                   peek(q);
                   break;
            case 4:
                   if(isempty(q))
                   {
                     printf("queue is empty\n");   
                   }
                   else{
                       printf("queue is not empty.\n");
                   }
                   break;
            case 5:
                   size(q);
                   break;
            case 6:
                   display(q);
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
