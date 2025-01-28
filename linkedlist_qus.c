//Qus- Task is - designing a Student Management System to store and manipulate student data using a singly linked list. Each node in the linked list represents a student and contains the following fields:
//Roll Number (integer, unique for each student)
//Name (string)
//Marks (float)
//task is to implement the following functionalities:
//1-Insert Student: Add a new student to the linked list. Ensure the list remains sorted by Roll Number after every insertion.
//2-Search Student by Name: Implement a function that searches for a student by name. If the name is found, return the Roll Number and Marks; otherwise, return "Student not found."
//3-Sort Students by Marks: Implement a function to sort the students based on their Marks in descending order.
//4-Delete Student by Roll Number: Implement a function to delete a student from the list given their Roll Number.
//5-Print the list.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int roll_no;
    char *name;
    float marks;
    struct Node* next;
};
int roll_no;
char name[10000];       
float marks;
struct Node* create_node(int roll_no,char *name,float marks)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    if(!newnode)
    {
        printf("memory allocation failed.\n");
        return NULL;
    }
    newnode->roll_no=roll_no;
    newnode->name=(char *)malloc(strlen(name)+1);
    if(!newnode->name)
    {
        printf("memory allocation failed for name.\n");
        free(newnode);
        return NULL;
    }
    strcpy(newnode->name,name);
    newnode->marks=marks;
    newnode->next=NULL;
    return newnode;
}
void insert_student(struct Node** head)
{
    printf("enter the data of new student.\n");
    printf("enter roll number.\n");
    scanf("%d",&roll_no);
    struct Node* temp1 = *head;
    while (temp1 != NULL) {
        if (temp1->roll_no == roll_no) {
            printf("Error: Roll number %d already exists. Please enter a unique roll number.\n", roll_no);
            return; 
        }
        temp1 = temp1->next;
    }
    printf("enter name.\n");
    getchar();
    scanf("%[^\n]",name);
    printf("enter marks.\n");
    scanf("%f",&marks);
    struct Node* newnode=create_node(roll_no,name,marks);
    if(*head==NULL || (*head)->roll_no>roll_no)
    {
        newnode->next=*head;
        *head=newnode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL && temp->next->roll_no<roll_no)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void search_student(struct Node* head,char* search_name)
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        if(strcmp(temp->name, search_name)==0)
        {
            printf("data of searched student.\n");
            printf("roll number is %d\nmarks is %f\n",temp->roll_no,temp->marks);
            return;
        }
        temp=temp->next;
    }
    printf("student not found.\n");
}
void sort_by_marks(struct Node* head)
{
    struct Node* temp=head;
    while(temp->next!=NULL)
    {
        struct Node* ptr=temp->next;
        while(ptr!=NULL)
        {
            if(ptr->marks>temp->marks)
            {
                float dummy=temp->marks;
                temp->marks=ptr->marks;
                ptr->marks=dummy;
            }
            ptr=ptr->next;
        }
        temp=temp->next;
    }
}
int delete_student(struct Node** head,int delete_roll)
{
    if(*head==NULL)
    {
       printf("list is empty.\n");
       return 0;
    }
    struct Node* temp=*head;
    struct Node* prev=NULL;
    if(temp->roll_no==delete_roll)
    {
        *head=temp->next;
        free(temp);
        return 1;
    }
    while(temp!=NULL)
    {
        if(temp->roll_no==delete_roll)
        {
            prev->next=temp->next;
            free(temp);
            return 1;
        }
        prev=temp;
        temp=temp->next;
    }
    return 0;
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
        printf("roll number : %d\nname : %s\nmarks : %f\n",temp->roll_no,temp->name,temp->marks);
        temp=temp->next;
    }
}
int main()
{
    int n;
    printf("enter the size of linked list.\n");
    scanf("%d",&n);
    struct Node* head=NULL;
    struct Node* prev=NULL;
    printf("enter the data of the list sorted by unique roll numbers.\n");
    for(int i=0;i<n;i++)
    {
        printf("enter roll number.\n");
        scanf("%d",&roll_no);
        printf("enter name.\n");
        getchar();
        scanf("%[^\n]",name);
        printf("enter marks.\n");
        scanf("%f",&marks);
        struct Node* newnode=create_node(roll_no,name,marks);
        if(head==NULL)
        {
            head=newnode;
        }else{
            prev->next=newnode;
        }
        prev=newnode;
    }
    printf("----MENU----\n");
    printf("1.insert student by roll number.\n");
    printf("2.search student by name.\n");
    printf("3.sort students by marks.\n");
    printf("4.delete data by roll number.\n");
    printf("5.print the data.\n");
    printf("6.exit.\n");
    int op,choice;
    printf("enter the number of operations.\n");
    scanf("%d",&op);
    while(op)
    {
        printf("enter the choice.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                  insert_student(&head);
                  printf("element inserted.\n");
                  break;
            case 2:
                  char search_name[1000];
                  printf("enter the name of student u want to search.\n");
                  getchar();
                  scanf("%[^\n]",search_name);
                  search_student(head,search_name);
                  break;
            case 3:
                  sort_by_marks(head);
                  printf("list is sorted by marks.\n");
                  break;
            case 4:
                  int delete_roll;
                  printf("enter roll number to delete.\n");
                  scanf("%d",&delete_roll);
                  if(delete_student(&head,delete_roll)==1)
                       printf("data deleted\n");
                  else
                       printf("data not found.\n");
                  break;
            case 5:
                  print_list(head);
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
//time and space complexity
//for Inserting a student takes O(N) time.
//for Searching for a student takes O(N) time.
//for Sorting the list by marks takes O(N^2) time.
//for Deleting a student takes O(N) time.
//for Printing the list takes O(N) time.
//overall time complexity O(N^2) (due to the sorting function)
//overall space complexity O(N * M) (due to the storage of N nodes and their name strings)
