#include <stdio.h>
#include "funs.h"
#include <time.h>


int main()
{
    const int numGame=8;
    int monkFights[numGame];//����ս������¼
    int evilFights[numGame];//����ս������¼
    int luckyEvils[numGame];//�����Ƿ�׽����ɮ��¼��0����δ׽��,1����׽��
    //�������к����������ս��ֵ
    CreateMonks(monkFights,numGame);
    CreateEvils(evilFights,numGame);
    //�ȽϺ��к�������ս�����
    printf("���ս�����Ľ��:\n");
    Fight(evilFights,monkFights,numGame);
    //��������ս��������Ժ���ս�������ź󣬱Ƚ�ս�����
    printf("�����Ľ��:\n");
    SortFights(evilFights,monkFights,numGame);
    Fight(evilFights,monkFights,numGame);
    //�����ʤ������
    int i=0;
    int numLuckyEvils=GetLuckyEvils(monkFights,luckyEvils,numGame);
    if(numLuckyEvils>0){
         printf("\n�����ι���%d������׽����ɮ�����ǵĳ��������б�:\n",numLuckyEvils);
         for(i=0;i<numGame;i++){
            if(luckyEvils[i]==1){
                printf("%3d",i+1);
            }
         }
        }
    else{
        printf("\n����û���Ƚ�������:(\n");
    }
    //����������ĺ��б��
    int busyMonkID=0;
    printf("\n���������:\n");
    GetBusyMonks(monkFights,&busyMonkID,numGame);
    if(busyMonkID==0){
        printf("��ɮ");
    }
    else if(busyMonkID==1){
        printf("��");
    }
    else if(busyMonkID==2){
        printf("�˽�");
    }
    else{
        printf("���");
    }
    return 0;
}
