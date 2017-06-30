#include <stdio.h>


int main(void)
{
  int x=5;
  while(x>=0){
    if(0<x<1)
        printf("\b");
    else
        printf("%d",x);
    x--;
  }
  printf("Duang\n");
  printf("%d",1);
  printf("\b");
  printf("%d",2);

  return 0;
}
