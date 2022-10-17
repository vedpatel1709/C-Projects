
/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   : Patel Ved Rajendrakumar
	ID     :149409203
	Email  :vrpatel33@myseneca.ca
	Section:IPC144 NDD
*/
#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#include<stdio.h>
int main(void) {
	int year, month;
	const int JAN = 1, DES = 12;

	printf("General Well-being Log\n");
	printf("======================\n");

	do {

		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d" "%d", &year, &month);

		if (year > 2021 || year < 2010)
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");

		if (month > DES || month < JAN)
			printf("   ERROR: Jan.(1) - Dec.(12)\n");

	}

	while ((year > 2021 || year < 2010) || (month < 1 || month > 12));

	printf("\n");
	printf("*** Log date set! ***\n");
	printf("\n");

	switch (month) {

	case 1: printf("Log starting date: %d-JAN-01\n", year);
		break;
	case 2: printf("Log starting date: %d-FEB-01\n", year);
		break;
	case 3: printf("Log starting date: %d-MAR-01\n", year);
		break;
	case 4: printf("Log starting date: %d-APR-01\n", year);
		break;
	case 5: printf("Log starting date: %d-MAY-01\n", year);
		break;
	case 6: printf("Log starting date: %d-JUN-01\n", year);
		break;
	case 7: printf("Log starting date: %d-JUL-01\n", year);
		break;
	case 8: printf("Log starting date: %d-AUG-01\n", year);
		break;
	case 9: printf("Log starting date: %d-SEP-01\n", year);
		break;
	case 10: printf("Log starting date: %d-OCT-01\n", year);
		break;
	case 11: printf("Log starting date: %d-NOV-01\n", year);
		break;
	case 12: printf("Log starting date: %d-DEC-01\n", year);
		break;

	}

	return 0;
}
