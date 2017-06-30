#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	char word[100],put[100];
	char word1[100],put1[100];
	int i = 0,t;
	FILE * fp,* fp1;
	
	printf("please put in p 1\n");
	while(i < 100)
	{
		scanf("%c",&t);
        if (t != '\n')
          word[i] = t;
        else    
          break;
		i ++;
	}
	 
	if ((fp = fopen("readme.txt","wt+")) == NULL)
	   printf("can not open the file\n");
	fwrite(word,sizeof(word),1,fp);
	rewind(fp);
	fread(put,sizeof(word),1,fp);
	fclose(fp);
	printf("\n%s",put);
	
/*	printf("please put in p 2\n");
	for (i = 0;i < 100;i ++)
	{
		scanf("%c",&t);
		if (t == '\n')
		   break;
		else
		  word1[i] = t;
	 } 
	 
	 if ((fp1 = fopen("word2.txt","wt+")) == NULL)
	     printf("can not open the file");
     fprintf(fp1,"%s",word1);
     rewind(fp1);
     fscanf(fp1,"%s",put1);
     printf("\n%s",put1);*/
	return 0;
}
