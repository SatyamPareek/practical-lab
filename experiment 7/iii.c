#include<stdio.h>
#include<stdlib.h>
struct node
{
    int row;
    int col;
    int value;
    struct node *next;
};
typedef struct node node;

node *create()
{
    node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->next=NULL;
    return newnode;

}
node *insert(node *head,int row,int col,int value)
{
    node *newnode;
    newnode=create();
    newnode->row=row;
    newnode->col=col;
    newnode->value=value;

    if(head==NULL)
        head=newnode;
    else
    {
        node *temp;
        for(temp=head;temp->next;temp=temp->next);
        temp->next=newnode;
    }
    return head;
}

void display(node *head)
{
    node *temp;
    if(head==NULL)
        {
            printf("empty");
            return;
        }

    printf("row col value\n");
    for(temp=head;temp;temp=temp->next)
    {
            printf("%3d %3d %3d\n",temp->row,temp->col,temp->value);
    }

}

node *get_mat(node *head)
{
    int i ,j ,row,col;
    int count=0;
    printf("Enter the no of row and colm: ");
    scanf("%d%d",&row,&col);
    int x;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&x);
            if(x!=0)
                {
                    head=insert(head,i+1,j+1,x);
                    count++;
                }
        }
    }
    node *header;
    header=create();
    header->row=row;
    header->col=col;
    header->value=count;
    header->next=head;
    head=header;


    return head;
}
node *add(node *head1,node *head2)
{
    node *head=NULL;

    node *temp1;
    node *temp2;
    temp1=head1;
    temp2=head2;
    int cnt=0;
    if((temp1->row==temp2->row)&&(temp1->col==temp2->col))
    {
        temp1=temp1->next;
        temp2=temp2->next;

        while(temp1&&temp2)
        {
            if(temp1->row<temp2->row)
            {
                head=insert(head,temp1->row,temp1->col,temp1->value);
                temp1=temp1->next;
                cnt++;

            }
            else if(temp1->row>temp2->row)
            {
                head=insert(head,temp2->row,temp2->col,temp2->value);
                temp2=temp2->next;
                cnt++;

            }
            else
            {
                if(temp1->col<temp2->col)
                {
                    head=insert(head,temp1->row,temp1->col,temp1->value);
                    temp1=temp1->next;
                    cnt++;

                }
                else if(temp1->col>temp2->col)
                {
                    head=insert(head,temp2->row,temp2->col,temp2->value);
                    temp2=temp2->next;
                    cnt++;

                }
                else
                {
                    head=insert(head,temp1->row,temp1->col,temp1->value+temp2->value);
                    temp1=temp1->next;
                    temp2=temp2->next;
                    cnt++;


                }

            }
        }
        while(temp1)
        {
            head=insert(head,temp1->row,temp1->col,temp1->value);
            temp1=temp1->next;
            cnt++;

        }
        while(temp2)
        {
            head=insert(head,temp2->row,temp2->col,temp2->value);
            temp2=temp2->next;
            cnt++;
        }

    node *header;
    header=create();
    header->row=head1->row;
    header->col=head2->col;
    header->value=cnt;
    header->next=head;
    head=header;


    return head;
    }
    else
        printf("addition not possible");
    return NULL;
}

int main()
{
    node *head=NULL;
    node *head1=NULL;
    node *head2=NULL;
    head1=get_mat(head1);
    head2=get_mat(head2);
    head=add(head1,head2);
    display(head);
return 0;
}
