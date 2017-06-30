#include <stdio.h>
#include <stdlib.h>
#include "course.h"
#include "data.h"

int main(void)
{
    FILE *cfPtr;
    int choice;
    Course cSyllabus[100];
    int i;
    for(i=0;i<100;i++){
        cSyllabus[i].ID=0;
        cSyllabus[i].Month=0;
        cSyllabus[i].Day=0;
        cSyllabus[i].Seq=0;
        cSyllabus[i].Name[0]='\0';
    }
    loadRecord(cfPtr,cSyllabus);
    while((choice=enterChoice())!=6){
            switch(choice){
            case 1:
                displayRecord(cSyllabus);
                cleanMenu();
                break;
            case 2:
                updateRecord(cSyllabus);
                sortRecord(cSyllabus);
                cleanMenu();
                break;
            case 3:
                newRecord(cSyllabus);
                sortRecord(cSyllabus);
                cleanMenu();
                break;
            case 4:
                deleteRecord(cSyllabus);
                sortRecord(cSyllabus);
                cleanMenu();
                break;
            case 5:
                saveRecord(cfPtr,cSyllabus);
                cleanMenu();
                break;
            default:
                printf("Incorrect choice\n");
                cleanMenu();
                break;
            }//end switch
        }//end while
    return 0;
}

void cleanMenu(void)
{
   printf("\nPress any key to continue...");
   getch();
   system("cls");
   return;
}

