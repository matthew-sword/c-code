#include "course.h"
#include "data.h"
#include <stdio.h>



void loadRecord(FILE *fPtr,Course syllabus[])
{
    if((fPtr=fopen("A.txt","r"))==NULL){
        printf("File could not be opened.\n");
    }//end if
    else{
        rewind(fPtr);
        fscanf(fPtr,"%d%d%d%d%s",&syllabus[0].ID,&syllabus[0].Month,&syllabus[0].Day,&syllabus[0].Seq,syllabus[0].Name);
        int j=1;
        while(!feof(fPtr)){
          fscanf(fPtr,"%d%d%d%d%s",&syllabus[j].ID,&syllabus[j].Month,&syllabus[j].Day,&syllabus[j].Seq,syllabus[j].Name);
          j++;
       }//end while
    fclose(fPtr);
    printf("OK");
    }//end else
    return;
}


void displayRecord(Course syllabus[])
{
    printf("%-5s%-7s%-5s%-5s%13s\n","ID","Month","Day","Seq","Name");
    int i;
    for(i=0;i<100;i++){
        if(syllabus[i].ID!=0){
           printf("%-5d%-7d%-5d%-5d%13s\n",syllabus[i].ID,syllabus[i].Month,syllabus[i].Day,syllabus[i].Seq,syllabus[i].Name);
        }
        else{
            break;
        }
    }
    return;
}


void updateRecord(Course syllabus[])
{
    int newMonth,newDay,newSeq;
    int number;
    printf("Enter number to update(1-100):");
    scanf("%d",&number);
    if(syllabus[number-1].ID==0){
        printf("ID #%d has no information.\n",number);

    }
    else{
        printf("%-5s%-7s%-5s%-5s%13s\n","ID","Month","Day","Seq","Name");
        printf("%-5d%-7d%-5d%-5d%13s\n",syllabus[number-1].ID,syllabus[number-1].Month,syllabus[number-1].Day,
               syllabus[number-1].Seq,syllabus[number-1].Name);
        printf("Enter the new month:");
        scanf("%d",&newMonth);
        printf("Enter the new day:");
        scanf("%d",&newDay);
        printf("Enter the new Seq:");
        scanf("%d",&newSeq);
        syllabus[number-1].Month=newMonth;
        syllabus[number-1].Day=newDay;
        syllabus[number-1].Seq=newSeq;
        printf("%-5s%-7s%-5s%-5s%13s\n","ID","Month","Day","Seq","Name");
        printf("%-5d%-7d%-5d%-5d%13s\n",syllabus[number-1].ID,syllabus[number-1].Month,syllabus[number-1].Day,
               syllabus[number-1].Seq,syllabus[number-1].Name);
    }//end else

    return;
}

void newRecord(Course syllabus[])
{
   int number;
   printf("Enter new number to add(1-100):");
   scanf("%d",&number);
   if(syllabus[number-1].ID!=0){
        printf("ID #%d already contains information.\n",number);
    }
   else{
      syllabus[number-1].ID=number;
      printf("Enter the new month:");
      scanf("%d",&syllabus[number-1].Month);
      printf("Enter the new day:");
      scanf("%d",&syllabus[number-1].Day);
      printf("Enter the new Seq:");
      scanf("%d",&syllabus[number-1].Seq);
      printf("Enter the new course name:");
      scanf("%s",syllabus[number-1].Name);
      printf("%-5s%-7s%-5s%-5s%13s\n","ID","Month","Day","Seq","Name");
      printf("%-5d%-7d%-5d%-5d%13s\n",syllabus[number-1].ID,syllabus[number-1].Month,syllabus[number-1].Day,
               syllabus[number-1].Seq,syllabus[number-1].Name);
   }

   return;
}
void deleteRecord(Course syllabus[])
{
   int number;
   printf("Enter the number to delete(1-100):");
   scanf("%d",&number);
   if(syllabus[number-1].ID==0){
        printf("ID #%d has no information.\n",number);
    }
   else{
        syllabus[number-1].ID=0;
        syllabus[number-1].Month=0;
        syllabus[number-1].Day=0;
        syllabus[number-1].Seq=0;
        syllabus[number-1].Name[0]='\0';
        printf("Delete successfully.\n");
   }
   return;
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
    printf("6-end program\n?");
    scanf("%d",&menuChoice);
    return menuChoice;
}

void sortRecord(Course syllabus[])
{
    int i;
    int days[100];
    Course holdSyllabus;
    int hold;

    for(i=0;i<100;i++){
        if(syllabus[i].ID!=0){
            days[i]=getDaySeqofYear(syllabus[i].Month,syllabus[i].Day)+syllabus[i].Seq;
        }
        else{
            days[i]=367+12;
        }
    }
    int j,k;
    for(j=0;j<99;j++){
        for(k=0;k<99-j;k++){
            if(days[k]>days[k+1]){
                hold=days[k];
                days[k]=days[k+1];
                days[k+1]=hold;
                holdSyllabus=syllabus[k];
                syllabus[k]=syllabus[k+1];
                syllabus[k+1]=holdSyllabus;
            }//end if
        }//end for
    }//end for
    for(i=1;i<=100;i++){
        if(syllabus[i-1].ID!=0){
            syllabus[i-1].ID=i;
        }
        else{
            break;
        }
    }
    return;
}



void saveRecord(FILE *fPtr,Course syllabus[])
{
    fPtr=fopen("B.txt","w");
    rewind(fPtr);
    int k;
    for(k=0;k<100;k++){
        if(syllabus[k].ID!=0){
           fprintf(fPtr,"%d %d %d %d %s\n",syllabus[k].ID,syllabus[k].Month,syllabus[k].Day,syllabus[k].Seq,syllabus[k].Name);
        }
        else{
            break;
        }
    }
    printf("OK");
    return;
}

