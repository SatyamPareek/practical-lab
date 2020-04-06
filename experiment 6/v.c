#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;



node *create()
{
    node *newnode=(node*) malloc(sizeof(node));
    newnode->next=NULL;
    return newnode;
}
node *insert_last(node * head)
{   node *start;
    start=head;
    node *newnode=create();
    printf("Enter the data: ");
    scanf("%d",&newnode->data);

    if(head==NULL)
        head=newnode;
    else
    {
        for(start=head;start->next!=NULL;start=start->next);
            start->next=newnode;

    }
    return head;
}
node *insert_front(node * head)
{   node *start;
    start=head;
    node *newnode=create();
    printf("Enter the data: ");
    scanf("%d",&newnode->data);

    if(head==NULL)
        head=newnode;
    else
    {

        newnode->next=head;
        head=newnode;

    }
    return head;
}


void display( node *head)
{
    node *temp;
    printf("\n your list is : \n");
    if(head==NULL)
        printf("your list is empty\n");
    else
    {
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            printf(" %d ",temp->data);
        }
        printf("\n");
    }

}
node* merge(node* head, node *head2)
{

    node *head3,*temp1,*temp2;
    node *last;
    head3=last=NULL;
    if(head->data<head2->data)
        {
            head3=last=head;
            head=head->next;
            last->next=NULL;
        }
    else
    {
        head3=last=head2;
        head2=head2->next;
        last->next=NULL;

    }

    temp1=head;
    temp2=head2;
    while(temp1&&temp2)
    {
        if(temp1->data<temp2->data)
        {
            last->next=temp1;
            last=last->next;
            temp1=temp1->next;
            last->next=NULL;

        }
        else
        {
            last->next=temp2;
            last=last->next;
            temp2=temp2->next;
            last->next=NULL;

        }
    }
    if(temp1)
        last->next=temp1;
    else
        last->next=temp2;


    return head3;

}
node *shuffle( node *head)
{
    node *temp;
    node *prev;
    node *tempr;
    prev=NULL;
    temp=head;
    while(temp&&temp->next)
    {
        if(temp==head)
        {
            tempr=head->next;
            head->next=head->next->next;
            tempr->next=head;
            head=tempr;
            prev=head->next;
            temp=head->next->next;
        }
        if(prev->next&&temp->next)
        {
            tempr=temp;
        prev->next=temp->next;
        prev=prev->next;
        temp->next=prev->next;
        prev->next=temp;
        prev=temp;
        temp=temp->next;
        }


    }

    return head;


}



int main()
{
    int choice;
    node *start1=NULL;

    while(1)
    {
        system("CLS");

        printf("\n1.insert in first linked  list ");
        printf("\n2.display first linked list");
        printf("\n3.to shuffle : ");

    printf("\n0. exit");

    printf("\nEnter the choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
         start1=insert_last(start1);
        break;
    case 2:
        display(start1);
         printf("press any key to continue ");getch();
        break;
    case 3:
        {
            start1=shuffle(start1);
             printf("\npress any key to continue ");getch();

        }


    break;
        case 0:
            exit(0);



    }



    }
    return 0;

}
