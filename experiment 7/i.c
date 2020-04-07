#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char *data;
    struct node *next;
};
typedef struct node node;



node *create()
{
    node *newnode=(node*) malloc(sizeof(node));
    newnode->next=NULL;
}
node *insert_last(node * head,char data[])
{   node *start;
    start=head;
    node *newnode=create();
    newnode->data=malloc(sizeof(char)*(strlen(data)+1));
    strcpy(newnode->data,data);

    if(head==NULL)
        {
            head=newnode;
            head->next=head;
        }
    else
    {
        for(start=head;start->next!=head;start=start->next);
            start->next=newnode;
            newnode->next=head;

    }
    return head;
}

node *insert_before(node *start,char data[])
{
    char key[100];
    printf("Enter the key before which you want to insert the data: ");
    node *temp;
    fflush(stdin);
    gets(key);

    if(start==NULL)
    {
        printf("list is empty and value inserted at begning");
        start=create();
        start->data=malloc(sizeof(char)*(strlen(data)+1));
        strcpy(start->data,data);
        start->next=start;
        return start;
    }
    else if(strcmp(start->data,key)==0)
    {
        node *newnode;
        newnode=create();
        newnode->data=malloc(sizeof(char)*(strlen(data)+1));
        strcpy(newnode->data,data);
        newnode->next=start;
        for(temp=start;temp->next!=start;temp=temp->next);
        temp->next=newnode;
        start=newnode;
        return start;


    }

    else
    {
        node *newnode;
            temp=start;
        do
            {
                if(strcmp(temp->next->data,key))
                {
                    temp=temp->next;
                }
                else
                    break;
            }while(temp!=start);
        if(temp->next!=start&&(strcmp(temp->next->data,key)==0))
        {
            newnode=create();
            newnode->data=malloc(sizeof(char)*(strlen(data)+1));
            strcpy(newnode->data,data);
            newnode->next=temp->next;
            temp->next=newnode;
        }
        else
            printf("element not found");
        return start;
    }


}
node *insert_after(node *start,char data[])
{


    char key[100];
    printf("Enter the key after which you want to insert the data: ");
    node *temp;
    fflush(stdin);
    gets(key);
    temp=start;
    if(strcmp(start->data,key)==0)
    {
        node *newnode;
        newnode=create();
        newnode->data=malloc(sizeof(char)*(strlen(data)+1));
        strcpy(newnode->data,data);
        newnode->next=start->next;
        start->next=newnode;
        return start;
    }
    if(start==NULL)
    {
        printf("list is empty and value inserted at begning");
        start=create();
        start->data=malloc(sizeof(char)*(strlen(data)+1));
        strcpy(start->data,data);
        start->next=start;
        return start;
    }
    do
    {
        if(strcmp(temp->data,key)==0)
            break;
            temp=temp->next;

    }while(temp!=start);
    if(temp!=start)
    {
        node *newnode;
        newnode=create();
        newnode->data=malloc(sizeof(char)*(strlen(data)+1));
        strcpy(newnode->data,data);
        newnode->next=temp->next;
        temp->next=newnode;

    }
    else
        printf("value not found");


    return start;
}
node *delete_val(node *start, char data[])
{
    node *temp;
    if(start==NULL)
    {
        printf("list empyt");
        return NULL;

    }

    if(strcmp(data,start->data)==0)
    {

        if(start->next==start)
        {
            puts(start->data);
        printf(" deleted \n");
        start=NULL;
        return start;

        }

        temp=start;
        for(temp=start->next;temp->next!=start;temp=temp->next);
        temp->next=start->next;
        temp=start;

        start=start->next;
        puts(temp->data);
        printf(" deleted \n");
        free(temp);
        return start;

    }
    temp=start;
    do
    {
        if(strcmp(data,temp->next->data)==0)
            break;
        temp=temp->next;

    }while(temp!=start);
        if(strcmp(data,temp->next->data)==0)
        {
            node *del;
            del=temp->next;
            temp->next=temp->next->next;
            puts(del->data);
            printf(" deleted \n");
            free(del);
        }
        else
            printf("value not found");
        return start;




}

