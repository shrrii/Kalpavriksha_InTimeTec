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
//Q.2 (i) stack implementation using linear array-
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
                   break;
            default:
                   printf("invalid choice.\n");
                   break;
        }
        op--;
    }
    return 0;
}
//Q.2 (ii) stack implementation using linked list-
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
    free(temp);
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
                   break;
            default:
                   printf("invalid choice.\n");
                   break;
        }
        op--;
    }
    return 0;
}
//Q.3 Implement double linked list: insert at beginning, at end, at middle. delete from beginning,last, middle, traverse list 
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
//Q.5 Implement the following function as a new function for the linked list toolkit. Precondition: head_ptr points to the start of a 
//linked list. The list might be empty or it might be non-empty. Postcondition: The return value is the number of occurrences of 42 
//in the data field of a node on the linked list. The list itself is unchanged.
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
        exit(1);
    }
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
void find_occurance(struct Node* head)
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
    free(temp);
    printf("occurance of 42 in the list is: %d",count);
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
    find_occurance(head);
}
//Q.10 Write a "C" function to print a sparse matrix, each row in one line of output and properly formatted,using linked list
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* down;
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
    newnode->down=NULL;
    return newnode;
}
void print_list(struct Node* head,int row,int col)
{
    struct Node* temp;
    for(int i=0;i<row;i++)
    {
        temp=head;
        for(int k=0;k<i;k++)
        {
            temp=temp->down;   
        }
        for(int j=0;j<col;j++)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int row,col,value;
    printf("enter number of rows.\n");
    scanf("%d",&row);
    printf("enter number of columns.\n");
    scanf("%d",&col);
    struct Node* head=NULL;
    struct Node* temp=NULL;
    printf("enter value.\n");
    for(int i=0;i<row;i++)
    {
        struct Node* ptr=temp;
        struct Node* prev=NULL;
        for(int j=0;j<col;j++)
        {
            scanf("%d",&value);
            struct Node* newnode=create_node(value);
            if(head==NULL)
            {
                head=newnode;
            }
            if(i>0)
            {
                ptr->down=newnode;
                ptr=ptr->next;
            }
            if(j==0)
            {
                temp=newnode;
            }
            else if(prev!=NULL)
            {
                prev->next=newnode;
            }
            
            prev=newnode;
        }
    }
    printf("sparse matrix in one row is:\n");
    print_list(head,row,col);
}
//Q.13 Consider representing a linked list of integers using arrays. Write a "C" function to delete the ith node from the list.
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
        exit(1);
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
        free(temp);
        return;
    }
    else{
        for(int i=1;i<k;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
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
    free(temp);
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
