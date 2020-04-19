#include <stdio.h>
#include <stdlib.h>
#define size 100
#include<string.h>
int top1 = -1;
int top=-1;

char stack[size];
struct node
{
	char ch;
	struct node *rchild;
	struct node *lchild;
}  *stack1[11];
typedef struct node node;
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
void infixtopost(char *arr)
{
    int i,x=0;
    char dis[size];
     for(i=0;arr[i]!='\0';i++)
    {

        if(priority(arr[i])>0)
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

    }


    while(top>=0)
    {
        dis[x++]=pop();//printf("%c",pop());
    }
    dis[x]='\0';
    strcpy(arr,dis);
}



void push1(node *str)
{
	if (top1 > 10)
	printf("Stack is Full ");
	else
	{	top1++;
		stack1[top1] = str;

	}
}

node *pop1()
{
	node *exp;
	if (top1 >= 10)
		printf("Stack is Empty ");
	else
		exp = stack1[top1--];
	return exp;
}
void convert(char exp[])
{
	node *op1,  *op2;
	node *temp;
	int i;
	for (i=0;exp[i]!='\0';i++)
	if (exp[i] >= 'a'&& exp[i] <= 'z'|| exp[i] >= 'A' && exp[i] <= 'Z'||exp[i] >= '0' && exp[i] <= '9')
	{
		temp = (node*)malloc(sizeof(node));
		temp->ch = exp[i];
		temp->rchild = NULL;
		temp->lchild = NULL;
		push1(temp);
	}
	else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' ||
exp[i] == '^')
	{
		op1 = pop1();
		op2 = pop1();
		temp = (node*)malloc(sizeof(node));
		temp->ch = exp[i];
		temp->rchild = op1;
		temp->lchild = op2;
		push1(temp);
	}
}

void inorder(node *temp)
{
	if (temp != NULL)
	{
	    printf("%c", temp->ch);
		if(temp->lchild!=NULL)
		printf("(");
		inorder(temp->lchild);

		inorder(temp->rchild);
		if(temp->rchild!=NULL)
		printf(")");
	}
}
 main()
{
	char exp[size];

	printf("Enter the infix exp expression :");
	scanf("%s", exp);
	infixtopost(exp);
	printf("the post fox of the above expression is: ");
	puts(exp);
	convert(exp);
	printf("\nThe Equivalent tree is expression is:");
	inorder(pop1());
	printf("\n\n");

}
