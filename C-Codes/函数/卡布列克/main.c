#include <stdio.h>
#include <stdlib.h>

void sort(int a[5]);
void putin(); 
int main(int argc, char *argv[]) 
{
	int a[5];
	int i,j,ten = 1,t,cha,max = 0,min = 0;
	
	
	putin;          /*输入*/
	
	sort(a);    /*排序*/ 
	for (i = 1;i < 5;i ++) /*最大数*/
	{
		ten = 1;
		for (j = 5 - i;j > 1;j --)
		{
			ten = ten * 10;
		}
		max = max + a[i] * ten;
	}
	printf("最大数=%d\n",max);
	
	for (i = 1;i < 3;i ++)/*倒序*/ 
	{
		t = a[i];
		a[i] = a[5 - i];
		a[5 - i] = t;
	}
	
	
	for (i = 1;i < 5;i ++)/*最小数*/ 
	{
		ten = 1;
		for (j = 5 - i;j > 1;j --)
		{
			ten = ten * 10;
		}
		min = min + a[i] * ten;
    }
    printf("最小数=%d\n",min);
    
    
    cha = max - min;
    printf("差 = %d",cha);
	return 0;
}


void sort(int a[5])/*排序函数*/ 
{
	int i,j,temp;
	for (i = 1;i < 5;i ++)
	{
		for (j = 1; j <5 - i;j ++)
		{
			if(a[j] < a[j+1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp; 
			}
		}
	}
	for (i = 1;i < 5;i ++)
	{
		printf("%d",a[i]);
	}
	printf("\n"); 
}



