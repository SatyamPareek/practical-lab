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



#endif // QUEUE_H_INCLUDED
