/*
 * Class: CMSC226
 * Instructor: Farnaz Eivaz
 * Description: This program displays the Book Information section for Serendipity Booksellers.
 *              It details information about the book.
 * Due: 03/12/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Samriddhi Agrawal
*/
#include <iostream>
#include "bookinfo.h"


void bookInfo(char isbn[14], char title[51], char author[31],
	 char publisher[31], char date[11], int qtyOnHand,
	double wholesale, double retail) {
	//header
	cout << "Serendipity Booksellers" << endl;
	cout << "Book Information" << endl;
	cout << endl;
	// Display menu options
	cout << "ISBN: " << isbn<< endl;
	cout << "Title: "<<title<<endl;
	cout << "Author: "<<author<<endl;
	cout << "Publisher: "<<publisher<<endl;
	cout << "Date Added: "<<qtyOnHand<<endl;
	cout << "Quantity-On-hand: " << wholesale << endl;
	cout << "Wholesale Cost:" << wholesale<< endl;
	cout << "Retail Price: "<<retail<<endl;

	cout << endl;
}