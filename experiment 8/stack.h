#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<stdlib.h>
#include"tree.h"

struct stack
{
    int top;
    int size;
    node **S;

};
 typedef struct stack stack;

 void push(stack *s,node *data)
 {
     if(s->top>=s->size-1)
        printf("overflow");
        else
        {


            s->S[++(s->top)]=data;
        }

 }
 node * pop(stack *s)
 {
     if(s->top<0)
        {

            return NULL;
        }
     else
        {
            node *x;
            x=s->S[s->top];
        s->top--;
        return x;
        }
 }



 void createStack(stack *s,int size)
 {  s->top=-1;
     s->size=size;
     s->S=(node**)malloc(sizeof(node*)*s->size);

 }
 void display(stack s)
 {
     int i;
     for(i=0;i<=s.top;i++)
        printf(" %d ",s.S[i]);
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
