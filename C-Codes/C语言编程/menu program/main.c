#include <stdio.h>
#include <stdlib.h>

int main()
{   int choice,a,i;
    i=0;
    printf("Hello world!\n");
    printf("This is a menu program,please input your choice:\n");
    printf("1:choice one\n");
    printf("2:choice two\n");
    printf("3:choice three\n");
    do{
       i++;
       scanf("%d",&choice);
        if (choice>0&&choice<4) {
          printf("your choice is %d\n",choice);
          a=1;
        } else {
          a=0;
          printf("This option does not exist,please input your choice again.\n");
        }
    } while(a==0);
      printf("Running times =%d\n",i);
    return 0;
}
