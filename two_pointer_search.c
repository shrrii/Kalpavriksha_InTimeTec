//two_pointer_search
#include <stdio.h>
void two_pointer_search(int* arr,int n,int k)
{
    int left=0,right=n-1;
    while(left<right)
    {
        if(arr[left]==k)
        {
            printf("element found at %d position",left+1);
            return;
        }
        else if(arr[right]==k)
        {
            printf("element found at %d position",right+1);
            return;
        }
        else{
            left++;
            right--;
        }
    }
    printf("element not found.\n");
}
int main()
{
    int n;
    printf("enter the size of array.\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements of the array.\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int k;
    printf("enter element to search in array.\n");
    scanf("%d",&k);
    two_pointer_search(arr,n,k);
    return 0;
} 
