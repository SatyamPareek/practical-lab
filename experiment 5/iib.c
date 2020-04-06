#include<stdio.h>
#include<stdlib.h>
#define size 100
char stack[size];
int top=-1;
void push(char ch)
{

    if(top<size-1)
        stack[++top]=ch;
    else
        printf("stack overflow");
}
char pop()
{
    if(top>=0)
        return stack[top--];
    else
        printf("under flow");

}

int main()
{
    char string[size];
    char *reverse;

    printf("Enter the string to check for paligdrome :  ");
    gets(string);
    int len;
    len=strlen(string);
    int i;
    for(i=0;i<len;i++)
        push(string[i]);
    int f=1;
    for(i=0;i<len;i++)
    {
        if(string[i]!=pop())
        {
            f=0;
            break;
        }
    }
    if(f)
        printf("\n palingdrome");
    else
        printf("not pal");



return 0;
}
