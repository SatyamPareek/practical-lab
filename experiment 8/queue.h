#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct queue
{
    int front;
    int rear;
    int size;
    node **Q;
};

typedef struct queue queue;

void createque(queue *q,int s)
{
    q->front=-1;
    q->rear=-1;
    q->size=s;
    q->Q=malloc(sizeof(node*)*q->size);

}
void enque(queue *q,node *n)
{
    if(q->front==-1&&q->rear==-1)
    {
        q->front=q->rear=0;
        q->Q[q->front]=n;
    }
    else if(q->rear<q->size-1)
    {
        q->Q[++q->rear]=n;

    }
    else
        printf("overflow");
}
node *deque(queue *q)
{
    if(q->front==-1 && q->rear==-1)
    {
        printf("empty");
    }
    if(q->front==q->rear)
    {
        node *p;
        p=q->Q[q->front];
        q->front=q->rear=-1;
        return p;
    }
    else
    {
        return q->Q[q->front++];
    }

}
int isemptyque( queue q)
{
    if(q.front==-1&&q.rear==-1)
        return 1;
    return 0;
}


#endif // QUEUE_H_INCLUDED
