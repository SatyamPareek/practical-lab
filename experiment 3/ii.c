#include<stdio.h>
#include<stdlib.h>
int step;
void Get(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void put(int A[],int n)
{
    int i;
    printf("your list is \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void insertion(int A[],int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {
        j=i-1;
        x=A[i];
        while(j>-1&&A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
        if(step==1)
        {
            printf("\npass %d\n",i);
            put(A,n);
        }
    }
}
void SelectionSort(int A[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k])
                k=j;
        }
       swap(&A[i],&A[k]);
       if(step==1)
        {
            printf("\npass %d\n",i);
            put(A,n);
        }
    }
}
int main()
{
    int *arr;
    int n,choice;
    printf("Enter the no of the elements in the array");
    scanf("%d",&n);
    arr=malloc(sizeof(int)*n);
    Get(arr,n);
    while(1)
    {

        printf("\n\n1 to insertion sort \n2 to selecion sort: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("do you want to see steps:  1 yes 2 no");
            scanf("%d",&step);

            insertion(arr,n);
            printf("Array after sorting is : \n");
            put(arr,n);

        }
        else if(choice==2)
        {
            printf("do you want to see steps:  1 yes 2 no");
            scanf("%d",&step);
            SelectionSort(arr,n);
            printf("Array after sorting is : \n");
            put(arr,n);


        }







    }



return 0;
}
