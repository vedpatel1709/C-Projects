
/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   :Patel ved Rajendrakumar
	ID     : 149409203
	Email  : vrpatel33@myseneca.ca
	Section:IPC144 NDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "w6p2.h"

int getIntPositive(int* number)
{
	int  value;
	do {
		scanf("%d", &value);
		if (value <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (value <= 0);

	if (number != NULL)
		*number = value;
	else {

	}
	return value;
}

double getDoublePositive(double* number) 
{
	double value;
	do {
		scanf("%lf", &value);
		if (value <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (value <= 0);
	if (number != NULL)
		*number = value;
	return value;
}

void openingMessage(const int num_grams) 
{
	
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for 3 dry food bags of product data for analysis.\n");
	printf("NOTE: A 'serving' is %dg\n", NUM_GRAMS);
}

struct CatFoodInfo getCatFoodInfo(const int sequence_num)
{
	struct CatFoodInfo food = { 0 };
	printf("\nCat Food Product #%d\n", sequence_num);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&food.SKU_no);
	printf("PRICE         : $");
	getDoublePositive(&food.PRODUCT_price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&food.cal);

	return food;
};

void displayCatFoodHeader(void)
{
	printf("\n");
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(const int sku_id, const double* PRO_price, const int cal, const double* weight) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku_id, *PRO_price, *weight, cal);
}

double convertLbsKg(const double* pound, double* kgram)
{
	double value;
	value = *pound / CON_LBS;
	if (kgram != NULL)
	{
		*kgram = value;
	}
	return value;
}

int convertLbsG(const double* pound, int* gram)
{
	int value;
	value = convertLbsKg(pound, 0) * 1000;
	if (gram != NULL)
	{
		*gram = value;
	}
	return value;
}

void convertLbs(const double* Lbs, double* kgram, int* Gr)
{
	convertLbsKg(Lbs, kgram);
	convertLbsG(Lbs, Gr);
}

double calculateServings(const int Sgr, const int tgram, double* Cresult)
{
	double value;
	value = (double)tgram / (double)Sgr;
	if (Cresult != NULL)
	{
		*Cresult = value;
	}
	return value;
}

double  calculateCostPerServing(const double* Pprice, const double* TotalServing, double* calcostresult)
{
	double price = 0;
	price = *Pprice / *TotalServing;
	if (calcostresult != NULL)
	{
		*calcostresult = price;
	}
	return price;
}

double calculateCostPerCal(const double* price_product, const double* totalno_cal, double* calcost_calresult)
{
	double value = 0;
	value = *price_product / *totalno_cal;
	if (calcost_calresult != NULL)
	{
		*calcost_calresult = value;
	}
	return value;
}

struct ReportData calculateReportData(const struct CatFoodInfo data)
{
	struct ReportData info;
	double value;
	//old info
	info.SKU_ID = data.SKU_no;
	info.PRO_price = data.PRODUCT_price;
	info.LBS = data.weight;
	info.calories = data.cal;
	info.KG = convertLbsKg(&data.weight,&info.KG);
	info.GRAMS = convertLbsG(&data.weight, &info.GRAMS);
	info.TotalServing = calculateServings(NUM_GRAMS, info.GRAMS,&info.TotalServing);
	info.costserv = calculateCostPerServing(&info.PRO_price,&info.TotalServing, &info.costserv);
	
	value = info.calories * info.TotalServing;
	info.costcalperserv = calculateCostPerCal(&info.PRO_price, &value,&info.costcalperserv);
	return info;
}

void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg\n", NUM_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

void displayReportData(const struct ReportData info, const int cheap)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
		info.SKU_ID, info.PRO_price, info.LBS, info.KG, info.GRAMS,info.calories, info.TotalServing, info.costserv,info.costcalperserv);
}

	void displayFinalAnalysis(const struct CatFoodInfo catfoodinfo)
{
	printf("\n");
	printf("Final Analysis\n--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", catfoodinfo.SKU_no,catfoodinfo.PRODUCT_price);
	printf("Happy shopping!\n");
}

void start(void)
{
	struct CatFoodInfo catFoodDetail[MAX_PRODUCTS] = { {0} };
	int i = 0, cheapproduct = 0;
	openingMessage(MAX_PRODUCTS);
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		catFoodDetail[i] = getCatFoodInfo(i + 1);
	}
	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(catFoodDetail[i].SKU_no, &catFoodDetail[i].PRODUCT_price,catFoodDetail[i].cal, &catFoodDetail[i].weight);
	}
	struct ReportData r[MAX_PRODUCTS];
	displayReportHeader();
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		r[i] = calculateReportData(catFoodDetail[i]);
		if (r[i].costserv < r[i - 1].costserv)
		{
			cheapproduct = i;
		}
		else {

		}
	}

	int j;
	for (j = 0; j < MAX_PRODUCTS; j++)
	{
		struct ReportData info= { 0 };
		info = r[j];
		displayReportData(info, cheapproduct);
		if (cheapproduct == j)
		{
			printf(" ***");
		}
		else {

		}
		printf("\n");
	}
	displayFinalAnalysis(catFoodDetail[cheapproduct]);
}