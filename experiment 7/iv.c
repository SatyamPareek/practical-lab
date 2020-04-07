#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
   char *employee_name;
    int employee_no;
    float employee_salary;
    struct node *next;
};
typedef struct node node;



node *create()
{
    node *newnode=(node*) malloc(sizeof(node));
    newnode->next=NULL;
}
node *input(node *newnode)
{

    fflush(stdin);
    char name[100];
    printf("Enter the name: ");
    gets(name);
    newnode->employee_name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(newnode->employee_name, name);
    printf(" Enter the employee no: ");
    scanf("%d", &newnode->employee_no);
    printf(" Enter the total salary: ");
    scanf("%f", &newnode->employee_salary);
    return newnode;

}

void *output(node *newnode)
{
        printf("\n\n");
        printf("name: ");
        puts(newnode->employee_name);
        printf("employee no: %d", newnode->employee_no);
        printf("\ntotal salary : %.2f", newnode->employee_salary);


}
node *insert_last(node * head)
{   node *start;
    start=head;
    node *newnode=create();
    newnode=input(newnode);

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

node *insert_before(node *start)
{
    int key;
    printf("Enter the employeeno before which you want to insert the data: ");
    node *temp;
    scanf("%d",&key);
    if(start==NULL)
    {
        printf("list is empty and value inserted at begning");
        start=create();
        start=input(start);
        start->next=start;
        return start;
    }
    else if((start->employee_no==key))
    {
        node *newnode;
        newnode=create();
        newnode=input(newnode);
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
                if(!(temp->next->employee_no==key))
                {
                    temp=temp->next;
                }
                else
                    break;
            }while(temp!=start);
        if(temp->next!=start&&(temp->next->employee_no==key))
        {
            newnode=create();
            newnode=input(newnode);

            newnode->next=temp->next;
            temp->next=newnode;
        }
        else
            printf("element not found");
        return start;
    }


}
node *insert_after(node *start)
{


    int key;
    printf("Enter the employee no after which you want to insert the data: ");
    node *temp;
    scanf("%d",&key);
    temp=start;
    if(start->employee_no==key)
    {
        node *newnode;
        newnode=create();
        newnode=input(newnode);
        newnode->next=start->next;
        start->next=newnode;
        return start;
    }
    if(start==NULL)
    {
        printf("list is empty and value inserted at begning");
        start=create();
        start=input(start);
        start->next=start;
        return start;
    }
    do
    {
        if(temp->employee_no=key)
            break;
            temp=temp->next;

    }while(temp!=start);
    if(temp!=start)
    {
        node *newnode;
        newnode=create();
        newnode=input(newnode);
        newnode->next=temp->next;
        temp->next=newnode;

    }
    else
        printf("value not found");


    return start;
}
node *delete_val(node *start)
{
    node *temp;
    if(start==NULL)
    {
        printf("list empyt");
        return NULL;

    }
    printf("Enter the value to delete");
    int key;
    scanf("%d",&key);

    if(key==start->employee_no)
    {
        if(start->next==start)
           {
                output(start);
        printf(" deleted \n");
               start=NULL;
               return start;
           }

        temp=start;
        for(temp=start->next;temp->next!=start;temp=temp->next);
        temp->next=start->next;
        temp=start;

        start=start->next;
        output(temp);
        printf(" deleted \n");
        free(temp);
        return start;

    }
    temp=start;
    do
    {
        if(temp->next->employee_no==key)
            break;
        temp=temp->next;

    }while(temp!=start);
        if(key==temp->next->employee_no)
        {
            node *del;
            del=temp->next;
            temp->next=temp->next->next;
            output(del);
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
            output(temp);
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
node *insert_sorted(node *start,node*key)
{
    node *newnode;
        newnode=create();
        newnode->employee_name=malloc(sizeof(char)*(strlen(key->employee_name)+1));
        strcpy(newnode->employee_name,key->employee_name);
        newnode->employee_no=key->employee_no;
        newnode->employee_salary=key->employee_salary;

    node *temp;
    if(start==NULL)
    {
        start=newnode;
        return start;
    }

    temp=start;
    do
    {
        if(temp->next->employee_no>key->employee_no)
            break;
        temp=temp->next;

    }while(temp->next!=start);


    {
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return start;

}
node *sort(node *start)
{
    node *temp=NULL;
    temp=create();
    temp->employee_no=-9999;
    temp->next=temp;
    node *temp2;
    temp2=start;
    do
    {
        temp=insert_sorted(temp,temp2);
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

        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {

                start=insert_last(start);

            }printf("\n press any key to continue: ");getch();break;
        case 2:
            {
                display(start);
            }printf("\n press any key to continue: ");getch();break;
        case 3:
            {

                    start=insert_before(start);


            }printf("\n press any key to continue: ");getch();break;
        case 4:
            {

                start=insert_after(start) ;

            }printf("\n press any key to continue: ");getch();break;
        case 5:
            {

                start=delete_val(start);

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

