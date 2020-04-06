#include<stdio.h>
#include<stdlib.h>
#define size 100
int main()
{
    int  *arr1 ,*arr2,*merge,n;
    printf("Enter the no of the elements: ");
    scanf("%d",&n);
    arr1 = malloc(sizeof(int) * n);
    arr2 = malloc(sizeof(int) * n);
    merge = malloc(sizeof(int) * n*2);
    int i;
    printf("input the array in sorted order : \n");
    printf("Input the first array : \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr1[i]);
    int j,k;
    printf("Enter the second array: \n");
    for (i = 0; i < n; i++)
        scanf("%d",&arr2[i]);
    i=0;j=0;k=0;
    while(i<n&&j<n)
    {
        if(arr1[i]<arr2[j])
        {
            merge[k++]=arr1[i++];
        }
        else if (arr1[i] > arr2[j])
        {
            merge[k++] = arr2[j++];
        }
        else
        {
            merge[k++] = arr2[j++];
            i++;
        }

    }
    for(;i<n;i++)
        merge[k++]=arr1[i];
    for(;j<n;j++)
        merge[k++]=arr2[j];
    printf("\nmerged\n");
    free(arr1);
    free(arr2);
    for(i=0;i<k;i++)
        printf("%d ",merge[i]);
    printf(" \n Median is:");
    if(k%2==1)
    printf("%d",merge[k/2]);
    else
    {
        printf("%d,%d ",merge[(k)/2-1],merge[(k/2)]);
    }
    


    
    




    return 0;
}
