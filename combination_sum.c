//23-jan (recursion) Qus- given an array of distinct integers and a target integer, return a list of all unique combinations of array where the sum of 
//array is equal to target, you can choose combinations in any order and also use duplicates of elements. 
#include<stdio.h>
void combination_sum(int arr[],int n,int ind,int target,int list[],int id)
{
    if(ind==n)
    {
        if(target==0)
        {
            printf("[");
            for(int i=0;i<id;i++)
              {
                  if(i==id-1)
                  {
                      printf("%d",list[i]);
                  }
                  else{
                      printf("%d ",list[i]);
                  }
              }
            printf("] ");
        }
        return;
    }
    if(arr[ind]<=target)
    {
        list[id]=arr[ind];
        combination_sum(arr,n,ind,target-arr[ind],list,id+1);
    }
    combination_sum(arr,n,ind+1,target,list,id);
}
int main()
{
    int n;
    printf("enter the number of elements.\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements.\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int target;
    printf("enter the target.\n");
    scanf("%d",&target);
    int list[n];
    printf("combinations are - \n[");
    combination_sum(arr,n,0,target,list,0);
    printf("]");
}
