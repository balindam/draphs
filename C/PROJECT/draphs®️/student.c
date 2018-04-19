#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<structure.h>

extern struct node *first1;

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

}

void change_password()
{

}

int password_student()
{
    int enroll;
    printf("Enter the enrollment number\n");
    scanf("%d",&enroll);
    int l;
    l=enroll%100;
    FILE *fp;
    char str[7];
    fp=fopen("password_student.txt","r");
     while(l--)
    {
        fgets(str,6,fp);
    }
    printf("Enter the password");
    int c=0;
    char pass[7];

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
}
