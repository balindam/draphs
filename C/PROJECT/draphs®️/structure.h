#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

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
    int test;
    struct node *next_exam;
    struct node *next;
};

struct node_exam
{
    char subject[10];
    int marks;
    struct node_exam *next;
};




#endif // STRUCTURE_H_INCLUDED
