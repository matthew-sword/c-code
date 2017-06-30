#include <stdio.h>
#include <stdlib.h>
#include "course.h"
typedef struct{
           int ID;
           int Month;
           int Day;
           int Seq;
           char Name[100];
    }CourseData;

int main(void)
{
    FILE *cfPtr;
    int choice;
    if((cfPtr=fopen("syllabus.txt","r+"))==NULL){
        printf("File could not be opened.\n");
    }//end if
    else{
        while((choice=enterChoice())!=4){
            switch(choice){
            case 1:
                updateRecord(cfPtr);
                cleanMenu();
                break;
            case 2:
                newRecord(cfPtr);
                cleanMenu();
                break;
            case 3:
                deleteRecord(cfPtr);
                cleanMenu();
                break;
            default:
                printf("Incorrect choice\n");
                cleanMenu();
                break;
            }//end switch
        }//end while
       // sortRecord(cfPtr);
       // textFile(cfPtr);
        fclose(cfPtr);
    }//end else
    return 0;
}

void cleanMenu(void)
{
   printf("\nPress any key to continue...");
   getch();
   system("cls");
   return;
}
