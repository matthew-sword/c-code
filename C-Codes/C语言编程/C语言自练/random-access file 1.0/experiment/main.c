#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10]={1,3,5,7,9,2,4,6,8,0};
    int *aPtr;
    aPtr=a;
    int i;
    for(i=0;i<10;i=i+2){
        printf("%d\t",*(a+i));
    }
    printf("\n");
    int j;
    for(j=1;j<10;j=j+2){
        printf("%d\t",*(aPtr+j));
    }
    printf("\n");
    int m;
    for(m=9;m>=0;m--){
        printf("%d\t",a[m]);
    }
    printf("\n");
    int n;
    for(n=0;n<10;n++){
        printf("%d\n",aPtr[n]);
    }
    printf("Hello world!\n");
    return 0;
}
