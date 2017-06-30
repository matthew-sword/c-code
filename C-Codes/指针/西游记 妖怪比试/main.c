#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int Evil = 5;
const int Game = 7;

void single_score(int (* const) [Evil]);//每轮比分
void rank(const int * const,int * const);//单次排名，const？
void get_total_score(const int (* const)[Evil],int * const);//单个人总分
void dis_result(const ( * const)[Evil]);
void dis_f_result(const int * const,const int * const); 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int score[Game][Evil],ranking[Game][Evil];
	int total_score[Evil],total_rank[Evil];
	int i;
	printf("各局比赛结果如下\n");
	printf("局次   牛魔王    白骨精   红孩儿   黄风怪  黑熊怪\n");
	single_score(score);//参数不用写数组？ 
	dis_result(score);
	
	printf("各局比赛排名如下\n");
	printf("局次   牛魔王    白骨精   红孩儿   黄风怪   黑熊怪\n");
	for (i = 0;i < Game;i ++)
	{
		rank(score[i],ranking[i]);	
	} 
	dis_result(ranking);
	
	printf("比赛最终结果为:\n");
    printf("       牛魔王   白骨精  红孩儿  黄袍怪  黑风怪\n");
	get_total_score(score,total_score);
	rank(total_score,total_rank);
    dis_f_result(total_score,total_rank);
	return 0;
}

void single_score(int (* const ptr) [Evil])
{
	int i,j,k;
	srand(time(0));
	for (i = 0;i < Game;i ++)
	{
		for (j = 0;j < Evil;j ++)
		{
			ptr[i][j] = 0;//?！！！ 
		}
	}
	
	for (i = 0; i < Game;i ++)
	{
			for (k = 0;k < 100;k ++)
			{
				j = rand()%Evil;
				ptr[i][j]++;
			}
	}
}

void dis_result(const int(*const ptr)[Evil])
{
	int i,j;
	for (i = 0;i < Game;i ++)
	{
		printf("%d",i+1);
		for (j = 0;j < Evil;j ++)
		{
			printf("%9d",ptr[i][j]);
		}
		printf("\n");
	}
}

void rank(const int * const ptr1,int * const ptr2)
{
	int i,j;
	int max,sort;
	int copy_ptr1[Evil];
	
	for (i = 0;i < Evil;i ++)
	{
		copy_ptr1[i] = ptr1[i] + 1;
	}
	
	for (i = 0;i < Evil;i ++)
	{
		max = copy_ptr1[0];
		sort = 0;
		for (j = 0;j < Evil;j ++)
		{
			if (copy_ptr1[j] > max)
			{
				max = ptr1[j];
				sort = j;
			}
		}
		ptr2[sort] = i + 1;//!!!
		copy_ptr1[sort] = 0;
	}
}

void get_total_score(const int(*const ptr1)[Evil],int*const ptr2)
{
	int i,j;
	for (i = 0;i < Evil;i ++)
	    ptr2[i] = 0;
	
	for (i = 0;i < Evil;i ++)
	{
		for (j = 0;j < Game;j ++)
		{
			ptr2[i] = ptr2[i] + ptr1[i][j];
		}
	}    
}

void dis_f_result(const int*const ptr1,const int*const ptr2)
{
	int i;
	printf("总分"); 
	for (i = 0;i < Evil;i ++)
	{
		printf("%9d",ptr1[i]);
	}
	printf("\n");
	printf("排名");
	for (i = 0;i < Evil;i ++)
	{
		printf("%9d",ptr2[i]);
	}
}
