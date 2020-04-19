#include<stdlib.h>

struct link
{
    int data;
    struct link *next;
};
typedef struct link link;

struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;

}*root=NULL;
typedef struct node node;


struct queue
{
    int front;
    int rear;
    int size;
    node **Q;
};

typedef struct queue queue;
void create(queue *q,int s)
{
    q->front=-1;
    q->rear=-1;


    q->size=s;
    q->Q=(node**)malloc(sizeof(node*)*q->size);

}
void enque(queue *q,node *x)
{

    if(q->front==-1&&q->rear==-1)
    {
        q->front=q->rear=0;
        q->Q[q->front]=x;
    }
    else if((q->rear+1)%q->size==q->front)
    printf("queu full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[(q->rear)]=x;
    }

}

node* deque( queue *q)
{
    node *x=NULL;
    if(q->front==-1&&q->rear==-1)
        {
            printf("queu Empty");
            return NULL;
        }

    else if(q->front==q->rear)
    {   int z=q->front;
         q->front=-1;
        q->rear=-1;
        return q->Q[z];


    }
    else
        {
             x=q->Q[q->front];
             q->front=(q->front+1)%q->size;
             return x;

        }


}

int isEmpty(queue q)
{
    if((q.front==-1)&&(q.rear==-1))
        return 1;
    else
        return 0;
}




link *createnode()
{
    link *newnode=(link*) malloc(sizeof(link));
    newnode->next=NULL;
}


link *insert_last(link * head,int data)
{   link *start;
    start=head;
    link *newnode=createnode();

    newnode->data=data;

    if(head==NULL)
        head=newnode;
    else
    {
        for(start=head;start->next!=NULL;start=start->next);
            start->next=newnode;

    }
    return head;
}


void createtree( link *head)
{
    if(head==NULL)
    {
        printf("linked list empty");
        return;
    }

    node *p,*t;
    int x;
    queue q;
    create(&q,100);
    link *temp;

    root=(node *)malloc(sizeof(node));
    root->data=head->data;
    root->lchild=root->rchild=NULL;
    enque(&q,root);
    temp=head->next;
    while(!isEmpty(q)&&temp)
    {
        p=deque(&q);


        if(temp)
        {
            t=(node *)malloc(sizeof(node));
            t->data=temp->data;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enque(&q,t);
            temp=temp->next;

        }
        if(temp)
        {
            t=(node *)malloc(sizeof(node));
            t->data=temp->data;
            t->rchild=t->lchild=NULL;
            p->rchild=t;
            enque(&q,t);
            temp=temp->next;

        }
    }

}


void levelorder(node *p)
{

    queue q;
    create(&q,100);
    printf("%d ",p->data);
    enque(&q,p);
    while(!isEmpty(q))
    {
        p=deque(&q);
        if(p->lchild)
        {
            printf("%d ",p->lchild->data);
            enque(&q,p->lchild);
        }
        if(p->rchild)
        {
            printf("%d ",p->rchild->data);
            enque(&q,p->rchild);
        }


    }



}


void inorder(node *p)
{

    if(p!=NULL)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}


int main()
{
    link *head=NULL;

    int choice;
    while(1)
    {

        printf("\n1 to insert the element in the linked list for tree in level order");
        printf("\n2 to create tree");
        printf("\n3 for level order BFS");
        printf("\n4 for inorder of the tree");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("Enter the value: ");
            scanf("%d",&choice);
            head=insert_last(head,choice);
        }
        else if(choice==2)
        {
            createtree(head);
        }
        else if(choice==3)
        {
            printf("the level order of the tree is : ");
            levelorder(root);

        }
        else if(choice==4)
        {   printf("the in order of the tree is : ");
            inorder(root);
        }


    }

}
