#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    switch (sortCriteria)
    {
    case 1 : printf("Sorting by name : \n");
    for(int i = 0; i<addressBook->contactCount-1; i++)            //Sorting the names by using bubble sort method.
    {
        for(int j = 0; j<addressBook->contactCount-i-1;j++)
        {
            if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0)
            {
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }
    printf("S.no\tName\t\tPhone no\t\tEmail id\n");
    for(int i = 0;i<addressBook->contactCount;i++)                //Printing the sorted names.
    {
        printf("%-6d %-20s %-15s %-30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    break;

    case 2 : printf("Sorting by phone number : \n");

    for(int i = 0; i<addressBook->contactCount-1 ; i++)               //Sorting the Phone numbers by using bubble sort method.
    {
        for(int j = 0; j<addressBook->contactCount-i-1;j++)
        {
            if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone)>0)
            {
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }
    printf("S.no\tName\t\tPhone no\t\tEmail id\n");
    for(int i = 0;i<addressBook->contactCount;i++)                       //Printing the sorted phone numbers.
    {
        printf("%-6d %-20s %-15s %-30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    
    break;

    case 3 : printf("Sorting by email : \n");

    for(int i = 0; i<addressBook->contactCount-1 ; i++)         //Sorting the Email IDs by using bubble sort method.
    {
        for(int j = 0; j<addressBook->contactCount-i-1;j++)
        {
            if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email)>0)
            {
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }
    printf("S.no\tName\t\tPhone no\t\tEmail id\n");
    for(int i = 0;i<addressBook->contactCount;i++)             //Printing the sorted Email IDs.
    {
    {
        printf("%-6d %-20s %-15s %-30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    
    break;
    
    default: printf("Invalid");


    break;
    }
    
}
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0; //Keep the contactcount of the array of sturucture as 0 so that it will load from starting value.(or else it will be garbage).
    //populateAddressBook(addressBook);
    
    loadContactsFromFile(addressBook); // Load contacts from file during initialization (After files).
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

void  create_name(AddressBook *addressBook,int *valid)
{
    int attempts = 3,i;
    char *str = addressBook->contacts[addressBook->contactCount].name; // We are not creating a string because name should be stored directly in the current contact's 'name' field. 'str' is just a pointer that refers to that memory location, so any input we store in 'str' is automatically stored in the contact.
    while(attempts > 0)
    {
    printf("Enter the name : ");
    scanf(" %49[^\n]",str);

    if(strlen(str) < 4) //Checking that name should have atleast 4 characters. 
        {
            printf("Name must contain at least 4 characters.\n");
            *valid = 0; //Here *valid is acts as a flag..Like if the validation is fails then we will declare that as 0.
            attempts--;    
        if(attempts==0) //If we ran out of attempts then we should print failed to create contact and exit.
        {
          printf("Failed to create contact\n");
          return;   //we use return to just stop the function and exit.
        } 
            continue; //We use continue to go to the while loop and again ask for input if the 1st or second attempts fails.
        }

        for(i = 0 ; str[i]!='\0' ;i++)
       {
        if(isdigit(str[i])) //Checking that name should not have digits. 
        {
            printf("Numbers are not allowed in the name.\n");
            *valid=0; 
            attempts--;
        if(attempts==0)
        {
          printf("Failed to create contact\n");
          return;
        } 
            break; //Here we use break because break immediately exits the for loop.
        }
        if(!((isalpha(str[i])) || str[i] == ' ')) //Checking to make sure that there are no symbols.
        {
            printf("Symbols are not allowed in the name.\n");
            *valid=0;
            attempts--;
        if(attempts==0)
        {
          printf("Failed to create contact\n");
          return;
        } 
        break;
    }
    }
    if(str[i] != '\0')
    {
        continue;
    }
    *valid=1; //reached only if the for loop finished with no break at all (every character was a letter or space, and the length was already fine).
    return;
    }
}

void create_phone(AddressBook *addressBook, int *valid)
{
    int attempts = 3, i;
    char *str = addressBook->contacts[addressBook->contactCount].phone;  // We are not creating a new string because phone number should be stored directly in the current contact's phone field. str is just a pointer that refers to that memory location, so any input we store in str is automatically stored in the contact.
    while(attempts > 0) //Number of attempts we are giving if any validation is failed
    {
        printf("Enter the Phone number : ");
        scanf(" %19[^\n]", str);
        if(strlen(str) != 10) //Phine number should have 10 digits not more not less
        {
            printf("Error: Phone number must contain exactly 10 digits.\n");
            *valid = 0; //if failed we'll keep flag as 0
            attempts--;

            if(attempts == 0) //if there are no attempts left then print failed to create contact
            {
                printf("Failed to create contact.\n");
                return;
            }
            continue;
        }
        if(str[0] != '6' && str[0] != '7' && str[0] != '8' && str[0] != '9') //Starting number of phone number must start with 6 or 7 or 8 or 9
        {
            printf("Error: First digit must be between 6 and 9.\n");
            *valid = 0;
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to create contact.\n");
                return;
            }
            continue;
        }
        for(i = 0; str[i] != '\0'; i++)
        {
            if(isalpha(str[i]))  //If the input has character then the validation is failed.
            {
                printf("Error: Alphabets are not allowed in phone number.\n");
                *valid = 0;
                attempts--;

                if(attempts == 0)
                {
                    printf("Failed to create contact.\n");
                    return;
                }

                break;
            }
            if(!isdigit(str[i])) //Any symbols are not at all allowed in phone number.
            {
                printf("Error: Symbols are not allowed in phone number.\n");
                *valid = 0;
                attempts--;

                if(attempts == 0)
                {
                    printf("Failed to create contact.\n");
                    return;
                }

                break;
            }
        }
        if(str[i] != '\0')
        {
            continue;
        }
        for(i = 0; i < addressBook->contactCount; i++) //Checking there is no same phone number already stored.
        {
            if(strcmp(str, addressBook->contacts[i].phone) == 0) //for that we are comparing by strcmp if the return value is 0 then the
            {
                printf("Error: Phone number already exists.\n");
                *valid = 0;
                attempts--;

                if(attempts == 0)
                {
                    printf("Failed to create contact.\n");
                    return;
                }

                break;
            }
        }
        if(i != addressBook->contactCount) //The i value after the for loop will store its last value so by giving continue it will go to while loop re declare it self its starting value
        {
            continue;
        }
        *valid = 1;
        return;
    }
}

void create_mail(AddressBook *addressBook, int *valid)
{
    char *str = addressBook->contacts[addressBook->contactCount].email; // We are not creating a new string because email id should be stored directly in the current contact's email field. str is just a pointer that refers to that memory location, so any input we store in str is automatically stored in the contact.
    int attempts = 3, i, at = 0, dot = 0; //at and dot are counters to count the '@' and '.'
    int at_pos = -1, dot_pos = -1; //These are the indexes in which the '@' and '.' are placed...we gave the value -1 because if we give 0 then the index value will be 0 so that it will store the value in the 0th index so we use -1 because -1 is connot be the value of the array.
    while(attempts > 0)
    {
        //We have to re initalize these because while the loop is running it will contain the value of its first attempt only even if it is wrong then for the next attempt the values will not be the values which we have initalized at the start so when we give this then the continue takes place and it goes to the top of while loop again and retain the value.
        at = 0;
        dot = 0;
        at_pos = -1;
        dot_pos = -1;  
        printf("Enter the Email ID : ");
        scanf(" %49[^\n]", str);
    for(i = 0; str[i] != '\0'; i++)
    {
    if(isupper(str[i]))    // Check for uppercase letters.
    {
        printf("Email ID must contain only lowercase letters.\n");
        *valid = 0;
        attempts--;
        if(attempts == 0)
        {
            printf("Failed to create contact\n");
            return;
        }
        break;   // Stop checking once an uppercase letter is found.
    }
    }
      if(str[i] != '\0')
        {
            continue;
        }
        for(i = 0; str[i] != '\0'; i++) // Count @ and . and remembering their positions.
        {
            if(str[i] == '@')  
            {
                at++;
                at_pos = i;
            }
            if(str[i] == '.')
            {
                dot++;
                dot_pos = i;
            }
            if(!(isalnum(str[i]) || str[i] == '@' || str[i] == '.' )) //apart from the alphabets and @ and . any other symbol is invalid.
            {
                printf("Invalid symbol '%c'.\n", str[i]);
                *valid = 0;
                attempts--;

                if(attempts == 0)
                {
                    printf("Failed to create contact\n");
                    return;
                }
                break; 
            }
        }
        if(str[i] != '\0')
        {
            continue;
        }
        if(at != 1) // @ should be only one time 
        {
            printf("Email should contain exactly one @.\n");
            *valid = 0; //flag that we use to tell whether the validation is true or not
            attempts--;
            if(attempts == 0)
            {
                printf("Failed to create contact\n");
                return;
            }
            continue; //skip the next steps and go to while loop for the attempt 2 or 3.
        }
        if(dot != 1) //The . should be only one time
        {
            printf("Email should contain exactly one .\n");
            *valid = 0;
            attempts--;
            if(attempts == 0)
            {
                printf("Failed to create contact\n");
                return;
            }
            continue;
        }
        if(at_pos == 0) //if the @ is placed before the username then it is invalid.
        {
            printf("Username missing before @\n");
            *valid = 0;
            attempts--;
            if(attempts == 0)
            {
                printf("Failed to create contact\n");
                return;
            }
            continue;
        }
        if(dot_pos < at_pos) //if @ is placed after the . then it is invalid
        {
            printf("'.' should come after '@'.\n");
            *valid = 0;
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to create contact\n");
                return;
            }
            continue;
        }
        if(dot_pos == at_pos + 1) //if the next character after @ is . then the domain is missing
        {
            printf("Domain name missing.\n");
            *valid = 0;
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to create contact\n");
                return;
            }
            continue;
        }
    for(i = at_pos + 1; i < dot_pos; i++) //here we are checking between @ and .com to make sure that there are no numbers in domain
    {
    if(isdigit(str[i]))
    {
        printf("Domain name should not contain numbers.\n");
        *valid = 0;
        attempts--;

        if(attempts == 0)
        {
            printf("Failed to create contact\n");
            return;
        }

        break;
    }
    }
    if(i != dot_pos)  //The i value after the for loop will store its last value so by giving continue it will go to while loop re declare it self its starting value
    {
    continue;
    }
        if(strcmp(str + strlen(str) - 4, ".com") != 0) //Here str + strlen(str) - 4 means taking the address str points to and move it forward by length - 4 characters so that it directly points to the . and compare last four characters.
        {
            printf("Email must end with .com.\n"); //If email id does not end with the .com then it is invalid.
            *valid = 0;
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to create contact\n");
                return;
            }
            continue;
        }
        for(i = 0; i < addressBook->contactCount; i++)
        {
            if(strcmp(str, addressBook->contacts[i].email) == 0) //if the email id is already stored then it is invalid and wont be stored.
            {
                printf("Email ID already exists.\n");
                *valid = 0;
                attempts--;

                if(attempts == 0)
                {
                    printf("Failed to create contact\n");
                    return;
                }

                break;
            }
        }
        if(i != addressBook->contactCount)   //The i value after the for loop will store its last value so by giving continue it will go to while loop re declare it self its starting value
        {
            continue;
        }
        *valid = 1; //if it comes of out loop without any errors then flag is setted as 1.
        return;
    }
}

void createContact(AddressBook *addressBook)
{
    int n=1,p=1,m=1; //initalize the local variables as 1 and they act as the flag value.
	create_name(addressBook, &n); //And calling the name function.
    if(n==0)
    {
        return;
    }
    create_phone(addressBook, &p); //calling the phone function.
    if(p==0)
    {
        return;
    }
    create_mail(addressBook, &m); //calling the email function.
    if(m==0)
    {
        return;
    }
    if(n && p && m) //if the flags are true
    {
    addressBook->contactCount++;
    printf("Contact Successfully Created\n"); //if all these flags are true then the contact is suceessfully created.
    }
}

int search_name(AddressBook *addressBook, int *valid)
{
    char str[50];                 // Store the name entered by the user.
    int attempts = 3;             
    int i, count, choice;         
    int arr[100];                 // Store indexes of matched contacts.
    while(attempts > 0)           
    {
        count = 0;                
        printf("Enter the Name : ");
        scanf(" %49[^\n]", str);  
        for(i = 0; str[i] != '\0'; i++)   
        {
            if(!(isalpha(str[i]) || str[i] == ' ')) // Allow only alphabets and spaces.
            {
                printf("Invalid Name.\n");
                *valid = 0;       // Mark input as invalid.
                attempts--;       

                if(attempts == 0) 
                {
                    printf("Invalid Input.\n");
                    return -1;    // Exit the function.
                }
                break;            // Stop checking remaining characters.
            }
        }
        if(str[i] != '\0')        
        {
            continue;             // Ask for the name again.
        }
        printf("\nS.No\tName\t\tPhone Number\t\tEmail ID\n");
        for(i = 0; i < addressBook->contactCount; i++) // Search all contacts.
        {
            if(strcmp(str, addressBook->contacts[i].name) == 0) // Compare names.
            {
                printf("%d\t%-20s %-15s %-30s\n",count + 1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                arr[count] = i;   // Store the original contact index.
                count++;          // Increase the number of matches.
            }
        }
        if(count == 0)            // Check if no contact was found.
        {
            printf("Name not found.\n");
            *valid = 0;           
            attempts--;           
            if(attempts == 0)     
            {
                printf("Invalid Input.\n");
                return -1;        
            }
            continue;             
        }
        if(count == 1)            // Check if only one contact matched.
        {
            *valid = 1;           // Mark search as successful.
            return arr[0];        // Return the matched contact index.
        }
        printf("Enter the Serial Number : ");
        scanf("%d", &choice);     // Read the user's selected serial number.
        if(choice < 1 || choice > count) // Check if the serial number is valid.
        {
            printf("Invalid Serial Number.\n");
            *valid = 0;           
            attempts--;           
            if(attempts == 0)     
            {
                printf("Invalid Input.\n");
                return -1;       
            }
            continue;             
        }
        *valid = 1;               // Mark search as successful.
        return arr[choice - 1];   // Return the selected contact index.
    }
    return -1;                    // Return -1 if the search fails.
}

 int search_phone(AddressBook *addressBook, int *valid)
{
    char str[20]; //Taking new str[] string
    int attempts = 3, i; 
    while(attempts > 0) 
    {
        printf("Enter the Phone number : ");
        scanf(" %19[^\n]", str);
        if(strlen(str) != 10) //Length validation 
        {
            printf("Phone number must contain exactly 10 digits.\n");
            *valid = 0;
            attempts--;
            if(attempts == 0)
            {
                printf("Failed to search contact.\n");
                return -1; //Here we are returning -1 because -1 acts are the false and here returning 0 means it is true because here strcmp()==0 is match found. 
            }
            continue;
        }
        if(str[0] != '6' && str[0] != '7' && str[0] != '8' && str[0] != '9') // First digit validation 
        {
            printf("First digit must be between 6 and 9.\n");
            *valid = 0;
            attempts--;
            if(attempts == 0)
            {
                printf("Failed to search contact.\n");
                return -1;
            }
            continue;
        }
        for(i = 0; str[i] != '\0'; i++)
        {
            if(isalpha(str[i]))  // Character alphabets should not be allowed  
            {
                printf("Alphabets are not allowed in phone number.\n");
                *valid = 0;
                attempts--;

                if(attempts == 0)
                {
                    printf("Failed to search contact.\n");
                    return -1; //Here we are returning -1 because -1 acts are the false and here returning 0 means it is true because here strcmp()==0 is match found. 
                }
                break;
            }
            if(!isdigit(str[i])) //Symbols should not be allowed
            {
                printf("Symbols are not allowed in phone number.\n");
                *valid = 0;
                attempts--;
                if(attempts == 0)
                {
                    printf("Failed to search contact.\n");
                    return -1; //Here we are returning -1 because -1 acts are the false and here returning 0 means it is true because here strcmp()==0 is match found. 
                }
                break;
            }
        }
        if(str[i] != '\0')
        {
            continue;
        }
        for(i = 0; i < addressBook->contactCount; i++) // Search phone number
        {
            if(strcmp(str, addressBook->contacts[i].phone) == 0)
            {
                *valid = 1; //Flag
                return i; //If the Phone number is matched then we return value of the index so that we could print by using this
            }
        }
        printf("Contact with this phone number not found.\n");
        *valid = 0;
        attempts--;
        if(attempts == 0)
        {
            printf("Failed to search contact.\n");
            return -1;
        }
    }
    return -1; 
}

int search_mail(AddressBook *addressBook, int *valid)
{
    char str[50]; 
    int attempts = 3, i; 
    int at = 0, dot = 0; //at and dot are counters to count the '@' and '.'
    int at_pos = -1, dot_pos = -1; //These are the indexes in which the '@' and '.' are placed...we gave the value -1 because if we give 0 then the index value will be 0 so that it will store the value in the 0th index so we use -1 because -1 is connot be the value of the array.
    while(attempts > 0)
    {
        //We have to re initalize these because while the loop is running it will contain the value of its first attempt only even if it is wrong then for the next attempt the values will not be the values which we have initalized at the start so when we give this then the continue takes place and it goes to the top of while loop again and retain the value.
        at = 0;
        dot = 0;
        at_pos = -1;
        dot_pos = -1;
        printf("Enter the Email ID : ");
        scanf(" %49[^\n]", str);
        for(i = 0; str[i] != '\0'; i++)
        {
        if(isupper(str[i])) //If email is upper case then it is invalid
        {
        printf("Email ID must contain only lowercase letters.\n");
        *valid = 0;
        attempts--;
        if(attempts == 0)
        {
            printf("Invalid Input.\n");
            return -1;      // or return; depending on your function
        }
        break;
        }
        }
        if(str[i] != '\0')
        {
         continue;
        }
        for(i = 0; str[i] != '\0'; i++) // Count @ and . and remembering their positions
        {
            if(str[i] == '@')
            {
                at++;
                at_pos = i;
            }
            if(str[i] == '.')
            {
                dot++;
                dot_pos = i;
            }
            if(!(isalnum(str[i]) || str[i] == '@' || str[i] == '.')) //apart from the alphabets and @ and . any other symbol is invalid.
            {
                printf("Invalid symbol '%c'.\n", str[i]);
                *valid = 0;
                attempts--;
                if(attempts == 0)
                {
                    printf("Failed to search contact.\n");
                    return -1;
                }
                break;
            }
        }
        if(str[i] != '\0')
        {
            continue;
        }
        if(at != 1) // @ should be only one time 
        {
            printf("Email should contain exactly one '@'.\n");
            *valid = 0; //flag that we use to tell whether the validation is true or not
            attempts--;
            if(attempts == 0)
            {
                printf("Failed to search contact.\n");
                return -1;
            }
            continue; //skip the next steps and go to while loop for the attempt 2 or 3.
        }
        if(dot != 1) //The . should be only one time
        {
            printf("Email should contain exactly one '.'.\n");
            *valid = 0;
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to search contact.\n");
                return -1;
            }
            continue;
        }
        if(at_pos == 0) //if the @ is placed before the username then it is invalid.
        {
            printf("Username missing before '@'.\n");
            *valid = 0;
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to search contact.\n");
                return -1;
            }
            continue;
        }
        if(dot_pos < at_pos) //if @ is placed after the . then it is invalid
        {
            printf("Error: '.' should come after '@'.\n");
            *valid = 0;
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to search contact.\n");
                return -1;
            }
            continue;
        }

        if(dot_pos == at_pos + 1) //if the next character after @ is . then the domain is missing
        {
            printf("Domain name missing.\n");
            *valid = 0;
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to search contact.\n");
                return -1;
            }
            continue;
        }
        for(i = at_pos + 1; i < dot_pos; i++) //Domain should not contain numbers
        {
            if(isdigit(str[i]))
            {
                printf("Domain name should not contain numbers.\n");
                *valid = 0;
                attempts--;

                if(attempts == 0)
                {
                    printf("Failed to search contact.\n");
                    return -1;
                }

                break;
            }
        }
        if(i != dot_pos) //The i value after the for loop will store its last value so by giving continue it will go to while loop re declare it self its starting value
        {
            continue;
        }
        if(strcmp(str + strlen(str) - 4, ".com") != 0) //Here str + strlen(str) - 4 means taking the address str points to and move it forward by length - 4 characters so that it directly points to the . and compare last four characters.
        {
        {
            printf("Email must end with .com.\n");
            *valid = 0;
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to search contact.\n");
                return -1;
            }
            continue;
        }
        for(i = 0; i < addressBook->contactCount; i++)
        {
            if(strcmp(str, addressBook->contacts[i].email) == 0) // Search email
            {
                *valid = 1;
                return i;
            }
        }
        printf("Contact with this Email ID not found.\n");
        *valid = 0;
        attempts--;
        if(attempts == 0)
        {
            printf("Failed to search contact.\n");
            return -1;
        }
    }
    return -1; 
}
}

