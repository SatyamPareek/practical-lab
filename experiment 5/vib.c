#include<stdio.h>
#include<stdlib.h>
int size;
int isSafe(int maze[10][10], int x, int y)
{

    if (x >= 0 && x < size && y >= 0 && y < size && maze[x][y] == 1)
        return 1;

    return 0;
}
int solve(int maze[10][10],int x,int y,int sol[10][10],int size)
{
      if (x == size - 1 && y == size - 1) {
        sol[x][y] = 1;
        return 1;
    }


    if (isSafe(maze, x, y) == 1) {

        sol[x][y] = 1;


        if (solve(maze, x + 1, y, sol,size) == 1)
            return 1;



        if (solve(maze, x, y + 1, sol,size) == 1)
            return 1;


        sol[x][y] = 0;
        return 0;
    }

    return 0;
}



int SolveMaze(int maze[10][10],int sol[10][10],int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            sol[i][j]=0;
    }

    if(solve(maze,0,0,sol,size)==1)
    {
        printf("maze solved:\n");
        for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            printf("%d ",sol[i][j]);
            printf("\n");
    }

    }
    else
        printf("maze not solved");



}


int main()
{
    printf("Enter the maze");
    int i,j;
    printf("Enter the size :");
    scanf("%d",&size);
    int maze[10][10];
    int sol[10][10];
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            scanf("%d",&maze[i][j]);
    }



    SolveMaze(maze,sol,size);




return 0;
}
