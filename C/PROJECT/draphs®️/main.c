#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<student.h>
#include<teacher.h>
#include<structure.h>


void password_student();
void password_teacher();
struct create_node(struct node *);
struct append_node(struct node *);
void display_detail();



void main()
{
    int ch;
    printf("Enter the choice\n");
    label1:
        printf("1. Student login \n2. Teacher login\n 3. Exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            student_main();
            goto label1;
        }
        else if(ch==2)
        {
            teacher_main();
            goto label1;
        }
        else if
        {
            printf("Thank You\n");
        }
        else
        {
            printf("Wrong choice!! please enter the right choice\n");
            goto label1;
        }
    //exit of main statement
}


