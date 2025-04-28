/*
 * Class: CMSC226
 * Instructor: Farnaz Eivaz
 * Description: This program displays the Inventory Database menu for Serendipity Booksellers.
 *              It allows the user to choose from different inventory-related options.
 * Due: 03/12/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Samriddhi Agrawal
*/
#include "invmenu.h"
#include "bookinfo.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int SIZE = 20;
int bookCount;  
const int TITLE_SIZE = 51; // Maximum title length +1 for null terminator
const int ISBN_SIZE = 14;  // ISBNs are typically 13 characters +1 for null terminator
const int NAME_SIZE = 31;  // Author and publisher names (adjustable)
const int DATE_SIZE = 11;  // Date format "MM/DD/YYYY" (10 characters +1 for null terminator)

extern char bookTitle[SIZE][TITLE_SIZE];   // Array to hold book titles
extern char isbn[SIZE][ISBN_SIZE];         // Array to hold ISBN numbers
extern char author[SIZE][NAME_SIZE];       // Array to hold author names
extern char publisher[SIZE][NAME_SIZE];    // Array to hold publisher names
extern char dateAdded[SIZE][DATE_SIZE];    // Array to hold date added
extern int qtyOnHand[SIZE];                // Array to hold quantity on hand
extern double wholesale[SIZE];             // Array to hold wholesale price
extern double retail[SIZE];                // Array to hold retail price

void strUpper(char* str) {
	for (int i = 0; i < strlen(str); i++) {
		str[i] = toupper(str[i]);
	}
}

void loopUpBook() {
	int i = 0;
	char userSearchBook[TITLE_SIZE];  // Declare as a C-style string
	char userResponse;
	bool found = false; // Track if at least one match is found

	cin.ignore();
	cout << "Enter part of the book title to search for: ";
	cin.getline(userSearchBook, TITLE_SIZE);  // using C-style input 

	while (i < SIZE) {
		// Compare bookTitle[i] with userSearchBook using strstr
		if (strstr(bookTitle[i], userSearchBook) != nullptr) {
			found = true; // At least one match found
			cout << "Is this the book you are looking for? (Y/N): " << bookTitle[i] << endl;
			cin >> userResponse;
			cin.ignore(); // Clear leftover newline

			if (userResponse == 'Y' || userResponse == 'y') {
				bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i]);
				return; // Stop searching once user confirms
			}
		}
		i++; // Move to the next book
	}

	// If no match was found at all
	if (!found) {
		cout << "The book you searched for is not in inventory.\n" << endl;
	}

}
void addBook() {
	int i = 0;
	while (i<SIZE && bookTitle[i][0] != '\0') {
		i++;
	}
	if ( i== SIZE) {  // If no empty slot is found, inventory is full
		cout << "No more books may be added to the inventory. The array is full." << endl;
		return;
	}
	 
	cin.ignore(); // Clears leftover newline from previous input
	cout << "Enter Title: ";
	cin.getline(bookTitle[i], TITLE_SIZE);
	strUpper(bookTitle[i]);  // Convert title to uppercase

	cout << "Enter ISBN(#-###-#####-#): ";
	cin.getline(isbn[i], ISBN_SIZE);
	strUpper(isbn[i]);  // Convert ISBN to uppercase

	cout << "Enter Author: ";
	cin.getline(author[i], NAME_SIZE);
	strUpper(author[i]);  // Convert author to uppercase

	cout << "Enter Publisher: ";
	cin.getline(publisher[i], NAME_SIZE);
	strUpper(publisher[i]);  // Convert publisher to uppercase

	cout << "Enter Date Added to Inventory (MM/DD/YY): ";
	cin >> dateAdded[i];
	cout << "Enter Quantity Being Added: ";
	cin >> qtyOnHand[i];
	cout << "Enter Wholesale Cost: ";
	cin >> wholesale[i];
	cout << "Enter Retail Price: ";
	cin >> retail[i];
	cout << endl;
	cout << "\nRecord was successfully entered.\n" << endl;
	
	bookCount++;  // Increment bookCount to track the number of books added
}
void editBook() {
	int i = 0;
	int userEditChoice;
	char userSearchBook[TITLE_SIZE];  // For partial book title input
	char changedValueStr[NAME_SIZE];  // Temporary array for user input
	bool found = false;
	char userResponse;


	cin.ignore();// Clear leftover newline from previous cin
	cout << "Enter the title of the book to edit: ";
	cin.getline(userSearchBook, TITLE_SIZE);  // Get partial title input from user

	while (i < SIZE) {
		// Check if the partial title is found in the current book title using strstr
		if (strstr(bookTitle[i], userSearchBook) != nullptr) {
			found = true;  // Match found

			cout << "\nMatching Book Found: " << bookTitle[i] << endl;
			cout << "Is this the book you are looking for? (Y/N): ";
			cin >> userResponse;
			cin.ignore();  // Clear leftover newline

			if (userResponse == 'Y' || userResponse == 'y') {
				// If the user confirms, allow them to edit the book details
				do {
					// Display edit menu
					cout << "\nYou may edit any of the following fields: " << endl;
					cout << "1. ISBN " << endl;
					cout << "2. Title: " << endl;
					cout << "3. Author: " << endl;
					cout << "4. Publisher: " << endl;
					cout << "5. Date Added: " << endl;
					cout << "6. Quantity On Hand: " << endl;
					cout << "7. Wholesale Cost: " << endl;
					cout << "8. Retail Price: " << endl;
					cout << "9. Exit: " << endl;

					cout << "\nEnter Your Choice: ";
					cin >> userEditChoice;
					cin.ignore();  // Clear leftover newline

					switch (userEditChoice) {
					case 1:
						cout << "Current ISBN: " << isbn[i] << endl;
						cout << "Enter new ISBN: ";
						cin.getline(changedValueStr, NAME_SIZE);
						strUpper(changedValueStr);  // Convert to uppercase
						strcpy_s(isbn[i], ISBN_SIZE, changedValueStr); // Update ISBN
						break;
					case 2:
						cout << "Current Title: " << bookTitle[i] << endl;
						cout << "Enter new Title: ";
						cin.getline(changedValueStr, TITLE_SIZE);
						strUpper(changedValueStr);  // Convert to uppercase
						strcpy_s(bookTitle[i], TITLE_SIZE, changedValueStr);  // Update Title
						break;
					case 3:
						cout << "Current Author: " << author[i] << endl;
						cout << "Enter new Author: ";
						cin.getline(changedValueStr, NAME_SIZE);
						strUpper(changedValueStr);  // Convert to uppercase
						strcpy_s(author[i], NAME_SIZE, changedValueStr);  // Update Author
						break;
					case 4:
						cout << "Current Publisher: " << publisher[i] << endl;
						cout << "Enter new Publisher: ";
						cin.getline(changedValueStr, NAME_SIZE);
						strUpper(changedValueStr);  // Convert to uppercase
						strcpy_s(publisher[i], NAME_SIZE, changedValueStr);  // Update Publisher
						break;
					case 5:
						cout << "Current Date Added: " << dateAdded[i] << endl;
						cout << "Enter new Date(MM/DD/YYYY): ";
						cin.getline(changedValueStr, DATE_SIZE);
						strcpy_s(dateAdded[i], DATE_SIZE, changedValueStr);  // Update Date Added
						break;
					case 6:
						cout << "Current Quantity on Hand: " << qtyOnHand[i] << endl;
						cout << "Enter new Quantity on Hand: ";
						cin >> qtyOnHand[i];
						break;
					case 7:
						cout << "Current Wholesale Cost: " << wholesale[i] << endl;
						cout << "Enter new Wholesale Cost: ";
						cin >> wholesale[i];
						break;
					case 8:
						cout << "Current Retail Price: " << retail[i] << endl;
						cout << "Enter new Retail Price: ";
						cin >> retail[i];
						break;
					default:
						cout << "Invalid choice. Please try again.\n";
						break;
					}
				} while (userEditChoice != 9);  // Exit the edit menu
				return;  // Stop further searching once the book is edited
			}
		}
		i++;  // Move to the next book
	}

	// If no match was found at all
	if (!found) {
		cout << "No book matches your search.\n" << endl;
	}
}

