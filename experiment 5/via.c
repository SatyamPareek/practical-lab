#include<stdio.h>
void TOH(int n,int a,int b,int c)
{
    static int step=0;
    if(n>0)
    {
        TOH(n-1,a,c,b);
        printf("step %d :- moved one disk from%d to %d\n",++step,a,c);
        TOH(n-1,b,a,c);
    }
    return;
}


int main()
{
    int n;
    printf("Enter the no of the disks");
    scanf("%d",&n);
    TOH(n,1,2,3);
    return 0;

}
