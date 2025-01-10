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
//Question 4:Write a program that checks whether a matric is a sparse matrix.
//A sparse matrix is a special matrix where more than half of its elements are equal to zero.
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int row,col;
    int *p1=&row;
    int *p2=&col;
    printf("enter number of rows of matrix\n");
    scanf("%d",p1);
    printf("enter number of columns of matrix\n");
    scanf("%d",p2);
    int **matrix;
    matrix=(int **)malloc((*p1)*sizeof(int *));
    if(!matrix)
    {
        printf("allocation of matrix failed\n");
        return 1;
    }
    for(int i=0;i<*p1;i++)
    {
        matrix[i]=(int *)malloc((*p2)*sizeof(int));
        if(!matrix[i])
        {
            printf("allocation of matrix failed\n");
            return 1;
        }
    }
    for(int i=0;i<*p1;i++)
    {
        for(int j=0;j<*p2;j++)
        {
            scanf("%d",*(matrix+i)+j);
        }
    }
    printf("2d matrix is\n");
    for(int i=0;i<*p1;i++)
    {
       for(int j=0;j<*p2;j++)
       {
           printf("%d ",*(*(matrix+i)+j));
       }
       printf("\n");
    }
    int half_element=((*p1)*(*p2))/2;
    int count=0;
    int *p3=&count;
    for(int i=0;i<*p1;i++)
    {
        for(int j=0;j<*p2;j++)
        {
            if(*(*(matrix+i)+j)==0)
            {
                (*p3)++;
            }
        }
        free(matrix[i]);
    }
    free(matrix);
    if(*p3>half_element)
    {
        printf("matrix is a sparse matrix\n");
    }else{
        printf("matrix is not a sparse matrix\n");
    }
    return 0;
}
//Question 5: rotate 2d array 90 degrees
#include <stdio.h>
#include<stdlib.h>
int **allocate(int *p1,int *p2)
{
    int **m=(int **)malloc((*p1)*sizeof(int *));
    for(int i=0;i<*p1;i++)
    {
        m[i]=(int *)malloc((*p2)*sizeof(int));
    }
    return m;
}
int main()
{
    int row,col;
    int *p1=&row;
    int *p2=&col;
    scanf("%d %d",p1,p2);
    int **matrix=allocate(p1,p2);
    for(int i=0;i<*p1;i++)
    {
        for(int j=0;j<*p2;j++)
        {
            scanf("%d",*(matrix+i)+j);
        }
    }
    printf("matrix is\n");
    for(int i=0;i<*p1;i++)
    {
        for(int j=0;j<*p2;j++)
        {
            printf("%d ",*(*(matrix+i)+j));
        }
        printf("\n");
    }
    int **result=allocate(p2,p1);
    printf("\nrotated matrix is\n");
    for(int i=0;i<*p2;i++)
    {
        for(int j=(*p1)-1,k=0;j>=0||k>(*p1);j--,k++)
        {
            *(*(result+i)+k)=*(*(matrix+j)+i);
            printf("%d ",*(*(result+i)+k));
        }
        printf("\n");
    }
    return 0;
}
//Question 6: take a string as a input and then modify the string with only lower case and upper case alphabet character 
//remove special characters,number and then again modify this string with only Upper case characters.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void modify(char *result)
{
    while(*result!='\0')
    {
        if(*result>='a'&&*result<='z')
        { 
               *result-=32;
        }
        result++;
    }
}
int main()
{
    char *str;
    int maxlen;
    printf("enter the length of string\n");
    scanf("%d",&maxlen);
    getchar();
    str=(char *)malloc((maxlen+1)*sizeof(char));
    printf("enter a string\n");
    fgets(str,maxlen+1,stdin);
    printf("string is\n%s",str);
    int id=0;
    char *result;
    result=(char *)malloc((maxlen+1)*sizeof(char));
    for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z'))
        {
            continue;
        }else
        {
            result[id++]=str[i];
        }
    }
    printf("\nstring with only lower characters\n");
    printf("%s",result);
    printf("\n modified string after changing lower case to upper case\n");
    modify(result);
    printf("%s",result);
    return 0;
}
//Question 7: 
