#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	FILE * fp;
	char me[50],metoo[50];
	int i;
	
	if ((fp = fopen("me.txt","wt+")) == NULL)//w+ wt+
	    printf("can not open this file");
	    
	printf("please put in words\n");
	scanf("%s",me);
	
	fprintf(fp,"%s",me);
	//fclose(fp);
	
	//if ((fp = fopen("me.txt","rt+")) == NULL)//w+ wt+
	    //printf("can not open this file");
	    
	rewind(fp);
	fscanf(fp,"%s",metoo);
	
	printf("%s",metoo);
	fclose(fp);
	return 0;
}
