/* Matthew Dean
 * COP2220 Intro to Programming in C
 *
 * January 25, 2010
 * 
 * The cost of a vaction trip
 *
 */


//preprocessor directives
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int main()
{
	int numTravelers;
	int days_of_trip;
	double cost_airfare; //cost of airfare
	double cost_hotel_room;
	double cost_of_rentalCar;
	double totalTicket=1.0; //total cost for round trip
	double totalHotel=1.0; //total cost for the hotel room
	double totalRentalCar=1.0;
	double totalMeals=1.0; //total cost for the meals at $40 per day
	double grandTotal=1.0;

	printf ("Welcome to our Vaction Calculator! Where we calculate the total cost of your\n" );
	printf ("trip. Please enter the following information: \n" );

	//{{Infromation}}

	//prompt for number of travelers
	printf("\nHow many travelers will be coming with you? ");
	//get the number of travelers
	scanf("%d", &numTravelers);

	//echo input
	//printf("\ntravelers entered %d\n",numTravelers);

	//Days spend at the vaction place
	printf("\nHow many days will you be spending on vaction? ");
	scanf("%d", &days_of_trip);

	//prompt and get ticket price
	printf("\nWhat is your cost for your round trip? ");
	scanf("%lf", &cost_airfare);

	//echo input
	//printf("\nticket price entered %.2f\n",cost_airfare);

	//Daily cost of hotel per night
	printf ("\nHow much will it cost you for one night? ");
	scanf ("%lf", &cost_hotel_room);

	//Cost for the rental car
	printf ("\nHow much will your rental car cost for one day? ");
	scanf ("%lf", &cost_of_rentalCar);

	//{{Calculations}}

	//calculate total ticket price
	totalTicket = (double)numTravelers * cost_airfare;

	//Calculating total price for the Hotel room 
	totalHotel = ((double)days_of_trip - 1) * cost_hotel_room;

	//Calculating total cost for the rental car
	totalRentalCar = (double)days_of_trip * cost_of_rentalCar;

	//Meal Plan caluculation
	totalMeals = (40 * (double)numTravelers)* (double)days_of_trip;

	//Grand Total
	grandTotal = totalTicket + totalHotel + totalRentalCar + totalMeals;

	//{{Results}}

	//print the result
	//printf("\nthe total price is $%.2f\n", totalHotel);

	printf("\nThe total airfare for %d passengers is $%.2f\n", numTravelers, totalTicket);

	printf("\nThe total price for your hotel room will be $%.2f\n", totalHotel);

	printf("\nThe total cost of your rental car is $%.2f\n", totalRentalCar);

	//Meal plan
	printf ("\nTotal cost of our meal plan(at $40 per person per day ) will cost you : $%.2f\n", totalMeals);

	printf ("\nThe grand total our your wonderful vaction will be: $%.2f\n", grandTotal);

	printf ("\nThank You for your time. Hope that you have a great vaction! \n");
	//Felt like putting something like: Ouch!! Hope that didnt ruin your vaction.

	return 0;
}