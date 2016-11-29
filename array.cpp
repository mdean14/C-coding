#include <iostream>
using namespace std;

//deletes all the repeats from array a[] and then returns 
//the new size with the spots used by the none repeating chars.
void delete_repeats(char a[], int& size);
//Searches array a[] for  the target, from 0 up to size.
//If it finds target then it returns true, other wise returns false.
bool find_char( char target, char a[], int size);

int main ()
{
	char a[81] = "mary had a little lamb. its fleece was white as snow.";
	int size = 53;

	cout << "Before size = " << size; 
	cout << "\n array = ";
	for(int i = 0; i<size; i++)
	{
		cout<< a[i];
	}

	cout << "\n";
	//end of the first array a[]

	delete_repeats(a, size);

	cout<< "After: size = " << size; 
	cout<< "\n array = ";
	for( int i = 0; i<size; i++)
	{
		cout<< a[i];
	}

	cout <<"\n";
	char b[81] = " ";
	int size2 = 53;

	cout << "Before size = " << size; 
	cout << "\n array = ";
	for(int i = 0; i<size2; i++)
	{
		cout<< b[i];
	}

	cout << "\n";

	delete_repeats(b, size);

	cout<< "After: size = " << size2; 
	cout<< "\n array = ";
	for( int i = 0; i<size2; i++)
	{
		cout<< b[i];
	}

	cout <<"\n";

	return 0;
}

//Searches array a[] for  the target, from 0 up to size.
//If it finds target then it returns true, other wise returns false.
bool find_char( char target, char a[], int size)
{
	for (int i = 0; i< size; i++)
	{
		if (a[i] == target)
			return true;
	}
	return false;
}

//deletes all the repeats from array a[] and then returns 
//the new size with the spots used by the none repeating chars.
void delete_repeats(char a[], int& positions_used)
{
	int new_size = 0;
	for (int i = 0; i<positions_used; i++)
	{
		if (!find_char(a[i], a, new_size))
		{
			a[new_size] = a[i];
			new_size ++;
		}
	}
	positions_used = new_size;
}

