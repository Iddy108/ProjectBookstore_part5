/*
 * Class: CMSC226
 * Instructor: Farnaz Eivaz
 * Description: This program displays the Reports menu for Serendipity Booksellers,
 presenting various reporting options.
 * Due: 03/12/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Samriddhi Agrawal
*/
#include "reports.h"
#include <iostream>
#include<iomanip>
#include <cstring>
using namespace std;

const int SIZE = 20;
extern int bookCount;  // Declare idPtr as extern to use the global pointer
const int TITLE_SIZE = 51; // Maximum title length +1 for null terminator
const int ISBN_SIZE = 14;  // ISBNs are typically 13 characters +1 for null terminator
const int NAME_SIZE = 31;  // Author and publisher names (adjustable)
const int DATE_SIZE = 11;  // Date format "MM/DD/YYYY" (10 characters +1 for null terminator)

extern char bookTitle[SIZE][TITLE_SIZE];  // Holds book titles
extern char isbn[SIZE][ISBN_SIZE];        // Holds ISBN numbers
extern char author[SIZE][NAME_SIZE];      // Holds author names
extern char publisher[SIZE][NAME_SIZE];   // Holds publisher names
extern char dateAdded[SIZE][DATE_SIZE];   // Holds the date each book was added
extern int qtyOnHand[SIZE];               // Quantity on hand
extern double wholesale[SIZE];            // Wholesale price
extern double retail[SIZE];               // Retail price


/*
void strUpper(char* str) {
	while (*str != '\0') {  // Loop until null terminator
		*str = toupper(*str);  // Convert character to uppercase
		str++;  // Move to the next character
	}
}
*/
// Function to display a report listing all books with detailed information
void repListing() {
	char anyKey;
	// Loop through all books and print their information
	for (int i = 0; i < bookCount; i++) {
		cout << "Data for book " << bookTitle[i] << " added on " << dateAdded[i] << ": \n";
		cout << "ISBN: " << isbn[i] << endl;
		cout << "Title: " << bookTitle[i] << endl;
		cout << "Author: " << author[i] << endl;
		cout << "Publisher: " << publisher[i] << endl;
		cout << "Date Added: " << dateAdded[i] << endl;
		cout << "Quantity-On-hand: " << qtyOnHand[i] << endl;
		cout << "Wholesale Cost:" << wholesale[i] << endl;
		cout << "Retail Price: " << retail[i] << endl;
		cout << endl;
	}
	cin.ignore();

	// Wait for the user to press any key to continue
	cout << "Press any key to continue:";
	cin.get(anyKey);
	cout << endl;
}

// Function to display a report listing the wholesale cost of books
void repWholesale() {
	char anyKey;
	// Loop through all books and print their wholesale information
	for (int i = 0; i < bookCount; i++) {
		cout << "Data for book " << bookTitle[i] << " added on " << dateAdded[i] << ": \n";
		cout << "ISBN: " << isbn[i] << endl;
		cout << "Title: " << bookTitle[i] << endl;
		cout << "Quantity-On-hand: " << qtyOnHand[i] << endl;
		cout << "Wholesale Cost:" << wholesale[i] << endl;
		cout << endl;
	}
	cin.ignore();

	// Wait for the user to press any key to continue
	cout << "Press any key to continue:";
	cin.get(anyKey);
	cout << endl;
}

// Function to display a report listing the retail price of books
void repRetail() {
	char anyKey;

	// Loop through all books and print their retail information
	for (int i = 0; i < bookCount; i++) {
		cout << "Data for book " << bookTitle[i] << " added on " << dateAdded[i] << ": \n";
		cout << "ISBN: " << isbn[i] << endl;
		cout << "Title: " << bookTitle[i] << endl;
		cout << "Quantity-On-hand: " << qtyOnHand[i] << endl;
		cout << "Retail Price: " << retail[i] << endl;
		cout << endl;
	}
	cin.ignore();

	// Wait for the user to press any key to continue
	cout << "Press any key to continue:";
	cin.get(anyKey);
	cout << endl;
}

