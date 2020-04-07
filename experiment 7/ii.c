#include<stdio.h>
#include<stdlib.h>


struct node
{
     char student_name[20];
    int student_roll_no;
    float total_marks;
    struct node *next;
    struct node *prev;

};



typedef struct node node;

node *create()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->next=newnode->prev=NULL;
}
node *input(node *newnode)
{

    printf("Enter the name of the student: ");
    fflush(stdin);
    gets(newnode->student_name);
    printf("Enter the students roll no : ");
    scanf("%d",&newnode->student_roll_no);
    printf("Enter the students total marks: ");
    scanf("%f",&newnode->total_marks);
    return newnode;
}

void *output(node *newnode)
{
    printf("\nname of the student: ");

    puts(newnode->student_name);
    printf("roll no : ");
    printf("%d",newnode->student_roll_no);
    printf("\ntotal marks: ");
    printf("%0.2f",newnode->total_marks);
    printf("\n");


}


node *insert_last(node *head)
{
    node *newnode;
    printf("Enter the data: ");
    newnode=create();
    newnode=input(newnode);
    if(head==NULL)
        head=newnode;
    else
    {
        node *temp;
        for(temp=head;temp->next!=NULL;temp=temp->next);
            temp->next=newnode;
            newnode->prev=temp;
    }
    return head;
}
node *insert_front(node *head)
{

    node *newnode;
    printf("Enter the data: ");
    newnode=create();
    newnode=input(newnode);
    if(head==NULL)
        head=newnode;
    else
    {

        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }

return head;

}

node* insert_mid(node *head)
{
    int pos;
    printf("Which position to insert the element : \n");
    scanf("%d",&pos);
    pos--;
    if(pos==0)
        head=insert_front(head);
    else if(pos>0)
    {

        printf("Enter the data:");
        node *newnode;
        newnode=create();
        newnode=input(newnode);



        node* temp=head;
        int i;

        for(i=0;i<pos-1&&temp;temp=temp->next)
        {
            i++;
        }
        if(temp)
        {
            newnode->next=temp->next;
            newnode->prev=temp;
            temp->next->prev=newnode;
            temp->next=newnode;
        }



        return head;
    }
    return head;
}

node * insert_after(node * start ,int key)
{
    if(start==NULL)
    {
        printf("your list is empty");
        return start;
    }
    node *temp;
    for(temp=start;temp;temp=temp->next)
    {
        if(temp->student_roll_no==key)
            break;
    }
    if(temp->student_roll_no==key)
    {
        node *newnode;
        newnode=create();
        newnode=input(newnode);
        if(temp->next==NULL)
        {
            temp->next=newnode;
            newnode->prev=temp;
            return start;

        }

        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
    }
    return start;
}
node * insert_before(node * start ,int key)
{
    if(start==NULL)
    {
        printf("your list is empty");
        return start;
    }


    node *temp;
    for(temp=start;temp;temp=temp->next)
    {
        if(temp->student_roll_no==key)
            break;
    }
    if(temp->student_roll_no==key)
    {
        node *newnode;
        newnode=create();
        newnode=input(newnode);
        if(temp==start)
        {
            node *temp2;
            newnode->next=start;
            start->prev=newnode;
            start=newnode;
            return start;

        }
        temp=temp->prev;

        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
    }
    return start;
}

void display(node *head)
{

    node *temp;
    if(head==NULL)
    {
        printf("your list is empty");
        return;
    }
    printf("\nyour list  is : \n");
    for(temp=head;temp!=NULL;temp=temp->next)
        output(temp);

        printf("\n");
}

