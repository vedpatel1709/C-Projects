/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   :Patel Ved Rajendrakumar
	ID     :149409203
	Email  :vrpatel33@myseneca.c
	Section:IPC144 NDD
*/
#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w6p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* number)
{
	int value ;
	do
	{
		scanf("%d", &value);
		if (value <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (value <= 0);
	if (number != NULL)
	{
		*number = value;
	}
	return value;//return the variable value
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* number)
{
	double value ;
	do
	{
		scanf("%lf", &value);
		if (value <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (value <= 0);
	if (number != NULL) 
	{
		*number = value;
	}
	return value;//return the variable value
}


// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int num_product)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", num_product);
	printf("NOTE: A 'serving' is %dg\n", NUM_GRAMS);
}

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int number)
{
	struct CatFoodInfo food = { 0 };
	printf("\nCat Food Product #%d\n", number);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&food.SKU_no);
	printf("PRICE         : $");
	getDoublePositive(&food.PRODUCT_Price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&food.cal);

	return food;
}

// 5. Display the formatted table header

void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);

}

// 7. Logic entry point

void start()
{
	int i;
	struct CatFoodInfo cats[MAX_PRODUCTS] = { {0} };
	openingMessage(MAX_PRODUCTS);
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		cats[i] = getCatFoodInfo(i + 1);
	}
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(cats[i].SKU_no, &cats[i].PRODUCT_Price, cats[i].cal, &cats[i].weight);
	}
}

