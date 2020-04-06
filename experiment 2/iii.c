#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee
{
    char *employee_name;
    int employee_no;
    float employee_salary;
};
void insert(struct Employee *st, int i)
{
    fflush(stdin);
    char name[100];
    printf("Enter the name: ");
    gets(name);
    st[i].employee_name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(st[i].employee_name, name);
    printf(" Enter the employee no: ");
    scanf("%d", &st[i].employee_no);
    printf(" Enter the total salary: ");
    scanf("%f", &st[i].employee_salary);
}
void display(struct Employee st[], int no)
{
    int i;
    for (i = 0; i < no; i++)
    {
        printf("\n\n \t Employee no %d\n\n", i + 1);
        printf("name: ");
        puts(st[i].employee_name);
        printf("employee no: %d", st[i].employee_no);
        printf("\ntotal salary : %.2f", st[i].employee_salary);
    }
}

int main()
{
    int choice;
    int no = 0;
    struct Employee *st;
    st = (struct Employee *)malloc(sizeof(struct Employee) * (no + 1));
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
