#include <stdio.h>
#include <stdlib.h>
typedef struct{
           int ID;
           int Month;
           int Day;
           int HourSeq;
           char Name[100];
    }Course;



int main()
{
  int i;
    Course blankSyllabus={0,0,0,0,""};
    FILE *cfPtr;
if((cfPtr=fopen("syllabus.txt","w"))==NULL){
        printf("File could not be opened.\n");
    }
    else{
        for(i=1;i<=100;i++){
            //fprintf(cfPtr,"%d%d%d%d%s\n",0,0,0,0,);?
        }
        fclose(cfPtr);
    }
    printf("文件已创立.\n");
    Course syllabus={0,0,0,0,""};
if((cfPtr=fopen("syllabus.txt","r+"))==NULL){
        printf("File could not be opened.\n");
    }
    else{
        printf("Enter ID""(1 to 100,0 to end input)\n?");
        scanf("%d",&syllabus.ID);
        while(syllabus.ID!=0){
            printf("Enter Month,Day,HourSeq,Name\n?");
            fscanf(stdin,"%d%d%d%s",&syllabus.Month,&syllabus.Day,&syllabus.HourSeq,syllabus.Name);
            fseek(cfPtr,(syllabus.ID-1)*sizeof(Course),SEEK_SET);
            fwrite(&syllabus,sizeof(Course),1,cfPtr);
            printf("Enter ID\n?");
            scanf("%d",&syllabus.ID);
        }
        fclose(cfPtr);
    }
    printf("Hello world!\n");
    if((cfPtr=fopen("syllabus.txt","r"))==NULL){
        printf("File could not be opened.\n");
    }
    else{
        printf("%-4s%-6s%-4s%8s%5s\n","ID","Month","Day","HourSeq","Name");
        while(!feof(cfPtr)){
            fread(&syllabus,sizeof(Course),1,cfPtr);
            if(syllabus.ID!=0){
                printf("%-4d%-6d%-4d%8d%5s\n",syllabus.ID,syllabus.Month,syllabus.Day,syllabus.HourSeq,syllabus.Name);
            }
        }
        fclose(cfPtr);
    }
    printf("Hello world!\n");
    return 0;
}
/*void sortRecord(FILE *fPtr)
{
    Course syllabus[100];
    int daySeqofYear[100];
    int i;
    for(i=0;i<100;i++){
        fread(&syllabus[i],sizeof(Course),1,fPtr);
        if(syllabus[i].Month>0){
        daySeqofYear[i]=getDaySeqofYear(syllabus[i].Month,syllabus[i].Day);}
        else{
            daySeqofYear[i]=367;
        }
    }//end for
    int j,k;
    int hold,holdID,holdMonth,holdDay,holdSeq;
    for(j=0;j<99;j++){
        for(k=0;k<99-j;k++){
            if(daySeqofYear[k]>daySeqofYear[k+1]){
                hold=daySeqofYear[k];
                daySeqofYear[k]=daySeqofYear[k+1];
                daySeqofYear[k+1]=hold;

                holdID=syllabus[k].ID;
                syllabus[k].ID=syllabus[k+1].ID;
                syllabus[k+1].ID=holdID;

                holdMonth=syllabus[k].Month;
                syllabus[k].Month=syllabus[k+1].Month;
                syllabus[k+1].Month=holdMonth;

                holdDay=syllabus[k].Day;
                syllabus[k].Day=syllabus[k+1].Day;
                syllabus[k+1].Day=holdDay;

                holdSeq=syllabus[k].HourSeq;
                syllabus[k].HourSeq=syllabus[k+1].HourSeq;
                syllabus[k+1].HourSeq=holdSeq;
                strcpy(syllabus[k+1].Name,syllabus[k].Name);
            }//end if
        }//end for
    }//end for
    for(i=0;i<100;i++){
        fseek(fPtr,i*sizeof(Course),SEEK_SET);
        fwrite(&syllabus[i],sizeof(Course),1,fPtr);
    }

}
int getDaySeqofYear(int month,int day)
{
 int daySeqofYear,i;
 int M[12]={31,28,31,30,31,30,31,31,30,31,30,31};存储每月天数的数组*/
 /*if(month==1){
    daySeqofYear=day;
 }
 else{
    daySeqofYear=day;
    for(i=0;i<=(month-2);i++){
        daySeqofYear=daySeqofYear+M[i];
    }
 }
 return daySeqofYear;
}*/

