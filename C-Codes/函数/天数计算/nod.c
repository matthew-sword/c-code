

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
extern int nod(int x,int y)
{
  int n,t;
  t=x-1;
  if(t==2)
    n=30*t+y-1;
  else if(t==3||t==4) 
    n=30*t+y;
  else if(t==1||t==5||t==6)
    n=30*t+y+1;
  else if(t==7)
    n=30*t+y+2;
  else if(t==8||t==9)
    n=30*t+y+3;
  else if(t==10||t==11)
    n=30*t+y+4;
  else if(t==0)
    n=y;
  return(n);
}
