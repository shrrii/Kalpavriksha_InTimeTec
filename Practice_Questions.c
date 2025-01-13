// Question 1: Write a program to remove all duplicate characters from a given string
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void unique_string(char *str){
    int n=strlen(str);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(str[i]==str[j])
            {
                for(int k=j;k<n;k++)
                {
                    str[k]=str[k+1];
                }
            }
        }
    }
}
int main()
{
    char *str;
    int length;
    printf("enter length of the string\n");
    scanf("%d",&length);
    getchar();
    str=(char *)malloc((length+1)*sizeof(char));
    printf("enter string\n");
    fgets(str,length+1,stdin);
    printf("string is:\n%s",str);
    unique_string(str);
    printf("\nunique characters string is\n");
    printf("%s",str);
    return 0;
}
//Question 2: write a program to count the number of words in the string.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int solve(char str[],int n)
{
    int count=0;
    int word=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]!=' '&&str[i]!='\n')
        {
            if(!word)
            {
                count++;
                word=1;
            }
        }
        else{
            word=0;
        }
    }
    return count;
}
int main()
{
    char str[5000];
    printf("enter the string\n");
    scanf("%[^\n]",str);
    int n=strlen(str);
    int ans=solve(str,n);
    printf("%d",ans);
    return 0;
}
//Question 3: write a program to check if a given substring is present in given string or not 
//if yes then return the first index of the substring from string
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int solve(char str[],char substr[],int n,int m)
{
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        if(str[i]==substr[0])
        {
            ans=i;
            i++;
            for(int j=1;j<m;j++,i++)
            {
                if(str[i]!=substr[j])
                {
                    ans=-1;
                }
            }
            return ans;
        }
    }
    return ans;
}
int main()
{
    char str[1000],substr[1000];
    printf("enter the string\n");
    scanf("%[^\n]",str);
    getchar();
    printf("enter the substring\n");
    scanf("%[^\n]",substr);
    int n=strlen(str);
    int m=strlen(substr);
    int result=solve(str,substr,n,m);
    printf("%d",result);
    return 0;
}
//Question 4: write a program to check if one string is rotation of another string
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int k,l;
int solve(char str[],char substr[],int n,int m)
{
    if(n!=m)
    {
       return 0;
    }
    for(int j=0;j<m;j++)
        {
            if(str[0]==substr[j])
            {
                int match=1;
                k=j;
                for(int i=0;i<n;i++)
                {
                    if(str[i]!=substr[k])
                    {
                        match=0;
                        break;
                    }
                    k=(k+1)%m;
                }
                if(match)
                 return 1;
            }
        }
        return 0;
}
int main()
{
    char str[1000],substr[1000];
    printf("enter the string\n");
    scanf("%[^\n]",str);
    getchar();
    printf("enter the substring\n");
    scanf("%[^\n]",substr);
    int n=strlen(str);
    int m=strlen(substr);
    if(solve(str,substr,n,m)==1)
       printf("true");
    else
    {
        printf("false");
    }
    return 0;
}
//Question 5: write a program to convert a string into integer,function should handle negative numbers and return 0 for invalid inputs.
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int solve(char *str)
{
    int sign=1;
    int result=0;
    while(*str==' '||*str=='\t'||*str=='\n')
       {
           str++;
       }
       if(*str=='-'||*str=='+')
       {
           if(*str=='-')
           {
               sign=-1;
           }
           str++;
       }
       while(*str){
           if(*str=='\n')
           {
               break;
            }else if(isdigit(*str))
            { 
                result=result*10+(*str-'0');
            }
            else
            {
                return 0;
            }
            str++;
       }
      return sign*result;
}
int main()
{
   char *str;
   int maxlen;
   printf("enter the length of the string\n");
   scanf("%d",&maxlen);
   str=(char *)malloc((maxlen+1)*sizeof(char));
   getchar();
   printf("enter the string\n");
   fgets(str,maxlen+1,stdin);
   int ans=solve(str);
   printf("\ndigits are: %d",ans);
   free(str);
    return 0;
}
//Question 6: write a program to check if two strings are anagrams of each other or not.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void sort_string(char *str,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(str[j]>str[j+1])
            {
                char temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
}
int check(char *str1,char *str2,int n,int m)
{
    if(n!=m)
    {
        return 0;
    }
  for(int i=0;i<n;i++)
  {
      if(str1[i]!=str2[i])
      {
          return 0;
      }
  }
  return 1;
}
int main()
{
    char *str1,*str2;
    str1=(char *)malloc(500*sizeof(char));
    str2=(char *)malloc(500*sizeof(char));
    printf("enter the first string\n");
    scanf("%[^\n]",str1);
    getchar();
    printf("enter the second string\n");
    scanf("%[^\n]",str2);
    int n=strlen(str1);
    int m=strlen(str2);
    sort_string(str1,n);
    sort_string(str2,m);
    int ans=check(str1,str2,n,m);
    if(ans==0)
    {
        printf("false");
    }
    else
    {
       printf("true");
    }
    return 0;
}
//Question 7: 

//Question 8: Write a program to compress a string by replacing consecutive occurrences of the same character with the character 
//followed by the count. If the compressed string is not smaller than the original, return the original string.
#include <stdio.h>
#include<stdlib.h>
void compress(char *str)
{
    int count[128]={0};
    int should_compress=0;
    for(int i=0;str[i]!='\0';i++)
    {
        count[str[i]]++;
        if(count[str[i]]>1)
        {
            should_compress=1;
        }
    }
    if(!should_compress)
    {
        printf("%s",str);
        return;
    }
    for(int i=0;i<128;i++)
    {
        if(count[i]>0)
        {
            printf("%c%d",i,count[i]);
        }
        else if(count[i]==1)
        {
            printf("%c",i);
        }
    }
}
int main()
{
    char *str;
    str=(char *)malloc(500*sizeof(char));
    printf("enter the string\n");
    scanf("%[^\n]",str);
    printf("compressed string is\n");
    compress(str);
    return 0;
}
//Question 9: Write a program to remove all instances of a specific character from a string.
#include <stdio.h>
#include<stdlib.h>
int removed(char *str,char remove_char)
{
    int id=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]!=remove_char)
        {
            str[id++]=str[i];
        }
    }
    return id;
}
int main()
{
    char *str;
    str=(char *)malloc(500*sizeof(char));
    printf("enter the string\n");
    scanf("%[^\n]",str);
    char remove_char;
    getchar();
    printf("enter the character to remove from string\n");
    scanf("%c",&remove_char);
    int size=removed(str,remove_char);
    printf("updated string\n");
    for(int i=0;i<size;i++)
    {
        printf("%c",str[i]);
    }
    return 0;
}
//Question 10:
