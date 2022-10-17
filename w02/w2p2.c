/*
	==================================================
	Workshop #2 (Part-2):
	==================================================
	Name   : Patel ved rajendrakumar
	ID     :149409203
	Email  :vrpatel33@myseneca.ca
	Section:IPC 144NDD
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{

double dDollars = 0.0, remainingpennies = 0.0, remainingnickels = 0.0, servicefee = 0.0;
double	remainingdimes = 0.0, remainingloonies = 0.0, remainingtoonies = 0.0, dollars = 0.0, remainingquarters = 0.0;
int  toonies = 0, loonies = 0, quarters = 0, dimes = 0, pennies = 0, nickels = 0, cents = 0;
double remainingamount = 0.0;

printf("Change Maker Machine\n");
printf("====================\n");
printf("Enter dollars and cents amount to convert to coins: $");
scanf("%lf", &dollars);

servicefee = dollars * 0.05;
dDollars = dollars - servicefee;
printf("Service fee (5.0 percent): %.2lf\n", servicefee);
printf("Balance to dispense: $%.2lf\n", dDollars);
printf("\n");

cents = dDollars * 100;
toonies = cents / 200;
remainingamount = cents % 200;
remainingtoonies = remainingamount / 100;
printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonies, remainingtoonies);

loonies = remainingamount / 100;
remainingamount = (int)remainingamount % 100;
remainingloonies = remainingamount / 100;
printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", loonies, remainingloonies);

quarters = remainingloonies / 0.25;
remainingamount = (int)remainingamount % 25;
remainingquarters = remainingamount / 100;
printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quarters, remainingquarters);

dimes = remainingquarters / 0.10;
remainingamount = (int)remainingamount % 10;
remainingdimes = remainingamount / 100;
printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", dimes, remainingdimes);

nickels = remainingdimes / 0.05;
remainingamount = (int)remainingamount % 5;
remainingnickels = remainingamount / 100;
printf("$0.05 Nickels  X %d (remaining: $%.2lf)\n", nickels, remainingnickels);

pennies = remainingnickels / 0.01;
remainingamount = (int)remainingamount % 1;
remainingpennies = remainingamount / 100;
printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n", pennies, remainingpennies);

printf("\n");
printf("All coins dispensed!\n");
return 0;




}