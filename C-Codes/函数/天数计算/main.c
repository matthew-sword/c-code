#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

 
int main(int argc, char *argv[]) 
{
    int loop(int);
    int nod(int,int);
	int month,day,t,d;
	int year;
	printf("put the year month day\n");
	scanf("%d %d %d",&year,&month,&day);
	if (month>12||month<1||day<1||day>31)
	  printf("error");
	t=loop(year);
	if(t==0)  d=nod(month,day);
	else if (month>2)
	      d=nod(month,day)+1;
	else  d=nod(month,day); 	
	printf("it is the %d day of this year",d);
	return 0;
}

int loop(int y)
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


int nod(int x,int y)
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
