#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double y;
    int x,i;
    for(y=1;y>=-1;y-=0.1){
         x=acos(y)*10;
        for(i=1;i<x;i++){
            printf(" ");
        }
        printf(".");
        for(;i<62-x;i++){
            printf(" ");
        }
        printf(".\n");
    }
 return 0;
}
