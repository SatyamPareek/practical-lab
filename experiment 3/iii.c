#include<stdio.h>
#include<stdlib.h>

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
void QuickSort(int A[],int min, int max)
{

    int i,l,h,mid,temp;
    l=min;
    h=max;
    mid=A[(l+h)/2];

    while(l<=h)
    {
        while(mid>A[l])
            l++;
        while(mid<A[h])
            h--;
        if(l<=h)
        {
           swap(&A[l],&A[h]);
            l++;
            h--;

        }
    }

    if(l<max)
       QuickSort(A,l,max);
    if(h>min)
        QuickSort(A,min,h);

}
int main()
{
    int *arr;
    int n;
    printf("Enter the no of the elements in the array");
    scanf("%d",&n);

    arr=malloc(sizeof(int)*n);
    Get(arr,n);
    QuickSort(arr,0,n-1);
    printf("Array after sorting is : \n");
    put(arr,n);






return 0;
}
