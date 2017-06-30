#include <stdio.h>
#include <stdlib.h>
typedef struct{
           int ID;
           int Month;
           int Day;
           int Seq;
           char Name[100];
    }Course;



int main()
{
    Course syllabus={0,0,0,0,""};
    FILE *cfPtr;
    if((cfPtr=fopen("syllabus.txt","w"))==NULL){
        printf("File could not be opened\n");
    }//end if
    else{
        printf("Enter the ID,Month,Day,Seq and Name.\n");
        printf("Enter EOF to end input.\n");
        printf("?");
        scanf("%d%d%d%d%s",&syllabus.ID,&syllabus.Month,&syllabus.Day,&syllabus.Seq,syllabus.Name);
        while(!feof(stdin)){
            fprintf(cfPtr,"%d %d %d %d %s\n",syllabus.ID,syllabus.Month,syllabus.Day,syllabus.Seq,syllabus.Name);
            printf("?");
            scanf("%d%d%d%d%s",&syllabus.ID,&syllabus.Month,&syllabus.Day,&syllabus.Seq,syllabus.Name);
        }//end while
        fclose(cfPtr);
    }//end else
    return 0;
}
