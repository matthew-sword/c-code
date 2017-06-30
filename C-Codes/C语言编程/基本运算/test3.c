#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Hello world!\n");
    int a,b;
    int sum,pro,mod;
    scanf("%d%d",&a,&b);
    if(a>b){
        sum=a+b;
        printf("sum=%d\n",sum);
    }
    else if(a==b){
        pro=a*b;
        printf("pro=%d\n",pro);
    }
    else{
        mod=a%b;
        printf("mod=%d\n",mod);
    }


    return 0;
}
