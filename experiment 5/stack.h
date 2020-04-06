#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
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
            if(s->data==0)
            {

                printf("enter the value : ");
                scanf("%d",&s->data);
            }

            s->p[++(s->top)]=s->data;
        }
    s->data=0;
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






#endif // STACK_H_INCLUDED
