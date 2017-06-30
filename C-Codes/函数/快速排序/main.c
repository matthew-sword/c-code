#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void quick_sort( int *ptr,int ,int );
 
int main(int argc, char *argv[]) 
{
	int num[100];
	int i,j;
	srand(time(0));
	
	for (i = 0;i < 20;i ++)
		num[i] = rand() % 100;
	
	for (i = 0;i < 20;i ++)
		printf("%-5d",num[i]);
		
	quick_sort(num,0,19);
	
	printf("\n");
	for (i = 0;i < 20;i ++)
		printf("%-5d",num[i]);
	return 0;
}

void quick_sort(int *ptr,int left,int right)
{
	int i,j,temp,base;
	if (left > right)
	   return;//��;�˳����� 
	i = left;
	j = right;
	base = ptr[left];
	
	while (i != j)
	{
		while (i < j && ptr[j] >= base)//���ұ�Ѱ�Ҵ���base���� 
		      j --;
		while (i < j && ptr[i] <= base)//�����Ѱ��С��base���� 
		      i ++;  
		
		if (i < j)// ���߽��� 
		{
			temp = ptr[i];
		    ptr[i] = ptr[j];
		    ptr[j] = temp;
		}	     		
	} 
	
	ptr[left] = ptr[i];//��base�����м� 
	ptr[i] = base;
	
	quick_sort(ptr,left,i-1);//�ݹ飬��ͬ 
	quick_sort(ptr,i+1,right);
}