int searchContact(AddressBook *addressBook, int select)
{
    int n = 0, p = 0, m = 0, index; //set the local variables as 0
    switch(select)
    {
        case 1:
            index = search_name(addressBook, &n); 
            return index;
        case 2:
            index = search_phone(addressBook, &p); //We returned i in the search_phone function now that i value will be returned here
            if(p) //if the flag is true then it prints the searched phone number person's details
            {
                printf("S.no\tName\t\tPhone no\t\tEmail id\n");
                printf("%-6d %-20s %-15s %-30s\n",index + 1,addressBook->contacts[index].name,addressBook->contacts[index].phone,addressBook->contacts[index].email);
            }
            return index; //if true then the from above function i will be returned or else -1 will be returned which will not further proceed because it is anyway false 
        case 3:
            index = search_mail(addressBook, &m); //We returned i in the search_email function now that i value will be returned here
            if(m) //if the flag is true then it prints the email id person's details
            {
                printf("S.no\tName\t\tPhone no\t\tEmail id\n");
                printf("%-6d %-20s %-15s %-30s\n",index + 1,addressBook->contacts[index].name,addressBook->contacts[index].phone,addressBook->contacts[index].email);
            }
            return index; //if true then the from above function i will be returned or else -1 will be returned which will not further proceed because it is anyway false 
        case 4: 
                return -1; //it is exit 
        default:
            printf("Invalid choice. Please try again.\n");
            return -1;
    }
}

