#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Get(char A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%c",&A[i]);
    }
}
void swap(char *a,char *b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void put(char A[],int n)
{
    int i;
    printf("your list is \n");
    for(i=0;i<n;i++)
    {
        printf("%c ",A[i]);
    }
    printf("\n");
}
void QuickSort(char A[],int min, int max)
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
    char arr[100];
    int n;
    printf("Enter the string arrayfor sorting : ");
    scanf("%s",arr);
    n=strlen(arr);
    QuickSort(arr,0,n-1);
    printf("Array after sorting is : \n");
    put(arr,n);
return 0;
}
