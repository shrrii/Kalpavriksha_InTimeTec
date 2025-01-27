//23-jan-2025 - Qus- sum of two linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 10000
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
struct Node* parse_list(char *str)
{
    struct Node* head=NULL;
    struct Node* temp=NULL;
    char *token=strtok(str," ");
    while(token!=NULL)
    {
        int value=atoi(token);
        struct Node* newnode=create_node(value);
        if(head==NULL)
        {
            head=newnode;
        }else{
            temp->next=newnode;
        }
        temp=newnode;
        token=strtok(NULL," ");
    }
    return head;
}
void print_list(struct Node* node)
{
    struct Node* temp=node;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
struct Node* reverse(struct Node* head)
{
    struct Node* prev=NULL;
    struct Node* curr=head;
    while(curr!=NULL)
    {
        struct Node* nxtnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxtnode;
    }
    return prev;
}
struct Node* sum_oflist(struct Node* l1,struct Node* l2)
{
    struct Node* newhead=NULL;
    struct Node* prev=NULL;
    int carry=0,sum;
    while(l1!=NULL||l2!=NULL||carry)
    {
        sum=carry;
        if(l1!=NULL)
        {
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL)
        {
            sum+=l2->data;
            l2=l2->next;
        }
        carry=sum/10;
        sum=sum%10;
        struct Node* newnode=create_node(sum);
        if(newhead==NULL)
        {
            newhead=newnode;
        }else{
            prev->next=newnode;
        }
        prev=newnode;
    }
    return newhead;
}
int main()
{
    char *str1,*str2;
    str1=(char *)malloc(maxsize*sizeof(char));
    str2=(char *)malloc(maxsize*sizeof(char));
    if(!str1||!str2)
    {
        printf("memory allocation failed.\n");
        return 0;
    }
    printf("enter the first list element.\n");
    scanf("%[^\n]",str1);
    printf("enter the second list element.\n");
    getchar();
    scanf("%[^\n]",str2);
    struct Node* l1=parse_list(str1);
    struct Node* list1=reverse(l1);
    struct Node* l2=parse_list(str2);
    struct Node* list2=reverse(l2);
    struct Node* newhead=sum_oflist(list1,list2);
    struct Node* newh=reverse(newhead);
    printf("sum is\n");
    print_list(newh);
    return 0;
}
