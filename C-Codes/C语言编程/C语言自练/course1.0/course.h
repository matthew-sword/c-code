#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED
#include <stdio.h>
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
int enterChoice(void);
void sortRecord(FILE *fPtr);
void textFile(FILE *readfPtr);


#endif // COURSE_H_INCLUDED
