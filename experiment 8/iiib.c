#include<stdio.h>
#include<stdlib.h>
void insert(int A[],int n)
{
    int i=n,temp;
    temp=A[i];
    while(i>1&&temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;

    }
    A[i]=temp;
}
int Delete(int A[],int n)
{
    int i,j,x=A[1],val;
    val=A[1];
    x=A[n];
    A[1]=x;

    i=1;
    j=i*2;
    while(j<n-1)
    {
        if(A[j]<A[j+1])
            j=j+1;
        if(A[i]<A[j])
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=j*2;
        }
        else
            break;

    }
    A[n]=val;
    return val;
}
int main()
{

    int n;
    int H[100];
    int i;
    int m;
    int  choice;
    while(1)
    {
        printf("\n 1 for input");
        printf("\n 2 for display");
        printf("\n 3 for sorting");
        printf("\n 4 for exit");
        scanf("%d",&choice);


        if(choice==1)
        {
            printf("Enter the no of the elements");
            scanf("%d",&n);
            m=n;
            for(i=1;i<=n;i++)
                scanf("%d",&H[i]);
            for(i=2;i<=n;i++)
                insert(H,i);
            printf("\nelement inserted \n");

        }


        else if(choice==2)
        {

            for(i=1;i<=n;i++)
                printf("%d ",H[i]);
        }
        else if(choice==3)
        {
            for(i=n;i>=1;i--)
                Delete(H,i);
            printf("sorted");
        }

        else if(choice==4)
            exit(0);
    }




    return 0;

}

