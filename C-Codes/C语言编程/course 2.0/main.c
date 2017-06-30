#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "file.h"

int main()
{
    printf("Hello world!\n");
    char *Filename1= "syllabus.txt";
    char *Filename2= "course.txt";
    Node *header;
    header=loadCourseList(Filename1);
    int choice;
    while((choice=enterChoice())!=7){
        switch(choice){
            case 1:
                displayAllCourse(header);
                cleanMenu();
                break;
            case 2:
                header=updateCourse(header);
                header=sortID(header);
                cleanMenu();
                break;
            case 3:
                header=insertCourse(header);
                header=sortID(header);
                cleanMenu();
                break;
            case 4:
                header=deleteCourse(header);
                header=sortID(header);
                cleanMenu();
                break;
            case 5:
                saveCourseList(Filename2,header);
                cleanMenu();
                break;
            case 6:
                referByDate(header);
                cleanMenu();
                break;
            default:
                printf("Incorrect choice,please input your choice again.\n");
                cleanMenu();
                break;
            }//end switch
        }//end while
        destroyCourse(header);
    return 0;
}
