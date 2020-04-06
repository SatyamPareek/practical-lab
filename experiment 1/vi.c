#include<stdio.h>
#include<stdlib.h>
void Reverse(int arr[],int n)
{
    int i;
    for(i=0;i<(n/2);i++)
    {
        arr[i] = arr[i] ^ arr[n - i-1];
        arr[n-i-1] = arr[i] ^ arr[n - i-1];
        arr[i] = arr[i] ^ arr[n - i-1];
    }

}

int main()
{
    int arr[100];
    int n;
    printf("Enter the no of The elements");
    scanf("%d",&n);
    int i;
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    Reverse(arr,n);

    printf("The reverse of the array is\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

return 0;
}
