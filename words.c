//Assignment 4
//Matthew Dean
//program that reads a word for the user and makes it plural

#define SIZE 15

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>//string library fuinctions
#include <ctype.h>
//Gets a word from the user
void GetWord(char word[]);
//Test the word to see if its upper case or lower case
void Upper_lowerTest(char word[], int length);
//test the lower case ending of the word to see how to make it plural
void Rule(char word[], int length);
//test the upper case ending of the word to see how to make it plural
void RulesCaps(char word[], int length);
void Output(char word[], int length);
//Asks the user if they want to enter another word
void Quit(char *cptr);

int main( )
{
	char word1[SIZE]=""; //initializes an empty string (NO SPACE BETWEEN QUOTES)
	int length;
	char choice =' ';

	do{
	FILE * outptr;//declare file pointer
	outptr= fopen("out.txt","w");//connect to file(creates a file)

	GetWord(word1);
	length= strlen(word1);

	printf("\nThe word entered was %s\n", word1);
	fprintf(outptr, "\nThe word entered was %s\n", word1);//print the word in the file

	Upper_lowerTest(word1, length);
	fprintf(outptr, "\nThe plural form of the word entered is %s\n", word1);
	Output(word1, length);
	
	Quit(&choice);//yes or no to quit choice
	}while(choice!='n'&& choice!='N');
	return 0;
}
//gets a word from the user
void GetWord(char word1[])
{
	printf("\nPlease enter a word: ");
	scanf("%s", word1);
}
//test to figure out whether upper or lower
void Upper_lowerTest(char word1[], int length)
{
	if (isupper(word1[0]))
	{
		RulesCaps(word1, length);
	}
	else 
	{
		Rule(word1, length);
	}
}
//lower case words
void Rule(char word1[], int length)
{
	if (word1[length-2]== 'c' && word1[length-1]== 'h')
	{
		strcat(word1 , "es");
	}
	else if (word1[length-2]== 's' && word1[length-1]== 'h')
	{
		strcat(word1 , "es");
	}
	else if (word1[length-1]== 'y')
	{
		word1[length-1]= '\0';
		strcat(word1 , "ies");
	}
	else
	{
		strcat(word1, "s");
	}
}
//capital letter words
void RulesCaps(char word1[], int length)
{
	if (word1[length-2]== 'C' && word1[length-1]== 'H')
	{
		strcat(word1 , "ES");
	}
	else if (word1[length-2]== 'S' && word1[length-1]== 'H')
	{
		strcat(word1 , "ES");
	}
	else if (word1[length-1]== 'Y')
	{
		word1[length-1]= '\0';
		strcat(word1 , "IES");
	}
	else
	{
		strcat(word1, "S");
	}
}
//Asks the user if they want to enter another word
void Output(char word1[], int length)
{
	printf("\nYour word has %d letters\n", length);
	printf("\nThe plural form of the word entered is %s\n", word1);
}
void Quit(char *cptr)
{
	//char selection;
	printf("\nWould you like to enter anther word (y or n):\n  ");
	scanf(" %c", cptr);
	//return selection;
}
/*
do{
1. gets the word from the user
2. saves the singular word to a file
3. tests the word to see if its upper or lower case
4. once it determines upper or lower it sends 
it to the rules
5. Rules determine what to add to the end(ex. ies, es, or s)
6. save the plural word to the file
7. prints the plural word to the screen
8. asks the user if they want to enter another word
}while the user enters words
Please enter a word: bunny
The word entered was bunny
Your word has 5 letters
The plural form of the word entered is bunnies
Would you like to enter anther word (y or n):
  y
Please enter a word: WASH
The word entered was WASH
Your word has 4 letters
The plural form of the word entered is WASHES
Would you like to enter anther word (y or n):
  Y
Please enter a word: CATCH
The word entered was CATCH
Your word has 5 letters
The plural form of the word entered is CATCHES
Would you like to enter anther word (y or n):
  N
Press any key to continue . . .
*/
