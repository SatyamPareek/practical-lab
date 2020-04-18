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
term* add(term *t1,term *t2 )
{
    term *temp1;
    term *temp2;
    term *temp3;
    temp1=t1;
    temp2=t2;
    term *newnode=createterm();
    temp3=newnode;
    term *prev;
    while(temp1&&temp2)
    {
        prev=temp3;
        if(temp1->exp>temp2->exp)
           {
            temp3->coef=temp1->coef;
            temp3->exp=temp1->exp;
            temp3->next=createterm();
            temp3=temp3->next;
            temp1=temp1->next;

           }
        else if(temp1->exp<temp2->exp)
           {
            temp3->coef=temp2->coef;
            temp3->exp=temp2->exp;
            temp3->next=createterm();
            temp3=temp3->next;
            temp2=temp2->next;
           }
           else
           {
            temp3->coef=temp1->coef+temp2->coef;
            temp3->exp=temp1->exp;
            temp3->next=createterm();

            temp3=temp3->next;
            temp1=temp1->next;
            temp2=temp2->next;
           }

    }
    if(temp1)
    prev->next=temp1;
    else
        prev->next=temp2;
    return newnode;
}
term *mult(term *t1, term *t2)
{

    term *temp1,*temp2,*temp3;

    term* result=createterm();
    result->exp=0;
    result->coef=0;
    temp2=t2;
    while(temp2)
    {
        term *temp;
        temp3=NULL;
        term *prev=NULL;
        temp3=createterm();
        temp=temp3;
        for(temp1=t1;temp1;temp1=temp1->next)
        {
            prev=temp;
            temp->exp=temp1->exp+temp2->exp;
            temp->coef=temp1->coef*temp2->coef;
            temp->next=createterm();
            temp=temp->next;
        }

        prev->next=NULL;
        result=add(result,temp3);
        temp2=temp2->next;
    }

    return result;

}

int main()
{

    term *head1=NULL;
    term *head2=NULL;
    term *head3=NULL;
    int n1,n2,n3;
    head1=create(head1);
    head2=create(head2);
    term *head4=NULL;
    head4=add(head1,head2);

    head3=mult(head1,head2);

    printf("poly1 :\n");
    print(head1);
    printf("poly2 :\n");
    print(head2);
    printf("result of multiplication is :\n");

    print(head3);

    printf("result of addition  is :\n");

    print(head4);



}
