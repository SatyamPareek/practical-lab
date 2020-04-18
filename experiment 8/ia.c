#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;

};
typedef struct node node;
#include"queue.h"
node *root =NULL;
node* alloc()
{
    node *newnode;
    newnode=malloc(sizeof(node));
    newnode->lchild=newnode->rchild=NULL;
    return newnode;

}

void createtree()
{
    node *t,*p;
    int val;
    queue q;
    printf("Enter the value of the root");
    scanf("%d",&val);
    createque(&q,100);
    root=alloc();
    root->data=val;
    enque(&q,root);
    while(!isemptyque(q))
    {
        p=deque(&q);

        printf("Enter the left child of the %d else -1:",p->data);
        scanf("%d",&val);
        if(val!=-1)
        {
            t=alloc();
            t->data=val;
            p->lchild=t;
            enque(&q,t);
        }
        printf("Enter the right child of the %d  else -1:",p->data);
        scanf("%d",&val);
        if(val!=-1)
        {
            t=alloc();
            t->data=val;
            p->rchild=t;
            enque(&q,t);
        }

    }


}



void preorder(node *p)
{

    if(p!=NULL)
    {
        printf("%d ",p->data);

        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void postorder(node *p)
{

    if(p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
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
    createtree();
    printf("\n inorder traversal of the following tree ");
    inorder(root);
    printf("\n preorder traversal of the following tree ");
    preorder(root);
    printf("\n postorder traversal of the following tree ");
    postorder(root);

}
