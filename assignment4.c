#include<stdio.h>
#include<string.h>
#define MAX_ROWS 10
#define MAX_COLS 101
#define MAX_NAME_LENGTH 50
int main()
{
    int row,col;
    printf("please enter number of rows in this range 1<=R<=10\n");
    scanf("%d",&row);
     while (row < 1 || row > MAX_ROWS) {
        printf("Invalid input. Enter the number of rows (1-10):\n");
        scanf("%d", &row);
    }
    printf("please enter number of columns in this range 1<=C<=101\n");
    scanf("%d",&col);
    while (col < 1 || col > MAX_COLS) {
        printf("Invalid input. Enter the number of columns (1-101):\n");
        scanf("%d", &col);
    }
    char arr[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH];
    printf("enter the names\n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("Names at (%d,%d): ",i,j);
            scanf("%s", arr[i][j]);
        }
    }
    printf("2D array of names in matrix format\n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%s\t",arr[i][j]);
        }
        printf("\n");
    }
    int count=0;
    char longestname[50];
    int maxlength=0;
    printf("count of names starting with a vowel  ");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            //condition for checking count of names starting with a vowel
            if(arr[i][j][0]=='a'||arr[i][j][0]=='e'||arr[i][j][0]=='i'||arr[i][j][0]=='o'||arr[i][j][0]=='u')
            {
                count++;
            }
            //condition for finding longest name
            int length=strlen(arr[i][j]);
            if(length>maxlength)
            {
                maxlength=length;
                strcpy(longestname,arr[i][j]);
            }
        }
    }
    printf("%d\n",count);
    printf("longest name in the array\n");
    printf("%s",longestname);
    return 0;
}
