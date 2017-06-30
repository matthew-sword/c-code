#include "funs.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void CreateMonks(int monkFights[],int numGame)
{
 int monk[4]={0,30,20,10};
 int k;
 srand(time(NULL));
 for(k=0;k<numGame;k++){
    monkFights[k]=monk[rand()%4];
 }
}


void CreateEvils(int evilFights[],int numGame)
{
 int j;
 srand(time(NULL));
 for(j=0;j<numGame;j++){
    evilFights[j]=rand()%30+1;
 }
}


void Fight(const int evilFights[],const int monkFights[],int numGame)
{
  int i;
  float a=0,b=0;
  for(i=0;i<numGame;i++){
        if(monkFights[i]==0){
         printf("第%2d局:妖精战斗力%2d \t唐僧的战斗力%2d",i+1,evilFights[i],monkFights[i]);
        }
        else if(monkFights[i]==30){
         printf("第%2d局:妖精战斗力%2d \t悟空的战斗力%2d",i+1,evilFights[i],monkFights[i]);
        }
        else if(monkFights[i]==20){
         printf("第%2d局:妖精战斗力%2d \t八戒的战斗力%2d",i+1,evilFights[i],monkFights[i]);
        }
        else{
         printf("第%2d局:妖精战斗力%2d \t悟净的战斗力%2d",i+1,evilFights[i],monkFights[i]);

        }
         if(evilFights[i]>monkFights[i]){
             printf("\t结果:妖精获胜\n");
             a++;
         }
         if(evilFights[i]==monkFights[i]){
             printf("\t结果:不分胜负\n");
         }
         if(evilFights[i]<monkFights[i]){
             printf("\t结果:师徒获胜\n");
             b++;
         }
    }
     printf("战局统计:");
     printf("妖精胜率:%.2f%%",a*100/numGame);
     printf("\t");
     printf("师徒胜率:%.2f%%\n",b*100/numGame);

}


void SortFights(int evilFights[],int monkFights[],int numGame)
{
  int hold1,hold2,j,k;
    for(j=0;j<numGame-1;j++){
        for(k=0;k<numGame-1;k++){
            if(evilFights[k]>=evilFights[k+1]){
                hold1=evilFights[k];
                evilFights[k]=evilFights[k+1];
                evilFights[k+1]=hold1;
                hold2=monkFights[k];
                monkFights[k]=monkFights[k+1];
                monkFights[k+1]=hold2;
            }
        }
    }

}


int GetLuckyEvils(const int monkFights[],int luckyEvils[],int numGame)
{
 int i;
 int numLuckyEvils=0;
 for(i=0;i<numGame;i++){
    if(monkFights[i]==0){
        luckyEvils[i]=1;
        numLuckyEvils++;
    }
    else{
        luckyEvils[i]=0;
    }
 }
 return numLuckyEvils;
}


void GetBusyMonks(const int monkFights[],int *busyMonkID,int numGame)
{
 int monkTimes[4]={};
 int i;
 for(i=0;i<numGame;i++){
    if(monkFights[i]==0){
        monkTimes[0]++;
    }
    else if(monkFights[i]==10){
        monkTimes[1]++;
    }
    else if(monkFights[i]==20){
        monkTimes[2]++;
    }
    else{
        monkTimes[3]++;
    }
 }
 int max;
 max=monkTimes[0];
 *busyMonkID=0;
 for(i=1;i<4;i++){
    if(monkTimes[i]>max){
        max=monkTimes[i];
        *busyMonkID=i;
    }
 }
}


