#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "teacher.h"

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
        else if(ch==3)
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



