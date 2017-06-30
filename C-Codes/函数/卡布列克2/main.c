#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void sort(int a[4]); 
int main(int argc, char *argv[])
{
	int a[4],x,t = 1,i,j,max = 0,min = 0,cha;
	
	printf("输入");
	scanf("%d",&x);
	
	for (i = 0;i < 4;i ++)    /*分离位数*/
	{
	     t = 1;
         for (j = 4 - i;j > 1;j --)
	    {
		     t = t * 10;
       	}
       	a[i] = x/t;
       	x = x - a[i] * t;
	} 
	sort(a);/*排序*/
	
	for (i = 0;i < 4;i ++) /*最大数*/
	{
		t = 1;
		for (j = 4 - i;j > 1;j --)
		{
			t = t * 10;
		}
		max = max + a[i] * t;
	}
	printf("最大数=%d\n",max);
	
	for (i = 0;i < 2;i ++)/*倒序*/ 
	{
		t = a[i];
		a[i] = a[3 - i];
		a[3 - i] = t;
	}
	
	
	for (i = 0;i < 4;i ++)/*最小数*/ 
	{
		t = 1;
		for (j = 4 - i;j > 1;j --)
		{
			t = t * 10;
		}
		min = min + a[i] * t;
    }
    printf("最小数=%d\n",min);
    
    
    cha = max - min;
    printf("差 = %d",cha);
	return 0;
}


void sort(int a[4])
{
	int i,j,temp;
	for (i = 0;i < 4;i ++)
	{
		for (j = 0; j < 4 - i;j ++)
		{
			if(a[j] < a[j+1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp; 
			}
		}
	}
	for (i = 0;i < 4;i ++)
	{
		printf("%d ",a[i]);
	}
	printf("\n"); 
}
