//24-jan (binary search) Qus-Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the
//kth position of the combined sorted array without using extra space
#include<stdio.h>
int main()
{
    int n,m;
    printf("enter the size of first array.\n");
    scanf("%d",&n);
    printf("enter the size of second array.\n");
    scanf("%d",&m);
    int arr1[n],arr2[m];
    printf("enter the elements of first sorted array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("enter the elements of second sorted arary\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr2[i]);
    }
    int k;
    printf("enter value of k\n");
    scanf("%d",&k);
    if(k==0)
    {
        printf("invalid value of k.\n");
        return 0;
    }
    else if(k>(n+m))
    {
        printf("value of k is greater than the size of combined array.\n");
        return 0;
    }
    int count=0;
    int left=0,right=0;
    while(left<n&&right<m)
    {
        if(arr1[left]>arr2[right])
        {
            count++;
            if(count==k)
            {
                printf("kth element is %d\n",arr2[right]);
                return 0;
            }
            right++;
        }else if(arr1[left]<arr2[right])
        {
            count++;
            if(count==k)
            {
                printf("kth element is %d\n",arr1[left]);
                return 0;
            }
            left++;
        }
        else{
            count++;
            if(count==k)
            {
                printf("kth element is %d\n",arr2[right]);
                return 0;
            }
            count++;
            if(count==k)
            {
                printf("kth element is %d\n",arr2[right]);
                return 0;
            }
            left++;
            right++;
        }
    }
    while(left<n)
    {
        count++;
         if(count==k)
            {
                printf("kth element is %d\n",arr1[left]);
                return 0;
            }
        left++;
    }
    while(right<m)
    {
        count++;
        if(count==k)
        {
            printf("kth element is %d\n",arr2[right]);
            return 0;
        }
        right++;
    }
    return 0;
}
