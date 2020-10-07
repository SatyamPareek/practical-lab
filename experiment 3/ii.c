#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20
int step;
void Get(char A[][size],int n)
{
    int i;
    fflush(stdin);
    for(i=0;i<n;i++)
    {
        scanf("%s",&A[i]);
    }
}
void swap(char a[size],char b[size])
{
    char temp[size];
    strcpy(temp,a);
    strcpy(a, b);
    strcpy(b,temp);
    
}
void put(char A[][size],int n)
{
    int i;
    printf("your list is \n");
    for(i=0;i<n;i++)
    {
        printf("%s \n",A[i]);
    }
    printf("\n");
}
void insertion(char A[][size],int n)
{
    int i,j;
    char str[size];
    for(i=1;i<n;i++)
    {
        j=i-1;
        
        strcpy(str,A[i]);
        
        while(j>-1&&strcmp(A[j],str)>0)
        {
            strcpy(A[j+1],A[j]);
            j--;
        }
        strcpy(A[j+1],str);
        if(step==1)
        {
            printf("\npass %d\n",i);
            put(A,n);
        }
    }
}
void SelectionSort(char A[][size],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(strcmp(A[j],A[k])<0)
                k=j;
        }
       swap(A[i],A[k]);
       if(step==1)
        {
            printf("\npass %d\n",i);
            put(A,n);
        }
    }
}
int main()
{
    
    int n,choice;
    printf("Enter the no of the elements in the array");
    scanf("%d",&n);
    char arr[size][n];
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