void edit_name(AddressBook *addressBook, int *index)
{
    int attempts = 3, i;
    char str[50];
    while(attempts > 0)
    {
        printf("Enter the New Name : ");
        scanf(" %49[^\n]", str);
        if(strlen(str) < 4) //Minimum length required validation 
        {
            printf("Name must contain at least 4 characters.\n");
            attempts--;
            if(attempts == 0)
            {
                printf("Failed to Update Name.\n");
                return;
            }
            continue;
        }
        for(i = 0; str[i] != '\0'; i++) //Character validation 
        {
            if(isdigit(str[i])) //Digits should not be there
            {
                printf("Numbers are not allowed in the name.\n");
                attempts--;
                if(attempts == 0)
                {
                    printf("Failed to Update Name.\n");
                    return;
                }
                break;
            }
            if(!(isalpha(str[i]) || str[i] == ' ')) //Except alphabets any other signal should not be there
            {
                printf("Symbols are not allowed in the name.\n"); 
                attempts--;
                if(attempts == 0)
                {
                    printf("Failed to Update Name.\n");
                    return;
                }

                break;
            }
        }
        if(str[i] != '\0') //If the Validation failed it will come here and by continue it will skip remaining and goes back to while loop and re attempt
        {
            continue;
        }
        strcpy(addressBook->contacts[*index].name, str);  //Edit the selected contact's name by using strcpy()
        printf("Name Updated Successfully.\n");
        return;
    }
}

