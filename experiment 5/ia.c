#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int size;
    int *p;
    int data;

};
 typedef struct stack stack;

 void push(stack *s)
 {
     if(s->top>=s->size-1)
        printf("overflow");
        else
        {



                printf("enter the value : ");
                scanf("%d",&s->data);


            s->p[++(s->top)]=s->data;
        }

 }
 int pop(stack *s)
 {
     if(s->top<0)
        {
            printf("underflow");
            return -1;
        }
     else
        {
            int x;
            x=s->p[s->top];
        s->top--;
        return x;
        }
 }



 void create(stack *s)
 {  s->top=-1;
     printf("Enter the size: ");
     scanf("%d",&s->size);
     s->p=(int *)malloc(sizeof(stack)*s->size);
     s->data=0;
 }
 void display(stack s)
 {
     int i;
     for(i=0;i<=s.top;i++)
        printf(" %d ",s.p[i]);
 }
 int isempty(stack s)
 {
     if(s.top==-1)
        return 1;
     return 0;
 }
 int isfull(stack s)
 {
     if(s.top==s.size-1)
        return 1;
     return 0;
 }
int main()
{
    int option;
stack s;

    create(&s);
    do{int data;
        printf("\n\n1. push\n2. pop\n3. display \n4. exit\nEnter the option : ");
        scanf("%d",&option);
        switch (option)
        {
        case 1 :

        push(&s);

            /* code */
            break;
        case 2:
        printf("The deleted value is %d ",pop(&s));
        break;
        case 3:
        display(s);
        break;
        case 4:
        exit(0);
        break;

        default:printf("invalid option");
            break;
        }
    }while(1);
return 0;
}
