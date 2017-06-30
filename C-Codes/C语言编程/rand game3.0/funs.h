#ifndef FUNS_H_INCLUDED
void CreateMonks(int monkFights[],int numGame);
void CreateEvils(int evilFights[],int numGame);
void Fight(const int evilFights[],const int monkFights[],int numGame);
void SortFights(int evilFights[],int monkFights[],int numGame);
int GetLuckyEvils(const int monkFights[],int luckyEvils[],int numGame);
void GetBusyMonks(const int monkFights[],int *busyMonkID,int numGame);


#endif // FUNS_H_INCLUDED
