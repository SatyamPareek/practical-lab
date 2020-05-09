//i*(i-1)/2 +(i+j-n-1)
//lower right triangular matrix
#include<stdio.h>
#include<stdlib.h>
struct Matrix
{

    int *A;
    int n;
};
typedef struct Matrix Matrix;


void inputLRRMO(struct Matrix *l )
{
    int i,j,m;
    int val;

    printf("Enter the input in normal form\n");
    for(i=1;i<=l->n;i++)
    {
        for(j=1;j<=l->n;j++)
        {
            scanf("%d",&val);
            if(i+j>l->n)
                l->A[i*(i-1)/2 +(i+j-l->n-1)]=val;


        }

    }
}
void inputLRCMO(struct Matrix *l )
{
    int i,j,m;
    int val;

    printf("Enter the input in normal form\n");
    for(i=1;i<=l->n;i++)
    {
        for(j=1;j<=l->n;j++)
        {
            scanf("%d",&val);
            if(i+j>l->n)
                l->A[j*(j-1)/2 +(j+i-l->n-1)]=val;



        }

    }
}

void displayLRRMO(struct Matrix m)
{

    int i,j;
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i+j>m.n)
                printf("%d ", m.A[i*(i-1)/2 +(i+j-m.n-1)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
void displayLRCMO(struct Matrix m)
{

    int i,j;
     for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i+j>m.n)
                printf("%d ", m.A[j*(j-1)/2 +(j+i-m.n-1)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    struct Matrix m;
    printf("LOWER RIGHT TRIANGULAR MATRTX\n");
    printf("enter the value of n ie. size of matrix: ");
    scanf("%d",&m.n);
    m.A=malloc(sizeof(int)*(m.n*(m.n+1)/2));

    int choice;

    printf("Enter 1 for rmo form 2 for cmo form");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\n RMO\n");
        inputLRRMO(&m);
        displayLRRMO(m);

        printf("\n\n the RMO form of the following matrix is : \n ");
        int i;
        for(i=0;i<m.n*(m.n+1)/2;i++)
            printf("%d ",m.A[i]);
    }
    else
    {
        printf("\n CMO\n");
        inputLRCMO(&m);
        displayLRCMO(m);

        printf("\n\n the CMO form of the following matrix is : \n ");
        int i;
        for(i=0;i<m.n*(m.n+1)/2;i++)
            printf("%d ",m.A[i]);
    }



}