void edit_phone(AddressBook *addressBook, int *index)
{
    char str[20];
    int attempts = 3, i;
    while(attempts > 0)
    {
        printf("Enter the New Phone number : ");
        scanf(" %19[^\n]", str);
        if(strlen(str) != 10) // Length validation 
        {
            printf("Phone number must contain exactly 10 digits.\n");
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to Update Phone Number.\n");
                return;
            }
            continue;
        }
        if(str[0] != '6' && str[0] != '7' && str[0] != '8' && str[0] != '9') //First digit validation 
        {
            printf("First digit must be between 6 and 9.\n");
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to Update Phone Number.\n");
                return;
            }
            continue;
        }
        for(i = 0; str[i] != '\0'; i++)  // Character validation 
        {
            if(isalpha(str[i]))
            {
                printf("Alphabets are not allowed in phone number.\n");
                attempts--;

                if(attempts == 0)
                {
                    printf("Failed to Update Phone Number.\n");
                    return;
                }

                break;
            }
            if(!isdigit(str[i])) //Symbol should not be there
            {
                printf("Symbols are not allowed in phone number.\n");
                attempts--;

                if(attempts == 0)
                {
                    printf("Failed to Update Phone Number.\n");
                    return;
                }

                break;
            }
        }
        if(str[i] != '\0') //if validation fails comes here
        {
            continue;
        }
        for(i = 0; i < addressBook->contactCount; i++) // Duplicate validation
        {
            if(i != *index && strcmp(str, addressBook->contacts[i].phone) == 0)  //i!=index means current contact should not be the contact that we are editing. and compare by using strcmp()
            {
                printf("Phone number already exists.\n");
                attempts--;

                if(attempts == 0)
                {
                    printf("Failed to Update Phone Number.\n");
                    return;
                }

                break;
            }
        }
        if(i != addressBook->contactCount)
        {
            continue;
        }
        strcpy(addressBook->contacts[*index].phone, str); //edit the phone number by strcpy
        printf("Phone Number Updated Successfully.\n");
        return;
    }
}

