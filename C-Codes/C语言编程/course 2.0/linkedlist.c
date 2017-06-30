#include "linkedlist.h"

void displayAllCourse(Node *head)
{
  if(head == NULL){
    printf("This course empty.\n");
    return;
  }

  else{
    Node* pNode;
    printf("%-5s%-7s%-5s%-5s%13s\n","ID","Month","Day","Seq","Name");
    for(pNode = head;pNode != NULL;pNode = pNode->nextPtr){
        printf("%-5d%-7d%-5d%-5d%13s\n",pNode->ID,pNode->Month,pNode->Day,pNode->Seq,pNode->Name);
    }//end for

  }//end else

  return;
}

void displayOneCourse(Node* head,int id)
{
  if(head == NULL){
        printf("This course empty.\n");
        return;
  }

  else{
        Node* pNode;
        int isFind=0;
        printf("%-5s%-7s%-5s%-5s%13s\n","ID","Month","Day","Seq","Name");
        for(pNode = head;pNode != NULL;pNode = pNode->nextPtr){
              if(pNode->ID == id){
                printf("%-5d%-7d%-5d%-5d%13s\n",pNode->ID,pNode->Month,pNode->Day,pNode->Seq,pNode->Name);
                isFind = 1;
              }
        }
        if(isFind == 0){
            printf("The input number is not found.\n");
        }
        return;
      }
}


Node* updateCourse(Node* head)
{
    if(head == NULL){
        printf("The linked list is empty.\n");
        return head;
    }

    Node* temp;
    int number;
    printf("Please enter the number to update(1-100):");
    scanf("%d",&number);
    if ( number == head->ID )
    {
        displayOneCourse(head,number);
        temp = head;
        head = head->nextPtr;
        free(temp);
        printf("The input number is found and deleted. \n");
        head = insertCourse(head);
        return head;
    }

    int isFound = 0;
    Node* previous;
    Node* current;
    for ( previous = NULL, current = head ;
          current != NULL ;
          previous = current, current = current->nextPtr )
    {
        if ( number == current->ID )
        {
            displayOneCourse(head,number);
            previous->nextPtr = current->nextPtr;
            free(current);
            isFound = 1;
            break;
        }
    }
    if ( isFound )
    {
        printf("The input number is found and deleted. \n");
        head = insertCourse(head);
    }
    else
    {
        printf("The input number is not found. \n");
    }

    return head;
}


Node* insertCourse(Node *head)
{
    Node *newNode ;
    newNode = malloc(sizeof(Node));
    newNode->Month = checkMonth();
    newNode->Day = checkDay(newNode->Month);
    newNode->Seq = checkSeq();
    printf("Please enter the new course name.\n");
    scanf("%s",newNode->Name);
    newNode->Number = getDaySeqofYear(newNode->Month,newNode->Day);
    newNode->ID = 0;
    newNode->nextPtr = NULL;
    if ( head == NULL )
    {
        // if the linked list is empty
        head = newNode;
    }
    else if ( newNode->Number < head->Number )
    {
        // insert before the head
        newNode->nextPtr = head;
        head = newNode;
    }
     else
    {
        int isFound = 0;
        Node *previous;
        Node *current;

        // insert within the linked list
        for ( previous = NULL, current = head ;
              current != NULL ;
              previous = current, current = current->nextPtr )
        {
            // to find the position to insert
            if ( newNode->Number < current->Number )
            {
                // insert the node between the two
                previous->nextPtr = newNode;
                newNode->nextPtr = current;
                isFound = 1;
                break;
            }
            else if( newNode->Number == current->Number && newNode->Seq < current->Seq){
                previous->nextPtr = newNode;
                newNode->nextPtr = current;
                isFound = 1;
                break;
            }
        }
        if ( !isFound )
        {
            // insert into the last node
            previous->nextPtr = newNode;
        }
    }
    displayOneCourse(head,newNode->ID);
    return head;
}

Node* deleteCourse(Node* head)
{
   if ( head == NULL )
    {
        printf("The linked list is empty.\n");
        return NULL;
    }

    Node *temp;
    int number;
    printf("Please enter the number to delete(1-100):");
    scanf("%d",&number);

    if ( number == head->ID )
    {
        temp = head;
        head = head->nextPtr;
        free(temp);
        printf("The input number is found and deleted. \n");
        return head;
    }

    int isFound = 0;
    Node* previous;
    Node* current;
    for ( previous = NULL, current = head ;
          current != NULL ;
          previous = current, current = current->nextPtr )
    {
        if ( number == current->ID ){
            previous->nextPtr = current->nextPtr;
            free(current);
            isFound = 1;
            break;
        }
    }

    if ( isFound ){
        printf("The input number is found and deleted. \n");
    }
    else{
        printf("The input number is not found. \n");
    }

    return head;
}


Node* sortID(Node* head)
{
    Node* pNode;
    int i=1;
    for(pNode = head;pNode != NULL;pNode = pNode->nextPtr){
        pNode->ID = i;
        i++;
    }
    return head;
}


void destroyCourse(Node* head)
{
    Node* pNode;
    Node* hold;
    pNode = head;
    while(pNode != NULL){
         hold = pNode;
         pNode = pNode->nextPtr;
         free(hold);
    }
   free(head);
   printf("The linked list has destroyed successfully.\n");
}


Node* arrangeByDate(Node* head)
{
   return head;
}

void referByDate(Node* head)
{
   printf("Please enter the date that you want to refer.\n");
   int month,day,number;
   month = checkMonth();
   day = checkDay(month);
   number = getDaySeqofYear(month,day);
   Node* pNode;
   int isFind = 0;
   for(pNode = head;pNode != NULL;pNode = pNode->nextPtr){
        if(pNode->Number == number){
           printf("%-5s%-7s%-5s%-5s%13s\n","ID","Month","Day","Seq","Name");
           printf("%-5d%-7d%-5d%-5d%13s\n",pNode->ID,pNode->Month,pNode->Day,pNode->Seq,pNode->Name);
           isFind = 1;
        }
   }
   if(isFind == 0){
       printf("The input date is not found. \n");
   }

}
