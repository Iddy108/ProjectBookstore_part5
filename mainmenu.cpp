/*
 * Class: CMSC226
 * Instructor: Farnaz Eivaz
 * Description: This program displays a menu for the Serendipity Booksellers system, allowing users to choose between different modules.
 * Due: 03/23/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Samriddhi Agrawal
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"
#include "bookinfo.h"
using namespace std;

const int SIZE = 20;
const int TITLE_SIZE = 51; // Maximum title length +1 for null terminator
const int ISBN_SIZE = 14;  // ISBNs are typically 13 characters +1 for null terminator
const int NAME_SIZE = 31;  // Author and publisher names (adjustable)
const int DATE_SIZE = 11;  // Date format "MM/DD/YYYY" (10 characters +1 for null terminator)

char bookTitle[SIZE][TITLE_SIZE];  // Holds book titles
char isbn[SIZE][ISBN_SIZE];        // Holds ISBN numbers
char author[SIZE][NAME_SIZE];      // Holds author names
char publisher[SIZE][NAME_SIZE];   // Holds publisher names
char dateAdded[SIZE][DATE_SIZE];   // Holds the date each book was added
int qtyOnHand[SIZE];               // Quantity on hand
double wholesale[SIZE];            // Wholesale price
double retail[SIZE];               // Retail price

struct BookData {
	char bookTitle[51];
	char isbn[14];
	char author[31];
	char publisher[31];
	char dateAdded[11];
	int qtyOnHand;
	double wholesale;
	double retail;
};

int main() {
	int userTaskChoice;
	do{
		//header
		cout << "Serendipity Booksellers" << endl;
		cout << setw(15) << "Main Menu"<<endl;
		cout << endl;
		// Display menu options
		cout << "1. Cashier Module\n2. Inventory Database Module\n";
		cout << "3. Report Module\n4. Exit \n";
		cout << endl;
		//prompt user input
		cout << "Enter Your Choice: ";
		cin >> userTaskChoice;
		cout << endl;

		while (userTaskChoice > 4 || userTaskChoice < 1) {
			cout << "Please enter a number in the range 1-4. ";
			cin >> userTaskChoice;
		} 
		switch (userTaskChoice) {
		case 1:
			cashier();
			break;
		case 2:
			invMenu();
			break;
		case 3:
			reports();
			break;
		case 4:
			cout << "You selected item 4. ";
			break;
		}
		cout << endl;
	} while (userTaskChoice != 4);
	cout << endl;
	system("pause");
	return 0;
}

