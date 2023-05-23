#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(int type, int productID, string description, string maker, int price)
{
      this->type = type;
      this->productID = productID;
      this->description;
      this->maker = maker;
      this->price = price;
}

void Product::showProduct()
{
      std::cout << "--- 상품ID: " << productID << std::endl;
      std::cout << "상품설명: " << description << std::endl;
      std::cout << "생산자: " << maker << std::endl;
      std::cout << "가격 " << price << std::endl;
}