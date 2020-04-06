#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;


    int choice;
    while(1)
    {
        printf("\n\n\npress: \n 1. to open file and write.\n 2. to open and find the word \n 3. to close the file \n 4. to exit ");
        scanf("%d",&choice);

        if(choice==1)
        {
            char name[10];
            printf("Enter the name for the file");
            fflush(stdin);
            gets(name);
            fp=fopen(name,"w");
            char line[100];
            printf("Enter the line");
            gets(line);
            fprintf(fp,"%s",line);
            printf("line written to the file");
            printf("\n please close the file else changes will not be saved");


        }
        else if(choice==2)
        {
            char name[10];
            printf("Enter the name for the file");
            fflush(stdin);
            gets(name);
            fp = fopen(name, "r");
            if(fp!=NULL)
            {
                char line[100];
                char word[10];
                printf("Enter the word to find");
                fflush(stdin);
                gets(word);
                fgets(line,100,fp);
                char *p = strstr(line, word);
                if (p)
                {
                    printf("\n\tfound");
                }
                else
                    printf("\n\tnot found");

            }
            else
            printf("\nfile not found");
        }
        else if (choice == 3)
        {
            fclose(fp);
        }
        else if(choice==4)
        {
            exit(0);
        }

    }


return 0;
}
