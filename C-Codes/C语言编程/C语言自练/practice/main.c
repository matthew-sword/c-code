#include <stdio.h>
#include <stdlib.h>
void searchArray(int *arrayName,int size,int *maxPtr,int *minPtr);

int main()
{
    int a[5]={3,4,1,6,2};
    int min=0,max=0;
    printf("max=%d\n",max);
    printf("min=%d\n",min);
    searchArray(a,5,&max,&min);
    printf("max=%d\n",max);
    printf("min=%d\n",min);
    return 0;
}

void searchArray(int *arrayName,int size,int *maxPtr,int *minPtr)
{
    int i;
    *maxPtr=arrayName[0];
    *minPtr=arrayName[0];
    for(i=1;i<size;i++){
        if(arrayName[i]>*maxPtr){
            *maxPtr=arrayName[i];
        }
    }
    for(i=1;i<size;i++){
        if(arrayName[i]<*minPtr){
            *minPtr=arrayName[i];
        }
    }
}
