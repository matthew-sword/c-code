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
         printf("��%2d��:����ս����%2d \t��ɮ��ս����%2d",i+1,evilFights[i],monkFights[i]);
        }
        else if(monkFights[i]==30){
         printf("��%2d��:����ս����%2d \t��յ�ս����%2d",i+1,evilFights[i],monkFights[i]);
        }
        else if(monkFights[i]==20){
         printf("��%2d��:����ս����%2d \t�˽��ս����%2d",i+1,evilFights[i],monkFights[i]);
        }
        else{
         printf("��%2d��:����ս����%2d \t�򾻵�ս����%2d",i+1,evilFights[i],monkFights[i]);

        }
         if(evilFights[i]>monkFights[i]){
             printf("\t���:������ʤ\n");
             a++;
         }
         if(evilFights[i]==monkFights[i]){
             printf("\t���:����ʤ��\n");
         }
         if(evilFights[i]<monkFights[i]){
             printf("\t���:ʦͽ��ʤ\n");
             b++;
         }
    }
     printf("ս��ͳ��:");
     printf("����ʤ��:%.2f%%",a*100/numGame);
     printf("\t");
     printf("ʦͽʤ��:%.2f%%\n",b*100/numGame);

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


