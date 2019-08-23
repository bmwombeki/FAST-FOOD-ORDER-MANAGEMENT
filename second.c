#include "Queue.h"

// Adding in restaurant order to the list
void doAdd (node**head, int debugMode)
{
    /* get number of burgers ordered from input */
    int NumBurgers = getPosInt();
    if (NumBurgers < 0)
    {
        printf ("Error: Add command requires an integer value of at least 0\n");
        printf ("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    
    /* get number of salads ordered from input */
    int NumSalads = getPosInt();
    if (NumSalads < 0)
    {
        printf ("Error: Add command requires an integer value of at least 0\n");
        printf ("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    
    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Add command requires a name to be given\n");
        printf ("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    
    printf ("Adding In-restaurant order for \"%s\": %d burgers and %d salads\n", name,NumBurgers ,NumSalads);
    
    // add code to perform this operation here
    addToList( head, name,NumBurgers,NumSalads , FALSE, debugMode);
} // end of doAdd().....



// Adding a call ahead order to the list in a restaurant
void doCallAhead (node** head, int debugMode)
{
    /* get number of burgers ordered from input */
    int NumBurgers = getPosInt();
    if (NumBurgers < 0)
    {
        printf ("Error: Call-ahead command requires an integer value of at least 0\n");
        printf ("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    
    /* get number of salads ordered from input */
    int NumSalads = getPosInt();
    if (NumSalads < 0)
    {
        printf ("Error: Call-ahead command requires an integer value of at least 0\n");
        printf ("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    
    
    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Call-ahead command requires a name to be given\n");
        printf ("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    
    printf ("Adding Call-ahead order for \"%s\": %d burgers and %d salads\n", name,NumBurgers ,NumSalads);
    
    // add code to perform this operation here
    addToList( head, name,NumBurgers,NumSalads ,TRUE, debugMode);

} // end of doCallAhead().....



void doWaiting (node** head, int debugMode)
{
    /* get order name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Waiting command requires a name to be given\n");
        printf ("Waiting command is of form: w <name>\n");
        printf ("  where: <name> is the name of the group that is now waiting\n");
        return;
    }
    
    if(debugMode)
    {
        if(head == NULL) {
         printf("\n list is empty ");
        }
        
    }
    printf ("Call-ahead order \"%s\" is now waiting in the restaurant\n", name);
    
   //updating the status of a call ahead order
   updateStatus(*head,name, debugMode);
} //end  doWaiting()....


// Removing an order from the list function
void doRetrieve (node** hd, int debug)
{
    /* get info of prepared food ready on the counter from input */
    int PreparedBurgers = getPosInt();
    if (PreparedBurgers < 0)
    {
        printf ("Error: Retrieve command requires an integer value of at least 0\n");
        printf ("Retrieve command is of form: r <# burgers> <# salads>\n");
        printf ("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
        printf ("         <# saladss> is the number of salads waiting on the counter for pick up\n");
        return;
    }
    
    int PreparedSalads = getPosInt();
    if (PreparedSalads < 0)
    {
        printf ("Error: Retrieve command requires an integer value of at least 0\n");
        printf ("Retrieve command is of form: r <# burgers> <# salads>\n");
        printf ("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
        printf ("         <# saladss> is the number of salads waiting on the counter for pick up\n");
        return;
    }
    
    clearToEoln();
    printf ("Retrieve (and remove) the first group that can pick up the order of %d burgers and %d salads\n", PreparedBurgers ,PreparedSalads);
    
    // add code to perform this operation here
    printf("The name removed is %s\n", retrieveAndRemove(hd, PreparedBurgers, PreparedSalads, debug));
} // end of doRetrieve()......



// Displaying a number of orders ahead of a given name
void doList (node*hd, int debugMode)
{
    /* get order name from input */
    char *name = getName();
    int numberAhead;
    if (NULL == name)
    {
        printf ("Error: List command requires a name to be given\n");
        printf ("List command is of form: l <name>\n");
        printf ("  where: <name> is the name of the order to inquire about\n");
        return;
    }
    
    printf ("Order for \"%s\" is behind the following orders\n", name);
    
    // add code to perform this operation here
    if(doesNameExist(hd,name, debugMode)){
        numberAhead = countOrdersAhead(hd,name);
        printf("Number of orders ahead are %d\n", numberAhead);
    }
} // end of doList().....



// Displaying order informations
void doDisplay (node*head)
{
    clearToEoln();
    printf ("Display information about all orders\n");
    
    // add code to perform this operation here
    displayListInformation(head);
} // end of doDisplay()....


// Displaying estimated waiting time
void doEstimateTime(node*hd, int debugMode)
{
    /* get order name from input */
    int waitTime;
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: List command requires a name to be given\n");
        printf ("List command is of form: t <name>\n");
        printf ("  where: <name> is the name of the order to inquire about\n");
        return;
    }
    
    // displaying waiting time in minites
    if(doesNameExist(hd,name, debugMode)){
       waitTime =  displayWaitingTime(hd,name);
        printf("Estimated waiting time is  %d minites\n",  waitTime);
    }
   
} // end doEstimateTime()....


