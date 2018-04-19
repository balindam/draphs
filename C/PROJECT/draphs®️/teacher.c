#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "teacher.h"

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

struct node_exam
{
    char subject[10];
    int marks;
    struct node_exam *next;
};

struct node
{
    int enrollno;
    int year;
    int sem;
    int test;
    struct node_exam *next_exam;
    struct node *next;
};

struct node *first=NULL;

int password_teacher();
void fileread();
void add_student_node();
void search_student();
void delete_student();
void create_node_marks();
void avg_marks();
void append_marks();
void update_marks();
void writetofile();
void append_node_marks(int e,int y,int s,int t,struct node_exam *newnode);
void create_node();
void append_node(struct node *);
void display();


void teacher_main()
{
    printf("Login page\n");
    int choice;
    int result;
    result = password_teacher();
    if(result==1)
    {
        fileread();
        //display();
        do
        {
            printf("Enter any of the following options\n");
            label1:
                printf("1. Add student \n2. Search student \n3. Delete student \n4. Average marks \n5. Update Marks \n6. Append marks \n ");
                scanf("%d",&choice);
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
                    if(choice!=1&&choice!=2)
                    {
                        printf("Wrong choice please enter the right option\n");
                        goto label2;
                    }
             //printf("123");
            }while(choice==1);
        }
        printf("1234");
        display();
        printf("123456");
        if(first!=NULL)
    writetofile();
    else
    {
        FILE *fp;
        fp=fopen("data.txt","w");
        fclose(fp);
    }
    printf("12345678");
}

