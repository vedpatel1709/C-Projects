
/*
	==================================================
	Workshop #3 (Part-2):
	==================================================
	Name   : Patel Ved Rajendrakumar
	ID     :149409203
	Email  :vrpatel33@myseneca.ca
	Section:IPC144 NDD
*/
#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3
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
	int i = 0;
	double rating= 0.0;
	
	double morningrating = 0;
	double eveningrating = 0;
	for (i = 1; i < 4; i++)
	{


		switch (month) {

		case 1: printf("%d-JAN-0%d\n", year, i);
			break;
		case 2: printf("%d-FEB-0%d\n", year, i);
			break;
		case 3: printf("%d-MAR-0%d\n", year, i);
			break;
		case 4: printf("%d-APR-0%d\n", year, i);
			break;
		case 5: printf("%d-MAY-0%d\n", year, i);
			break;
		case 6: printf("%d-JUN-0%d\n", year, i);
			break;
		case 7: printf("%d-JUL-0%d\n", year, i);
			break;
		case 8: printf("%d-AUG-0%d\n", year, i);
			break;
		case 9: printf("%d-SEP-0%d\n", year, i);
			break;
		case 10: printf("%d-OCT-0%d\n", year, i);
			break;
		case 11: printf("%d-NOV-0%d\n", year, i);
			break;
		case 12: printf("%d-DEC-0%d\n", year, i);
			break;
		}
		do {
			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &rating);
			if (rating > 5.0 || rating < 0.0)
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}
		} while (rating > 5.0 || rating < 0.0);
		morningrating = morningrating + rating;

		do {
			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &rating);
			if (rating > 5.0 || rating < 0.0)
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}
		} while (rating > 5.0 || rating < 0.0);
		eveningrating = eveningrating + rating;
                printf("\n");
	}
	printf("Summary\n");
	printf("=======\n");
	printf("Morning total rating: %.3lf\n",morningrating);
	printf("Evening total rating: %.3lf\n",eveningrating );
	printf("----------------------------\n");
	printf("Overall total rating: %.3lf\n", morningrating + eveningrating);
	printf("\n");
	printf("Average morning rating:  %.1lf\n", morningrating / 3);
	printf("Average evening rating:  %.1lf\n", eveningrating / 3);
	printf("----------------------------\n");

	printf("Average overall rating:  %.1lf\n", (morningrating + eveningrating)/6 );
	

	return 0;
}
