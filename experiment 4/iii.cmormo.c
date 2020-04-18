#include<stdio.h>
//TRI DIAGONAL MATRIX

struct Matrix
{

    int *A;
    int n;
};
typedef struct Matrix Matrix;

void input(struct Matrix *l )
{
    int i,j,m;
    int val;
    for(i=1;i<=l->n;i++)
    {
        for(j=1;j<=l->n;j++)
        {
            scanf("%d",&val);
            if(i==j+1)
            l->A[j-1]=val;
            else if(i==j)
            l->A[l->n-1+i-1]=val;
            else if(i==j-1)
            l->A[2*(l->n)-1+i-1]=val;


        }

    }
}


void display(struct Matrix m)
{

    int i,j;
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i==j+1)
            printf("%3d",m.A[j-1]);
            else if(i==j)
            printf("%3d",m.A[m.n-1+i-1]);
            else if(i==j-1)
            printf("%3d",m.A[2*(m.n)-1+i-1]);
            else
                printf("  0");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    printf("enter the value of n ie. size of matrix: ");
    scanf("%d",&m.n);
    m.A=malloc(sizeof(int)*(3*m.n-2));
        input(&m);
        display(m);


        printf("\n\n the short form of the following matrix is : \n ");
        int i;
        for(i=0;i<3*m.n-2;i++)
            printf("%d ",m.A[i]);
}
