#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct course
{
	char name[15];
	char teacher[15];
	char place[20];  //全英文 
	int order[4];
	int week[19];
	int weekday[7];
} Strcou;
int doy(int x,int y,int z);//天数计算 day of the year 

void by_time(char * filename)//没有参数？ 
{
	int i,j,k,year,month,day,now,fstw,dif,week,wkd;
	int fy = 2016,fm = 8,fd =29 ;//第一周时间，以后可修改 
	FILE* fptr;
	Strcou course[8]; 
	 
	printf("请输入时间（如2016 9 25）\n");
	scanf("%d %d %d",&year,&month,&day);
	
	now = doy(year,month,day);
	fstw = doy(fy,fm,fd);
	dif = now - fstw;
	week = dif / 7;
	wkd = dif % 7 + 1;//next 读入数据 
	
	fptr = fopen(filename,"r");
	for (i = 0;i < 8;i ++)
	{
		fscanf(fptr,"%s\t%s\t%s\t",course[i].name,course[i].teacher,course[i].place);
		fscanf(fptr,"   ");
		for (j = 0;j < 4;j ++)
		
		{
			fscanf(fptr,"%d ",course[i].order[j]);
		}
		 fscanf(fptr,"   ");
		for (j = 0;j < 14;j ++)//改 
		{
			fscanf(fptr,"%d ",course[i].week[j]);
		}
		fscanf(fptr,"   "); 
		for (j = 0;j < 3;j ++)//改 
		{
			fscanf(fptr,"%d ",course[i].weekday[j]);
		}
    }
	for (i = 0;i < 8;i ++)
	{
		for (j = 0;j < 19;j ++)
		{
			if (course[i].week[j] == week)
			{
				for (k = 0;k < 7;k ++)
				{
					if (course[i].weekday[k] == wkd)
					{
						printf("%s%s%s",course[i].name,course[i].teacher,course[i].place);
					}
				}
			}
		}
	}
	fclose(fptr);
}

int doy(int x,int y,int z)
{
	int mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int leap,n = 0,i;
	
	if(x%4==0&&x%100!=0)//闰年判断 
	  leap = 1;
	else if(x%400==0)
	 leap = 1;
	else
	  leap = 0;
	
	for (i = 0;i < y - 1;i ++)
	{
		n += mon[i];
	}
	
	if (leap == 1 && y > 2)
	   n = n + z + 1;
	else
	   n = n + z;
	return (n);	
}
