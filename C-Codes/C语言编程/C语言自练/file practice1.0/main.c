#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ID;
    int Month;
    int Day;
    int Seq;
    char Name[30];
    FILE *cfPtr;
    if((cfPtr=fopen("syllabus.txt","w"))==NULL){
        printf("File could not be opened\n");
    }
    else{
        printf("Enter the ID,Month,Day,Seq and Name.\n");
        printf("Enter EOF to end input.\n");
        printf("?");
        scanf("%d%d%d%d%s",&ID,&Month,&Day,&Seq,Name);

        while(!feof(stdin)){
            fprintf(cfPtr,"%d %d %d %d %s\n",ID,Month,Day,Seq,Name);
            printf("?");
            scanf("%d%d%d%d%s",&ID,&Month,&Day,&Seq,Name);
        }

        fclose(cfPtr);
    }
    printf("Hello world!\n");

    return 0;
}
