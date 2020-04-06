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
node *insert_mid(node * head)
{   node *start,*newnode=NULL;
    start=head;
    int count;
    printf("which position to insert the data: ");
    scanf("%d",&count);
    if(count==0)
    head=insert_front(head)    ;

    else if(count>0)
    {
        start=head;
        int i;
        for(i=0;i<count-1&&start;i++)
            start=start->next;
        if(start)
        {
            newnode=create();
            printf("Enter the data: ");
            scanf("%d",&newnode->data);
            newnode->next=start->next;
            start->next=newnode;


        }

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
node *delete_front(node *head)
{
    node *temp;
    temp=head;
    if(head)
    {
        if(head->next==NULL)
        {
            printf("%d deleted",head->data);
            head=NULL;

            return head;
        }

        head=head->next;
        printf("%d deleted",temp->data);
        free(temp);
        return head;
    }
    else
        printf("list empty\n");

}
node *delete_last(node *head)
{
    node *temp,*newnode;
    temp=head;
    if(head)
    {
        if(head->next==NULL)
           {
                printf("%d deleted",head->data);
               head=NULL;
           return head;
           }
        for(temp=head;temp->next->next!=NULL;temp=temp->next);
        newnode=temp->next;
        temp->next=NULL;
         printf("%d deleted",newnode->data);
        free(newnode);



        return head;
    }
    else
        printf("list empty\n");

}
node *delete_mid(node *head)
{
    node *temp,*newnode;
    temp=head;
    int pos;
    printf("which postion to delete: ");
    scanf("%d",&pos);
    pos--;
    if(pos==0)
    {
        head=delete_front(head);
        return head;
    }
    int i;
    for(i=0;i<pos-1&&temp;i++)
        temp=temp->next;


    if(temp)
    {
        newnode=temp->next;
        temp->next=temp->next->next;
         printf("%d deleted",newnode->data);
        free(newnode);


        return head;
    }
    else
        printf("list empty\n");

}
int secondlast(node *start)
{
    node *temp;
    temp=start;
    while(temp->next->next!=NULL)
        temp=temp->next;
    return temp->data;
}


int main()
{
    int choice;
    node *start=NULL;
    while(1)
    {
        system("CLS");
        printf("\n1.insert at front");
    printf("\n2.insert at last");
    printf("\n3.display linked list");
    printf("\n4.to find second last element: ");




    printf("\n0. exit");

    printf("\nEnter the choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        start=insert_front(start);
        break;
    case 2:
        start=insert_last(start);
        break;
        case 3:
        display(start);
         printf("press any key to continue ");getch();
        break;
        case 4:
        {
            int sl;
            sl=secondlast(start);
            printf("the second last element is %d\n",sl);
             printf("press any key to continue ");getch();
         }
        break;
        case 0:
            exit(0);



    }



    }
    return 0;

}
