#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Faculty
{
    char faculty_name[10];
    char **subject_code;
    char *faculty_id[10];
    int no_of_sub;
    int no_of_class;
    char **class_names;

};
void insert(struct Faculty *st, int i)
{
    fflush(stdin);
    char name[100];
    int j;
    printf("Enter the name: ");
    gets(st[i].faculty_name);
    printf(" Enter the faculty id");
    fflush(stdin);
    gets(st[i].faculty_id);
    printf("Enter the no of the subjects teacher have");
    scanf("%d",&st[i].no_of_sub);
    st[i].subject_code=malloc(sizeof(char *)*st[i].no_of_sub);


    for(j=0;j<st[i].no_of_sub;j++)
    {
        fflush(stdin);
        printf("Enter the subject code for sub %d ",j+1);
        st[i].subject_code[j]=malloc(sizeof(char)*10);
        gets(st[i].subject_code[j]);

    }

    printf("Enter the no of the classes ");
    scanf("%d",&st[i].no_of_class);
    st[i].class_names=malloc(sizeof(char *)*st[i].no_of_class);


    for(j=0;j<st[i].no_of_class;j++)
    {
        fflush(stdin);
        printf("Enter the class name for class %d ",j+1);
        st[i].class_names[j]=malloc(sizeof(char)*10);
        gets(st[i].class_names[j]);

    }






}
void display(struct Faculty st[], int no)
{
   int i;
   for(i=0;i<no ;i++)
   {
       printf("\n\n\t faculty no %d",i+1);
       int j;
    printf("\n name: ");
    puts(st[i].faculty_name);

    printf("faculty id: ");
    puts(st[i].faculty_id);
    printf("the subjects teacher have: \n");
    for(j=0;j<st[i].no_of_sub;j++)
    {

        printf("\n\tsubject code for sub %d: ",j+1);
        puts(st[i].subject_code[j]);

    }

    printf(" the  classes faculty have : \n");

    for(j=0;j<st[i].no_of_class;j++)
    {

        printf("\n\t class name for class %d: ",j+1);
        puts(st[i].class_names[j]);

    }
   }

}

int main()
{
    int choice;
    int no = 0;
    struct Faculty *st;
    st = (struct Faculty *)malloc(sizeof(struct Faculty) * (no + 1));
    while (1)
    {
        printf("\n\npress: \n1.for insert \n2.display\n.3 exit");
        scanf("%d", &choice);
        if (choice == 1)
        {

            insert(st, no);
            no++;
        }
        else if (choice == 2)
        {
            display(st, no);
        }
        else if (choice == 3)
        {
            exit(0);
        }
    }

    return 0;
}
