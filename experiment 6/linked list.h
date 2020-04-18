#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>
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
node *insert_sorted(node * head)
{   node *temp,*newnode=NULL,*prev;
    temp=head;

    prev=NULL;
    printf("enter the data");
    newnode=create();
    scanf("%d",&newnode->data);

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
node *delete_comsorted(node *head)
{
    node *temp,*newnode;
    node *prev;
    prev=head;
    temp=head->next;

    while(temp!=NULL)
    {
        if(prev->data!=temp->data)
    {
        prev=temp;
        temp=temp->next;
    }
    else
    {
        prev->next=temp->next;
        free(temp);
        temp=prev->next;
    }
    }
    return head;

}
node* reverse(node* head)
{
    node *a,*b,*c;
    a=b=NULL;
    c=head;
    while(c)
    {
        a=b;
        b=c;
        c=c->next;
        b->next=a;
    }
    return b;

}
node* concat(node* head, node *head2)
{

    node *temp;
    for(temp=head;temp->next!=NULL;temp=temp->next);
    temp->next=head2;
    head2=NULL;
    return head;


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
        last->next=head2;


    return head3;

}

int isloop( node *head)
{


    node *slow;
    node *fast;
    slow=fast=head;
    do
    {
        slow=slow->next;
        fast=fast->next;
        fast=(fast!=NULL)?fast->next:NULL;
    }
    while((fast!=slow)||(fast&&slow));
    return (slow==fast)?1:0;

}





#endif // LINKED_LIST_H_INCLUDED
