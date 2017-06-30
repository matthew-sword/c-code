#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(void)
{
    int monster,people;/*monster����������ս������people����ʦͽ��ս����*/
    int A[4]={0,30,20,10};/*ʦͽ���ˣ�����ʦ�������ա��˽䡢����*/
    int i;/*����*/
    int a = 0,b = 0;/*ͳ��ʤ��*/
    srand(time(NULL));/*������ʼ��*/
    for(i = 1; i <= 10; i++){
     monster = rand() % 30;
     people=A[rand() % 4];
     if(monster > people){
        if(people == 0){
         printf("��%2d��:����ս����%2d \t��ɮ��ս����%2d",i,monster,people);
        }
        if(people == 30){
         printf("��%2d��:����ս����%2d \t���յ�ս����%2d",i,monster,people);
        }
        if(people == 20){
         printf("��%2d��:����ս����%2d \t�˽���ս����%2d",i,monster,people);
        }
        if(people == 10){
         printf("��%2d��:����ս����%2d \t�򾻵�ս����%2d",i,monster,people);

        }
         printf("\t����:������ʤ\n");
         a++;
     }
    if(monster == people){
        if(people == 0){
         printf("��%2d��:����ս����%2d \t��ɮ��ս����%2d",i,monster,people);
        }
        if(people == 30){
         printf("��%2d��:����ս����%2d \t���յ�ս����%2d",i,monster,people);
        }
        if(people == 20){
         printf("��%2d��:����ս����%2d \t�˽���ս����%2d",i,monster,people);
        }
        if(people == 10){
         printf("��%2d��:����ս����%2d \t�򾻵�ս����%2d",i,monster,people);

        }
         printf("\t����:ƽ��\n");
     }
     if(monster < people){
        if(people == 0){
         printf("��%2d��:����ս����%2d \t��ɮ��ս����%2d",i,monster,people);
        }
        if(people == 30){
         printf("��%2d��:����ս����%2d \t���յ�ս����%2d",i,monster,people);
        }
        if(people == 20){
         printf("��%2d��:����ս����%2d \t�˽���ս����%2d",i,monster,people);
        }
        if(people == 10){
         printf("��%2d��:����ս����%2d \t�򾻵�ս����%2d",i,monster,people);
        }
         printf("\t����:ʦͽ��ʤ\n");
         b++;
     }
    }
    printf("ս��ͳ��:");
    printf("����ʤ��:%d",a * 10);
    printf(".0%%");
    printf("\t");
    printf("ʦͽʤ��:%d",b * 10);
    printf(".0%%");
    return 0;
}
