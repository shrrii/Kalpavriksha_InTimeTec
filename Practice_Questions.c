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
//Question 7: There is some problem in this question

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
//Question 10:Write a program to find the longest palindromic substring in a given string. A palindrome reads the same forward 
//and backward. If there are multiple longest palindromic substrings of the same length, return any one of them.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
bool checkpalindrome(char *str,int low,int high)
{
    while(low<high)
    {
        if(str[low]!=str[high])
        {
            return false;
        }
        low++;
        high--;
    }
    return true;
}
void print(char *str,int n,char *result)
{
    int start=0,maxlen=1;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(checkpalindrome(str,i,j)&&(j-i+1)>maxlen)
            {
                start=i;
                maxlen=j-i+1;
            }
        }
    }
    strncpy(result,str+start,maxlen);
    result[maxlen]='\0';
}
int main()
{
    int row,col;
    char *str;
    str=(char *)malloc(500*sizeof(char));
    fgets(str,500,stdin);
    int n=strlen(str);
    char result[500];
    print(str,n,result);
    printf("%s",result);
    return 0;
}
//Question 11: Generate and print all permutations of a given string. Assume all characters in the string are unique.
#include <stdio.h>
#include<string.h>
void swap(char *a,char *b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void permutation(char *str,int first,int last)
{
    if(first==last)
    {
        printf("%s ",str);
    }
    else{
        for(int i=first;i<=last;i++)
        {
            swap((str+first),(str+i));
            permutation(str,first+1,last);
            swap((str+first),(str+i));
        }
    }
}
int main()
{
    char str[500];
	scanf("%s",str);
    int n=strlen(str);
    permutation(str,0,n-1);
    return 0;
}
//Question 12: write a program to check if one string is a rotation of another.
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
    char *str1,*str2;
    str1=(char *)malloc(1000*sizeof(char));
    str2=(char *)malloc(1000*sizeof(char));
    printf("enter the string\n");
    scanf("%[^\n]",str1);
    getchar();
    printf("enter the substring\n");
    scanf("%[^\n]",str2);
    int n=strlen(str1);
    int m=strlen(str2);
    if(solve(str1,str2,n,m)==1)
    {
        printf("true");
    }else{
        printf("false");
    }
    return 0;
}
//Question 13: Find the smallest substring in a given string that contains all the characters of another string.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define char_count 256
char* smallest_substring(char* str,char* substr)
{
    int n=strlen(str);
    int m=strlen(substr);
    if(m==0)
    {
        return " ";
    }
    if(m>n)
    {
       return "No such substring found";
    }
    int str_count[char_count]={0};
    int substr_count[char_count]={0};
    for(int i=0;i<m;i++)
    {
        substr_count[substr[i]]++;
    }
    int start=0,minlength=INT_MAX,start_ind=-1,count=0;
    for(int i=0;i<n;i++)
    {
        str_count[str[i]]++;
        if(substr_count[str[i]]!=0&&str_count[str[i]]<=substr_count[str[i]])
        {
            count++;
        }
        if(count==m)
        {
            while(str_count[str[start]]>substr_count[str[start]]||
                  substr_count[str[start]]==0){
                      if(str_count[str[start]]>substr_count[str[start]]){
                          str_count[str[start]]--;
                      }
                      start++;
                  }
                  int windowlength=i-start+1;
                  if(minlength>windowlength)
                  {
                      minlength=windowlength;
                      start_ind=start;
                  }
        }
    }
    if(start_ind==-1)
    {
        return "no such substring found";
    }
    static char result[10000];
    strncpy(result,str+start_ind,minlength);
    result[minlength]='\0';
    return result;
}
int main()
{
    char *str,*substr;
    str=(char*)malloc(10000*sizeof(char));
    substr=(char*)malloc(10000*sizeof(char));
    if(str==NULL||substr==NULL)
    {
        printf("memory allocation failed\n");
        return 1;
    }
    printf("enter the string\n");
    fgets(str,10000,stdin);
    printf("enter the substring\n");
    fgets(substr,10000,stdin);
    str[strcspn(str,"\n")]='\0';
    substr[strcspn(substr,"\n")]='\0';
    char* result=smallest_substring(str,substr);
    printf("smallest substring is: %s",result);
    free(str);
    free(substr);

    return 0;
}
//Question 14: Write a program to remove adjacent duplicate characters in a string recursively until no adjacent duplicates remain.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void new_string(char *str,int id,int n,int start)
{
    for(int i=start;i<n;i++)
    {
        str[id++]=str[i];
    }
    str[id]='\0';
}
void remove_adjacent(char *str)
{
    int n=strlen(str);
    for(int i=0;i<n-1;i++)
    {
        if(str[i]==str[i+1])
        {
            int start=i+2;
            new_string(str,i,n,start);
            remove_adjacent(str);
            return;
        }
    }
}
int main()
{
    char *str;
    str=(char *)malloc(10000*sizeof(char));
    printf("enter the string\n");
    fgets(str,10000,stdin);
    str[strcspn(str,"\n")]='\0';
    remove_adjacent(str);
    printf("resultant string is: %s",str);
    free(str);
    return 0;
}
//Question 15:Write a program in C to validate whether a given string is a valid IPv4 address.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int check(char *str,int n)
{
    if(n>15)
    {
        return 0;
    }
    int count=0;
    char *token=strtok(str,".");
    while(token!=NULL)
    {
        count++;
        if(count>4)
        {
            return 0;
        }
        int num=0;
        for(int i=0;token[i]!='\0';i++)
        {
            if(token[i]<'0'||token[i]>'9')
            {
                return 0;
            }
            num=num*10+(token[i]-'0');
        }
        if(num<0||num>255)
        {
            return 0;
        }
        token=strtok(NULL,".");
    }
    return count==4;
}
int main()
{
    char *str;
    int maxlen=20;
    str=(char *)malloc(maxlen*sizeof(char));
    printf("enter the IP address\n");
    fgets(str,maxlen,stdin);
    str[strcspn(str,"\n")]='\0';
    int n=strlen(str);
    int ans=check(str,n);
    if(ans==1)
    {
        printf("valid");
    }else{
        printf("invalid");
    }
    free(str);
    return 0;
}
