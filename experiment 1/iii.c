#include<stdio.h>
#include<stdlib.h>

void str(char string[],char ch)
{

    int flag=0;

    int len=strlen(string);
    int i;
    for(i=0;i<len;i++)
    {
        if(string[i]==ch)
        {
            int j;
            for(j=i;j<len;j++)
            {
                string[j]=string[j+1];

            }
            len--;
            break;
        }
    }
}
int main()
{
    char string[100];
    int hel[256] = {0};

    printf("Enter the string to check: ");
    gets(string);
    printf("Enter the character to delete: ");
    char ch;
    scanf("%c",&ch);
    str(string,ch);

    puts(string);
return 0;
}
