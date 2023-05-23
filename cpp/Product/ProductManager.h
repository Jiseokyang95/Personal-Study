#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include "Product.h"

class ProductManager {
	int nextId;
	int numberOfProducts;
	Product* p[100];
	
public:
	ProductManager();
	~ProductManager();
	void operate();
	void addProduct(int type);
};

#endif