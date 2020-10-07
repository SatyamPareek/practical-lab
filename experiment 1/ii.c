#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void str(char string[],int start,int lenght)
{

    int flag=0;

    int len=strlen(string);
    int i;
    for(i=0;(string[i+start-1]!='\0')&&start+i<=lenght;i++)
    {
        string[i]=string[start+i-1];


    }
    string[i]='\0';
}
int main()
{
    char string[100];
    int hel[256] = {0};

    printf("Enter the string to check: ");
    gets(string);
    printf("Enter start and lenght ");
    int start ,lenght;
    scanf("%d%d",&start,&lenght);
    str(string,start,lenght);

    puts(string);
return 0;
}