void deleteBook() {
	int i = 0;
	char userSearchBook[TITLE_SIZE];  // For partial book title input
	char confirmDeletion;

	cin.ignore();  // Clear leftover newline from previous input
	cout << "Enter part of the title of the book to delete: ";
	cin.getline(userSearchBook, TITLE_SIZE);  // Get partial title input from user

	bool found = false;  // Track if we find at least one matching book

	while (i < SIZE) {
		// Check if the partial title is found in the current book title using strstr
		if (strstr(bookTitle[i], userSearchBook) != nullptr) {
			found = true;  // Match found

			cout << "\nMatching Book Found: " << bookTitle[i] << endl;
			cout << "Is this the book you want to delete? (Y/N): ";
			cin >> confirmDeletion;
			cin.ignore();  // Clear leftover newline

			if (confirmDeletion == 'Y' || confirmDeletion == 'y') {
				// If the user confirms, delete the book
				bookInfo(isbn[i], bookTitle[i], author[i], publisher[i],
					dateAdded[i], qtyOnHand[i], wholesale[i], retail[i]);
				cout << "\nAre you sure you want to delete this book? (Y/N): ";
				cin >> confirmDeletion;

				if (confirmDeletion == 'Y' || confirmDeletion == 'y') {
					// Set the book's title and ISBN to empty strings
					bookTitle[i][0] = '\0';  // Clear title
					isbn[i][0] = '\0';  // Clear ISBN

					cout << "The book has been deleted." << endl << endl;
					return;  // Stop searching once the book is deleted
				}
			}
		}
		i++;  // Move to the next book
	}

	// If no match was found at all
	if (!found) {
		cout << "No book matches your search.\n" << endl;
	}
}

int invMenu() {
	int userTaskChoice;
	do {
		//header
		cout << "Serendipity Booksellers" << endl;
		cout << "  Inventory Database" << endl;
		cout << endl;
		// Display menu options
		cout << "1. LookUp a Book\n2. Add a Book\n";
		cout << "3. Edit a Book's Record\n4. Delete a Book \n";
		cout << "5. Return to the Main Menu\n";
		cout << endl;
		//prompt user input
		do {
			cout << "Enter Your Choice: ";
			cin >> userTaskChoice;
			if (userTaskChoice > 5 || userTaskChoice < 1) {
				cout << "\nPlease enter a number in the range 1-5.\n";
			}
		} while (userTaskChoice > 5 || userTaskChoice < 1);

		switch (userTaskChoice) {
		case 1:
			loopUpBook();
			break;
		case 2:
			addBook();
			break;
		case 3:
			editBook();
			break;
		case 4:
			deleteBook();
			break;
		case 5:
			cout << "You selected item 5. \n" << endl;
			break;
		}

	} while (userTaskChoice != 5);

	cout << endl;
	return 0;
}
