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

int firstc(node *start1,node *start2)
{
    node *temp1;
    node *temp2;

    temp1=sort(start1);
    temp2=sort(start2);

    while(temp1&&temp2)
    {
        if(temp1->data<temp2->data)
            temp1=temp1->next;
        else if(temp1->data>temp2->data)
            temp2=temp2->next;
        else
            return temp1->data;


    }
    return -1;
}




int main()
{
    int choice;
    node *start1=NULL;
    node *start2=NULL;
    node *start3=NULL;

    while(1)
    {
        system("CLS");

        printf("\n1.insert in first linked  list ");
        printf("\n2.insert in second linked  list ");
        printf("\n3.display first  list ");
        printf("\n4.display second  list ");
        printf("\n5.find first common element");




    printf("\n0. exit");

    printf("\nEnter the choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
         start1=insert_last(start1);
        break;
    case 2:
         start2=insert_last(start2);
        break;
    case 3:
        display(start1);
         printf("press any key to continue ");getch();
        break;
    case 4:
        display(start2);
         printf("press any key to continue ");getch();
        break;
    case 5:
        {
              int common;
              common=firstc(start1,start2);
              printf(" %d is the first common element ",common);
             printf("press any key to continue ");getch();
             break;
         }


        case 0:
            exit(0);



    }



    }
    return 0;

}
