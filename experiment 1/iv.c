#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int num1,num2;
    printf("Enter the two number:");
    scanf("%d%d",&num1,&num2);
    printf("The number before swaping: num 1=%d num2= %d \n",num1,num2);
    swap(&num1,&num2);
    printf("The number after  swaping: num 1=%d num2= %d \n", num1, num2);
    return 0;
}