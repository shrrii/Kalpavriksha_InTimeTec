// Question 1- Write a c program to read the rows and columns dimensions of a 2d array of type int(maximum dimension: 50 rows and 50 columns)
//print the array in matrix form and then find the addition of all rows and all column and print both arrays in 1d array seperately.
#include <stdio.h>
#include<stdlib.h>
#define maxrow 50
#define maxcol 50
int main()
{
    int row,col;
    scanf("%d\n%d",&row,&col);
    int **matrix;
    matrix=(int **)malloc(row*sizeof(int *));
    for(int i=0;i<row;i++)
    {
        matrix[i]=(int *)malloc(col*sizeof(int));
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("matrix is\n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    int *add_row,*add_col;
    add_row=(int *)malloc(row*sizeof(int));
    add_col=(int *)malloc(col*sizeof(int));
    for(int i=0;i<row;i++)
    {
        add_row[i]=0;
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            add_row[i]+=matrix[i][j];
        }
    }
    printf("addition of all rows is\n[ ");
    for(int i=0;i<row;i++)
    {
        printf("%d ",add_row[i]);
    }
    printf("]\n");
    for(int i=0;i<col;i++)
    {
        add_col[i]=0;
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            add_col[i]+=matrix[j][i];
        }
    }
    printf("addition of all columns is\n[ ");
    for(int i=0;i<col;i++)
    {
        printf("%d ",add_col[i]);
    }
    printf("]\n");
    return 0;
}
// Question 2: Given an array, of size n, reverse it,taking input as a character type.
//Example: If array a b c d e , after reversing it, the array should be e d c b a, 
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int *ptr=&n;
    printf("enter number of elements");
    scanf("%d",ptr);
    char *arr;
    arr=(char *)malloc(n*sizeof(char));
    for(int i=0;i<n;i++)
    {
        scanf("%s",arr+i);
    }
    printf("input array is\n");
    for(int i=0;i<n;i++)
    {
        printf("%c ",*(arr+i));
    }
    printf("\n reversed array is\n");
    for(int i=n-1;i>=0;i--)
    {
        printf("%c ",*(arr+i));
    }
    free(arr);
    return 0;
}
//Question 3: Remove duplicates from Sorted Array
#include<stdio.h>
#include<stdlib.h>
int solve(int *arr,int n)
{
    int id=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[i-1])
        {
            arr[id++]=arr[i];
        }
    }
    return id;
}
int main()
{
    int n;
    int *ptr=&n;
    printf("enter the number of elements");
    scanf("%d",ptr);
    int *arr;
    arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    int updateindex=solve(arr,n);
    printf("updated matrix is\n");
    for(int i=0;i<updateindex;i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}
