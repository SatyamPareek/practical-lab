#ifndef DEQUEUE_H_INCLUDED
#define DEQUEUE_H_INCLUDED

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
void enque_rear(queue *q)
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
void enque_front(queue *q)
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
    else if(q->front==0)
    printf("queu full front front");
    else
    {

        q->p[--(q->front)]=q->data;
    }

    q->data=0;

}

int deque_front( queue *q)
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
int deque_rear( queue *q)
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
        return q->p[q->rear--];


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







#endif // DEQUEUE_H_INCLUDED
