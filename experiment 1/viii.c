#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[100];
    int n;
    
    int max,min;
    printf("Enter the no of the elements: ");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    min=max=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
        if(arr[i]<min)
        min=arr[i];
    }
    int m=max-min+1;
    int hash[m];
    for(i=0;i<m;i++)
    hash[i]=0;
    
    for(i=0;i<n;i++)
    {
        hash[arr[i]-min]++;
    }
    for(i=0;i<n;i++)
    {
        if(hash[arr[i]-min]==1)
        printf("%d ",arr[i]);
        else
        {
            continue;
        }
        
    }
return 0;
}