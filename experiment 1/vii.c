#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char str1[],char str2[])
{
    int n1,n2;
    n1=strlen(str1);
    n2=strlen(str2);
    int m=n1>n2?n1:n2;
    int i;
    char temp;
    for(i=0;i<m;i++)
    {
        temp=str1[i];
        str1[i]=str2[i];
        str2[i]=temp;
    }
}
int main()
{
    char str1[100],str2[100];
    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string :");
    gets(str2);

    swap(str1,str2);
    printf("the first string: \n");
    puts(str1);
    printf("\nthe second string: \n");
    puts(str2);

return 0;
}