#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define SIZE 5

int main()
{
    int Monster[SIZE],Monk[SIZE];
    int Sword[4]={0,30,20,10};/*唐僧、悟空、八戒、沙僧的战斗力*/
    srand(time(NULL));/*随机初始化*/
    int i;
    for(i=0;i<SIZE;i++){
       Monster[i]=rand()%30;
    }
    for(i=0;i<SIZE;i++){
        Monk[i]=Sword[rand()%4];
    }
    int a=0,b=0;/*a为记录妖精获胜的局数，b为记录和尚获胜的局数*/
    printf("随机战斗的结果:\n");
    for(i=0;i<SIZE;i++){
        if(Monk[i]==0){
         printf("第%2d局:妖精战斗力%2d \t唐僧的战斗力%2d",i+1,Monster[i],Monk[i]);
        }
        else if(Monk[i]==30){
         printf("第%2d局:妖精战斗力%2d \t悟空的战斗力%2d",i+1,Monster[i],Monk[i]);
        }
        else if(Monk[i]==20){
         printf("第%2d局:妖精战斗力%2d \t八戒的战斗力%2d",i+1,Monster[i],Monk[i]);
        }
        else{
         printf("第%2d局:妖精战斗力%2d \t悟净的战斗力%2d",i+1,Monster[i],Monk[i]);

        }
         if(Monster[i]>Monk[i]){
             printf("\t结果:妖精获胜\n");
             a++;
         }
         if(Monster[i]==Monk[i]){
             printf("\t结果:平局\n");
         }
         if(Monster[i]<Monk[i]){
             printf("\t结果:师徒获胜\n");
             b++;
         }
    }
    printf("战局统计:");
    printf("妖精胜率:%d",a*100/5);
    printf(".0%%");
    printf("\t");
    printf("师徒胜率:%d",b*100/5);
    printf(".0%%\n");

    a=0;
    b=0;
    printf("妖精越来越强的结果:\n");
    int hold1,hold2,j,k;
    for(j=0;j<SIZE-1;j++){
        for(k=0;k<SIZE-1;k++){
            if(Monster[k]>=Monster[k+1]){
                hold1=Monster[k];
                Monster[k]=Monster[k+1];
                Monster[k+1]=hold1;
                hold2=Monk[k];
                Monk[k]=Monk[k+1];
                Monk[k+1]=hold2;
            }
        }
    }
     for(i=0;i<SIZE;i++){
        if(Monk[i]==0){
         printf("第%2d局:妖精战斗力%2d \t唐僧的战斗力%2d",i+1,Monster[i],Monk[i]);
        }
        else if(Monk[i]==30){
         printf("第%2d局:妖精战斗力%2d \t悟空的战斗力%2d",i+1,Monster[i],Monk[i]);
        }
        else if(Monk[i]==20){
         printf("第%2d局:妖精战斗力%2d \t八戒的战斗力%2d",i+1,Monster[i],Monk[i]);
        }
        else{
         printf("第%2d局:妖精战斗力%2d \t悟净的战斗力%2d",i+1,Monster[i],Monk[i]);

        }
         if(Monster[i]>Monk[i]){
             printf("\t结果:妖精获胜\n");
             a++;
         }
         if(Monster[i]==Monk[i]){
             printf("\t结果:平局\n");
         }
         if(Monster[i]<Monk[i]){
             printf("\t结果:师徒获胜\n");
             b++;
         }
    }
    printf("战局统计:");
    printf("妖精胜率:%d",a*100/5);
    printf(".0%%");
    printf("\t");
    printf("师徒胜率:%d",b*100/5);
    printf(".0%%\n");
    return 0;
}
