#include "course.h"
#include "data.h"
#include <stdio.h>
typedef struct{
           int ID;
           int Month;
           int Day;
           int Seq;
           char Name[100];
    }CourseData;


void updateRecord(FILE *fPtr)
{
    int number;
    int NewMonth,NewDay,NewSeq;
    CourseData syllabus={0,0,0,0,""};
    printf("Enter number to update(1-100):");
    scanf("%d",&number);
    rewind(fPtr);
    fseek(fPtr,(number-1)*sizeof(CourseData),SEEK_SET);
    fread(&syllabus,sizeof(CourseData),1,fPtr);
    if(syllabus.ID==0){
        printf("ID #%d has no information.\n",number);

    }
    else{
        printf("%-4d%-6d%-4d%8d%5s\n",syllabus.ID,syllabus.Month,syllabus.Day,syllabus.Seq,syllabus.Name);
        printf("Enter the new month:");
        scanf("%d",&NewMonth);
        printf("\nEnter the new day:");
        scanf("%d",&NewDay);
        printf("\nEnter the new Seq:");
        scanf("%d",&NewSeq);
        syllabus.Month=NewMonth;
        syllabus.Day=NewDay;
        syllabus.Seq=NewSeq;
        printf("%\n-4d%-6d%-4d%8d%5s\n",syllabus.ID,syllabus.Month,syllabus.Day,syllabus.Seq,syllabus.Name);
        fseek(fPtr,(number-1)*sizeof(CourseData),SEEK_SET);
        fwrite(&syllabus,sizeof(CourseData),1,fPtr);
    }
}

void newRecord(FILE *fPtr)
{
    CourseData syllabus={0,0,0,0,""};
    int newID;
    printf("Enter new ID(1-100):");
    scanf("%d",&newID);
    rewind(fPtr);
    fseek(fPtr,(newID-1)*sizeof(CourseData),SEEK_SET);
    fread(&syllabus,sizeof(CourseData),1,fPtr);
    if(syllabus.ID!=0){
        printf("ID #%d already contains information.\n",syllabus.ID);
    }
    else{
        printf("Enter Month,Day,Seq,Name\n?");
        scanf("%d%d%d%s",&syllabus.Month,&syllabus.Day,&syllabus.Seq,&syllabus.Name);
        syllabus.ID=newID;
        rewind(fPtr);
        fseek(fPtr,(syllabus.ID-1)*sizeof(CourseData),SEEK_SET);
        fwrite(&syllabus,sizeof(CourseData),1,fPtr);
    }
}

void deleteRecord(FILE *fPtr)
{
     CourseData syllabus;
     CourseData blankSyllabus={0,0,0,0,""};
     int number;
     printf("Enter ID to delete(1-100):");
     scanf("%d",&number);
     rewind(fPtr);
     fseek(fPtr,(number-1)*sizeof(CourseData),SEEK_SET);
     fread(&syllabus,sizeof(CourseData),1,fPtr);
     if(syllabus.ID==0){
        printf("ID %d does not exist.\n",number);

    }
    else{
        rewind(fPtr);
        fseek(fPtr,(number-1)*sizeof(CourseData),SEEK_SET);
        fwrite(&blankSyllabus,sizeof(CourseData),1,fPtr);
    }
}

int enterChoice(void)
{
    int menuChoice;
    printf("\nEnter your choice\n");
    printf("1-update an ID\n");
    printf("2-add a new ID\n");
    printf("3-delete an ID\n");
    printf("4-end program\n?");
    scanf("%d",&menuChoice);
    return menuChoice;

}

void sortRecord(FILE *fPtr)
{
    CourseData syllabus[100];
    CourseData holdSyllabus;
    int daySeqofYear[100];
    int i;
    for(i=0;i<100;i++){
        rewind(fPtr);
        fseek(fPtr,i*sizeof(CourseData),SEEK_SET);
        fread(&syllabus[i],sizeof(CourseData),1,fPtr);
        if(syllabus[i].Month>0){
        daySeqofYear[i]=getDaySeqofYear(syllabus[i].Month,syllabus[i].Day);
        }
        else{
            daySeqofYear[i]=367;
        }
    }//end for
    int j,k;
    int hold;
    for(j=0;j<99;j++){
        for(k=0;k<99-j;k++){
            if(daySeqofYear[k]>daySeqofYear[k+1]){
                hold=daySeqofYear[k];
                daySeqofYear[k]=daySeqofYear[k+1];
                daySeqofYear[k+1]=hold;

                holdSyllabus=syllabus[k];
                syllabus[k]=syllabus[k+1];
                syllabus[k+1]=holdSyllabus;
            }//end if
        }//end for
    }//end for
    for(i=0;i<100;i++){
            rewind(fPtr);
        fseek(fPtr,i*sizeof(CourseData),SEEK_SET);
        fwrite(&syllabus[i],sizeof(CourseData),1,fPtr);
    }

}

void textFile(FILE *readPtr)
{
   FILE *writePtr;
   CourseData syllabus={0,0,0,0,""};
   if((writePtr=fopen("syllabus.txt","w"))==NULL){
        printf("File could not be opened.\n");
    }
    else{
        rewind(readPtr);
        fprintf(writePtr,"%-4s%-6s%-4s%8s%5s\n","ID","Month","Day","HourSeq","Name");

        while(!feof(readPtr)){
            fread(&syllabus,sizeof(CourseData),1,readPtr);
            if(syllabus.ID!=0){
                fprintf(writePtr,"%-4d%-6d%-4d%8d%5s\n",syllabus.ID,syllabus.Month,syllabus.Day,syllabus.Seq,syllabus.Name);
            }
        }
        fclose(writePtr);
    }
}



