#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	FILE * fp;
    char msg[20];//="this is a text";
    char buf[20];
    
    scanf("%s",msg);
    if ((fp = fopen("text1.txt","wt+")) == NULL)//!!!!!格式格式格式 
    {
    	printf("erro,can not open the file");
    	exit(1);
	}
	fwrite(msg,sizeof(msg),1,fp);//strlen(msg)+1 
	
	rewind(fp);
	fread(buf,sizeof(msg),1,fp);
	printf("%s",buf);
	fclose(fp);
	return 0;
}