// Function to display a report listing books sorted by quantity on hand (descending order)
void repQty() {
	char anyKey;

	char tempBookTitle[SIZE][TITLE_SIZE];  // Holds book titles
	char tempIsbn[SIZE][ISBN_SIZE];        // Holds ISBN numbers
	char tempDateAdded[SIZE][DATE_SIZE];   // Holds the date each book was added
	int tempQtyOnHand[SIZE];               // Quantity on hand
	
	//copy to temp variabled
	for (int i = 0; i < SIZE; i++) {
		tempQtyOnHand[i] = qtyOnHand[i];
		strcpy_s(tempBookTitle[i],bookTitle[i]);
		strcpy_s(tempIsbn[i], isbn[i]);
		strcpy_s(tempDateAdded[i], dateAdded[i]);
	}


	//sort temp varibles
	for (int i = 0; i < bookCount - 1; i++) {
		for (int j = i + 1; j < bookCount - 1; j++) {
			if (tempQtyOnHand[i] > tempQtyOnHand[j]) {
				int holderQty = tempQtyOnHand[i];
				char* holderTitle = tempBookTitle[i];
				char* holderIsbn = tempIsbn[i];
				char* holderDate = tempDateAdded[i];

				tempQtyOnHand[i] = tempQtyOnHand[j];
				tempQtyOnHand[j] = holderQty;

				strcpy_s(tempBookTitle[i], tempBookTitle[j]);
				strcpy_s(tempBookTitle[j], holderTitle);

				strcpy_s(tempIsbn[i], tempIsbn[j]);
				strcpy_s(tempIsbn[j], holderIsbn);

				strcpy_s(tempDateAdded[i], tempDateAdded[j]);
				strcpy_s(tempDateAdded[j], holderDate);
			}

		}
	}


	// Loop to display the sorted list by quantity
	for (int i = 0; i < bookCount; i++) {
		cout << "Data for book " << tempBookTitle[i]<< " added on " << tempDateAdded[i]<< ": \n";
		cout << "Quantity-On-Hand: "<< tempQtyOnHand[i] <<endl;
		cout << "Title: " << tempBookTitle[i]<<endl;
		cout << "ISBN: "<< tempIsbn[i] <<endl;
		cout << endl;
	}
	cin.ignore();

	// Wait for the user to press any key to continue
	cout << "Press any key to continue:";
	cin.get(anyKey);
	cout << endl;
}
void repCost() {
	char anyKey;
	
	char tempBookTitle[SIZE][TITLE_SIZE];  // Holds book titles
	char tempIsbn[SIZE][ISBN_SIZE];        // Holds ISBN numbers
	char tempDateAdded[SIZE][DATE_SIZE];   // Holds the date each book was added
	int tempQtyOnHand[SIZE];               // Quantity on hand
	double tempWholesale[SIZE];           // Quantity on hand


	//copy to temp variabled
	for (int i = 0; i < SIZE; i++) {
		tempWholesale[i] = wholesale[i];
		tempQtyOnHand[i] = qtyOnHand[i];

		strcpy_s(tempBookTitle[i], bookTitle[i]);
		strcpy_s(tempIsbn[i], isbn[i]);
		strcpy_s(tempDateAdded[i], dateAdded[i]);
	}

	//sort temp varibles
	for (int i = 0; i < bookCount - 1; i++) {
		for (int j = i + 1; j < bookCount - 1; j++) {
			if (tempWholesale[i] > tempWholesale[j]) {

				double holderWholesale = tempWholesale[i];
				int holderQty = tempQtyOnHand[i];
				char* holderTitle = tempBookTitle[i];
				char* holderIsbn = tempIsbn[i];
				char* holderDate = tempDateAdded[i];

				tempWholesale[i] = tempWholesale[j];
				tempWholesale[j] = holderWholesale;

				tempQtyOnHand[i] = tempQtyOnHand[j];
				tempQtyOnHand[j] = holderQty;

				strcpy_s(tempBookTitle[i], tempBookTitle[j]);
				strcpy_s(tempBookTitle[j], holderTitle);

				strcpy_s(tempIsbn[i], tempIsbn[j]);
				strcpy_s(tempIsbn[j], holderIsbn);

				strcpy_s(tempDateAdded[i], tempDateAdded[j]);
				strcpy_s(tempDateAdded[j], holderDate);
			}
		}
	}

	// Loop to display the sorted list by quantity
	for (int i = 0; i < bookCount; i++) {
		cout << "Data for book " << tempBookTitle[i] << " added on " << tempDateAdded[i] << ": \n";
		cout << "Wholesale Cost: " << tempWholesale[i] << endl;
		cout << "Quantity-On-Hand: " << tempQtyOnHand[i] << endl;
		cout << "Title: " << tempBookTitle[i] << endl;
		cout << "ISBN: " << tempIsbn[i] << endl;
		cout << endl;
	}

	cin.ignore();

	// Wait for the user to press any key to continue
	cout << "Press any key to continue:";
	cin.get(anyKey);
	cout << endl;
}
void repAge() {
	char anyKey;

	char tempBookTitle[SIZE][TITLE_SIZE];  // Holds book titles
	char tempIsbn[SIZE][ISBN_SIZE];        // Holds ISBN numbers
	char tempDateAdded[SIZE][DATE_SIZE];   // Holds the date each book was added
	int tempQtyOnHand[SIZE];               // Quantity on hand


	//copy to temp variabled
	for (int i = 0; i < SIZE; i++) {
		tempQtyOnHand[i] = qtyOnHand[i];

		strcpy_s(tempDateAdded[i], dateAdded[i]);
		strcpy_s(tempBookTitle[i], bookTitle[i]);
		strcpy_s(tempIsbn[i], isbn[i]);
	}

	//sort temp varibles
	for (int i = 0; i < bookCount - 1; i++) {
		for (int j = i + 1; j < bookCount - 1; j++) {
			if (tempDateAdded[i] > tempDateAdded[j]) {

				char* holderDate = tempDateAdded[i];
				int holderQty = tempQtyOnHand[i];
				char* holderTitle = tempBookTitle[i];
				char* holderIsbn = tempIsbn[i];

				tempQtyOnHand[i] = tempQtyOnHand[j];
				tempQtyOnHand[j] = holderQty;


				strcpy_s(tempDateAdded[i], tempDateAdded[j]);
				strcpy_s(tempDateAdded[j], holderDate);

				strcpy_s(tempBookTitle[i], tempBookTitle[j]);
				strcpy_s(tempBookTitle[j], holderTitle);

				strcpy_s(tempIsbn[i], tempIsbn[j]);
				strcpy_s(tempIsbn[j], holderIsbn);

			}
		}
	}

	// Loop to display the sorted list by quantity
	for (int i = 0; i < bookCount; i++) {
		cout << "Data for book " << tempBookTitle[i] << " added on " << tempDateAdded[i] << ": \n";
		cout << "Date: " << tempDateAdded[i] << endl;
		cout << "Quantity-On-Hand: " << tempQtyOnHand[i] << endl;
		cout << "Title: " << tempBookTitle[i] << endl;
		cout << "ISBN: " << tempIsbn[i] << endl;
		cout << endl;
	}
	cin.ignore();

	// Wait for the user to press any key to continue
	cout << "Press any key to continue:";
	cin.get(anyKey);
	cout << endl;
}

