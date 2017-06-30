#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct card{
       char *face;
       char *suit;
    };
    struct card aCard={"Three","Hearts"};
    struct card *cardPtr;
    cardPtr=&aCard;
    printf("%s\n",aCard.suit);
    printf("%s\n",(&aCard)->face);
    printf("%s\n",cardPtr->face);
    printf("%s\n",(*cardPtr).suit);
    return 0;
}
