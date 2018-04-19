#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "teacher.h"

int en;

int password_student();
void change_password();
void generate_marksheet();

void student_main()
{
    printf("Login page");
    int choice;
    int result;
    result = password_student();
    if(result==1)
    {
        do
            {
            printf("Select any one of the following\n");
            label1:
                printf("1. Generate marksheet \n2. Change password\n");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    generate_marksheet();
                    break;
                case 2:
                    change_password();
                    break;
                default:
                    printf("Wrong option\n");
                    goto label1;
                }
            printf("Enter the option\n");
            label2:
                printf("1. Menu \n2.Logout \n");
                scanf("%d",&choice);
                if(choice!=1&&choice!=2)
                {
                    printf("Wrong choice please enter the right option\n");
                    goto label2;
                }
            }while(choice==1);
    }
}

void generate_marksheet()
{
    int e,y,s,t,m;char sub[10];
    FILE *fp;
    fp=fopen("data.txt","r");
    while(fscanf(fp,"%d %d %d %d %s %d ",&e,&y,&s,&t,sub,&m)!=EOF)
    {
        if(e==en)
        {
            printf("Enrollment no.- %d\n Year - %d\n Semester - %d\n Test - %d\n Subject - %s\n Marks - %d\n",e,y,s,t,sub,m);
        }
    }
    fclose(fp);
}

void change_password()
{
    char str1[10];
    int enroll;
    FILE *fp;
    fp=fopen("password_student.txt","r+");
    while(fscanf(fp,"%d ",&enroll)!=EOF)
    {
        if(enroll==en)
        {
            printf("Enter the new password\n");
            scanf("%s",str1);
            fputs(str1,fp);
            fputs(" ",fp);
        }
        else
        {
            fscanf(fp,"%s ",str1);
        }
    }
}

int password_student()
{

    printf("Enter the enrollment number\n");
    scanf("%d",&en);
    FILE *fp;
    char str[10];
    fp=fopen("password_student.txt","r");
    printf("Enter the password");
    int c=0;int e;
    char pass[10];
    while(fscanf(fp,"%d %s ",&e,str)!=EOF)
    {
        if(e==en)
            break;
    }
    /*while(c!=6)
    {
        scanf("%c",&pass[c]);
        printf("*");
    }
    printf("\n");
    pass[7]='\0';*/
    scanf("%s",pass);
    if(strcmp(pass,str)==0)
    {
        printf("Access granted\n");
        return 1;
    }
    else
    {
        printf("Invalid password\n");
        return 0;
    }
    fclose(fp);
}

