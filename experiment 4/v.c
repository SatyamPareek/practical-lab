
#include<stdio.h>
//upper left triangular matrix

struct Matrix
{

    int *A;
    int n;
};
typedef struct Matrix Matrix;

void inputRMO(struct Matrix *l )
{
    int i,j,m;
    int val;
    for(i=1;i<=l->n;i++)
    {
        for(j=1;j<=l->n;j++)
        {
            scanf("%d",&val);
            if(j+i<=l->n+1)
                l->A[l->n*(i-1) -(i-1)*(i-2)/2 + j-1]=val;

        }

    }
}
void inputCMO(struct Matrix *l )
{

    int i,j,m;
    int val;
    for(i=1;i<=l->n;i++)
    {
        for(j=1;j<=l->n;j++)
        {
            scanf("%d",&val);
            if(i+j<=l->n+1)
                l->A[l->n*(j-1) -(j-1)*(j-2)/2 + i-1]=val;

        }

    }
}

void displayRMO(struct Matrix m)
{

    int i,j;
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(j+i<=m.n+1)
                printf("%d ", m.A[m.n*(i-1) -(i-1)*(i-2)/2 + j-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
void displayCMO(struct Matrix m)
{

    int i,j;
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(j+i<=m.n+1)
                printf("%d ", m.A[m.n*(j-1) -(j-1)*(j-2)/2 + i-1 ]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    struct Matrix m;
    printf("enter the value of n ie. size of matrix: ");
    scanf("%d",&m.n);
    m.A=malloc(sizeof(int)*(m.n*(m.n+1)/2));

    int choice;

    printf("Enter 1 for rmo form 2 for cmo form");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\n RMO\n");
        inputRMO(&m);
        displayRMO(m);
           printf("\n\n the RMO form of the following matrix is : \n ");
        int i;
        for(i=0;i<(m.n*(m.n+1)/2);i++)
            printf("%d ",m.A[i]);
    }
    else
    {
        printf("\n CMO\n");
        inputCMO(&m);
        displayCMO(m);

           printf("\n\n the CMO form of the following matrix is : \n ");
        int i;
        for(i=0;i<(m.n*(m.n+1)/2);i++)
            printf("%d ",m.A[i]);
    }



}

