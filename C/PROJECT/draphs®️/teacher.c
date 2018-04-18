#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<structure.h>

extern struct node *first1;

void teacher_main()
{
    printf("Login page\n");
    int result;
    result = password_teacher();
    if(result==1)
    {
        do
        {
            printf("Enter any of the following options\n");
            label1:
                printf("1. Add student \n2. Search student \n3. Delete student \n4. Average marks \n5. Update Marks \n6. Append marks \n ");
                int choice;
                switch(choice)
                {
                case 1:
                    add_student_node();
                    break;
                case 2:
                    search_student();
                    break;
                case 3:
                    delete_student();
                    break;
                case 4:
                    avg_marks();
                    break;
                case 5:
                    update_marks();
                    break;
                case 6:
                    append_marks();
                    break;
                default:
                    printf("Wrong choice please enter the right choice\n");
                    goto label1;
                }
                printf("Enter the option\n");
                label2:
                    printf("1. Menu \n2. Logout\n");
                    scanf("%d",&choice);
                    if(choice!=1||choice!=2)
                    {
                        printf("Wrong choice please enter the right option\n");
                        goto label2;
                    }
            }while(choice==1);
        }
}

void append_node_marks(int e,int y,int s,int t,struct node_exam *newnode)
{
    struct node *temp;
    struct node_exam *temp1;
    temp=first1;
    while((temp->enrollno==e)&&(temp->year==y)&&(temp->sem==s)&&(temp->test==t))
    {
        temp=temp->next;
    }
    if(first1->next_exam==NULL)
    {
        first1->next_exam = newnode;
    }
    else
    {
        temp1=first1->next_exam;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=newnode;
    }
}

void create_node_marks()
{
    struct node_exam *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    char s[10];
    int m;
    int e,t,y,s;
    printf("Enter the enrollment number\n");
    scanf("%d",&e);
    printf("Enter the year\n");
    scanf("%d",&y);
    printf("Enter the semester\n");
    scanf("%d",&s);
    printf("Enter the test\n");
    scanf("%d",&t);
    printf("Enter the subject\n");
    scanf("%s",&s);
    printf("Enter the marks\n");
    scanf("%d",&m);
    strcpy(newnode->subject,s);
    newnode->marks=m;
    append(e,y,s,t,newnode);
}

void append_node(struct node *newnode)
{
    struct node *temp;
    if(first1==NULL)
    {
        first1=newnode;
        first1->next=NUlL;
    }
    else
    {
        temp=first1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void create_node()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int e,y,s,t;
    printf("Enter the enrollment number\n");
    scanf("%d",&e);
    printf("Enter the current year\n");
    scanf("%d",&y);
    printf("Enter the current semester\n");
    scanf("%d",&s);
    printf("Enter the current test\n");
    scanf("%d",&t);
    newnode->enrollno=e;
    newnode->year=y;
    newnode->sem=s;
    newnode->test=t;
    append_node(newnode);
}

void update_marks()
{

}

void append_marks()
{

}

void add_student_node()
{

}

void search_student()
{

}

void delete_student()
{

}

void avg_marks()
{

}

int password_teacher()
{
    char user[5];
    printf("Enter the username\n");
    scanf("%s",&user);
    FILE *fp;
    char str[7];
    fp=fopen("password_teacher.txt","r");
    int i=0;
    char u[6]
    while(1)
    {
        fgets(u,5,fp);
        if(strcmp(u,user)==0)
        {
            break;
        }
    }
    fgets(str,6,fp);
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
