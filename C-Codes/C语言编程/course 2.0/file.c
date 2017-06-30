#include "file.h"


Node* loadCourseList(const char * filename)
{
    FILE *fPtr;
    if ( (fPtr = fopen ( filename, "r" )) == NULL )
    {
        printf("This file is not found.\n");
        return NULL;
    }
    else{
        Node *head;
        head = malloc(sizeof(Node));
        rewind(fPtr);
        fscanf(fPtr,"%d%d%d%d%s\n",&head->ID,&head->Month,&head->Day,&head->Seq,head->Name);
        if(feof(fPtr)){
            printf("There is nothing can be loaded.\n");
            return NULL;
        }
        head->Number = getDaySeqofYear(head->Month,head->Day);
        head->nextPtr = NULL;
        Node *previous;
        Node *current;
        previous = head;
        int i;
        for(i = 1;!feof(fPtr);i++){
            current = malloc(sizeof(Node));
            fscanf(fPtr,"%d%d%d%d%s\n",&current->ID,&current->Month,&current->Day,&current->Seq,current->Name);
            current->Number = getDaySeqofYear(current->Month,current->Day);
            current->nextPtr = NULL;
            previous->nextPtr = current;
            previous = current;
        }
        fclose(fPtr);
        printf("Total %d records are loaded.\n",i);
        return head;
    }
}

void saveCourseList(const char* filename,Node* head)
{
    FILE* fPtr;
    fPtr = fopen(filename,"w");
    rewind(fPtr);
    if(head != NULL){
        Node *pNode;
        for(pNode = head;pNode != NULL;pNode = pNode->nextPtr){
            fprintf(fPtr,"%-5d%-7d%-5d%-5d%13s\n",pNode->ID,pNode->Month,pNode->Day,pNode->Seq,pNode->Name);
        }//end for
        printf("File is saved successfully.\n");
    }

   else{
        printf("There is not anything can be saved.\n");
   }
}

int enterChoice(void)
{
    int menuChoice;
    printf("\nEnter your choice\n");
    printf("1-display the record\n");
    printf("2-update an ID\n");
    printf("3-add a new ID\n");
    printf("4-delete an ID\n");
    printf("5-save the record\n");
    printf("6-refer course by date\n");
    printf("7-end program\n?");
    scanf("%d",&menuChoice);
    return menuChoice;
}


void cleanMenu(void)
{
   printf("\nPress any key to continue...");
   getch();
   system("cls");
   return;
}


int getDaySeqofYear(int month,int day)
{
   int daySeqofYear,i;
   int M[12]={0,31,28,31,30,31,30,31,31,30,31,30};/*存储每月天数的数组*/
      daySeqofYear=day;
      for(i=0;i<month;i++){
         daySeqofYear=daySeqofYear+M[i];
       }
   return daySeqofYear;
}


