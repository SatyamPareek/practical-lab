#include<stdio.h>
#include<stdlib.h>
#define size 100
int main()
{
    int n;
    int arr[size];
    int hash[size];
    int m,i;
    printf("Enter the range N: ");
    scanf("%d", &m);
    for (i = 0; i <= m; i++)
        hash[i] = 0;

    printf("Enter the no of the elements of array");
    scanf("%d",&n);


    printf("Enter the no of the elemnts: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        hash[arr[i]]++;
    }
    printf("\n the missing Elements are : ");

    for(i=1;i<=m;i++)
    {
        if(hash[i]==0)
        printf("%d ",i);
        else
        {
            continue;
        }

    }


    return 0;
}