void edit_mail(AddressBook *addressBook, int *index)
{
    char str[50];
    int attempts = 3, i;
    int at = 0, dot = 0; //at and dot are counters to count the '@' and '.'
    int at_pos = -1, dot_pos = -1; //These are the indexes in which the '@' and '.' are placed...we gave the value -1 because if we give 0 then the index value will be 0 so that it will store the value in the 0th index so we use -1 because -1 is connot be the value of the array.
    while(attempts > 0)
    {
         //We have to re initalize these because while the loop is running it will contain the value of its first attempt only even if it is wrong then for the next attempt the values will not be the values which we have initalized at the start so when we give this then the continue takes place and it goes to the top of while loop again and retain the value.
        at = 0;
        dot = 0;
        at_pos = -1;
        dot_pos = -1;
        printf("Enter the New Email ID : ");
        scanf(" %49[^\n]", str);
     for(i = 0; str[i] != '\0'; i++)      // Check for uppercase letters.
    {
     if(isupper(str[i]))
     {
        printf("Email ID must contain only lowercase letters.\n");
        attempts--;

        if(attempts == 0)
        {
            printf("Failed to Update Email ID.\n");
            return;
        }

        break;    // Stop checking once an uppercase letter is found.
       }
     }
     if(str[i] != '\0')    // Loop ended because an uppercase letter was found.
     {
     continue;         // Ask for the email again.
     }
    for(i = 0; str[i] != '\0'; i++)  // Count @ and . and validate characters 
    {
        if(str[i] == '@')
        {
                at++;
                at_pos = i;
        }
            if(str[i] == '.')
            {
                dot++;
                dot_pos = i;
            }
            if(!(isalnum(str[i]) || str[i] == '@' || str[i] == '.')) //apart from the alphabets and @ and . any other symbol is invalid.
            {
                printf("Invalid symbol '%c'.\n", str[i]);
                attempts--;

                if(attempts == 0)
                {
                    printf("Failed to Update Email ID.\n");
                    return;
                }
                break;
            }
        }
        if(str[i] != '\0')
        {
            continue;
        }
        if(at != 1) // @ should be only one time 
        {
            printf("Email should contain exactly one '@'.\n");
            attempts--;
            if(attempts == 0)
            {
                printf("Failed to Update Email ID.\n");
                return;
            }
            continue;
        }
        if(dot != 1) //The . should be only one time
        {
            printf("Email should contain exactly one '.'.\n");
            attempts--;
            if(attempts == 0)
            {
                printf("Failed to Update Email ID.\n");
                return;
            }
            continue;
        }
        if(at_pos == 0) //if the @ is placed before the username then it is invalid.
        {
            printf("Username missing before '@'.\n");
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to Update Email ID.\n");
                return;
            }
            continue;
        }
        if(dot_pos < at_pos) //if @ is placed after the . then it is invalid
        {
            printf("Error: '.' should come after '@'.\n");
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to Update Email ID.\n");
                return;
            }
            continue;
        }
        if(dot_pos == at_pos + 1) //if the next character after @ is . then the domain is missing
        {
            printf("Domain name missing.\n");
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to Update Email ID.\n");
                return;
            }
            continue;
        }
        for(i = at_pos + 1; i < dot_pos; i++)  // Domain should not contain numbers 
        {
            if(isdigit(str[i])) 
            {
                printf("Domain name should not contain numbers.\n");
                attempts--;

                if(attempts == 0)
                {
                    printf("Failed to Update Email ID.\n");
                    return;
                }
                break;
            }
        }
        if(i != dot_pos) //The i value after the for loop will store its last value so by giving continue it will go to while loop re declare it self its starting value
        {
            continue;
        }
        if(strcmp(str + strlen(str) - 4, ".com") != 0)
        {
            printf("Email must end with .com.\n");
            attempts--;

            if(attempts == 0)
            {
                printf("Failed to Update Email ID.\n");
                return;
            }
            continue;
        }
        for(i = 0; i < addressBook->contactCount; i++)  // Duplicate validation
        {
            if(i != *index &&
               strcmp(str, addressBook->contacts[i].email) == 0)
            {
                printf("Email ID already exists.\n");
                attempts--;

                if(attempts == 0)
                {
                    printf("Failed to Update Email ID.\n");
                    return;
                }

                break;
            }
        }
        if(i != addressBook->contactCount)
        {
            continue;
        }
        strcpy(addressBook->contacts[*index].email, str); //edit the array of structure by using strcpy()
        printf("Email ID Updated Successfully.\n");
        return;
    }
}

