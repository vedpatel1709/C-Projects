/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   :Patel Ved Rajendrakumar
	ID     :149409203
	Email  :vrpatel33@myseneca.c
	Section:IPC144 NDD
*/
#define MAX_PRODUCTS 3
#define NUM_GRAMS 64
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int SKU_no;
	double PRODUCT_Price;
	int cal; //calories
	double weight; // in pounds
};


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number);// viaa pointer argument

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number);//via pointer argument

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product);// used void because do not want any return value.

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int number);

// 5. Display the formatted table header
void displayCatFoodHeader();

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight);
// integer types are passed by value, but double floating-point types are passed by address 

// 7. Logic entry point
void start();
