#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//first the lower diag then main then upper

//TRI DIAGONAL MATRIX

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

    printf("Enter the input in normal form\n");
    for(i=1;i<=l->n;i++)
    {
        for(j=1;j<=l->n;j++)
        {
            scanf("%d",&val);
            if(abs(i-j)<=1)
                l->A[2*i+j-3]=val;



        }

    }
}
void inputCMO(struct Matrix *l )
{
    int i,j,m;
    int val;

    printf("Enter the input in normal form\n");
    for(i=1;i<=l->n;i++)
    {
        for(j=1;j<=l->n;j++)
        {
            scanf("%d",&val);
            if(abs(i-j)<=1)
                l->A[2*j+i-3]=val;



        }

    }
}

void input(struct Matrix *l )
{
    int i,j,m;
    int val;

    printf("Enter the input in normal form\n");
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
void displayRMO(struct Matrix m)
{

    int i,j;
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(abs(i-j)<=1)
            printf("%3d",m.A[2*i+j-3]);

            else
                printf("  0");
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
            if(abs(i-j)<=1)
            printf("%3d",m.A[2*j+i-3]);

            else
                printf("  0");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    printf("TRIAGONAL MATRIX\n");
    printf("enter the value of n ie. size of matrix: ");
    scanf("%d",&m.n);
    m.A=malloc(sizeof(int)*(3*m.n-2));
    int choice;
    int i;
    printf("\ press 1 for RMO 2 for CMO and 3 for diagonal form: ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("RMO\n");
        inputRMO(&m);
        displayRMO(m);
        printf("The RMO form of the followin mat is \n");
        for(i=0;i<3*m.n-2;i++)
            printf("%d ",m.A[i]);
    }
    else if(choice==2)
    {
        printf("CMO\n");
        inputCMO(&m);
        displayCMO(m);
        printf("The CMO form of the followin mat is \n");
        for(i=0;i<3*m.n-2;i++)
            printf("%d ",m.A[i]);
    }
    else
     {
        printf("The Diagonal form\n");
        input(&m);
        display(m);
        printf("The CMO form of the followin mat is \n");
        for(i=0;i<3*m.n-2;i++)
            printf("%d ",m.A[i]);
    }



}
