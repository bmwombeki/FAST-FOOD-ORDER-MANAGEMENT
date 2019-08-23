#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define false = 0;
#define true = 1;

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

typedef struct node{
    char name[30];
    int numberBurgers;
    int numberSalads;
    boolean inRestaurant;
    struct node* next;
}node;

// first

int main (int argc, char **argv);
int getNextNWSChar();
int getPosInt ();
char *getName();
void printCommands();
void clearToEoln();

// second
void doAdd (node**head, int debugMode);
void doCallAhead (node** head, int debugMode);
void doWaiting (node**head, int debugMode);
void doRetrieve (node** hd, int debug);
void doList (node*hd, int debugMode);
void doDisplay (node*head);


// third
void debugDisplay(node * head);
int debugCheck(int argc, char **argv);
boolean doesNameExist(node *head, char* name, int debugMode);
void addToList(node** pHead, char*name,int burgers,int salad, boolean status, int debugMode);
boolean updateStatus(node* head, char* name, int debugMode);
char *retrieveAndRemove (node** head, int  burgers, int salads, int debugMode);
int countOrdersAhead(node* head, char *name);
void displayOrdersAhead(node* head, char* name, int debugMode);
void displayListInformation(node* head);
int displayWaitingTime(node* hd, char *name);
