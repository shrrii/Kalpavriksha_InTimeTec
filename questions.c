//Question 1:
//Input : aaabccdddd
//Output: a3b1c2d4
#include<stdio.h>
void count_frequency(char *input)
{
  int count[128]={0};
  int i;
  for(i=0;input[i]!='\0';i++)
    {
      count[input[i]]++;
    }
  for(int i=0;i<128;i++){
    if(count[i]>0)
    {
      printf("%c%d",i,count[i]);
    }
  }
}
int main()
{
  char input[100];
  printf("enter the input string ");
  scanf("%s",input);
  printf("Input: %s\n Output: ",input);
  count_frequency(input);
  return 0;
}

//Question -2 :Matrix Multiplication
//Take size of matrix as input from user
//Use pointer and dynamic memory to take matrix as input and then do matrix multiplication
#include<stdio.h>
#include<stdlib.h>
int **allocatematric(int row,int col)
{
    int **matrix=(int **)malloc(row*sizeof(int *));
    
    for(int i=0;i<row;i++)
    {
        matrix[i]=(int *)malloc(col*sizeof(int));
    }
    return matrix;
}
void inputmatrix(int **matrix,int row,int col,const char *name)
{
    printf("enter element of %s matrix\n",name);
     for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
}
void printmatrix(int **matrix,int row,int col,const char *name)
{
    printf("%s matrix is\n",name);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
int **multiplymatrix(int **A,int r1,int c1,int **B,int c2,int **result )
{
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            result[i][j]=0;
            for(int k=0;k<c1;k++)
            {
                result[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return result;
}
int main()
{
    int r1,r2,c1,c2;
    printf("enter the number of rows of first matrix ");
    scanf("%d",&r1);
    printf("enter the number of column of first matrix ");
    scanf("%d",&c1);
    int **A=allocatematric(r1,c1);
    inputmatrix(A,r1,c1,"first");
    printf("enter the number of rows of second matrix ");
    scanf("%d",&r2);
    printf("enter the number of columns of second matrix");
    scanf("%d",&c2);
    if(c1!=r2)
    {
        printf("matrix multiplication is not possible");
        return 1;
    }
    int **B=allocatematric(r2,c2);
    inputmatrix(B,r2,c2,"second");
    printmatrix(A,r1,c1,"first");
    printmatrix(B,r2,c2,"second");
    int **result=allocatematric(r1,c2);
    int **answer=multiplymatrix(A,r1,c1,B,c2,result);
    printmatrix(result,r1,c2,"result");
    return 0;
}
