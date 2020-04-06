#include<stdio.h>
#include<stdlib.h>
#define size 100
int stack[size];
int top1=-1;
int top2=size;

void push1(int val)
{

    if(top1<top2-1)
    {
        stack[++top1]=val;
    }
    else
        printf("\nStack overflow");


}
void push2(int val)
{

    if(top2>top1+1)
    {
        stack[--top2]=val;
    }
    else
        printf("\nstack overflow");
}
int pop1()
{

    if(top1>-1)
        return stack[top1--];
    else
        printf("\nunderflow for the first");
        return -1;
}
int pop2()
{
    if(top2<size-1)
        return stack[top2++];
    else
        printf("\nstack underflow for the last");
        return -1;
}



int main()
{


    int choice;
    while(1)
    {
        printf("\n\n1 to insert in the first \n2 to insert in the second \n3 to pop1 \n4 to pop 2 \n5 to exit");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter the value to insert: ");
            scanf("%d",&choice);
            push1(choice);

        }
        else if(choice==2)
        {


            printf("Enter the value to insert: ");
            scanf("%d",&choice);
            push2(choice);
        }
        else if(choice==3)
        {

            printf("\n%d popped",pop1());
        }
        else if(choice==4)
        {

            printf("\n%d popped",pop2());
        }
        else if(choice==5)
            exit(0);

    }



return 0;
}
