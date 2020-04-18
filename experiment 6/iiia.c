#include<stdlib.h>
struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;

}*root=NULL;
typedef struct node node;
#include"queue.h"
void createtree()
{
    node *p,*t;
    int x;
    queue q;
    create(&q,100);
    printf("Enter the root value");
    scanf("%d",&x);
    root=(node *)malloc(sizeof(node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enque(&q,root);
    while(!isEmpty(q))
    {
        p=deque(&q);
        printf("Enter the left child of %d :",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(node *)malloc(sizeof(node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enque(&q,t);

        }
       printf("Enter the right child of %d :",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(node *)malloc(sizeof(node));
            t->data=x;
            t->rchild=t->lchild=NULL;
            p->rchild=t;
            enque(&q,t);

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
int main()
{
    createtree();
    printf("the level order of the tree is : ");
    levelorder(root);
}
