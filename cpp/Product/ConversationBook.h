#ifndef CONVERSATIONBOOK_H
#define CONVERSATIONBOOK_H

#include <string>
using namespace std;

#include "Book.h"

class ConversationBook  : public Book {
	string language;
public:
	ConversationBook(int type, int productID, string description, string maker,
			int price, int ISBN, string title, string author, string language);
	void showConversationBook();

	string getLanguage() { return language; }
};

#endif