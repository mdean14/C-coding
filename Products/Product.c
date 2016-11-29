/* Matthew Dean
 * COP2220 Intro to Programming in C
 * Spring 2010
 * Menu program that allows different things to happen. And structs 
 */

#define _CRT_SECURE_NO_DEPRECATE

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define SIZE 20

typedef struct{
int id;
char name[SIZE];
double price;
}game;

//Function Prototypes
char GetChoice(void);
//Fills the first five slots with games
void FillFive(game list[SIZE], int *num);
//Saves program to a file
void SaveToFile(game list[SIZE], int *num, FILE *infileptr);
//Displays the list of games
void PrintList(game list[SIZE], int *num);
//Adds a game to the list
void Add_Item(game list[SIZE], int *num);
//Clears ALL records
void Clear_records(int *num);
//Deletes a game from the list
void Delete_Game(game list[SIZE], int *num);

int main( )
{
	game list[SIZE];
	int num=0;
	char choice= ' ';
	
	FILE *infileptr;//declare file pointer

	FillFive(list, &num);

	infileptr = fopen("out.txt","w");//connect to file(creates a file)

	do{
		choice = GetChoice();//gets menu choice

		if(choice == 'a' || choice == 'A')
			Add_Item(list, &num);
		else if(choice == 'd' || choice == 'D')
			Delete_Game(list, &num);
		else if(choice == 'p' || choice == 'P')
			PrintList(list, &num);
		else if(choice == 's' || choice == 'S')
			SaveToFile(list, &num, infileptr);
		else if(choice == 'c' || choice == 'C')
			Clear_records(&num);
		else if(choice == 'q' || choice == 'Q')
			printf("\nchoice was Q - you are going to QUIT\n");
		else printf("\nChoice not recognized\n");
	}while(choice !='q' && choice !='Q');



	
	return 0;
}
char GetChoice(void)
{
	char choice;
	printf("\n\nA....Add a new game to inventory");
	printf("\nD....Delete a game from the inventory list");
	printf("\nP....Displays the products");
	printf("\nS....Save to a File");
	printf("\nC....Clear all records");
	printf("\nQ...Quit");
	printf("\nENTER SELETION:  ");
	scanf(" %c", &choice);
	printf("\n");
	return choice;
}

void FillFive(game list[], int *num)
{   
	list[*num].id= 101;
	list[*num].price= 59.99;
	strcpy(list[*num].name, "Modern Warfare 2");
	*num= *num+1;
	list[*num].id= 201;
	list[*num].price= 49.99;
	strcpy(list[*num].name, "Street Fighter 4");
	*num= *num+1;
	list[*num].id= 301;
	list[*num].price= 69.99;
	strcpy(list[*num].name, "Madden 2011     ");
	*num= *num+1;
	list[*num].id= 401;
	list[*num].price= 59.99;
	strcpy(list[*num].name, "God of War 3    ");
	*num= *num+1;
	list[*num].id= 501;
	list[*num].price= 59.99;
	strcpy(list[*num].name, "Dante's Inferno ");
	*num= *num+1;
}
void PrintList(game list[], int *num)
{
	int i;
	printf("Id\tName\t\t\tPrice");
	for(i=0;i<*num;i++)
	{
		printf("\n%d", list[i].id);
		printf("\t%s", list[i].name);
		printf("\t%.2f", list[i].price);

	}
}
void Add_Item(game list[SIZE], int *num)
{
	printf("\nPlease enter the id of the game: ");
	scanf("%d", &list[*num].id);
	printf("\nPlease enter the name of the game: ");
	scanf("%s", list[*num].name);
	printf("\nPlease enter the price of the game: ");
	scanf("%lf", &list[*num].price);
	*num= *num+1;
}
void Clear_records(int *num)
{
	*num=0;
}
void Delete_Game(game list[SIZE], int *num)
{
	int target;
	int i;
	for(i=0;i<*num;i++)
	{
		printf("\n%d", list[i].id);
		printf("\t%s", list[i].name);
	}
	printf("\nWhich game would u like to delete? Enter the id: ");
	scanf("%d", &target);
	for (i=0;i<*num;i++)
	{
		if (target == list[i].id)
		{
			list[i] = list[*num - 1];
			*num= *num - 1;
		}
	}
}
void SaveToFile(game list[SIZE], int *num, FILE *infileptr)
{
	int i;
	printf("Id\tName\t\t\tPrice");
	for(i=0;i<*num;i++)
	{
		fprintf(infileptr ,"\n%d", list[i].id);
		fprintf(infileptr ,"\t%s", list[i].name);
		fprintf(infileptr ,"\t%.2f", list[i].price);

	}
}
/* OutPut:
A....Add a new game to inventory
D....Delete a game from the inventory list
P....Displays the products
S....Save to a File
C....Clear all records
Q...Quit
ENTER SELETION:  p
Id      Name                    Price
101     Modern Warfare 2        59.99
201     Street Fighter 4        49.99
301     Madden 2011             69.99
401     God of War 3            59.99
501     Dante's Inferno         59.99
A....Add a new game to inventory
D....Delete a game from the inventory list
P....Displays the products
S....Save to a File
C....Clear all records
Q...Quit
ENTER SELETION:  q
choice was Q - you are going to QUIT
Press any key to continue . . .
*/
