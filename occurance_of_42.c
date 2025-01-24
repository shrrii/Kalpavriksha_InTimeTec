#include<stdio.h>
#include<stdlib.h>
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
int find_occurance(struct Node* head)
{
    if(head==NULL)
    {
        printf("list is empty.\n");
    }
    int count=0;
    struct Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==42)
        {
            count++;
        }
        temp=temp->next;
    }
    return count;
}
int main()
{
    int n,value;
    printf("enter number of elements.\n");
    scanf("%d",&n);
    struct Node* head=NULL;
    struct Node* prev=NULL;
    printf("enter values:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        struct Node* newnode=create_node(value);
        if(head==NULL)
        {
            head=newnode;
        }else{
            prev->next=newnode;   
        }
        prev=newnode;
    }
    int ans=find_occurance(head);
    printf("occurance of 42 in the list is: %d",ans);
    return 0;
}
