#include <stdio.h>
#include <stdlib.h>
void swap(int a[], int b[],int n)
{
    int i,temp;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    } 
}
int main()
{
    int num1[100], num2[100];

    printf("Enter the size of the arays:");
    int n;
    scanf("%d", &n);
    int i;
    printf("input the first array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num1[i]);
    }
    printf("input the second array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num2[i]);
    }
    printf("\noutput the first array\n");
    

    swap(&num1, &num2,n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", num1[i]);
    }
    printf("\noutput the second array\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", num2[i]);
    }

    return 0;
}