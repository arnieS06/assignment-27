#pragma once

#include <vector>
#include <string>

struct Book {
	std::string title;
	std::string author;
	double price;
	short releaseYear;
};

struct Store {
	const std::string name = "Arnie's bookstore \n-----------------";
	short openingTime = 10;
	short closingTime = 6;
	const std::string cityLocation = "Berkeley, CA.";
	std::string owner;
};

struct Inventory {
	std::vector <Book> Books;
};