void display( node *head)
{
    node *temp;
    printf("\n your list is : \n");
    if(head==NULL)
        printf("your list is empty\n");
    else
    {   temp=head;
        do
        {
            puts(temp->data);
            printf("\n");
            temp=temp->next;
        }while(temp!=head);
        printf("\n\n");
    }

}

node *delete_last(node *head)
{
    node *temp,*newnode;
    temp=head;
    if(head)
    {
        if(head->next==head)
           {
               head=NULL;
           return head;
           }
        for(temp=head;temp->next->next!=head;temp=temp->next);
        newnode=temp->next;
        temp->next=head;
        free(newnode);



        return head;
    }
    else
        printf("list empty\n");

}




node *delete_front(node *head)
{
    node *temp,*start;
    temp=head;
    if(head)
    {
        if(head->next==head)
        {
            head=NULL;
            return head;
        }
        for(start=head;start->next!=head;start=start->next);
        start->next=head->next;
        head=head->next;
        free(temp);
        return head;
    }
    else
        printf("list empty\n");

}

node *insert_sorted(node *start,char data[])
{
    node *temp;
    if(start==NULL)
    {
        start=create();
        start->data=malloc(sizeof(char)*(strlen(data)+1));
        strcpy(start->data,data);
        return start;
    }

    temp=start;
    do
    {
        if(strcmp(temp->next->data,data)>0)
            break;
        temp=temp->next;

    }while(temp->next!=start);


    {
        node *newnode;
        newnode=create();
        newnode->data=malloc(sizeof(char)*(strlen(data)+1));
        strcpy(newnode->data,data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return start;

}
node *sort(node *start)
{
    node *temp=NULL;
    temp=create();
    temp->data=malloc(sizeof(char)*20);
    strcpy(temp->data,"\0");
    temp->next=temp;
    node *temp2;
    temp2=start;
    do
    {
        temp=insert_sorted(temp,temp2->data);
       temp2=temp2->next;
    }while(temp2!=start);
    temp=delete_front(temp);
    while(start!=NULL)
    {
        start=delete_last(start);
    }

    return temp;


}


int main()
{
    node *start;
    start=NULL;

    int choice;
    while(1)
    {
        system("CLS");
        printf("\n\n 1. to insert element at last");
        printf("\n 2.to display the list");
        printf("\n 3.insert node before certain value");
        printf("\n 4.insert node after certain value");
        printf("\n 5.remove the node with particular value");
        printf("\n 6.complete deletion of the list");
        printf("\n 7.to sort the list");
        printf("\n 8.to exit");
        char data[100];
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("Enter the data(string) to insert: ");
                fflush(stdin);
                gets(data);
                start=insert_last(start,data);

            }printf("\n press any key to continue: ");getch();break;
        case 2:
            {
                display(start);
            }printf("\n press any key to continue: ");getch();break;
        case 3:
            {
                printf("Enter the data(string) to insert: ");
                fflush(stdin);
                gets(data);
                start=insert_before(start,data) ;

            }printf("\n press any key to continue: ");getch();break;
        case 4:
            {
                printf("Enter the data(string) to insert: ");
                fflush(stdin);
                gets(data);
                start=insert_after(start,data) ;

            }printf("\n press any key to continue: ");getch();break;
        case 5:
            {
                printf("Enter the data(string) to delete: ");
                fflush(stdin);
                gets(data);
                start=delete_val(start,data);

            }printf("\n press any key to continue: ");getch();break;
        case 6:
            {
                while(start!=NULL)
                {
                    start=delete_last(start);
                }
                printf("all list deleted");

            }printf("\n press any key to continue: ");getch();break;
        case 7:
            {
                printf("sorted");
                start=sort(start);

            }printf("\n press any key to continue: ");getch();break;
        case 8:
            {
              exit(0)  ;
            }printf("\n press any key to continue: ");getch();break;

        }


    }
    display(start);

    return 0;

}

