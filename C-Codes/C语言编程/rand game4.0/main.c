#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int numEvils = 5; 
const int numGame = 7;

void generateScores(int (* const) [numEvils]);//随机产生妖精各局得票
void getRanking(const int * const, int * const);//根据妖精各局得票得出各局排名
void getTotalScores(const int (* const) [numEvils], int * const);
void displayResults(const int (* const) [numEvils]);
void displayFinalResults(const int * const, const int * const);

int main()
{
    int scores[numGame][numEvils],ranks[numGame][numEvils];
    int totalScores[numEvils],finalRanks[numEvils];
    int i;
    printf("%d局比赛结果为:\n",numGame);
    printf("场次:  牛魔王   白骨精   红孩儿   黄袍怪   黑风怪\n");
    generateScores(scores);
    displayResults(scores);

    printf("%d局比赛排名分别为:\n",numGame);
    printf("场次:  牛魔王   白骨精   红孩儿   黄袍怪   黑风怪\n");
    for(i=0;i<numGame;i++){
        getRanking(scores[i],ranks[i]);
    }
    displayResults(ranks);

    printf("比赛最终结果为:\n");
    printf("       牛魔王   白骨精   红孩儿   黄袍怪   黑风怪\n");
    getTotalScores(scores,totalScores);
    getRanking(totalScores,finalRanks);
    displayFinalResults(totalScores,finalRanks);
    return 0;
}

void generateScores(int(*const ptr)[numEvils])
{
    int i,j,k;
    srand(time(NULL));
    for(i=0;i<numGame;i++){
        for(j=0;j<numEvils;j++){
            ptr[i][j]=0;
        }
    }
    for(i=0;i<numGame;i++){
        for(k=0;k<100;k++){
            j=rand()%numEvils;
            ptr[i][j]++;
        }
    }
}

void displayResults(const int(*const ptr)[numEvils])
{
    int i,j;
    for(i=0;i<numGame;i++){
        printf("%d:",i+1);
        for(j=0;j<numEvils;j++){
            printf("%9d",ptr[i][j]);
        }
        printf("\n");
    }
}

void getRanking(const int*const ptr1,int*const ptr2)
{
   int i,j;
   int sort,max;
   int copyPtr1[numEvils];
   for(i=0;i<numEvils;i++){
      copyPtr1[i]=ptr1[i]+1;
   }
   for(i=0;i<numEvils;i++){
      max=copyPtr1[0];
      sort=0;
      for(j=0;j<numEvils;j++){
         if(copyPtr1[j]>max){
            max=copyPtr1[j];
            sort=j;
         }
      }
      ptr2[sort]=i+1;
      copyPtr1[sort]=0;
   }
}

void getTotalScores(const int(*const ptr1)[numEvils],int*const ptr2)
{
   int i,j;
   for(i=0;i<numEvils;i++){
       ptr2[i]=0;
   }
   for(i=0;i<numEvils;i++){
       for(j=0;j<numGame;j++){
           ptr2[i]=ptr1[j][i]+ptr2[i];
       }
   }
}

void displayFinalResults(const int*const ptr1,const int*const ptr2)
{
   int i;
   printf("总分:");
   for(i=0;i<numEvils;i++){
       printf("%9d",ptr1[i]);
   }
   printf("\n排名:");
   for(i=0;i<numEvils;i++){
       printf("%9d",ptr2[i]);
   }
}


