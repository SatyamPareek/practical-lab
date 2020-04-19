#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;

};
typedef struct node node;

node *root =NULL;
node* alloc()
{
    node *newnode;
    newnode=malloc(sizeof(node));
    newnode->lchild=newnode->rchild=NULL;
    return newnode;

}
void insert(int key)
{
    if(root==NULL)
    {
        root=alloc();
        root->data=key;
        return ;
    }
    node *t,*p=NULL,*r=NULL;
    t=root;
    while(t)
    {
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else
            return;
    }
    p=alloc();
    p->data=key;
    if(key<r->data)
        r->lchild=p;
    else
        r->rchild=p;
}

void inorder(node *p)
{
    if(p!=NULL)
    {
        inorder(p->lchild);
        printf("%d",p->data);
        inorder(p->rchild);
    }
}
node *inpre(node *p)
{
    p=p->lchild;
    while(p&&p->rchild)
        p=p->rchild;
    return p;
}
node *insuc(node *p)
{
    p=p->rchild;
    while(p&&p->lchild)
        p=p->lchild;
    return p;
}
int height(node *p)
{

    if(p==NULL)
        return 0;

        int x=height(p->lchild);
        int y=height(p->rchild);
        return x>y?x+1:y+1;
}
int noofnodes(node *p)
{
    if(p)
    { int x,y;

            x=noofnodes(p->lchild);
            y=noofnodes(p->rchild);
            return x+y+1;



    }
        return 0;
}
int nointernal(node *p)
{
    if(p)
    { int x,y;
                x=nointernal(p->lchild);
                y=nointernal(p->rchild);

            if(p->lchild&&p->rchild)
            {
                return x+y+1;
            }
            else
                return x+y;



    }
        return 0;
}

int noleaves(node *p)
{
    if(p)
    { int x,y;
                x=noleaves(p->lchild);
                y=noleaves(p->rchild);

            if((p->lchild==NULL)||(p->rchild==NULL))
            {
                return x+y+1;
            }
            else
                return x+y;



    }
        return 0;
}



int level(node *p)
{

  return height(p)+1;
}


node * Delete(node*p,int key)
{

    if(p==NULL)
    {
        return NULL;

    }
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
            free(p);
            return NULL;

    }

    if(key<p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key > p->data)
        p->rchild=Delete(p->rchild,key);
    else
    {
        node *q;
        if(height(p->lchild)>height(p->rchild))
        {
            q=inpre(p);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);

        }

        else
        {
            q=insuc(p);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }


    return p;


}
node * search(int key)
{
    node *t=root;
    while(t!=NULL)
    {

        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return NULL;
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1 for insert");
        printf("\n2 for delete");
        printf("\n3 for inorder");
        printf("\n4 for height");
        printf("\n5 for levels");
        printf("\n6 for no of nodes");
        printf("\n7 for no of internal");
        printf("\n8 for no of leaves");

        printf("\n10 for exit");

        printf("\nEnter the choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("Enter the value: ");
            scanf("%d",&choice);
            insert(choice);

        }
        else if(choice==2)
        {
            printf("Enter the value: ");
            scanf("%d",&choice);
            root=Delete(root,choice);

        }
        else if(choice==3)
            inorder(root);
        else if(choice==4)
        {

         printf("height: %d",height(root));

        }else if(choice==5)
        {
            printf("level: %d",level(root));


        }else if(choice==6)
        {
            printf("no of nodes: %d",noofnodes(root));


        }else if(choice==7)
        {

                 printf("no of internal: %d",nointernal(root));

        }else if(choice==8)
        {

                printf("no of leaves: %d",noleaves(root));

        }

        else if(choice==10)
            exit(0);



    }
}
