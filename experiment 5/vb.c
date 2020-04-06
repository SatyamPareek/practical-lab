#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define size 100
int top=-1;
int step=0;

char stack[size];
void push(char val)
{
    if(top>=size-1)
    printf("stack overflow");

    else
    {
        stack[++top]=val;
    }

}
char pop()
{
    if(top<0)
    {
        printf("under flow");
        return -1;

    }


    else
    {
        return stack[top--];
    }

}

void display()
{
    int i;
    for(i=0;i<=top;i++)
    printf("%c ",stack[i]);
}
int priority( char x)
{
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    else if(x=='^')
        return 3;
    else
        return -1;
}
int isoperator(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
        return 1;

    else
        return 0;
}
main()
{ char arr[size];
    printf("do you want to display steps : 1 yes ");
    scanf("%d",&step);
    fflush(stdin);

    int x;
        char dis[size];
     x=0;
        printf("\n\nEnter the in fix form:  ");
    gets(arr);
    strrev(arr);

    int i;
    if(step==1)
    {
        printf("your output of the prefix form is : ");
    printf("\n\n\nEXP      STACK");
    int f=0;
    while(f<(30))
    {
        printf(" ",f++);
    }
    printf("OUTPUT\n");
    }


    for(i=0;arr[i]!='\0';i++)
    {   if(step==1)
    {
        printf("\n%c",arr[i]);
        printf("      ");
    }

        if(isoperator(arr[i]))
            {
                if(priority(stack[top])<priority(arr[i]))
                    push(arr[i]);
                else
                {
                    while((priority(stack[top])>=priority(arr[i])))
                        dis[x++]=pop();//printf("%c",pop());
                        push(arr[i]);
                }
            }
        else if( arr[i]=='(')
                push(arr[i]);

        else if( arr[i]==')')
        {
            while(stack[top]!='(')
                    dis[x++]=pop();//printf("%c",pop());
            pop();
        }
        else
            dis[x++]=arr[i];
    if(step==1)
    {
       int tt=top,j;
        printf("   ");
    display();
    for(j=0;j<((35)-2*tt);j++)
        printf(" ");

    int m;
    for(m=x-1;m>=0;m--)
        printf("%c ",dis[m]);
    printf("\n");
    }
    }


    while(top!=-1)
    {
        dis[x++]=pop();//printf("%c",pop());
    }
    printf("\nyour final result prefix: ");
    int g;
    strrev(dis);
    for(g=0;g<x;g++)
        printf("%c ",dis[g]);




    getch();

}
