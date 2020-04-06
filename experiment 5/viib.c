#include<stdio.h>
#include<stdlib.h>
#include"stack.h"


int main()
{
    int option;
    stack q;
    stack q1;
    create(&q1);
    create(&q);
    do{int data;
        printf("\n\n1. enque\n2. deque\n3. display \n4. exit\nEnter the option : ");
        scanf("%d",&option);
        switch (option)
        {

        case 1 :
//            printf("Enter the value: ");
//        scanf("%d",&data);
        push(&q);

            break;
        case 2:
        while(q.top!=-1)
        {
            q1.data=pop(&q);
            push(&q1);
        }
        printf("%d dequed ",pop(&q1));
        while(q1.top!=-1)
        {
            q.data=pop(&q1);
            push(&q);
        }

        break;
        case 3:
        display(q);
        break;
        case 4:
        exit(0);
        break;

        default:printf("invalid option");
            break;
        }
    }while(1);
}
