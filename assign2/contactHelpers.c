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
#include<stdio.h>
#include<string.h>
#include<ctype.h>



#include"contactHelpers.h"
#define MAX_CONTACTS 5

// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n');
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
	printf("\n");
}

// getInt function definition goes here:                                           
int getInt(void)
{
	int value;
	char NL = 'x';
	scanf(" %d%c", &value, &NL);
	while (NL != '\n')
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf(" %d%c", &value, &NL);
	}
	return value;
}

//getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
	int value = getInt();
	while ((value < min) || (value > max))
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);

		value = getInt();
	}
	return value;
}

// yes function definition goes here:
int yes(void)
{
	char YesNo = 'x';
	char NL = 'x';
	int response = -1;

	scanf(" %c%c", &YesNo, &NL);
	while (!((NL == '\n') && ((YesNo == 'Y') || (YesNo == 'y') || (YesNo == 'N') || (YesNo == 'n'))))
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf(" %c%c", &YesNo, &NL);
	}

	if (YesNo == 'Y' || YesNo == 'y')
	{
		response = 1;
	}
	else
	{
		response = 0;
	}
	return response;
}

// menu function definition goes here:
int menu(void)
{
	int option;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");
	option = getIntInRange(0, 6);
	
	return option;
}
// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
	int value;
	char YesNo;
	struct Contact contact[MAX_CONTACTS] =
	{ { { "Rick", {'\0'}, "Grimes" },
{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
{ "4161112222", "4162223333", "4163334444" } },
{
  { "Maggie", "R.", "Greene" },
  { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
  { "9051112222", "9052223333", "9053334444" } },
{
  { "Morgan", "A.", "Jones" },
  { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
  { "7051112222", "7052223333", "7053334444" } },
{
  { "Sasha", {'\0'}, "Williams" },
  { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
  { "9052223333", "9052223333", "9054445555" } },
	};


	do
	{
		value = menu();
		if (value == 0)
		{
			printf("\nExit the program? (Y)es/(N)o: ");
			YesNo = yes();
			if (YesNo == 1)
			{
				printf("\nContact Management System: terminated\n");
				return;
			}
			else
			{
				printf("\n");
			}
		}
		else if (value == 1)
		{
			printf("\n");
			displayContacts(contact, MAX_CONTACTS);
			pause();

		}
		else if (value == 2)
		{
			printf("\n");
			addcontact(contact, MAX_CONTACTS);
			pause();

		}
		else if (value == 3)
		{
			updateContact(contact, MAX_CONTACTS);
			pause();

		}
		else if (value == 4)
		{
			printf("\n");
			deleteContact(contact, MAX_CONTACTS);
			pause();

		}
		else if (value == 5)
		{
			searchContacts(contact, MAX_CONTACTS);
			pause();

		}
		else if (value == 6)
		{
			sortContacts(contact, MAX_CONTACTS);
			pause();

		}
	} while ((value >= 0) || (value <= 6));
}


void getTenDigitPhone(char phoneNum[]) {
	int needInput = 1; // Control variable to tell if the user needs to input a new value
	int isNumeric = 1; // Control variable to tell if the inputed value is numeric.

	while (needInput == 1) {
		isNumeric = 1; // Reset the control variable
		scanf("%10s", phoneNum);
		clearKeyboard();

		// We check each character to see if the input is numeric.
		// If any of them is not a digit, we stop checking and change the control variable.
		int i;
		for (i = 0; i < strlen(phoneNum); i++) {
			if (isdigit(phoneNum[i]) == 0) { // Check if the character is a digit.
				isNumeric = 0; // Change the control variable to 'False'
				i = strlen(phoneNum); // Break the iteration.
			}
		}

		// (String Length Function: validate entry of 10 characters)
		// If the length is correct and the input is numeric, we return the value.
		// If not, we display an error message and repeat the code.
		if (strlen(phoneNum) == 10 && isNumeric == 1)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

	// findContactIndex:
	int findContactIndex(const struct Contact Contacts[], int size, const char cellNum[])
	{
		int i;
		int index = -1;
		for (i = 0; i < size; i++)
		{
			if (strcmp(Contacts[i].numbers.cell, cellNum) == 0)
			{
				index = i;
			}
		}
		return index;
	}

	// displayContactHeader
	// Put empty function definition below:
	void displayContactHeader(void)
	{
		printf("+-----------------------------------------------------------------------------+\n");
		printf("|                              Contacts Listing                               |\n");
		printf("+-----------------------------------------------------------------------------+\n");
	}

	// displayContactFooter
	// Put empty function definition below:
	void displayContactFooter(int count)
	{
		printf("+-----------------------------------------------------------------------------+\n");
		printf("Total contacts: %d\n\n", count);
	}

	// displayContact:
	// Put empty function definition below:
	void displayContact(const struct Contact* contact)
	{
		printf(" %s ", contact->name.firstName);
		if (strlen(contact->name.middleInitial) != 0) printf("%s ", contact->name.middleInitial);
		printf("%s\n", contact->name.lastName);
		printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
		printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
		if (contact->address.apartmentNumber > 0) printf("Apt# %d, ", contact->address.apartmentNumber);
		printf("%s, %s\n", contact->address.city, contact->address.postalCode);
	}

	// displayContacts:
	// Put empty function definition below:
	void displayContacts(const struct Contact contacts[], int size)
	{
		int i;
		int count = 0;
		displayContactHeader();
		for (i = 0; i < size; i++)
		{
			if (strlen(contacts[i].numbers.cell) != 0) {
				displayContact(&contacts[i]);
				count++;
			}
		}
		displayContactFooter(count);
	}

	// searchContacts:
	// Put empty function definition below:
	void searchContacts(const struct Contact contact[], int size) {
		char cellnumbers[11];
		int found = -1;
		printf("\n");
		printf("Enter the cell number for the contact: ");
		getTenDigitPhone(cellnumbers);
		found = findContactIndex(contact, size, cellnumbers);
		if (found > -1) {
			printf("\n");
			displayContact(&contact[found]);
			printf("\n");

		}
		else {
			printf("*** Contact NOT FOUND ***\n\n");
		}

	}



	// addContact:
	// Put empty function definition below:
	void addcontact(struct Contact contact[], int size)
	{
		int i;
		int space = -1;
		for (i = 0; i < size; i++) {
			if (strlen(contact[i].numbers.cell) == 0) {
				space = i;
				i = size;
			}
		}
		if (space > -1)
		{
			getContact(&contact[space]);
			printf("--- New contact added! ---\n\n");

		}
		else {
			
			printf("*** ERROR: The contact list is full! ***\n\n");

		}
	}


	// updateContact:
	// Put empty function definition below:
	void updateContact(struct Contact contact[], int size)
	{
		char phoneno[11];
		int found = -1;
		int YesNo;
		printf("\n");
		printf("Enter the cell number for the contact: ");
		getTenDigitPhone(phoneno);
		found = findContactIndex(contact, size, phoneno);
		if (found == -1) {
			printf("*** Contact NOT FOUND ***\n\n");
		}
		else {
			printf("\n");
			printf("Contact found:\n");
			displayContact(&contact[found]);
			printf("\nDo you want to update the name? (y or n): ");
			YesNo = yes();
			if (YesNo == 1) {
				getName(&contact[found].name);
			}
			
			printf("Do you want to update the address? (y or n): ");
			YesNo = yes();
			
			if (YesNo == 1) {
				getAddress(&contact[found].address);
			}
			
			printf("Do you want to update the numbers? (y or n): ");
			YesNo = yes();
			
			if (YesNo == 1) {
				getNumbers(&contact[found].numbers);
			}
				printf("--- Contact Updated! ---\n\n");
			
		}
	}


	// deleteContact:
	// Put empty function definition below:
	void deleteContact(struct Contact contact[], int size) {
		char phone[11];
		char YesNo;
		int found = -1;
		printf("Enter the cell number for the contact: ");
		getTenDigitPhone(phone);
		found = findContactIndex(contact, size, phone);
		if (found == -1) {
			printf("*** Contact NOT FOUND ***\n");
		}
		else {
			printf("\n");
			printf("Contact found:\n");
			displayContact(&contact[found]);
			printf("\n");
			printf("CONFIRM: Delete this contact? (y or n): ");
			YesNo = yes();
						
			if (YesNo == 1) {
			
				//contact[found].numbers.business[0] = '\0';
				contact[found].numbers.cell[0] = '\0';
				//contact[found].numbers.home[0] = '\0';
				printf("--- Contact deleted! ---\n\n");
			}
                        else{
                    printf("\n");
                            }
		}
	}

	// sortContacts:
	// Put empty function definition below:
	void sortContacts(struct Contact contact[], int size) {
		int i, j;
		struct Contact a2;

		for (i = 0; i < size - 1; i++) {
			for (j = i + 1; j < size; j++) {
				if ((contact[i].numbers.cell) > 0 && (contact[j].numbers.cell > 0)) {
					if (strcmp(contact[i].numbers.cell, contact[j].numbers.cell) > 0) {
						a2 = contact[i];
						contact[i] = contact[j];
						contact[j] = a2;
					}
				}

			}
		}
		printf("\n--- Contacts sorted! ---\n\n");
	}
