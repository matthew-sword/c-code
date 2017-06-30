#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void resetArray(int array_x[],int array_size);
void displayArray(int array_x[],int array_size);
void sortArray_bubble(int array_x[],int array_size);
void sortArray_selection(int array_x[],int array_size);

int main()
{
    const int arraySize=8;
    int a[arraySize];
    resetArray(a,arraySize);
    displayArray(a,arraySize);
    printf("\n*\n");
    sortArray_bubble(a,arraySize);
    printf("\n*\n");
    sortArray_selection(a,arraySize);


    return 0;
}

void resetArray(int array_x[],int array_size)
{
 srand(time(NULL));
 int i;
 for(i=0;i<array_size;i++){
    array_x[i]=rand()%100;
 }
}

void displayArray(int array_x[],int array_size)
{
 int j;
 for(j=0;j<array_size;j++){
      printf("%6d",array_x[j]);
    }
    printf("\n");
}

void sortArray_bubble(int array_x[],int array_size)
{
 int m=0,n=0,hold;
 for(m=0;m<array_size-1;m++){
    for(n=0;n<array_size-1-m;n++){
        if(array_x[n]>array_x[n+1]){
            hold=array_x[n];
            array_x[n]=array_x[n+1];
            array_x[n+1]=hold;
        }
    }
    displayArray(array_x,array_size);
 }
}

void sortArray_selection(int array_x[],int array_size)
{
 int max,num;
 int i,j;
 for(j=0;j<array_size-1;j++){
        max=array_x[j];
        num=j;
    for(i=j;i<array_size-1;i++){
    if(array_x[j]<array_x[i+1]){
        max=array_x[i+1];
        num=i+1;
    }
 }
 array_x[num]=array_x[j];
 array_x[j]=max;
   displayArray(array_x,array_size);
 }
}