void editContact(AddressBook *addressBook)
{
    int select,choice,index;
    printf("Search Contact By\n"); //By how we want to search
    printf("1.Search by Name\n");
    printf("2.Search by Phone Number\n");
    printf("3.Search by Email ID\n");
    printf("4.Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &select);
    if(select == 4) //To exit 
    {
        return;
    }
    index = searchContact(addressBook, select); //Declaration of SearchContact();
    if(index == -1) //In searchcontact function we are returing -1 as failed or false case so if index is -1 then stop the program
    {
        return;
    }
    printf("1.Edit by name\n");
    printf("2.Edit by Phone Number\n");
    printf("3.Edit by Email ID\n");
    printf("4.Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            edit_name(addressBook, &index); //Calling of edit_name()
            break;
        case 2:
            edit_phone(addressBook, &index); //Calling of edit_phone()
            break;
        case 3:
            edit_mail(addressBook, &index); //Calling of edit_mail()
            break;
        case 4:
            return;
        default:
            printf("Invalid Choice\n"); //if choosed invalid case then print invalid choice
            break;
    }
}

int delete_name(AddressBook *addressBook,int *flag)
{
    *flag=1;  //flag to check in if condition that the validations and requriments true or not
    int r = search_name(addressBook,flag);
    return r; 
}

int delete_phone(AddressBook *addressBook,int *flag)
{
    *flag=1; //flag to check in if condition that the validations and requriments true or not
    int r = search_phone(addressBook,flag);
    return r;
}

int delete_email(AddressBook *addressBook,int *flag)
{
    *flag=1; //flag to check in if condition that the validations and requriments true or not
    int r = search_mail(addressBook,flag);
    return r;
}

void deleteContact(AddressBook *addressBook)
{
	int option,n,p,m;
    printf("1.Delete by name\n");
    printf("2.Delete by phone number\n");
    printf("3.Delete by email id\n");
    printf("4.Exit\n");
    printf("Enter your Choice : ");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
    {
    int index = delete_name(addressBook, &n);
    if(n)
    {
        char ch;

        printf("Are you sure you want to delete this contact? (Y/N) : "); //Confirmation for deletion
        scanf(" %c", &ch);

        if(ch == 'Y' || ch == 'y') //if we want to delete for sure
        {
            for(int i = index; i < addressBook->contactCount - 1; i++) //start the local variable by index value and upto contactcount-1
            {
                addressBook->contacts[i] = addressBook->contacts[i + 1]; //The name will be overwrite the previous name
            }

            addressBook->contactCount--; //it will adjust the movement because while overwriting basically it delete the previous name

            printf("Contact Deleted Successfully.\n");
        }
        else
        {
            printf("Delete Cancelled.\n");
        }
    }
    break;
}
        break;

        case 2:
        int index1 = delete_phone(addressBook,&p);
        if(p)
        {
            for(int i=index1; i < addressBook->contactCount-1;i++) //start the local variable by index value and upto contactcount-1
            {
                addressBook->contacts[i] = addressBook->contacts[i+1]; //The phone number will be overwrite the previous phone number
            }
            addressBook->contactCount--; //it will adjust the movement because while overwriting basically it delete the previous phone number
            printf("Contact Deleted Successfully\n");
        }
        break;

        case 3:
        int index2 = delete_email(addressBook,&m);
        if(m)
        {
            for(int i=index2; i < addressBook->contactCount-1;i++) //start the local variable by index value and upto contactcount-1
            {
                addressBook->contacts[i] = addressBook->contacts[i+1];  //The email id will be overwrite the previous email id
            }
            addressBook->contactCount--; //it will adjust the movement because while overwriting basically it delete the previous email id
            printf("Contact Deleted Successfully\n");
        }
        break;

        case 4:  
           return; //Exit
        default :
        printf("Invalid contact Information"); //If false then this prints
        break;
    }
}