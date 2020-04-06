#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    char student_name[20];
    int student_roll_no;
    float total_marks;
};
void insert(struct student *st ,int i)
{

    char name[100];
    printf("Enter the name: ");
    fflush(stdin);
    gets(st[i].student_name);
    printf(" Enter the Roll no: ");
    scanf("%d",&st[i].student_roll_no);
    printf(" Enter the total marks: ");
    scanf("%f",&st[i].total_marks);

}
void display(struct student st[],int no)
{
    int i;
    for(i=0;i<no;i++)
    {
        printf("\n\n \t student no %d\n",i+1);
        printf("name: ");
        puts(st[i].student_name);
        printf("roll no: %d",st[i].student_roll_no);
        printf("\ntotal marks : %.2f",st[i].total_marks);


    }


}



int main()
{
    int choice;
    int no=0;
    struct student *st;
    st=(struct student *)malloc(sizeof(struct student)*(no+1));
    while(1)
    {
        printf("\n\npress: \n1.for insert \n2.display\n.3 exit");
        scanf("%d",&choice);
        if(choice==1)
        {

            insert(st,no);
            no++;
        }
        else if(choice==2)
        {
            display(st,no);


        }
        else if(choice==3)
        {
            exit(0);
        }

    }


return 0;
}
