#include <stdio.h>
#include <stdlib.h>
#include"funs.h"



void welcome(void)
{
   printf("***Welcome to Simpletron!***\n");
   printf("***Please enter your program one instruction***\n");
   printf("***(or data word) at a time. I will type the***\n");
   printf("***location number and a question mark(?).  ***\n");
   printf("***You then type the word for that location.***\n");
   printf("***Type the sentinel -99999 to stop entering***\n");
   printf("***your program.***\n");
   return;
}

void program(int Array[])
{
   int i,j;
   int hold,True=0;
   for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            while(True==0){
                printf("%d%d ?",i,j);
                scanf("%d",&hold);
                if(hold==-99999){
                    True=1;
                }
                else{
                    True=matching(hold);
                    if(True==0){
                        printf("Error:wrong input.\n");
                        printf("Please enter the number again.\n");
                    }//end if
                }//end else
            }//end while
            if(hold!=(-99999)){
                Array[10*i+j]=hold;
                True=0;
                }
            else{
                break;
                }
        }//end for
        if(hold==-99999){
            break;
        }//end if
   }//end for
   printf("***Program loading completed***\n");
   printf("***Program execution begins ***\n");
   return;
}


int matching(int x)
{
   int m;
   m=(x-x%100)/100;
   if(m==10||m==11){
      return 1;
   }
   else if(m==20||m==21){
      return 1;
   }
   else if(m==30||m==31||m==32||m==33){
      return 1;
   }
   else if(m==40||m==41||m==42||m==43){
      return 1;
   }
   else{
      return 0;
   }
}


void operation(int x,int y,int Array[])
{
   int a;
   switch(x){
      case 10:
         printf("Please enter a number:");
         scanf("%d",&Array[y]);
         break;
      case 11:
         printf("print the number:%d\n",Array[y]);
         break;
      case 20:
        a=Array[y];
        break;
      case 21:
        Array=a;
        break;
      case 30:
        a=a+Array[y];
        break;
      case 31:
        a=a-Array[y];
        break;
      case 32:
        if(Array[y]==0){
            printf("Error attempt to divide by zero.\n");
        }
        else{
            a=a/Array[y];
        }
        break;
      case 33:
        a=a*Array[y];
        break;
      case 40:

   }

}


