#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	char s1[100],s2[100];
	int i,l1,l2,t,p=0;
	gets(s1);
	gets(s2);
	l1=strlen(s1);
	l2=strlen(s2);
	if(l1>l2) 
	  t=l2;
	else
	  t=l1;
    for(i=0;i<t;i++)
    {
    	if(s1[i]==s2[i])  
		  continue;
    	else if(s1[i]>s2[i])
    	  {
    	    p=s1[i]-s2[i];
    	    break;
		  }
		else
		{
		  p=s1[i]-s2[i];
		  break; 	
		}  
	}
	printf("%d",p);
	return 0;
}
