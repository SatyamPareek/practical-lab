#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
void str(char string[])
{
   int hel[256]={0};
    int len=strlen(string);
    int i;
    for(i=0;i<len;i++)
    {
        hel[string[i]]++;
    }
    for(i=0;i<256;i++)
    {
        if(hel[i]!=0)
        printf("%c %d \n",i,hel[i]);
    }
}

int main()
{
    char string[size];


    printf("Enter the string to check: ");
    gets(string);
    str(string);
    cin.get();
    return 0;

}
