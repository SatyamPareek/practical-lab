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
        printf("overfow");

}
char pop()
{

    if(top>-1)
        return stack[top--];
    else
        printf("under flow");


}
int main()
{
    char exp[size];
    int f=1,i;
    printf("Enter the expression : ");
    gets(exp);
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            push(exp[i]);
        else if(exp[i]==')')
        {
            while(stack[top]!='(')
            {
                if(stack[top]=='['||stack[top]=='{')
                    {
                        f=0;
                        break;
                    }
                pop();
            }
            pop();


        }
        else if(exp[i]=='}')
        {
            while(stack[top]!='{')
            {
                if(stack[top]=='['||stack[top]=='(')
                    {
                        f=0;
                        break;
                    }
                pop();
            }
            pop();


        }
        else if(exp[i]==']')
        {
            while(stack[top]!='[')
            {
                if(stack[top]=='('||stack[top]=='{')
                    {
                        f=0;
                        break;
                    }
                pop();
            }
            pop();


        }

        if (f==0)
            break;



    }
    if(top>-1)
    f=0;
    if(f)
        printf("\nbraces matched");
    else
        printf("\n not matched");


return 0;
}
