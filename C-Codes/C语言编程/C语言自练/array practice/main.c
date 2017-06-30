#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5];
    int i;
    printf("please enter five numbers.\n");
    for(i=0;i<5;i++){
       scanf("%d",&a[i]);
    }
   for(i=4;i>=0;i--){
    printf("a[%d]=%d\n",i,a[i]);
   }
   int sum=0;
   for(i=0;i<5;i++){
    sum=sum+a[i];
   }
   printf("sum=%d\n",sum);
   printf("average=%d\n",sum/5);
   int hold,j,k;
   for(j=0;j<4;j++){
        for(k=0;k<4;k++){
            if(a[k]>=a[k+1]){
                hold=a[k];
                a[k]=a[k+1];
                a[k+1]=hold;
            }
        }
    }
    for(i=0;i<5;i++){
        printf("a[%d]=%d\n",i,a[i]);
    }
    printf("ÖÐÖµa[2]=%d\n",a[2]);

    return 0;
}
