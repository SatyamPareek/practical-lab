#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

int data=0;

node *create()
{
    node *newnode=(node*) malloc(sizeof(node));
    newnode->next=NULL;
}
node *insert_last(node * head)
{   node *start;
    start=head;
    node *newnode=create();
    if(!data)
    {
        printf("Enter the data: ");
    scanf("%d",&newnode->data);

    }
    else
        newnode->data=data;
    if(head==NULL)
        head=newnode;
    else
    {
        for(start=head;start->next!=NULL;start=start->next);
            start->next=newnode;

    }
    return head;
    data=0;
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
node *insert_sorted(node * head,int data)
{   node *temp,*newnode=NULL,*prev;
    temp=head;

    prev=NULL;

    newnode=create();
    newnode->data=data;

    while(temp&&temp->data<newnode->data)
    {
        prev=temp;
        temp=temp->next;
    }

    {

        prev->next=newnode;
        newnode->next=temp;
    }
    return head;

}
node *delete_front(node *head)
{
    node *temp;
    temp=head;
    if(head)
    {
        if(head->next==NULL)
        {

            head=NULL;

            return head;
        }

        head=head->next;

        free(temp);
        return head;
    }
    else
        printf("list empty\n");

}
node *sort(node *start)
{
    node *temp=NULL;
    temp=create();
    temp->data=0;


    while(start!=NULL)
    {
        temp=insert_sorted(temp,start->data);
        start=delete_front(start);

    }
    temp=delete_front(temp);

    return temp;
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
        printf("\n3.to sort the list");

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
            start1=sort(start1);
             printf("\npress any key to continue ");getch();

        }
        break;
        case 0:
            exit(0);



    }



    }
    return 0;

}
