#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
  int yao,i,zhan,n=0,winrate,monk[5]={0,10,20,30};
  int yaonum[10] = {0},j = 0,k; 
  char *m_name[]={"��ɮ","ɳɮ","�˽�","���"}; 
  
  srand(time(0));
  for(i=0;i<10;i++)
  {
  	yao=rand()%30;      /*�������ս����*/ 
  	zhan=rand()%4;     /*���г���˳��*/ 
  	
  	
  	if(monk[zhan]>yao)  /*����ս��*/ 
  	{
  		n+=1; 
  		printf("��%d�� ",i+1); 
  		printf("��=%-5d  %s =%-5d ����ʤ\n\n",yao,m_name[zhan],monk[zhan]);
	  }
	else if(monk[zhan]==yao)
	{
		printf("��%d�� ",i+1);
		printf("��=%-5d  %s =%-5d ƽ��\n\n",yao,m_name[zhan],monk[zhan]);
	}
	       
    else   
	{
		printf("��%d�� ",i+1);
		printf("��=%-5d  %s =%-5d ����ʤ\n\n",yao,m_name[zhan],monk[zhan]);
	}
 
   if (monk[zhan] == 0)    /*��������*/  
   {
   	yaonum[j] = i + 1;
   	j++;
   }

  }
   printf("��%d������ץ����ɮ������˳���� ",j );
   for (k = 0;k < j;k++)
   {
   	printf("%-5d",yaonum[k]);
   }
   
   winrate=n*10;
   printf("\n����ʤ��=%d%%",winrate);
	return 0;
}
