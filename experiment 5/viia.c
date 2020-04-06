#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int front;
    int rear;
    int size;
    int data;
    int *p;
};

typedef struct queue queue;
void create(queue *q)
{
    q->front=-1;
    q->rear=-1;
    q->data=0;
    printf("Enter the size of the queue: ");
    scanf("%d",&q->size);
    q->p=(int* )malloc(sizeof(queue)*q->size);

}
void enque(queue *q)
{
    if(q->data==0)
    {
    printf("Enter the data: ");
    scanf("%d",&q->data);
    }
    if(q->front==-1&&q->rear==-1)
    {
        q->front=q->rear=0;
        q->p[q->front]=q->data;
    }
    else if(q->rear==q->size-1)
    printf("queu full");
    else
    {

        q->p[++(q->rear)]=q->data;
    }

    q->data=0;

}

int deque( queue *q)
{
    if(q->front==-1&&q->rear==-1)
        {
            printf("queu Empty");
            return -1;
        }

    else if(q->front==q->rear)
    {   int z=q->front;
         q->front=-1;
        q->rear=-1;
        return q->p[z];


    }
    else
        return q->p[q->front++];


}
void display(queue q)
{   int i;
   if(q.front==-1&&q.rear==-1)
  {
       printf("Que Empty");
    return;
  }
    printf(" \n\n\t your que is :\n");
   for( i=q.front;i<=q.rear;i++)
        printf("%d ",q.p[i]);
}

int main()
{
    int option;
    queue q;
    create(&q);
    do{int data;
        printf("\n\n1. enque\n2. deque\n3. display \n4. exit\nEnter the option : ");
        scanf("%d",&option);
        switch (option)
        {
        case 1 :
//            printf("Enter the value: ");
//        scanf("%d",&data);
        enque(&q);

            /* code */
            break;
        case 2:
        printf("The deleted value is %d ",deque(&q));
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
