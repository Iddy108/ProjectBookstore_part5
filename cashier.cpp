/*
 * Class: CMSC226
 * Instructor: Farnaz Eivaz
 * Description: This program collects book sale details and prints a formatted receipt.
 * Due: 03/12/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Samriddhi Agrawal
*/
#include "cashier.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE = 20;
const int TITLE_SIZE = 51; // Maximum title length +1 for null terminator
const int ISBN_SIZE = 14;  // ISBNs are typically 13 characters +1 for null terminator

extern char bookTitle[SIZE][TITLE_SIZE];   // Array to hold book titles
extern char isbn[SIZE][ISBN_SIZE];         // Array to hold ISBN numbers
extern int qtyOnHand[SIZE];          // Array to hold the quantity on hand of each book
extern double retail[SIZE];

// Function for the cashier module to process sales and generate a receipt
int cashier() {
	const double TAX_RATE = 0.06;
	int* qtyPtr = qtyOnHand;
	string date, title;
	char isbnOfBook[15];
	int quantity, bookIndex = -1;
	double price, subtotal = 0, bookSubtotal, tax, total;
	char shopAgain, moreBooks, tryAgain;
	bool isbnFound = false;

	do {
		cout << "Serendipity Booksellers" << endl;
		cout << " Cashier Module" << endl;
		cout << endl;

		// User Input
		cout << "Date: ";
		cin >> date;
		cin.ignore();

		do {
			//Ask for IBSN
			do{ 
				cout << "Enter the ISBN of the book you would like to purchase: ";
				cin.getline(isbnOfBook, 15);
				cin.ignore();

				//Search for ISBN in the isbn array
				for (int i = 0; i < SIZE; i++) {
					if (isbn[i]== isbnOfBook) {
						bookIndex = i; //Found the book, store index
						isbnFound = true;
						break;
					}
				}

				// If no match is foundd, book is not in inventory
				if (!isbnFound) {
					cout << "The book you searched for is not in inventory. Do you want to input a different and valid isbn? (y/n)\n";
					cin >> tryAgain;
					cout << endl;
					if (tryAgain == 'n' || tryAgain == 'N') {
						return 0; // Exit the function if the user doesn't want to try again
					}
				}
			} while (!isbnFound); // Loop until the ISBN is found

			// Once ISBN is found, get book title and price from arrays
            title = bookTitle[bookIndex];
            price = retail[bookIndex];

			// Ask for quantity of books being purchased
			cout << "Quantity: ";
			cin >> quantity;
			cin.ignore();

			// Check if enough books are in stock using the pointer (qtyPtr)
			if (*(qtyPtr + bookIndex) >= quantity) { // Using pointer to access stock
				*(qtyPtr + bookIndex) -= quantity;  // Subtract from stock using pointer

				bookSubtotal = price * quantity;
				subtotal += bookSubtotal;

				// Ask if the user wants to add another book
				cout << "Would you like to enter another book? (y/n): ";
				cin >> moreBooks;
				cin.ignore();
				cout << endl;
			}
			else {
				cout << "Sorry, there are not enough copies of \"" << title << "\" in stock." << endl;
				return (0); // Return to main menu if there's not enough stock
			}

			// Price calculations
			tax = TAX_RATE * subtotal;
			total = subtotal + tax;

			// Receipt header
			cout << "Serendipity Book Sellers\n" << endl;
			cout << "Date: " << date << endl;
			cout << endl;
			//Column header
			cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tSubtotal" << endl;
			for (int i = 0; i < 83; i++) {
				cout << "_";
			}

			// Data Info of Book
			cout << endl;
			cout << left << setw(6) << quantity
				<< setw(14) << isbnOfBook
				<< setw(24) << title
				<< right << fixed << setprecision(2)
				<< setw(7) << "$" << price
				<< setw(7) << "$" << subtotal << endl;
			cout << endl << endl;
		} while (moreBooks == 'y' || moreBooks == 'Y');

		//Summary 
		cout << setw(24) << "Subtotal" << setw(7) << "$ " << subtotal << endl;
		cout << setw(19) << "Tax" << setw(12) << "$ " << tax << endl;
		cout << setw(21) << "Total" << setw(10) << "$ " << total << endl;

		cout << endl;
		cout << "Thank You for Shopping at Serendipity!\n";
		cout << "Would you like to shop again? If yes, please type 'y' or 'Y': ";
		cin >> shopAgain;
		cout << endl;
	} while (shopAgain == 'y' || shopAgain == 'Y');

	cin.ignore();
	return 0;
}