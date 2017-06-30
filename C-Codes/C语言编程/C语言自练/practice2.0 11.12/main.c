#include <stdio.h>
#include <stdlib.h>
 typedef struct{
           int ID;
           int Month;
           int Day;
           int HourSeq;
           char Name[100];
    }Course;

void displayCourseList(Course cCourseList[],int size);

int main(void)
{
    Course syllabus[3]={{1,2,25,3,"c++"},{2,4,27,3,"c++"},{3,5,3,1,"Digit-Circuit"}};
    int a=3;
    printf("ID\tDate\tSeq\tcourseName\n");
    displayCourseList(syllabus,a);

    return 0;
}

void displayCourseList(Course cCourseList[],int size)
{
    int i;
    for(i=0;i<size;i++){
        printf("%d",cCourseList[i].ID);
        printf("\t%d",cCourseList[i].Month);
        printf("-");
        printf("%d",cCourseList[i].Day);
        printf("\t%d",cCourseList[i].HourSeq);
        printf("\t%s\n",cCourseList[i].Name);
    }
}