void append_node_marks(int e,int y,int s,int t,struct node_exam *newnode)
{
    struct node *temp;
    struct node_exam *temp1;
    temp=first;
    while(1)
    {
        if((temp->enrollno==e)&&(temp->year==y)&&(temp->sem==s)&&(temp->test==t))
        {
            break;
        }
        else if(temp->next!=NULL)
        {
            temp=temp->next;
        }
        else
            break;
    }
    if(temp->next_exam==NULL)
    {
        temp->next_exam = newnode;
        newnode->next=NULL;
    }
    else
    {
        temp1=temp->next_exam;
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
    newnode = (struct node_exam *)malloc(sizeof(struct node_exam));
    char sub[10];
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
    scanf("%s",sub);
    printf("Enter the marks\n");
    scanf("%d",&m);
    strcpy(newnode->subject,sub);
    newnode->marks=m;
    newnode->next=NULL;
   // printf("1234");
    append_node_marks(e,y,s,t,newnode);
    //printf("1234455");
}

void append_node(struct node *newnode)
{
    struct node *temp;
    if(first==NULL)
    {
        first=newnode;
    }
    else
    {
        temp=first;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    create_node_marks();
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
    newnode->next=NULL;
    append_node(newnode);
}

void update_marks()
{
    struct node *temp1;
    struct node_exam *temp2;
    temp1=first;
    int e,y,s,t,m;
    char sub[10];
    printf("Enter the enrollment number\n");
    scanf("%d",&e);
    printf("Enter the year\n");
    scanf("%d",&y);
    printf("Enter the semester\n");
    scanf("%d",&s);
    printf("Enter the test\n");
    scanf("%d",&t);
    printf("Enter the subject\n");
    scanf("%s",sub);
    while(temp1!=NULL)
    {
        if(temp1->year==y && temp1->sem==s && temp1->enrollno==e && temp1->test==t)
        {
            break;
        }
        else
        {
            if(temp1->next!=NULL)
                temp1=temp1->next;
            else
                break;
        }
    }
    temp2=temp1->next_exam;
    while(temp2!=NULL)
    {
        if(strcmp(temp2->subject,sub)==0)
        {
            break;
        }
        else
        {
            if(temp2->next!=NULL)
                temp2=temp2->next;
            else
                break;
        }
    }
    printf("Enter new marks: \n");
    scanf("%d",&m);
    temp2->marks=m;
}

void append_marks()
{
    int e,y,s,t,m;char sub[10];
    printf("Enter the details of the subject to be added\n");
    printf("Enter the enrollment number\n");
    scanf("%d",&e);
    printf("Enter the year\n");
    scanf("%d",&y);
    printf("Enter the semester\n");
    scanf("%d",&s);
    printf("Enter the test\n");
    scanf("%d",&t);
    printf("Enter the new subject\n");
    scanf("%s",sub);
    printf("Enter the marks\n");
    scanf("%d",&m);
    int f;f=0;
    struct node *temp1;
    struct node_exam *temp2;temp2=NULL;
    temp1=first;
    while(temp1!=NULL)
    {

        if(temp1->enrollno==e && temp1->sem==s && temp1->test==t && temp1->year==y)
        {
            temp2=temp1->next_exam;
            while(temp2!=NULL)
            {
                if(temp2->next!=NULL)
                    temp2=temp2->next;
                else
                {
                    struct node_exam *newnode;
                    newnode=(struct node_exam *)malloc(sizeof(struct node_exam));
                    strcpy(newnode->subject,sub);
                    newnode->marks=m;
                    temp2->next=newnode;
                    newnode->next=NULL;
                    f=1;
                    break;
                }
            }
            if(f==1)
            break;
        }
        else
        {
            if(temp1->next!=NULL)
            {
                temp1=temp1->next;
            }
            else
                break;
        }
    }
}

void add_student_node()
{
    printf("Enter the details of the student to be added\n");
    create_node();
}

void search_student()
{
    display();
    int e,f;f=0;
    struct node *temp1;
    struct node_exam *temp2;temp2=NULL;
    temp1=first;
    printf("enter enrollment number of the student: ");
    scanf("%d",&e);
    printf("enrollment number of the student is %d\n",e);
    while(temp1!=NULL)
    {
        temp2=temp1->next_exam;
        if(temp1->enrollno==e)
        {
            while(temp2!=NULL)
            {
                printf("Marks of the student in the subject %s is %d in the exam T%d in semester %d\n",temp2->subject,temp2->marks,temp1->test,temp1->sem);
                if(temp2->next!=NULL)
                temp2=temp2->next;
                else
                {
                    f=1;
                    break;
                }
            }
        }
        else
        {
            if(temp1->next!=NULL)
            {
                temp1=temp1->next;
            }
            else
                break;
        }
        if(f==1)
            break;
    }
}

void delete_student()
{
    int e;
    struct node *temp,*prev,*ahead;prev=NULL;
    printf("Enter the student enrollment number to be deleted\n");
    scanf("%d",&e);
    temp=first;
    if(temp->next==NULL)
    {
        free(temp);
        first=NULL;
        printf("123");
    }
    else
    {
        ahead=temp->next;
        while(ahead!=NULL)
        {
            if(temp->enrollno==e)
            {
                if(prev==NULL)
                {
                    free(temp);
                    first=ahead;
                    break;
                }
                else
                {
                    prev->next=ahead;
                    free(temp);
                    break;
                }
            }
            prev=temp;
            temp=temp->next;
            if(ahead->next!=NULL)
                ahead=ahead->next;
            else
                break;
        }
        if(temp->enrollno==e)
        {
            prev->next=NULL;
        }
    }
}

void avg_marks()
{
    char sub[10];
    printf("Enter the subject\n");
    scanf("%s",sub);
    int count=0;
    int m=0;
    float avg;
    struct node *temp1;
    struct node_exam *temp2;
    temp1=first;
    while(temp1!=NULL)
    {
        temp2=temp1->next_exam;
        while(temp2->next!=NULL)
        {
            if(strcmp(temp2->subject,sub)==0)
            {
                break;
            }
            else
            {
                temp2=temp2->next;
            }
        }
        if(strcmp(temp2->subject,sub)==0)
        {
            m=m+temp2->marks;
            count++;
            if(temp1->next!=NULL)
                temp1=temp1->next;
            else

                break;
        }
    }
    avg=(float)m/count;
    printf("Average marks of all student in subject %s is %f\n",sub,avg);
}

void fileread()
{
    FILE *fp;
    int e,eprev,size,y,s,t,m;char sub[10];
    fp=fopen("data.txt","r");
    struct node *temp1;
    struct node_exam *temp2,*newnode2;temp1=NULL;temp2=NULL;
    struct node *newnode1;

    while(fscanf(fp,"%d %d %d %d %s %d ",&e,&y,&s,&t,sub,&m)!=EOF)
    {
        if(temp1==NULL)
        {
            newnode1=(struct node *)malloc(sizeof(struct node));
            newnode1->enrollno=e;
            newnode1->year=y;
            newnode1->sem=s;
            newnode1->test=t;
            newnode2=(struct node_exam *)malloc(sizeof(struct node_exam));
            strcpy(newnode2->subject,sub);
            newnode2->marks=m;
            first=newnode1;
            temp1=first;
            first->next_exam=newnode2;
            temp2=newnode2;
            first->next=NULL;
            temp2->next=NULL;
        }
        else
        {
            if(e==eprev)
            {
            newnode2=(struct node_exam *)malloc(sizeof(struct node_exam));
            strcpy(newnode2->subject,sub);
            newnode2->marks=m;
            temp2->next=newnode2;
            temp2=newnode2;
            temp2->next=NULL;
            }
            else
            {
            newnode1=(struct node *)malloc(sizeof(struct node));
            newnode1->enrollno=e;
            newnode1->year=y;
            newnode1->sem=s;
            newnode1->test=t;
            temp1->next=newnode1;
            temp1=temp1->next;
            newnode2=(struct node_exam *)malloc(sizeof(struct node_exam));
            strcpy(newnode2->subject,sub);
            newnode2->marks=m;
            temp1->next_exam=newnode2;
            temp2=newnode2;
            temp2->next=NULL;
            }
        }
        eprev=e;
    }
    fclose(fp);
}
void display()
{
    struct node *temp;struct node_exam *temp1;
    temp=first;
    while(temp!=NULL)
    {
        printf("%d->%d->%d->%d->",temp->enrollno,temp->year,temp->sem,temp->test);
        temp1=temp->next_exam;
        while(temp1!=NULL)
        {
            printf("%s->%d->",temp1->subject,temp1->marks);
            if(temp1->next!=NULL)
                temp1=temp1->next;
            else
                break;
        }
        if(temp->next!=NULL)
            temp=temp->next;
        else
            break;
    }
}
void writetofile()
{
    FILE *fp;
    fp=fopen("data.txt","w");
    struct node *temp1;
    struct node_exam *temp2;
    temp1=first;
    while(temp1!=NULL)
    {
        temp2=temp1->next_exam;
        while(temp2!=NULL)
        {
            fprintf(fp,"%d %d %d %d ",temp1->enrollno,temp1->year,temp1->sem,temp1->test);
            fprintf(fp,"%s %d ",temp2->subject,temp2->marks);
            if(temp2->next!=NULL)
                temp2=temp2->next;
            else
                break;
        }
        if(temp1->next!=NULL)
            temp1=temp1->next;
        else
            break;
    }
fclose(fp);
}

int password_teacher()
{
    char user[10];
    printf("Enter the username\n");
    scanf("%s",user);
    FILE *fp;
    char str[10];
    fp=fopen("password_teacher.txt","r");
    char u[10];
    while(1)
    {
        while(fscanf(fp,"%s %s ",u,str)!=EOF)
        {
            if(strcmp(u,user)==0)
            {
                break;
            }
        }
    printf("Enter the password");
    int c=0;
    char pass[10];
   /* while(c!=6)
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
}
fclose(fp);
}

