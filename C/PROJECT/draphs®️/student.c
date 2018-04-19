#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<structure.h>

int enroll;

void student_main()
{
    printf("Login page");
    int result;
    result = password_student();
    if(result==1)
    {
        do
            {
            printf("Select any one of the following\n");
            label1:
                printf("1. Generate marksheet \n2. Change password\n");
                int choice;
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
                printf("1. Menu \n2.Logout \");
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
        if(e==enroll)
        {
            printf("Enrollment no.- %d\n Year - %d\n Semester - %d\n Test - %d\n Subject - %s\n Marks - %d\n",e,y,s,t,sub,m);
        }
    }
    fclose(fp);
}

void change_password(int en)
{
    int enroll;char str1[6];
    FILE *fp;
    fp=fopen("password_student.txt","r+");
    while(fscanf(fp,"%d ",&enroll)!=EOF)
    {
        if(enroll==en)
        {
            printf("Enter the new password\n");
            scanf("%s",str1);
            fwrite(fp,"%s ",str1);
        }
        else
        {
            fscanf(fp,"%s ",str);
        }
    }
}

int password_student()
{

    printf("Enter the enrollment number\n");
    scanf("%d",&enroll);
    FILE *fp;
    char str[6];
    fp=fopen("password_student.txt","r");
    printf("Enter the password");
    int c=0;int e;
    char pass[7];
    while(fscanf(fp,"%d %s ",&e,str)!=EOF)
    {
        if(e==enroll)
            break;
    }
    while(c!=6)
    {
        scanf("%c",&pass[c]);
        printf("*");
    }
    printf("\n");
    pass[7]='\0';
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
