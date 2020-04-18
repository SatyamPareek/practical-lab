#include<stdio.h>
#include<stdlib.h>

struct term
{

    int coef;
    int exp;

    struct term* next;

};

typedef struct term term;
term *createterm()
{
    term* newterm;
    newterm=(term *)malloc(sizeof(term));
    newterm->next=NULL;
    return newterm;
}



term* create(struct term *head)
{
    printf("\nEnter the no of terms ?");

    int n;
    scanf("%d",&n);


    term *temp;
    temp=head;
    int i=0;

    printf("\nEnter the terms in decreasing coeff\n");



    for(i=0;i<n;i++)
    {
        if(head==NULL)
        {
            head=createterm();
            printf("coefficient and power : ");
            scanf("%d%d",&head->coef,&head->exp);
            temp=head;

        }
        else
        {
            temp->next=createterm();
            printf("coefficient and power : ");
            scanf("%d%d",&temp->next->coef,&temp->next->exp);
            temp=temp->next;

        }
    }

return head;
}
void display(term* head)
{

    term *temp;
    int i=0;

    for(temp=head;temp;temp=temp->next)
    {
        printf(" \nterms %d \n\tcoeff: ",i+1);
        printf("%d",temp->coef);
        printf("\n\tpower: ");
        printf("%d",temp->exp);
        i++;
    }


}
void print( term *p)
{
    int i;
    printf("\n");
    term *temp=p;
    for(;temp->next;)
    {
        if(temp->coef)
        printf("   %d ",temp->exp);
        temp=temp->next;
    }
    if(temp->coef)
    printf("   %d ",temp->exp);
    printf("\n");
    temp=p;
    for(;temp->next;)
    {
        if(temp->coef)
        printf("%2dX +",temp->coef);
        temp=temp->next;
    }
    if(temp->coef)
        printf("%2dX",temp->coef);

    printf("\n");
}
int compare(term *t1,term *t2)
{


    while(t1&&t2)
    {
        if(t1->exp>t2->exp)
        {
            return -1;
        }
        else if(t1->exp<t2->exp)
        {
            return 1;
        }
        else
        {
                if(t1->coef>t2->coef)
                {
                    return -1;
                }
                else if(t1->coef<t2->coef)
                {
                    return 1;
                }


        }
        t1=t1->next;
        t2=t2->next;

    }
    if(t1)
        return -1;
    else if(t2)
        return 1;
    else
        return 0;





}

int main()
{

    term *head1=NULL;
    term *head2=NULL;


    head1=create(head1);
    head2=create(head2);
    print(head1);
    print(head2);
    int d;
    d=compare(head1,head2);
    if(d>0)
        printf("second is big");
    else if(d<0)
        printf("second is big");
    else
    printf("equal");
}
