#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void sort(int a[4]); 
int main(int argc, char *argv[])
{
	int a[4],x,t = 1,i,j,max = 0,min = 0,cha;
	
	printf("����");
	scanf("%d",&x);
	
	for (i = 0;i < 4;i ++)    /*����λ��*/
	{
	     t = 1;
         for (j = 4 - i;j > 1;j --)
	    {
		     t = t * 10;
       	}
       	a[i] = x/t;
       	x = x - a[i] * t;
	} 
	sort(a);/*����*/
	
	for (i = 0;i < 4;i ++) /*�����*/
	{
		t = 1;
		for (j = 4 - i;j > 1;j --)
		{
			t = t * 10;
		}
		max = max + a[i] * t;
	}
	printf("�����=%d\n",max);
	
	for (i = 0;i < 2;i ++)/*����*/ 
	{
		t = a[i];
		a[i] = a[3 - i];
		a[3 - i] = t;
	}
	
	
	for (i = 0;i < 4;i ++)/*��С��*/ 
	{
		t = 1;
		for (j = 4 - i;j > 1;j --)
		{
			t = t * 10;
		}
		min = min + a[i] * t;
    }
    printf("��С��=%d\n",min);
    
    
    cha = max - min;
    printf("�� = %d",cha);
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
