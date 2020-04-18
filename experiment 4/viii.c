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
            printf("%2d",Mat.M[i][j]);
        printf("\n");
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
        result.M=malloc(sizeof( int *)*result.row);
        for(i=0;i<result.row;i++);
        result.M[i]=malloc(sizeof(int)*result.col);
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

int main()
{
    matrix Mat1,Mat2,result;
    int row,col;
    printf("Enter the row and col for the first Matrix : ");
    scanf("%d%d",&row,&col);
    create(&Mat1,row,col);
    input(&Mat1);
    output(Mat1);

    printf("Enter the row and col for the Second Matrix : ");
    scanf("%d%d",&row,&col);
    create(&Mat2,row,col);
    input(&Mat2);
    output(Mat2);
    result=add(Mat1,Mat2);
    output(result);


return 0;
}
