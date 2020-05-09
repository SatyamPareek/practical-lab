#include<stdio.h>
#include<stdlib.h>
struct matrix
{
    int row;
    int col;
    int **M;

};
typedef struct matrix matrix;
void create( matrix *Mat,int r,int c)
{
    int i,j;
    Mat->row=r;
    Mat->col=c;
    Mat->M=malloc(sizeof(int *)*Mat->row);
    for(i=0;i<Mat->row;i++)
       Mat->M[i]=malloc(sizeof(int)*Mat->col);
    return;
}
void input( matrix *Mat)
{
    int i,j;
    printf("Enter the values: \n");
    for(i=0;i<Mat->row;i++)
    {
        for(j=0;j<Mat->col;j++)
            scanf("%d",&Mat->M[i][j]);

    }
}
void output(matrix Mat)
{
    int i,j;
    printf("your matrix is : \n");
    for(i=0;i<Mat.row;i++)
    {
        for(j=0;j<Mat.col;j++)
            printf(" %3d",Mat.M[i][j]);
        printf("\n\n");
    }
}

matrix add(matrix Mat1, matrix Mat2)
{
    matrix result;
    if(Mat1.row==Mat2.row&&Mat1.col==Mat2.col)
    {
        int i,j;
        result.row=Mat1.row;
        result.col=Mat2.col;
        create(&result,Mat1.row,Mat1.col);
        for(i=0;i<result.row;i++)
        {
            for(j=0;j<result.col;j++)
            {
                result.M[i][j]=Mat1.M[i][j]+Mat2.M[i][j];
            }
        }
        printf("sucess");

    }
    else
    {
        printf("addtion not possible: ");
        result.row=0;
        result.col=0;
        result.M=NULL;
    }
    return result;
}

matrix mult(matrix Mat1, matrix Mat2)
{
    matrix result;
    if(Mat1.col==Mat2.row)
    {
        create(&result ,Mat1.row,Mat2.col);
        int i,j,k;
        int sum;
        for(i=0;i<Mat1.row;i++)
        {
            for(j=0;j<Mat2.col;j++)
            {
                sum=0;
                for(k=0;k<Mat1.col;k++)
                {
                    sum=sum+Mat1.M[i][k]*Mat2.M[k][j];
                }
                result.M[i][j]=sum;
            }
        }


    }
    else
    {
        printf("addtion not possible: ");
        result.row=0;
        result.col=0;
        result.M=NULL;
    }
    return result;
}
matrix transpose(matrix Mat)
{

    int i,j;
    matrix result;
    create(&result,Mat.col,Mat.row);
    for(i=0;i<Mat.row;i++)
    {
        for(j=0;j<Mat.col;j++)
        {
            result.M[j][i]=Mat.M[i][j];
        }
    }
    return result;
}
void cofact(matrix mat, matrix *temp, int p, int q,int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {

            if (row != p && col != q)
            {
                temp->M[i][j++] = mat.M[row][col];


                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}


int detm(matrix mat)
{
    if(mat.row!=mat.col)
    {
        printf("determinant not possible \n");
        return 0;

    }
    int n=mat.col;

    int D = 0;

    if (n == 1)
        return mat.M[0][0];

    matrix temp;
    create(&temp,mat.col-1,mat.row-1);

    int sign = 1;
    int f;
    for ( f = 0; f < n; f++)
    {

        cofact(mat, &temp, 0, f,n);
        D += sign * mat.M[0][f] * detm(temp);

        sign = -sign;
    }

    return D;
}

int main()
{
    matrix Mat1,Mat2,result={0,0,NULL};
    int row,col;
    int choice;
    while(1)
    {

        printf("press\n1 for input \n2 for display \n3 for transpose \n4 for multiplication \n5 for addition \n 6 for determinant\n 7 to exit: \n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n\t 1 for matrix 1\n\t 2 for matrix 2");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("Enter the no of rows and cols");
                scanf("%d%d",&row,&col);
                create(&Mat1,row,col);
                input(&Mat1);

            }
            if(choice==2)
            {
                printf("Enter the no of rows and cols");
                scanf("%d%d",&row,&col);
                create(&Mat2,row,col);
                input(&Mat2);

            }


        }
        else if(choice==2)
        {
            printf("\n\t 1 for mat1\n\t 2 for mat2\n\t3 for result mat");
            scanf("%d",&choice);
            if(choice==1)
            {
                output(Mat1);

            }
            if(choice==2)
            {
                output(Mat2);

            }
            if(choice==3)
            {
                output(result);

            }


        }
        else if(choice==3)
        {
            printf("\n\t 1 for matrix 1\n\t 2 for matrix 2");
            scanf("%d",&choice);
            if(choice==1)
            {
                Mat1=transpose(Mat1);
             }
            if(choice==2)
            {
                Mat2=transpose(Mat2);

            }


        }
        else if(choice==4)
        {
            printf("\n\t 1 for a*b\n\t 2 for b*a");
            scanf("%d",&choice);
            if(choice==1)
            {
                result=mult(Mat1,Mat2);
                printf("result stored in result mat");
            }
            else if(choice==2)
            {
                result=mult(Mat2,Mat1);
                printf("result stored in result mat");

            }


        }
        else if(choice==5)
        {


            result=add(Mat1,Mat2);
            printf("result stored in result mat");

        }
        else if(choice==6)
        {
            printf("\n\t 1 for mat1 n\t 2 for mat2");
            scanf("%d",&choice);
            if(choice==1)
            {

                printf("The determinant of matrix 1 is: %d ",detm(Mat1));
            }
            if(choice==2)
            {
                ;
                printf("The determinant of matrix 1 is: %d ",detm(Mat2));

            }


        }
        else if(choice==7)
            exit(0);


    }

return 0;
}
