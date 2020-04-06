#include<stdio.h>
main()
{
    int num,i,j;
    int pos=0;
    printf("Enter the no: ");
    scanf("%d",&num);

    for(i=num;i!=0;i=i/10)
    {
        pos++;
    }
printf("your no rotation is :\n");
    int digits[pos+1];
    for(i=0;i<pos;i++)
    {
        digits[pos-1-i]=num%10;
        num=num/10;

    }
    for(i=0;i<pos;i++)
        {
            for(j=i;j<pos;j++)
                printf("%d",digits[j]);
            for(j=0;j<i;j++)
                printf("%d",digits[j]);
            printf("\n");
        }

}
