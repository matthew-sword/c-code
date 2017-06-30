#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
 {
 	int s=1;
 	float pi=0,n=1,t=1;
 	while(fabs(t)>1e-6)
 	{
 		pi=pi+t;
 		n=n+2;
 		s=-s;
 		t=s/n;
	 }
	pi=pi*4; 
	printf("pi=%f\n",pi); 
	return 0;
}