int reports() {
	int userTaskChoice;
	do {
		//header
		cout << "Serendipity Booksellers" << endl;
		cout << setw(13) << "Reports" << endl;
		cout << endl;
		// Display menu options
		cout << "1. Inventory Listing" << endl;
		cout << "2. Inventory Wholesale Value\n";
		cout << "3. Inventory Retail Value\n";
		cout << "4. Listing by Quantity\n";
		cout << "5. Listing by Cost\n";
		cout << "6. Listing by Age\n";
		cout << "7. Return to Main Menu\n" << endl;
		do {
			cout << "Enter Your Choice: ";
			cin >> userTaskChoice;
			cout << endl;
			if (userTaskChoice > 7 || userTaskChoice < 1) {
				cout << "Please enter a number in the range 1-7.\n";
			}
		} while (userTaskChoice > 7 || userTaskChoice < 1);

		switch (userTaskChoice) {
		case 1:
			repListing();
			break;
		case 2:
			repWholesale();
			break;
		case 3:
			repRetail();
			break;
		case 4:
			repQty();
			break;
		case 5:
			repCost();
			break;
		case 6:
			repAge();
			break;
		case 7:
			cout << "You selected item 7. \n" << endl;
			break;
		}
		cout << endl;
	} while (userTaskChoice != 7);


	return 0;
}