#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

#include "Product.h"

class Book : public Product {
	int ISBN;
	string title;
	string author;
public:
	Book(int type, int productID, string description, string maker, int price, int ISBN, string title, string author);
	void showBook();

	void setTitle(string title) { this->title = title; }
	string getAuthor() { return author; }
	int getISBN() { return ISBN; }
};

#endif