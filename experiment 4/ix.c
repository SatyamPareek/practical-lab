//program of the sparse matrix
#include<stdio.h>
#include<stdlib.h>
#define size 51//50+1
#define maxcol 10
struct term
{
    int row;
    int col;
    int val;

};
struct Matrix
{

    int *A;
    int n;
};
typedef struct Matrix Matrix;
void read(struct term a[])
{   int row,col,num,cnt=0;
    printf("Enter the no of the row: ");
    scanf("%d",&row);
    printf("Enter the no of the column: ");
    scanf("%d",&col);
    int i,j,k=1;
    printf("Enter the elements: \n");

    for(i=1;i<=row;i++)
    {
        for(j=1;j<=col;j++)
        {
            scanf("%d",&num);
            if(num!=0)
            {
                a[k].row=i;
                a[k].col=j;
                a[k].val=num;
                k++;
                cnt++;
            }
        }
    }
    a[0].row=row;
    a[0].col=col;
    a[0].val=cnt;
}
void spdisp(struct term a[])
{
    int i,j;
    printf("\n\nrow col val");
    for(i=0;i<=a[0].val;i++)
    {
        printf("\n%3d %3d %3d",a[i].row,a[i].col,a[i].val);
        if(i==0)
            printf("\n");

    }

}
void disp(struct term a[])
{   printf("\n\n output in normal form \n");
    int i,j,k=1;
    for(i=1;i<=a[0].row;i++)
    {
        for(j=1;j<=a[0].col;j++)
        {
            if(a[k].row==i&&a[k].col==j)
            {
                printf("%4d",a[k].val);
                k++;
            }
            else
                printf("   0");

        }
        printf("\n\n");
    }
}
void add(struct term a[],struct term b[],struct term c[])//c=a+b;
{
    if((a[0].row==b[0].row)&&(a[0].col==b[0].col))
    {
        int i=1,j=1,k=1,cnt=0;
        while((i<=a[0].val)&&(j<=b[0].val))
        {

            if(a[i].row<b[j].row)
            {
                c[k].row=a[i].row;
                c[k].col=a[i].col;
                c[k++].val=a[i++].val;
            }
            else if(a[i].row>b[j].row)
            {
                c[k].row=b[j].row;
                c[k].col=b[j].col;
                c[k++].val=b[j++].val;

            }
            else
            {


                if(a[i].col<b[j].col)
                {
                    c[k].row=a[i].row;
                    c[k].col=a[i].col;
                    c[k++].val=a[i++].val;
                }
                else if(a[i].col>b[j].col)
                {
                    c[k].row=b[j].row;
                    c[k].col=b[j].col;
                    c[k++].val=b[j++].val;

                }
                else
                {
                    c[k].row=a[i].row;
                    c[k].col=a[i].col;
                    (c[k++].val)=(a[i++].val)+(b[j++].val);
                }
            }
        }
        while (i<=a[0].val)
        {
            c[k].row=a[i].row;
            c[k].col=a[i].col;
            c[k++].val=a[i++].val;
        }
        while (j<=b[0].val)
        {
            c[k].row=a[j].row;
            c[k].col=a[j].col;
            c[k++].val=a[j++].val;
        }
        c[0].val=k-1;
        c[0].row=a[0].row;
        c[0].col=a[0].col;

    }
    else
        printf("addition not possible");
}
void trans(struct term a[],struct term b[])//b= a trans
{
    int i,k,l=1;
    for(i=1;i<=a[0].col;i++)
    {
        for(k=1;k<=a[0].val;k++)
        {
            if(a[k].col==i)
            {
                b[l].col=a[k].row;
                b[l].val=a[k].val;
                b[l++].row=a[k].col;
            }

        }
    }
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;
}
void ftrans(struct term a[],struct term b[])//b= a trans
{
    int rowterms[maxcol],startingpos[maxcol+1];
    int i,j;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;
    for(i=0;i<=a[0].col;i++)
    rowterms[i]=0;
    for(i=1;i<=a[0].val;i++)
        rowterms[a[i].col]++;

    startingpos[1]=1;


    for(i=2;i<=a[0].col;i++)
        startingpos[i]=startingpos[i-1]+rowterms[i-1];
    for(i=1;i<=a[0].val;i++)
    {

        j=startingpos[a[i].col]++;
        b[j].row=a[i].col;
        b[j].col=a[i].row;
        b[j].val=a[i].val;
    }


}
void mult(struct term a[],struct term b[],struct term c[])//c=a*b;
{
    if(a[0].col!=b[0].row)
    {
        printf("multiplication not possible");
        return;

    }
    struct term btrans[size];
    ftrans(b,btrans);
    int apos,bpos,pos=1;
//    result dimesion = a.row x b.col = a.row x brans.row;
    c[0].row=a[0].row;
    c[0].col=btrans[0].row;

    for(apos=1;apos<=a[0].val;)
    {
        int row=a[apos].row;

        for(bpos=1;bpos<=btrans[0].val;)
        {
            int col=btrans[bpos].row;

            int tempa=apos;
            int tempb=bpos;
            int sum=0;

            while(tempa<=a[0].val&&a[tempa].row==row&&tempb<=btrans[0].val&&btrans[tempb].row==col)
            {

                if(a[tempa].col<btrans[tempb].col)
                    tempa++;
                else if(a[tempa].col>btrans[tempb].col)
                    tempb++;
                else
                    sum=sum+((a[tempa++].val)*(btrans[tempb++].val));
            }
            if(sum!=0)
            {
                c[pos].row=row;
                c[pos].col=col;
                c[pos++].val=sum;
            }

            while(bpos<=b[0].val && btrans[bpos].row==col)
                bpos++;



        }
        while(apos<=a[0].val && a[apos].row==row)
                apos++;




    }
     c[0].val=pos-1;

}
void sparsein(struct term a[])
{


    int pos=1,cnt;
    start:
        fflush(stdin);
    printf("Enter the no of row and column: ");
    scanf("%d%d",&a[0].row,&a[0].col);
    printf("Enter the no of non zero term: ");
    scanf("%d",&cnt);
    printf("Enter in correct sparse format and sequence\n");

    if(cnt>a[0].row*a[0].col)
        {
            printf("\n\n\tinvalid input\n");
          goto start;
        }
    printf("Enter the input: \n");
    printf("row col value\n");
    while(cnt--)
    {
        scanf("%d",&a[pos].row);
        if((a[pos].row>a[0].row)||(a[pos].row<=0))
        {
             printf("\n\n\t\tinvalid input\n\n");
             goto start;

        }

    scanf("%d",&a[pos].col);
    if((a[pos].col>a[0].col)||(a[pos].col<=0))
        {
             printf("\n\n\t\tinvalid input\n\n");
             goto start;

        }

    scanf("%d",&a[pos].val);
    pos++;
    }

    a[0].val=pos-1;
    struct term c[size];
    ftrans(a,c);
    ftrans(c,a);

}
void LR( struct term a[])
{

            Matrix m;
            printf("enter the value of n ie. size of matrix: ");
            scanf("%d",&m.n);
            m.A=malloc(sizeof(int)*(m.n*(m.n+1)/2));
            int i;
            printf("Enter the elements in RMO form");
            for(i=0;i<m.n*(m.n+1)/2;i++)
                scanf("%d",&m.A[i]);
            int j;

            int pos=1;
            a[0].row=m.n;
            a[0].col=m.n;
            a[0].val=(m.n*(m.n+1)/2);
            for(i=1;i<=m.n;i++)
            {
                for(j=1;j<=m.n;j++)
                {
                    if(i+j>m.n)
                    {
                        a[pos].val=m.A[i*(i-1)/2 +(i+j-m.n-1)];
                        a[pos].row=i;
                        a[pos].col=j;
                        pos++;
                    }


                }

            }
}
void LL( struct term a[])
{

            Matrix m;
            printf("enter the value of n ie. size of matrix: ");
            scanf("%d",&m.n);
            m.A=malloc(sizeof(int)*(m.n*(m.n+1)/2));
            int i;
            printf("Enter the elements in RMO form");
            for(i=0;i<m.n*(m.n+1)/2;i++)
                scanf("%d",&m.A[i]);
            int j;

            int pos=1;
            a[0].row=m.n;
            a[0].col=m.n;
            a[0].val=(m.n*(m.n+1)/2);
            for(i=1;i<=m.n;i++)
            {
                for(j=1;j<=m.n;j++)
                {
                    if(i>=j)
                    {
                        a[pos].val=m.A[i*(i-1)/2 +j-1];
                        a[pos].row=i;
                        a[pos].col=j;
                        pos++;
                    }


                }

            }
}
void UR(struct term a[])
{

            Matrix m;
            printf("enter the value of n ie. size of matrix: ");
            scanf("%d",&m.n);
            m.A=malloc(sizeof(int)*(m.n*(m.n+1)/2));
            int i;
            printf("Enter the elements in RMO form");
            for(i=0;i<m.n*(m.n+1)/2;i++)
                scanf("%d",&m.A[i]);
            int j;

            int pos=1;
            a[0].row=m.n;
            a[0].col=m.n;
            a[0].val=(m.n*(m.n+1)/2);
            for(i=1;i<=m.n;i++)
            {
                for(j=1;j<=m.n;j++)
                {
                    if(j-i>=0)
                    {
                        a[pos].val=m.A[m.n*(i-1) -(i-1)*(i-2)/2 + j-i];
                        a[pos].row=i;
                        a[pos].col=j;
                        pos++;
                    }

                }

            }
}
void UL(struct term a[])
{

            Matrix m;
            printf("enter the value of n ie. size of matrix: ");
            scanf("%d",&m.n);
            m.A=malloc(sizeof(int)*(m.n*(m.n+1)/2));
            int i;
            printf("Enter the elements in RMO form");
            for(i=0;i<m.n*(m.n+1)/2;i++)
                scanf("%d",&m.A[i]);
            int j;

            int pos=1;
            a[0].row=m.n;
            a[0].col=m.n;
            a[0].val=(m.n*(m.n+1)/2);
            for(i=1;i<=m.n;i++)
            {
                for(j=1;j<=m.n;j++)
                {
                    if(j+i<=m.n+1)
                    {
                        a[pos].val=m.A[m.n*(i-1) -(i-1)*(i-2)/2 + j-1];
                        a[pos].row=i;
                        a[pos].col=j;
                        pos++;
                    }

                }

            }
}


