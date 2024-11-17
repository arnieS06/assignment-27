#include <iostream>
#include <fstream>
#include <string>
#include "Structs.h"
using namespace std;


ostream& operator << (ostream& os, const Store& store) {
	os << "The store is located in " << store.cityLocation << endl;
	os << "It opens at " << store.openingTime << " am, \nand closes at " << store.closingTime << " pm." << endl;

	return os;
}

void addBook(string title, string author, double price, short releaseYear, Inventory& inventory) {
	inventory.Books.push_back({ title, author, price, releaseYear });
}

void findBook(Inventory& inventory) {
	char userInput;
	short numberInput;

	for (int i = 0; i < inventory.Books.size(); i++) {
		cout << "\nBook " << i + 1 << ":";
		cout << "\n  Title: " << inventory.Books[i].title;
		cout << "\n  Author: " << inventory.Books[i].author;
		cout << "\n  Price: $" << inventory.Books[i].price;
		cout << "\n  Release Year: " << inventory.Books[i].releaseYear << endl;
	}

	cout << "Here's the current list of books that we have. \nIs this anything you are interested in? (y/n) -> ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y') {
		cout << "\nI see. Enter the number of the book you want -> ";
		cin >> numberInput;

		if (numberInput < 1 || numberInput > inventory.Books.size() + 1) {
			cout << "\nStop trolling";
			return;
		}

		cout << "That seems like an interesting choice. You now own " << inventory.Books[numberInput - 1].title << endl;
		cout << "Thanks for shopping have a nice day." << endl;
	}

	else {
		cout << "Exiting the bookstore." << endl;
	}
}


int main() {
	short input;
	char charInput;
	Store store;
	Inventory inventory;
	string book;
	string author;
	double price;
	short releaseYear;
	short forLoop;


	cout << "Welcome to \n" << store.name;
	cout << "\nWe are located at \n" << store.cityLocation << "\n";
	cout << "\nWhat do you want to do? \n"
		<< "1) I want to add a book \n"
		<< "2) I want to see the store details \n"
		<< "enter here --> ";

	cin >> input;

	switch (input) {
	case 1:
		cout << "\nhow many books do you wanna add? -> ";
		cin >> forLoop;

		if (forLoop < 1) {
			cout << "Be serious. You wanna add less than 1 book?" << endl;
			break;
		}

		for (int i = 0; i < forLoop; i++) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "What is the title of this book? -> ";
			getline(cin, book);

			cout << "What is the author of this book? -> ";
			getline(cin, author);

			cout << "Give me the price of this book in $ -> ";
			cin >> price;

			cout << "Tell me what year it was released -> ";
			cin >> releaseYear;

			addBook(book, author, price, releaseYear, inventory);
			cout << "\n";
		}

		cout << "Would you like to find your books? (y/n) -> ";
		cin >> charInput;

		if (charInput == 'y' || charInput == 'Y') {
			findBook(inventory);
		}

		else {
			cout << "\nExiting the book store.";
		}

		break;
	case 2:
		cout << store;
		break;
	default:
		cout << "please enter a valid request, terminating." << endl;
	}



	return 0;
}