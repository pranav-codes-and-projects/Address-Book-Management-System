#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fptr;
    fptr = fopen("contacts.txt","w"); //open the contacts.txt file
    if(fptr == NULL)  //if the file pointer is null then no need of further execution it is false
    {
        printf("File not found\n");
        return;
    }
    fprintf(fptr,"#%d\n",addressBook->contactCount); // Print number of contacts in contacts.txt
    for( int i = 0; i< addressBook->contactCount;i++)
    {
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fptr); //Close the fptr after the work is done
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fptr;
    fptr = fopen("contacts.txt", "r"); //open the contacts.txt file
    if(fptr == NULL) //if the file pointer is null then no need of further execution it is false
    {
        return;
    }
    fscanf(fptr, "#%d\n", &addressBook->contactCount); // Read number of contacts 
    for(int i = 0; i < addressBook->contactCount; i++) // Read all contacts 
    {
        fscanf(fptr,"%49[^,],%19[^,],%49[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fptr); //Close the fptr after the work is done.
}
