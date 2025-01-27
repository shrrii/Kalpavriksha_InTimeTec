//24-jan (recursion) Qus-You are given an array 'A' of 'N' integers. You have to return true if there exists a subset of elements
//of 'A' that sums up to 'K'. Otherwise, return false.
#include <stdio.h>
#include<stdbool.h>
bool find_combination(int arr[],int n,int k,int id)
{
    if(k==0)
    {
        return true;
    }
    if(id==n||k<0)
    {
        return false;
    }
    bool take=find_combination(arr,n,k-arr[id],id+1);
    bool not_take=find_combination(arr,n,k,id+1);
    return take||not_take;
}
int main()
{
    int n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    int k;
    printf("enter the value of target\n");
    scanf("%d",&k);
    int arr[n];
    printf("enter elements.\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    if(find_combination(arr,n,k,0))
    {
        printf("true");
    }else{
        printf("false");
    }
    return 0;
}
