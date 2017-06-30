#include <stdio.h>
#include "funs.h"
#include <time.h>


int main()
{
    const int numGame=8;
    int monkFights[numGame];//和尚战斗力记录
    int evilFights[numGame];//妖精战斗力记录
    int luckyEvils[numGame];//妖精是否捉到唐僧记录，0代表未捉到,1代表捉到
    //创建和尚和妖精的随机战斗值
    CreateMonks(monkFights,numGame);
    CreateEvils(evilFights,numGame);
    //比较和尚和妖精的战斗结果
    printf("随机战斗力的结果:\n");
    Fight(evilFights,monkFights,numGame);
    //按照妖精战斗力升序对和尚战斗力重排后，比较战斗结果
    printf("排序后的结果:\n");
    SortFights(evilFights,monkFights,numGame);
    Fight(evilFights,monkFights,numGame);
    //计算获胜妖精数
    int i=0;
    int numLuckyEvils=GetLuckyEvils(monkFights,luckyEvils,numGame);
    if(numLuckyEvils>0){
         printf("\n本场次共有%d个妖精捉到唐僧，他们的出场次序列表:\n",numLuckyEvils);
         for(i=0;i<numGame;i++){
            if(luckyEvils[i]==1){
                printf("%3d",i+1);
            }
         }
        }
    else{
        printf("\n本场没有先进的妖精:(\n");
    }
    //计算出场最多的和尚编号
    int busyMonkID=0;
    printf("\n辛苦和尚是:\n");
    GetBusyMonks(monkFights,&busyMonkID,numGame);
    if(busyMonkID==0){
        printf("唐僧");
    }
    else if(busyMonkID==1){
        printf("悟净");
    }
    else if(busyMonkID==2){
        printf("八戒");
    }
    else{
        printf("悟空");
    }
    return 0;
}
