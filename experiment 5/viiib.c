#include<stdio.h>
#include<stdlib.h>
#include"dequeue.h"

int main()
{
    int option;
    queue q;
    create(&q);
    do{int data;
        printf("\n\n1. enque\n2. deque\n3. display \n4. exit\n5 enque front \n6. deque rear  \nEnter the option : ");
        scanf("%d",&option);
        switch (option)
        {
        case 1 :
//            printf("Enter the value: ");
//        scanf("%d",&data);
        enque_rear(&q);

            /* code */
            break;
        case 2:
        printf("The deleted value is %d ",deque_front(&q));
        break;
        case 3:
        display(q);
        break;
        case 4:
        exit(0);
        break;

case 5:
       enque_front(&q);
        break;

case 6:
        printf("The deleted value is %d ",deque_rear(&q));
        break;

        default:printf("invalid option");
            break;
        }
    }while(1);
}
