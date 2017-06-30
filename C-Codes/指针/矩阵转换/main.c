#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	void change(int *);
	int a[5][5],i,j,*aptr;
	srand(time(0));
	for(i=0;i<5;i++)
	  for(j=0;j<5;j++)
	    a[i][j]=rand()%99+1;
	    for(i=0;i<5;i++)
	    {
	      for(j=0;j<5;j++)
	        printf("%-4d",a[i][j]);
	      printf("\n\n");
		}
    aptr=a;                      /*aptr=a和aptr=&a[0][0]等价*/
    change(aptr);
    printf("转换后\n");
    for(i=0;i<5;i++)
	    {
	      for(j=0;j<5;j++)
	        printf("%-4d",a[i][j]);
	      printf("\n\n");
		}
	return 0;
}
void change(int *p)
{
  int i,j,temp;
  int *pmax,*pmin;
  pmax=p;
  pmin=p;
  for(i=0;i<5;i++)
	  for(j=0;j<5;j++)
	  {
	  	if(*pmax<*(p+5*i+j))  pmax=p+5*i+j;
	  	if(*pmin>*(p+5*i+j))  pmin=p+5*i+j;
		  }	
    temp=*(p+12);
    *(p+12)=*(pmax);
    *(pmax)=temp;
    
    temp=*(p);
    *(p)=*(pmax);
    *(p)=temp;
    pmin=p+1;
    for(i=0;i<5;i++)
	  for(j=0;j<5;j++)
	  {
	  	if(((p+5*i+j)!=p)&&(*pmin>*(p+5*i+j))) 
	  	  temp=*(pmin);
          *(pmin)=*(p+4);
          *(p+4)=temp;
	  }
}
