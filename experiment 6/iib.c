#include <stdio.h>
#include <stdlib.h>
#include"linked list.h"


main()
{ int option;
node *s;

    s=NULL;
    do{int data;
        printf("\n\n1. push\n2. pop\n3. display \n4. exit\nEnter the option : ");
        scanf("%d",&option);
        switch (option)
        {
        case 1 :

        s=insert_last(s);

            /* code */
            break;
        case 2:
        s=delete_last(s);
        break;
        case 3:
        display(s);
        break;
        case 4:
        exit(0);
        break;

        default:printf("invalid option");
            break;
        }
    }while(1);
}
