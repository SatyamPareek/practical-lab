#include<stdio.h>
#include<stdlib.h>
int size;
int *stack;
int top1;
int top2;
int top3;
void push(int val,int st)
{
    if(st==1)
    {
        if(top1>0)
            stack[--top1]=val;
        else
        printf("stack 1 overflow");
    }
    else if(st==2)
    {
        if(top2<2*size-1)
            stack[++top2]=val;
        else
        printf("stack 2 overflow");

    }
    else
    {
        if(top3<3*size-1)
            stack[++top3]=val;
        else
        printf("stack 3 overflow");

    }


}
int pop(int st)
{
    if(st==1)
    {
        if(top1<size)
            return stack[top1++];

        else
        printf("stack 1 under flow ");
        return -1;
    }
    else if(st==2)
    {
        if(top2>=size)
            return stack[top2--];

        else
        printf("stack 2 under flow ");
        return -1;

    }
    else
    {
        if(top3>=2*size)
            return stack[top3--];

        else
        printf("stack 3 under flow ");
        return -1;

    }


}


int main()
{

    printf("Enter the size of the stacks: ");
    scanf("%d",&size);
    stack=malloc(sizeof(int )*3*size);
    top1=size;
    top2=size-1;
    top3=2*size-1;

    int choice;
    while(1)
    {
        printf("\n\n1 to push in the first stack \n2 to push in the second \n3 to push in 3rd");
        printf("\n\n4 to pop form the first stack \n5 to pop form the second \n6 to pop form 3rd");
        printf("\n 7 to exit");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("\n Enter the value to be pushed: ");
                scanf("%d",&choice);
                push(choice,1);
            }
            break;
         case 2:
            {
                 printf("\n Enter the value to be pushed: ");
                scanf("%d",&choice);
                push(choice,2);

            }
            break;
         case 3:
            {
                 printf("\n Enter the value to be pushed: ");
                scanf("%d",&choice);
                push(choice,3);

            }
            break;
         case 4:
            {
                printf("\n %d poped",pop(1));

            }
            break;
         case 5:
            {
                printf("\n %d poped",pop(2));

            }
            break;
         case 6:
            {
                printf("\n %d poped",pop(3));
            }
            break;
         case 7:
            {
               printf("%d %d %d ",top1,top2,top3);
            }
            break;


        }




    }



return 0;
}
