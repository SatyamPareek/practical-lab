#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int front1;
    int rear1;
    int front2;
    int rear2;
    int size;
    int data;
    int *p;
};

typedef struct queue queue;
void create(queue *q)
{
    printf("Enter the size of the queue: ");
    scanf("%d",&q->size);
    q->front1=-1;
    q->rear1=-1;
    q->front2=2*q->size;
    q->rear2=2*q->size;

    q->data=0;

    q->p=(int* )malloc(sizeof(queue)*q->size*2);

}
void enque1(queue *q)
{
    if(q->data==0)
    {
    printf("Enter the data: ");
    scanf("%d",&q->data);
    }
    if(q->front1==-1&&q->rear1==-1)
    {
        q->front1=q->rear1=0;
        q->p[q->front1]=q->data;
    }
    else if(q->rear1==q->size-1)
    printf("queu full front");
    else
    {

        q->p[++(q->rear1)]=q->data;
    }

    q->data=0;

}

int deque1( queue *q)
{
    if(q->front1==-1&&q->rear1==-1)
        {
            printf("queu Empty front");
            return -1;
        }

    else if(q->front1==q->rear1)
    {   int z=q->front1;
         q->front1=-1;
        q->rear1=-1;
        return q->p[z];


    }
    else
        return q->p[q->front1++];


}
void enque2(queue *q)
{
    if(q->data==0)
    {
    printf("Enter the data: ");
    scanf("%d",&q->data);
    }
    if((q->front2==(q->size)*2)&&q->rear2==(q->size)*2)
    {
        q->front2=q->rear2=(q->size*2)-1;
        q->p[q->front2]=q->data;
    }
    else if(q->rear2==q->size)
    printf("queu full back");
    else
    {

        q->p[--(q->rear2)]=q->data;
    }

    q->data=0;

}

int deque2( queue *q)
{
    if(q->front2==q->size*2&&q->rear2==q->size*2)
        {
            printf("queu Empty back");
            return -1;
        }

    else if(q->front2==q->rear2)
    {   int z=q->front2;
         q->front2=q->size*2;
        q->rear2=q->size*2;
        return q->p[z];


    }
    else
        return q->p[q->front2--];


}




int main()
{
    int option;
    queue q;
    create(&q);
    do{int data;
        printf("\n\n1. enque 1 \n2. deque1 \n3. display \n4. exit\n5 enque 2 \n6. deque 2  \nEnter the option : ");
        scanf("%d",&option);
        switch (option)
        {
        case 1 :
//            printf("Enter the value: ");
//        scanf("%d",&data);
        enque1(&q);

            /* code */
            break;
        case 2:
        printf("The deleted value is %d ",deque1(&q));
        break;
        case 3:
        {
            printf("%d %d %d %d ",q.front1,q.front2,q.rear1,q.rear2);
        }
        break;
        case 4:
        exit(0);
        break;

case 5:
       enque2(&q);
        break;

case 6:
        printf("The deleted value is %d ",deque2(&q));
        break;

        default:printf("invalid option");
            break;
        }
    }while(1);
}
