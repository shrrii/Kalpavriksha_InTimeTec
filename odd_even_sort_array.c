//27-jan-2025 Qus- Given an array arr[] of positive integers. Your task is to sort them so that the first part of the array contains odd numbers 
//sorted in descending order, and the rest of the portion contains even numbers sorted in ascending order.
#include <stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void print(int odd[],int even[],int k,int l)
{
for(int i=0;i<k;i++)
    {
        printf("%d ",odd[i]);
    }
    for(int i=0;i<l;i++)
    {
        printf("%d ",even[i]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int even[n],odd[n];
    int l=0,k=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            even[l]=arr[i];
            l++;
        }
        else if(arr[i]%2!=0)
        {
            odd[k]=arr[i];
            k++;
        }
    }
    for(int i=0;i<l-1;i++)
    {
        for(int j=0;j<l-i-1;j++)
        {
            if(even[j]>even[j+1])
            {
                swap(&even[j],&even[j+1]);
            }
        }
    }
    for(int i=0;i<k-1;i++)
    {
        for(int j=0;j<k-i-1;j++)
        {
            if(odd[j]<odd[j+1])
            {
                swap(&odd[j],&odd[j+1]);
            }
        }
    }
    print(odd,even,k,l);
    return 0;
}
