//Matthew Dean
//cop2220
//Snacks- menu with different options to choose from

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

//Function prototype
// Displays the list of snack items and prompts for the user’s choice 
void Menu(char *selectionPtr); 
//compares the amount the user has deposited to the price of item selected. 
//returns 1 if the amount is enough to cover the cost, 0 if there is not enough.
int CheckMoney(double *purchase, double item_cost); 
//uses CoinMenu function to display and collect money from the user 
//uses CheckMoney function to keep comparing the deposited amount to the item cost.
void GetMoney(double *purchasePtr, double item_cost, char selection);  
//calculates the amount of change to be returned
void GetChange(double *purchase, double item_cost, double *change); 
//Displays the codes for coin input – gets user input amounts
//compares the int codes and updates the purchase amount entered
void CoinMenu(double *purchase);  
//Asks the user if they want another snack.
void Quit(char *cptr);
//sets the cost of the purchase based on value in selection
void GetCost(char selection, double *item_costptr);
//prompts the user for a selection
//returns the menu selection

int main ( )
{
	char choice =' ';
	char selection = ' ';
	double item_cost= 0;
	double change = 0;
	double purchase = 0;
	int select=0;
	do{

		//printf("choice entered %c", choice);
		
		//menu function displays snakcs and gets snack choice
		purchase = 0.0;
		Menu(&selection);
		GetCost(selection,&item_cost);
		//call GetMoney function
		GetMoney(&purchase, item_cost, selection);	
		//call getChange
		GetChange(&purchase, item_cost, &change);
		printf("-----------------------------------");
		printf("\nThanks you for your time!\n");
		printf("\nPrice of Item: %c is $%.2f\n", selection, item_cost);
		printf("\nMoney entered: $%.2f\n", purchase);
		printf("\nDispensing Item: %c\n", selection);
		printf("\nDispensing Change %.2f\n", change);
		
		Quit(&choice);//yes or no to quit choice
	}while(choice!='n'&& choice!='N');
	
	printf ("\n GODDBYE\n");
}

//prompts the user for a selection
//returns the menu selection
void Quit(char *cptr)
{
	//char selection;
	printf("\nWould u like to make another selection (y or n):  ");
	scanf(" %c", cptr);
	//return selection;
}
void Menu(char *selectionPtr)
{
		printf("\nP  Potato Chips		$1.25\n");	
		printf("C  Chocolate bar	$1.30\n");
		printf("B  Brownie		$1.75\n");
		printf("N  Nuts			$1.40\n");
		printf("K  Keebler crackers	$1.00\n");
		printf("O  Oreo cookies		$1.50\n");

		printf("\nPlease enter the selection of your snack: ");
		scanf(" %c", selectionPtr);
}
void GetCost(char selection, double *item_costPtr)
{
	if (selection == 'p' || selection== 'P')
	{
		*item_costPtr = 1.25;
	}
	if (selection == 'c' || selection== 'C')
	{
		*item_costPtr = 1.30;
	}
	if (selection == 'b' || selection== 'B')
	{
		*item_costPtr = 1.75;
	}
	if (selection == 'n' || selection== 'N')
	{
		*item_costPtr = 1.40;
	}
	if (selection == 'k' || selection== 'K')
	{
		*item_costPtr = 1.00;
	}
	if (selection == 'o' || selection== 'O')
	{
		*item_costPtr = 1.50;
	}
}
void CoinMenu(double *purchasePtr)
{
	int select= 0;
	printf("\nPlease deposit your money by selection: \n");
    printf("1-$5.00\n");
    printf("2-$1.00\n");
    printf("3-$0.25\n");
    printf("4-$0.10\n");
    printf("5-$0.05\n");

	printf ("Select a number to make your deposit: ");
	//scanf (" %lf", *purchasePtr);
	scanf(" %d", &select);

	if(select == 1)
		*purchasePtr = *purchasePtr + 5.00;
	else if(select == 2)
		*purchasePtr = *purchasePtr + 1.00; 
	else if(select == 3)
		*purchasePtr = *purchasePtr + 0.25;
	else if(select == 4)
		*purchasePtr= *purchasePtr + 0.10;
	else if(select == 5)
		*purchasePtr= *purchasePtr + 0.05;
	else 
		printf("You have entered the worng value");
}
void GetMoney(double *purchasePtr, double item_cost, char selection)
{
	//loop to test if it is enough money
	//inside the loop call CoinMenu and Check money
	int enough = 0; //initialize for the loop

	while(enough==0) //loop test
	{
		//call coinMenu function
		CoinMenu(purchasePtr);
		enough = CheckMoney(purchasePtr, item_cost); //loop update step
	}

	//the return of check money is loop controller
}
//compares the amount the user has deposited to the price of item selected. 
//returns 1 if the amount is enough to cover the cost, 0 if there is not enough.
int CheckMoney(double *purchasePtr, double item_cost)
{
	if (*purchasePtr >= item_cost)//value at and the amount the user 
	//enters may be greater than the purchase price
	{
		return 1;
	}
	else 
	return 0;
}
void GetChange(double *purchasePtr, double item_cost, double *change)
{
	*change = *purchasePtr - item_cost;
}

/* Sample Output:
P  Potato Chips         $1.25
C  Chocolate bar        $1.30
B  Brownie              $1.75
N  Nuts                 $1.40
K  Keebler crackers     $1.00
O  Oreo cookies         $1.50

Please enter the selection of your snack: c

Please deposit your money by selection:
1-$5.00
2-$1.00
3-$0.25
4-$0.10
5-$0.05
Select a number to make your deposit: 1
-----------------------------------
Thanks you for your time!

Price of Item: c is $1.30

Money entered: $5.00

Dispensing Item: c

Dispensing Change 3.70

Would u like to make another selection (y or n):  n

 GODDBYE
Press any key to continue . . .
*/ 
/* pseudocode:
1. present the menu (printf)
2. ask user for selection (printf, scanf, if statements)
3. ask the user for money (printf, scanf, if else statements
4. make sure the money is the right amaount (while loop & if statement
5. dispense the food and change(if any) (math and printf)
6. ask user if they would like to purchase another snack (do/while loop & printf)
*/ 

