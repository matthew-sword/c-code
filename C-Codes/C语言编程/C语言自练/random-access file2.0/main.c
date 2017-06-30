#include <stdio.h>
#include <stdlib.h>
struct clientData{
    int acctNum;
    char lastName[15];
    char firstName[10];
    double balance;
};

int main()
{
    FILE *cfPtr;
    struct clientData client={0,"","",0.0};
    if((cfPtr=fopen("credit.dat","rb+"))==NULL){
        printf("File could not be opened.\n");
    }
    else{
        printf("Enter account number""(1 to 100,0 to end input)\n?");
        scanf("%d",&client.acctNum);
        while(client.acctNum!=0){
            printf("Enter lastName,firstName,balance\n?");
            fscanf(stdin,"%s%s%lf",client.lastName,client.firstName,&client.balance);
            fseek(cfPtr,(client.acctNum-1)*sizeof(struct clientData),SEEK_SET);
            fwrite(&client,sizeof(struct clientData),1,cfPtr);
            printf("Enter account number\n?");
            scanf("%d",&client.acctNum);
        }
        fclose(cfPtr);
    }
    printf("Hello world!\n");
    return 0;
}
