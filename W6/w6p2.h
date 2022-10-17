/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   :Patel ved Rajendrakumar
	ID     : 149409203
	Email  : vrpatel33@myseneca.ca
	Section:IPC144 NDD 
*/
#define MAX_PRODUCTS 3
#define NUM_GRAMS  64
#define CON_LBS 2.20462

struct  CatFoodInfo {
	int SKU_no;
	double PRODUCT_price;
	int cal;//calories
	double weight;//in pounds
};

int getIntPositive(int* number);

double getDoublePositive(double* number);

void openingMessage(const int num_grams);

struct CatFoodInfo getCatFoodInfo(const int number);

void displayCatFoodHeader(void);

void displayCatFoodData(const int SKU_no, const double* PRODUCT_price, const int cal, const double* weight);

struct ReportData
{
	int SKU_ID;
	double PRO_price;
	int calories;
	double LBS;
	double KG;
	int GRAMS;
	double TotalServing;
	double costserv;
	double costcalperserv;
};

double convertLbsKg(const double* pound, double* kgram);

int convertLbsG(const double* pound, int* gram);

void convertLbs(const double* Lbs, double* kgram, int* Gr);

double calculateServings(const int Sgr, const int tgram, double* Cresult);

double  calculateCostPerServing(const double* Pprice, const double* TotalServing, double* calcostresult);

double calculateCostPerCal(const double* price_product, const double* totalno_cal, double* calcost_calresult);

struct ReportData calculateReportData(const struct CatFoodInfo data);

void displayReportHeader(void);

void displayReportData(const struct ReportData info, const int cheap);

void start();

