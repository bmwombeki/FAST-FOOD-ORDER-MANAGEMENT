#include "Queue.h"


// Displaying debug information
void debugDisplay(node * head){
    printf( " Person Name: \"%s\"\n Number of burgers: %d \n Number of salads: %d /n \n", head->name,head->numberBurgers, head->numberSalads);
}


int debugCheck(int argc, char **argv){
    int i;                                 // check if debug mode flag is given
    for(i = 0; i < argc; ++i)  if(strcmp(argv[i], "-d") == 0)  return TRUE;
    return FALSE;
}


// checking to see if the name is already in the list(queue)
boolean doesNameExist(node *head, char* name, int debugMode){
    /*if(head == NULL){
        return FALSE;
    }*/
        while(head!= NULL){ // go through the linked list to check if the name exists
            if(debugMode){
                debugDisplay(head); // if the debug mode is on, debug information is displayed
            }
            
            if(strcmp(head->name, name) == 0){ // check if the names are the same
                return TRUE;
            }
            head = head->next;
        } // end of while loop
    return FALSE;
} // end of doesNameExist()


//This function adds a new node to the end of the list
void addToList(node** pHead, char*name,int burgers,int salad, boolean status, int debugMode ) {
    struct node*pCurrent = *pHead;
    struct node*prev = NULL;
    
    if(debugMode) {
     printf("\n");
        if(*pHead == NULL){ // check if the list is empty
            printf(" List is empty \n");
        }
    }
    
    while(pCurrent!= NULL) { // go through the list
        if(doesNameExist(pCurrent, name, debugMode) == TRUE) { // check if the name already exist
            printf("\n Error: name \"%s\" is already in the List\n", name);
            return;
        } // end of if
        prev = pCurrent;
        pCurrent = pCurrent->next;
    } // end of while loop
    
    node*pTemp = (node*)malloc(sizeof(node)); // create a new node and store data
    pTemp->numberBurgers = burgers;
    pTemp->numberSalads = salad;
    pTemp->inRestaurant = status;
    strcpy(pTemp->name,name);
    pTemp->next = NULL;
    
    if(prev == NULL){ // if list is empty, pTemp becomes a new head
        *pHead = pTemp;
    }
    
    else {
        prev->next = pTemp;
    }
    
     
} // addToList()......


//updating the restaurant status function
boolean updateStatus(node* head, char* name, int debugMode){
    
    if(debugMode){ // checking if debug mode is on
        printf("\n");
    }
    
    while(head!= NULL)
    {
        if(strcmp(head->name, name) == 0){   // check if the order exist
            if( head->inRestaurant == FALSE) {    // check the status of the order in the list
                return FALSE;                      // if it is already in the list false is returned
            }
            
            else {
                head->inRestaurant = FALSE;  // if the order is not in the list, the status is updated
                return TRUE;
            }
            
        } // end of if (doesNameExist)....
        head = head->next;
    } // end of while loop
    return FALSE;
} // end of updateStatus()......


// function to retrieve and remove the order that has been prepared
char *retrieveAndRemove (node** head, int  burgers, int salads, int debugMode)
{
    node* pCurrent = *head; // pCurrent is equal to head
    node* prev = NULL;
    
    if (pCurrent == NULL){ // checking if the list is empty
        printf("List is empty\n");
    }
    
    // traversing though a list until the first order that matches the order to be removed is found
    while((pCurrent!= NULL) && (pCurrent->numberBurgers > burgers) && (pCurrent->numberSalads > salads)){
        prev = pCurrent;
        pCurrent = pCurrent->next;
    } // end of while loop
    
    char* orderName = NULL;
    //if prev is NULL that means the first order in the list matches the order to be removed
    if(prev == NULL) {
        orderName = pCurrent->name;
        node*temp = pCurrent;
        *head = temp->next;
        free(temp);
        return orderName;
    }
    
    /* if prev is not equal to NULL,the order to be removed is in the middle or at the
    end of the list. The order is then removed if it is in the list*/
     
    else {
        orderName = pCurrent->name;
        prev->next = pCurrent->next;
        free(pCurrent);
         return orderName;
    }
    
} // end of retrieveAndRemove


// counting the numbers of orders ahead
int countOrdersAhead(node* head, char *name)
{
    if(name == NULL) {
        printf("Name does not exisit");
    }
    
    int count = 0;
    while(head != NULL){  // traverse the list and count the orders that are ahead of a certain name
        if(strcmp(head->name,name) == 0){ // when the name is found, the loop is exited
            break;
        }
        count++;
        head = head->next;
    }
    return count;
} // end of countOrdersAhead()


// Displaying orders ahead of a certain name
void displayOrdersAhead (node* head, char* name, int debugMode )
{
    if (debugMode) {
        printf("\n");
    }
    
    // display debug information if debug is on
    if(debugMode) {
        debugDisplay(head);
    }
    // traverse through the list
    while(head != NULL){
        // show the order
        printf("The number of burgers: %d , The number of salads: %d \n", head->numberBurgers, head->numberSalads);
        if(strcmp(head->name, name) == 0){
            break;
        }
        head = head->next;
    } // end of while loop
} // end of displayOrdersAhead ()....


// Displaying all the order information in a list
void displayListInformation (node* head){
    
    while(head!= NULL){ // traverse through the list
        printf("The Name is, %s\n",head->name); // print name
        printf("\n");
        printf("Number of burgers, %d \n", head->numberBurgers); // print number of burgers
        printf("\n");
        printf("Number of salads, %d \n", head->numberSalads); // print number of salads
        printf("\n");
        if(head->inRestaurant == TRUE) { // check the order's status
            printf("order is a call ahead order\n");
        }
        
        else {
            printf("Order is waiting in the restaurant \n");
        }
          printf("\n");
        head = head->next;
    } // end of while loop
    
} // end of displayListInformation ()....


//Displaying the wait time
int displayWaitingTime(node* hd, char *name) {
    int waitingTime = 0;  // waiting time is initialized to zero
     if(name == NULL){
         printf("Name does not exist");
     }
    while(hd!= NULL){
        
        if(strcmp(hd->name,name) == 0){  // when the name is found, the loop is exited
            break;
        }
        waitingTime = waitingTime + 10*(hd->numberBurgers) + 5*(hd->numberSalads); // updating waiting time
        hd = hd->next;
    } // end of while loop
    return waitingTime;
} // end displayWaitingTime()....
