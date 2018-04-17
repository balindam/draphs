#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct date              //structure for date
{
    int day;
    int month;
    int year;
};

struct student          //structure for student details
{
    char name[20];
    int enroll;
    char gender;
    struct date dob;
    char blood_grp[3];
    char batch[3];
};

struct node
{
    int enrollno;
    int year;
    int sem;
    char exam[2];
    char subject[10];
    int marks;
    struct node *next;
};

struct node *first=NULL;

void password_student();
void password_teacher();
struct create_node(struct node *);
struct append_node(struct node *);
void display_detail();



void main()
{
    printf("1. Student login \n2. Teacher login\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        password_student();
    }
    else if(ch==2)
    {
        password_teacher();
    }
    else
    {
        printf("Wrong choice!!\n");
    }
}
void password_student()
{
    int enroll;
    scanf
}
