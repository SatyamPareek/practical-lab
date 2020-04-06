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
void displayalt( node *head)
{
    node *temp;
    printf("\n your list is : \n");
    if(head==NULL)
        printf("your list is empty\n");
    else
    {
        for(temp=head;temp!=NULL;)
        {
            printf(" %d ",temp->data);

            if(temp->next)
                temp=temp->next;
                temp=temp->next;
        }
        printf("\n");
    }

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
        printf("\n2.display linked  list ");
        printf("\n3. display alternatively  list ");


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
            displayalt(start1);
         printf("press any key to continue ");getch();


        break;
        case 0:
            exit(0);



    }



    }
    return 0;

}
