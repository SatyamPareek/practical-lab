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
node* concateven( node *start1,node *start2)
{
    node *temp;
  node *head3;
  head3=NULL;
  for(temp=start1;temp!=NULL;temp=temp->next)
  {
      if(temp->data%2==0)
      {
          data=temp->data;
          head3=insert_last(head3);
      }
  }

  for(temp=start2;temp!=NULL;temp=temp->next)
  {
      if(temp->data%2==0)
      {
          data=temp->data;
          head3=insert_last(head3);
      }
  }

return head3;
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
        printf("\n5.concat even elements  ");
        printf("\n6.display new list  ");



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
           start3=concateven(start1,start2);
         printf("press any key to continue ");getch();
         break;
    case 6:
        display(start3);
         printf("press any key to continue ");getch();
        break;

        break;
        case 0:
            exit(0);



    }



    }
    return 0;

}
