#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define SIZE 5

int main()
{
    int Monster[SIZE],Monk[SIZE];
    int Sword[4]={0,30,20,10};/*��ɮ����ա��˽䡢ɳɮ��ս����*/
    srand(time(NULL));/*�����ʼ��*/
    int i;
    for(i=0;i<SIZE;i++){
       Monster[i]=rand()%30;
    }
    for(i=0;i<SIZE;i++){
        Monk[i]=Sword[rand()%4];
    }
    int a=0,b=0;/*aΪ��¼������ʤ�ľ�����bΪ��¼���л�ʤ�ľ���*/
    printf("���ս���Ľ��:\n");
    for(i=0;i<SIZE;i++){
        if(Monk[i]==0){
         printf("��%2d��:����ս����%2d \t��ɮ��ս����%2d",i+1,Monster[i],Monk[i]);
        }
        else if(Monk[i]==30){
         printf("��%2d��:����ս����%2d \t��յ�ս����%2d",i+1,Monster[i],Monk[i]);
        }
        else if(Monk[i]==20){
         printf("��%2d��:����ս����%2d \t�˽��ս����%2d",i+1,Monster[i],Monk[i]);
        }
        else{
         printf("��%2d��:����ս����%2d \t�򾻵�ս����%2d",i+1,Monster[i],Monk[i]);

        }
         if(Monster[i]>Monk[i]){
             printf("\t���:������ʤ\n");
             a++;
         }
         if(Monster[i]==Monk[i]){
             printf("\t���:ƽ��\n");
         }
         if(Monster[i]<Monk[i]){
             printf("\t���:ʦͽ��ʤ\n");
             b++;
         }
    }
    printf("ս��ͳ��:");
    printf("����ʤ��:%d",a*100/5);
    printf(".0%%");
    printf("\t");
    printf("ʦͽʤ��:%d",b*100/5);
    printf(".0%%\n");

    a=0;
    b=0;
    printf("����Խ��Խǿ�Ľ��:\n");
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
         printf("��%2d��:����ս����%2d \t��ɮ��ս����%2d",i+1,Monster[i],Monk[i]);
        }
        else if(Monk[i]==30){
         printf("��%2d��:����ս����%2d \t��յ�ս����%2d",i+1,Monster[i],Monk[i]);
        }
        else if(Monk[i]==20){
         printf("��%2d��:����ս����%2d \t�˽��ս����%2d",i+1,Monster[i],Monk[i]);
        }
        else{
         printf("��%2d��:����ս����%2d \t�򾻵�ս����%2d",i+1,Monster[i],Monk[i]);

        }
         if(Monster[i]>Monk[i]){
             printf("\t���:������ʤ\n");
             a++;
         }
         if(Monster[i]==Monk[i]){
             printf("\t���:ƽ��\n");
         }
         if(Monster[i]<Monk[i]){
             printf("\t���:ʦͽ��ʤ\n");
             b++;
         }
    }
    printf("ս��ͳ��:");
    printf("����ʤ��:%d",a*100/5);
    printf(".0%%");
    printf("\t");
    printf("ʦͽʤ��:%d",b*100/5);
    printf(".0%%\n");
    return 0;
}
