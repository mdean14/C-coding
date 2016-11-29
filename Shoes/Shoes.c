/*Matthew Dean
shoes.c - loop to read from the file report.txt
Shows all the quantitys of each shoe, most in stock, and restock
March 1, 2010
Assignment 2 due: March 3rd
*/


//preprocessor directives
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

//function prototypes

void Display (int globeQty, int adioQty, int osirisQty, int dcQty, int etniesQty, int nikeQty);
//takes the calculated quantities of each item and displays on the screen

int MostInStock (int globeQty, int adioQty, int osirisQty, int dcQty, int etniesQty, int nikeQty);
//takes the quantities of each item and returns the ID of the item with the largest inventory

void Restock  (int globeQty, int adioQty, int osirisQty, int dcQty, int etniesQty, int nikeQty);
//takes the quantities of each item and displays the brand name of those with less than 10 units in stock



int main()
{
	//varaible declarations: Shoes, id, and quantity 
	int globeQty = 0;
	int adioQty = 0;
	int osirisQty = 0;
	int dcQty = 0;
	int etniesQty = 0;
	int nikeQty = 0;
	int id; //current id (1 through 6) read from the file
	int currentQty; //current quantity read from the file
	

	//declaration of pointer to the file
	FILE * inptr;
	
	//connect to the file
	inptr = fopen("report.txt","r");
	
	//scan in the first code/ qty pair from the file
	fscanf(inptr, "%d%d", &id, &currentQty);

	while(id!=-9999)//-9999 is the end of the numbers in the file
	{
		// use if/else or switch to update the quantities
		switch (id)
		{
			case 1:
				globeQty+=currentQty;
				break;
			case 2:
				adioQty+=currentQty;
				break;
			case 3:
				osirisQty+=currentQty;
				break;
			case 4:
				dcQty+=currentQty;
				break;
			case 5:
				etniesQty+=currentQty;
				break;
			case 6:
				nikeQty+=currentQty;
				break;
		}

		//get the next code/ quantity pair
		fscanf(inptr, "%d %d",&id, &currentQty);
					
	}
	//close the file
	fclose(inptr);

	//display the quantities for each item(call the Display function)
	Display(globeQty, adioQty, osirisQty, dcQty, etniesQty, nikeQty);

	//determine which quantity is the most in stock (call MostInStock function)
	id=MostInStock (globeQty, adioQty, osirisQty, dcQty, etniesQty, nikeQty);

	//use if/else or switch to print the most in stock onto the screen
	switch (id)
		{
			case 1:
				printf(" Most in stock is globeQty\n\n");
				break;
			case 2:
				printf("Most in stock is adioQty\n\n");
				break;
			case 3:
				printf("Most in stock is osirisQty\n\n");
				break;
			case 4:
				printf(" Most in stock is dcQty\n\n");
				break;
			case 5:
				printf("Most in stock is etniesQty\n\n");
				break;
			case 6:
				printf("Most in stock is nikeQty\n\n");
				break;
		}

	//determine which shoes need to be restocked (call the Restock function)
	Restock (globeQty, adioQty, osirisQty, dcQty, etniesQty, nikeQty);
	
	return 0;
}

// Displays all the quantitys to the screen
void Display (int globeQty, int adioQty, int osirisQty, int dcQty, int etniesQty, int nikeQty)
{
		
	printf (" Globes Quantity:  %d\n", globeQty);

	printf (" Adio Quantity: %d\n", adioQty);

	printf (" Osiris Quantity: %d\n", osirisQty);

	printf (" DC Quantity: %d\n", dcQty);

	printf (" Etnies Quantity: %d\n", etniesQty);

	printf (" Nike Quantity: %d\n\n", nikeQty);
}
//Figures out the most in stock and sends id to the main
int MostInStock (int globeQty, int adioQty, int osirisQty, int dcQty, int etniesQty, int nikeQty)
{
	int id = 1;
	int max = globeQty;

	if (adioQty > max)
	{
		max = adioQty;
		id = 2;
	}
	if (osirisQty > max)
	{
		max = osirisQty;
		id = 3;
	}
	if (dcQty > max)
	{
		max = dcQty;
		id = 4;
	}
	if (etniesQty > max)
	{
		max = etniesQty;
		id = 5;
	}
	if (nikeQty > max)
	{
		max = nikeQty;
		id = 6;
	}
	return id; 
}
// Shows all the shoes that are less than 10 and need to be restocked
void Restock  (int globeQty, int adioQty, int osirisQty, int dcQty, int etniesQty, int nikeQty)
{
	printf(" Need to restock:\n\n");

		if (globeQty<10)
			printf(" Globe\n");

		if (adioQty<10)
			printf(" Adio\n");

		if (osirisQty<10)
			printf(" Osiris\n");

		if (dcQty<10)
			printf(" DC\n");

		if (etniesQty<10)
			printf(" Etnies\n");

		if (nikeQty<10)
			printf(" Nike\n");

	printf("\n\n");
}

/*
 Globes Quantity:  29
 Adio Quantity: 6
 Osiris Quantity: 10
 DC Quantity: 3
 Etnies Quantity: 5
 Nike Quantity: 18

 Most in stock is globeQty

 Need to restock:
 Adio
 DC
 Etnies


Press any key to continue . . .

*/