int pos(node *head,int key)
{

    node *temp;
    int pos=0;
    for(temp=head;temp;temp=temp->next)
        {
            pos++;
            if(temp->student_roll_no==key)
                return pos;
        }
        return -1;



}
void displayrev(node *head)
{
    node *temp;
    if(head==NULL)
    {
        printf("your list is empty");
        return;
    }
    printf("\nyour list  is : \n");
    temp=head;
    for(temp=head;temp->next!=NULL;temp=temp->next);
    for(temp;temp!=NULL;temp=temp->prev)
        output(temp);
        printf("\n");
}
node *del_val(node *start,int key)
{

    node *temp;
    for(temp=start;temp!=NULL;temp=temp->next)
    {
        if(temp->student_roll_no==key)
            break;
    }
    if(temp->student_roll_no==key)
    {
        node *del;
        if(temp==start)
        {
            if(start->next==NULL)
                {
                    start=NULL;
                    return start;
                }


            del=start;
            start=start->next;
            start->prev=NULL;
            free(del);

            return start;
        }
        if(temp->next==NULL)
        {
            del=temp;
            temp->prev->next=NULL;
            free(del);
            return start;
        }

        del=temp;
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(del);



    }
    else
        printf("element not found");
    return start;
}


node* delete_front(node *head)
{

    if(head==NULL)
    {
        printf("list empty");

        return NULL;
    }
    else
    {
        if(head->next==NULL)
        {

            head=NULL;
            return head;
        }

        node *newnode;
        newnode=head;
        head=head->next;
        head->prev=NULL;

        free(newnode);
        return head;

    }

}
node *insert_sorted(node *start,node *key)
{
    node *temp;
    node *key2;
    node *newnode;
    newnode=create();
    newnode->student_roll_no=key->student_roll_no;
    newnode->total_marks=key->total_marks;
    strcpy(newnode->student_name,key->student_name);
    int flag=0;
    for(temp=start;temp;temp=temp->next)
    {
        if(temp->student_roll_no<newnode->student_roll_no)
            continue;
        else
            {
                flag=1;
                break;
            }
    }
    if(flag)
    {


        temp=temp->prev;
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;

    }
    else
    {
        for(temp=start;temp->next;temp=temp->next);
        temp->next=newnode;
        newnode->next=NULL;
        newnode->prev=temp;


    }
    return start;

}
node *sort(node *start)
{
    node *temp;
    temp=create();
    temp->next=NULL;
    temp->prev=NULL;
    temp->student_roll_no=-9999;
    node *temp2=start;
    while(temp2)
    {
        temp=insert_sorted(temp,temp2);
        temp2=temp2->next;
    }
    temp2=start;
    while(start)
    {
        start=delete_front(start);
    }
    temp=delete_front(temp);

    return temp;



}








int main()
{
    node *start;
    start=NULL;


    int choice;
    while(1)
    {   printf("press any key to continue");
        getch();
        system("CLS");
        printf("\n\n1. to insert element");
        printf("\n2. to display clock wise the list");
        printf("\n3. to insert after certain roll no");
        printf("\n4. to insert befor certain roll no");
        printf("\n5. to insert node at i th position");
        printf("\n6. to find postion of certain roll wrt head");
        printf("\n7. removing particular roll no");
        printf("\n8. completer deletion of the list");
        printf("\n9. display anti clock wise (reverse)");
        printf("\n10. to sort the list");
        printf("\n11. to exit");
        scanf("%d",&choice);
        int roll;

        switch(choice)
        {
        case 1:
            {
                start=insert_last(start);

            }break;
        case 2:
            {
                display(start);

            }break;
        case 3:
            {
                printf("Enter the roll no after which you want to insert the data: ");
                scanf("%d",&roll);
                start=insert_after(start,roll);

            }break;
        case 4:
            {
                printf("Enter the roll no before which you want to insert the data: ");
                scanf("%d",&roll);
                start=insert_before(start,roll);

            }break;
        case 5:
            {
                start=insert_mid(start);

            }break;
        case 6:
            {
                printf("Enter the roll no to find its postion: ");
                scanf("%d",&roll);
                printf("\n %d is present at %d th postion wrt to head",roll,pos(start,roll));

            }break;
        case 7:
            {
                printf("Enter the roll no to remove: ");
                scanf("%d",&roll);
                start=del_val(start,roll);


            }break;
        case 8:
            {
                while(start)
                {
                    start=delete_front(start);
                }

            }break;
        case 9:
            {
                displayrev(start);

            }break;
        case 10:
            {
                printf("Sorted \n");
                start=sort(start);

            }break;
        case 11:
            {
                exit(0);

            }break;

        }
    }
    display(start);

    return 0;

}
