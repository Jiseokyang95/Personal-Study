#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
	int type;
	int productID;
	string description;
	string maker;
	int price;
	int productType; // Book : 1, CompactDisk : 2, ConversationBook : 3
public:
	Product(int type, int productID, string description, string maker, int price);
	void showProduct();

	int getProductID() { return productID; }
	string getDescription() { return description; }
	string getMaker() { return maker; }
	int getPrice() { return price; }
	int getType() { return type; }
};

#endif