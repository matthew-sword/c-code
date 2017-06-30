#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
 {
 	void sort(char (*p)[6]);
 	int i,j;
 	char a[10][6];
 	char (*aptr)[6];
 	
 	srand(time(0));             /*随机产生字符串*/ 
 	for(i=0;i<10;i++)
 	  for(j=0;j<6;j++)
 	    a[i][j]=65+rand()%26;
 	    
 	for(i=0;i<10;i++)            /*输出字符串*/
 	{
 		for(j=0;j<6;j++)
 	  	printf("%c",a[i][j]);
 	  	printf("\n\n");
	 }
	aptr=a;                      /*aptr point to a的第一行 */
 	sort((*aptr)[6]);
 	printf("the sorted one is\n");   /*输出排序后的字符串*/
	 for(i=0;i<10;i++)
 	{
 		for(j=0;j<6;j++)
 	  	printf("%c",a[i][j]);
 	  	printf("\n\n");
	 }  
 	
	return 0;
}
void sort(char (*s)[6])
{
	int i,j;
	char temp[6]={'a'};
	char *t;
	t=temp; 
	for(i=0;i<9;i++)
 	  for(j=0;j<9-i;j++)
 	  {
 	  	if(strcmp(s[j],s[j+i])>0)
 	  	{
 	  		strcpy(t,s[j]);
 	  		strcpy(s[j],s[j+1]);
 	  		strcpy(s[j+1],t);
		   }
	   }
 } 
