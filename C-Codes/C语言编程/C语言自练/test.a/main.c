#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *nextPtr;
};
typedef struct node Node;

int main()
{
    Node *n[10];
    int i;
    for(i=0;i<10;i++){
        n[i]=malloc(sizeof(Node));
    }
    for(i=0;i<9;i++){
        n[i]->value=10+i;
        n[i]->nextPtr=n[i+1];
    }
    n[9]->value=19;
    n[9]->nextPtr=NULL;
    Node *Ptr;
    printf("This is a linked list.\n");
    for(Ptr=n[0];Ptr!=NULL;Ptr=Ptr->nextPtr){
        printf("%4d",Ptr->value);
    }
    printf("\n");
    for(i=0;i<10;i++){
        free(n[i]);
    }
    printf("Hello world!\n");
    return 0;
}
