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
node *enque(node * head)
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
node *deque(node *head)
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




int main()
{
    int option;
    node  *q=NULL;

    do{int data;
        printf("\n\n1. enque\n2. deque\n3. display \n4. exit\nEnter the option : ");
        scanf("%d",&option);
        switch (option)
        {
        case 1 :
//            printf("Enter the value: ");
//        scanf("%d",&data);
        q=enque(q);

            /* code */
            break;
        case 2:
        q=deque(q);
        break;
        case 3:
        display(q);
        break;
        case 4:
        exit(0);
        break;

        default:printf("invalid option");
            break;
        }
    }while(1);
}
