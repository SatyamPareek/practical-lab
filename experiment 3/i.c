#include<stdio.h>
#include<stdlib.h>
int LinearSearch( int *arr,int key ,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(key==arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int *arr;
    int n;
    printf("Enter the no of the elements in the array");
    scanf("%d",&n);
    arr=malloc(sizeof(int)*n);
    int i;
    printf("Enter the array: \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int key;
   while(1)
   {
       printf("press 1 to search 2 to exit :");
       scanf("%d",&key);
        if(key==1)
        {
             printf("\nEnter the value to search: ");
    scanf("%d",&key);
    key=LinearSearch(arr,key,n);
    if(key!=-1)
        printf("\nfound at %d index" ,key+1);
    else
        printf("\nnot found ");
        }
        else if(key==2)
            exit(0);

   }



return 0;
}
