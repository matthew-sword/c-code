#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int daycounter(int ,int ,int );
int loop(int);
int nod(int,int); 
void gossip(int ,int );
int main(int argc, char *argv[]) 
{
	int yearB,monthB,dayB,daynow,daypass,daytotal;
	int yearT,monthT,dayT,daymild = 0,i;

	printf("������������գ���ʽ2000 1 1��\n");
	scanf("%d %d %d",&yearB,&monthB,&dayB);
	
	printf("����������ʱ�䣨��ʽ2000 1 1��\n");
	scanf("%d %d %d",&yearT,&monthT,&dayT);
	
	daynow = daycounter(yearT,monthT,dayT);
	daypass = daycounter(yearB,monthB,dayB);
	
	if (loop(yearB) == 1)   /*1��������*/
	   daypass = 366 - daypass;
	else 
	    daypass = 365 - daypass; 
	
	for (i = yearB + 1;i < yearT;i ++)
	{
		if (loop(i) == 1)
		   daymild = daymild + 366;
		else  
		   daymild = daymild + 365;  
	}
	
	daytotal = daypass + daynow  + daymild;
	printf("�������������Ѿ� %d ����!\n\n",daytotal); 
	gossip(yearB,yearT);
	return 0;
}




int loop(int y)       /*�����ж�*/
{
	int f;
	if(y%4==0&&y%100!=0)
	   f=1;
	else if(y%400==0)
	        f=1;
    else 
      f=0;
    return (f);
 } 
 
 
 

int nod(int x,int y)   /*��������*/
{
  int n,t;
  t=x-1;
  if(t==2)
    n=30*t+y-1;
  else if(t==3||t==4) 
    n=30*t+y;
  else if(t==1||t==5||t==6)
    n=30*t+y+1;
  else if(t==7)
    n=30*t+y+2;
  else if(t==8||t==9)
    n=30*t+y+3;
  else if(t==10||t==11)
    n=30*t+y+4;
  else if(t==0)
    n=y;
  return(n);
}
 
 
 
 int daycounter(int y,int m,int d)   /*����ͳ��*/
{
	int t,day;
	if (loop(y) == 0)
		day = nod(m,d);
	else if (m > 2)
	      day = nod(m,d) + 1;
	else  day = nod(m,d);
	return (day);
} 




void gossip(int b,int t)
{
	int c;
	c = t - b;
	if (c <= 20)       printf("���������д���ഺ!");
	else if (c <= 25)  printf("��Ů���У���������û�иϽ���ȥ����20��������ˣ�һ���ϲ�������"); 
	else if (c <= 30)  printf("���˺���������û�иϽ���ȥ������30�����ˣ�һ���ϲ�������");
	else if (c <= 40)  printf("���Ӵ���û��û�У��Ͻ��������������㶮�ģ�"); 
	else if (c <= 50)  printf("��Լ���������ǲ�Լ��");
	else if (c <= 100) printf("����Ա��������Ƭ��лл��");
	else if (c >=150)  printf("����������TA�Ĺײİ�ѹ��ȥ��"); 
	}
