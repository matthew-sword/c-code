#include <stdio.h>
#include <stdlib.h>

void getArray(int a[],int size);
void increaseArray(int a[],int size);

int main()
{
    int b[5],i;
    int SIZE=5;
    printf("please input five numbers.\n");
    for(i=0;i<5;i++){
      scanf("%d",&b[i]);
    }
    getArray(b,SIZE);
    printf("\n");
    increaseArray(b,SIZE);
    return 0;
}
void getArray(int a[],int size){
 int j;
 for(j=0;j<size;j++){
    printf("a[%d]=%d\n",j,a[j]);
 }
}
void increaseArray(int a[],int size){
 int j;
 for(j=0;j<size;j++){
    printf("a[%d]=%d\n",j,a[j]+1);
 }
}