main()
{
    struct term a[size];
    struct term b[size];


    int ch;
    while(1)
    {
    printf("\n1. Input mat 1 ");
    printf("\n2. Input mat 2 ");
    printf("\n3. Transpose:");//1 of 2
    printf("\n4. ADD");
    printf("\n5. MULTIPLY");
    printf("\n6. DISPLAY");
    printf("\n7. EXIT");
    printf("\n Enter the option: ");
    scanf("%d",&ch);
    if(ch==1)
    {
        int ch2;
        start1:
        printf("\n\t1. In sparse form ");
        printf("\n\t2. In Normal form :");
        printf("\n\t3. In LOWER RIGHT TRIANGULAR RMO form :");
        printf("\n\t4. In UPPER RIGHT TRIANGULAR RMO form :");
        printf("\n\t5. In LOWER LEFT TRIANGULAR RMO form :");
        printf("\n\t6. In UPPER LEFT TRIANGULAR RMO form :");



        scanf("%d",&ch2);
        if(ch2==2)
        {
            read(a);
        }
        else if(ch2==1)
        {
            sparsein(a);
        }
        else if(ch2==3)
        {
            LR(a);
        }
        else if(ch2==4)
        {
            UR(a);
        }
        else if(ch2==5)
        {
            LL(a);
        }
        else if(ch2==6)
        {
            UL(a);
        }

        else
        {
            printf("Invalid");
            goto start1;
        }


    }
    else if(ch==2)
    {
        int ch2;
        start2:
        printf("\n\t1. In sparse form ");
        printf("\n\t2. In Normal form :");
        printf("\n\t3. In LOWER RIGHT TRIANGULAR RMO form :");
        printf("\n\t4. In UPPER RIGHT TRIANGULAR RMO form :");
        printf("\n\t5. In LOWER LEFT TRIANGULAR RMO form :");
        printf("\n\t6. In UPPER LEFT TRIANGULAR RMO form :");
        scanf("%d",&ch2);
        if(ch2==2)
        {
            read(b);
        }
        else if(ch2==1)
        {
            sparsein(b);
        }
        else if(ch2==3)
        {
            LR(b);
        }
        else if(ch2==4)
        {
            UR(b);
        }
        else if(ch2==5)
        {
            LL(b);
        }
        else if(ch2==6)
        {
            UL(b);
        }
        else
        {
            printf("Invalid");
            goto start2;
        }


    }
    else if(ch==3)
    {
        struct term c[size];
        int ch2;
        start3:
        printf("\n\t1. Of mat 1 ");
        printf("\n\t2. Of mat 2 :");
        scanf("%d",&ch2);
        if(ch2==1)
        {
            ftrans(a,c);

        }
        else if(ch2==2)
        {
            ftrans(b,c);
        }
        else
        {
            printf("invalid");
            goto start3;
        }
        printf("\nYOur transpose in sparse form: \n");
        spdisp(c);
        printf("\nYOur transpose in Normal form: \n");
        disp(c);
    }
    else if(ch==4)
    {
        struct term c[size];
        add(a,b,c);
        printf("\nYOur Addition in sparse form: \n");
        spdisp(c);
        printf("\nYOur Addition in Normal form: \n");
        disp(c);

    }
    else if(ch==5)
    {
        struct term c[size];
        mult(a,b,c);
        printf("\nYOur Multiplication in sparse form: \n");
        spdisp(c);
        printf("\nYOur Multiplication in Normal form: \n");
        disp(c);

    }
    else if(ch==6)
    {
        int ch2;
        start6:
        printf("\n\t1. Of mat 1 ");
        printf("\n\t2. Of mat 2 :");
        scanf("%d",&ch2);
        if(ch2==1)
        {
        printf("\nYOur Output in sparse form: \n");
        spdisp(a);
        printf("\nYOur Output in Normal form: \n");
        disp(a);
        }
        else if(ch2==2)
        {
        printf("\nYOur tran in sparse form: \n");
        spdisp(b);
        printf("\nYOur trans in Normal form: \n");
        disp(b);
        }
        else
        {
            printf("invalid");
            goto start6;
        }
    }
    else if(ch==7)
        exit(0);
    else
        printf("\n\n\t invalid input");
    }

}
