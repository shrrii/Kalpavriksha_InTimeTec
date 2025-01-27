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
void delete_node(struct Node** head,int k)
{
    if(*head==NULL)
    {
        printf("list is empty.\n");
        return;
    }
    struct Node* temp=*head;
    struct Node* prev=NULL;
    if(k==1)
    {
        *head=temp->next;
        return;
    }
    else{
        for(int i=1;i<k;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
    }
}
void print_list(struct Node* head)
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
}
int main()
{
    int n;
    printf("enter size of array.\n");
    scanf("%d",&n);
    int arr[n];
    struct Node* head=NULL;
    struct Node* temp=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        struct Node* newnode=create_node(arr[i]);
            if(head==NULL)
            {
                head=newnode;
            }
            else{
                temp->next=newnode;
            }
            temp=newnode;
    }
    int k;
    printf("enter kth node for delete.\n");
    scanf("%d",&k);
    if(k<=0||k>n)
    {
        printf("invalid node.\n");
    }
    delete_node(&head,k);
    print_list(head);
}
