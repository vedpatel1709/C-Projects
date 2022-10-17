//==============================================
// Name:           Patel Ved Rajendrakumar
// Student Number: 149409203
// Email:          vrpatel33@myseneca.ca
// Section:        NDD
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "contacts.h"
#include "contactHelpers.h"

// getName:
void getName(struct Name* name) {
    int prompt;
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);
    
    printf("Do you want to enter a middle initial(s)? (y or n): "); //prompt user for yes or no
    prompt = yes();
    if (prompt == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]S", name->middleInitial);
        clearKeyboard();
    }
    else {
        name->middleInitial[0] = '\0';
    }
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}

// getAddress:
void getAddress(struct Address* address) {
    int prompt;
    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt();
    do
    {
        if (address->streetNumber < 1)
        {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
            address->streetNumber = getInt();
        }

    } while (address->streetNumber < 1);
    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);
    //clearKeyboard();
    printf("Do you want to enter an apartment number? (y or n): "); //prompt user for yes or no
    prompt = yes();
    if (prompt == 1)
    {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();
        do
        {
            if (address->apartmentNumber < 1)
            {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
                address->apartmentNumber = getInt();
            }

        } while (address->apartmentNumber < 1);
       
    }
    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]s", address->postalCode);
    clearKeyboard();
    printf("Please enter the contact's city: ");
    scanf("%40[^\n]s", address->city);
    clearKeyboard();
}
// getNumbers:

void getNumbers(struct Numbers* numbers) {
    char prompt;
    printf("Please enter the contact's cell phone number: ");
  
    getTenDigitPhone(numbers->cell);

    

    printf("Do you want to enter a home phone number? (y or n): ");
    prompt = yes();
    if (prompt == 1)
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
        clearKeyboard();
    }
    else
    {
        numbers->home[0] = '\0';
    }
    printf("Do you want to enter a business phone number? (y or n): ");
    prompt = yes();
    if (prompt == 1)
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
                
    }
    else {
        numbers->business[0] = '\0';
    }

}
// getContact
void getContact(struct Contact* contact) {
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
