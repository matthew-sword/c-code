#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
  int yao,i,zhan,n=0,winrate,monk[5]={0,10,20,30};
  int yaonum[10] = {0},j = 0,k; 
  char *m_name[]={"唐僧","沙僧","八戒","悟空"}; 
  
  srand(time(0));
  for(i=0;i<10;i++)
  {
  	yao=rand()%30;      /*妖精随机战斗力*/ 
  	zhan=rand()%4;     /*和尚出场顺序*/ 
  	
  	
  	if(monk[zhan]>yao)  /*进行战斗*/ 
  	{
  		n+=1; 
  		printf("第%d局 ",i+1); 
  		printf("妖=%-5d  %s =%-5d 和尚胜\n\n",yao,m_name[zhan],monk[zhan]);
	  }
	else if(monk[zhan]==yao)
	{
		printf("第%d局 ",i+1);
		printf("妖=%-5d  %s =%-5d 平局\n\n",yao,m_name[zhan],monk[zhan]);
	}
	       
    else   
	{
		printf("第%d局 ",i+1);
		printf("妖=%-5d  %s =%-5d 妖精胜\n\n",yao,m_name[zhan],monk[zhan]);
	}
 
   if (monk[zhan] == 0)    /*优秀妖精*/  
   {
   	yaonum[j] = i + 1;
   	j++;
   }

  }
   printf("共%d个妖精抓到唐僧，出场顺序是 ",j );
   for (k = 0;k < j;k++)
   {
   	printf("%-5d",yaonum[k]);
   }
   
   winrate=n*10;
   printf("\n和尚胜率=%d%%",winrate);
	return 0;
}
