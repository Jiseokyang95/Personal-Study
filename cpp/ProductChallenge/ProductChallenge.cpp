#include <iostream>
#include <string>
using namespace std;

class Product
{
      int id;
      string info;
      string pro;
      string price;

public:
      Product() { ; }
      Product(int id, string info, string pro, string price)
      {
            this->id = id;
            this->info = info;
            this->pro = pro;
            this->price = price;
      }
      int getId() { return id; }
      string getInfo() { return info; }
      string getPro() { return pro; }
      string getPrice() { return price; }
      virtual void show() = 0;
};

class Book : public Product
{
      string ISBN;
      string writer;
      string BName;

public:
      Book(int id, string info, string pro, string price, string IS, string writer, string BN) : Product(id, info, pro, price)
      {
            ISBN = IS;
            this->writer = writer;
            BName = BN;
      }
      string getISBN() { return ISBN; }
      string getWriter() { return writer; }
      string getBName() { return BName; }
      void show();
};
void Book::show()
{
      cout << "--- 상품ID : " << getId() << endl;
      cout << "상품설명 : " << getInfo() << endl;
      cout << "생산자 : " << getPro() << endl;
      cout << "가격 : " << getPrice() << endl;
      cout << "ISBN : " << ISBN << endl;
      cout << "책제목 : " << BName << endl;
      cout << "저자 : " << writer << endl;
}

class CompactDisc : public Product
{
      string AName;
      string singer;

public:
      CompactDisc(int id, string info, string pro, string price, string AN, string singer) : Product(id, info, pro, price)
      {
            AName = AN;
            this->singer = singer;
      }
      void show();
};
void CompactDisc::show()
{
      cout << "--- 상품ID : " << getId() << endl;
      cout << "상품설명 : " << getInfo() << endl;
      cout << "생산자 : " << getPro() << endl;
      cout << "가격 : " << getPrice() << endl;
      cout << "앨범제목 : " << AName << endl;
      cout << "가수 : " << singer << endl;
}

class ConversationBook : public Book
{
      string lan;

public:
      ConversationBook(int id, string info, string pro, string price, string IS, string writer, string BN, string lan)
          : Book(id, info, pro, price, IS, writer, BN)
      {
            this->lan = lan;
      }
      void show();
};
void ConversationBook::show()
{
      cout << "--- 상품ID : " << getId() << endl;
      cout << "상품설명 : " << getInfo() << endl;
      cout << "생산자 : " << getPro() << endl;
      cout << "가격 : " << getPrice() << endl;
      cout << "ISBN : " << getISBN() << endl;
      cout << "책제목 : " << getBName() << endl;
      cout << "저자 : " << getWriter() << endl;
      cout << "언어 : " << lan << endl;
}

int main()
{

      int num;
      int id = -1;
      string info, pro, price, AN, singer, BN, writer, lan, ISBN;
      Product *p[100];
      bool exit = true;

      cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;
      while (exit)
      {
            cout << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ? ";
            cin >> num;
            switch (num)
            {
            case 1:
                  cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ? ";
                  cin >> num;
                  cin.ignore(1);
                  id++;
                  if (id >= 100)
                        break;
                  if (num == 1)
                  {
                        cout << "상품설명>>";
                        getline(cin, info);
                        cout << "생산자>>";
                        getline(cin, pro);
                        cout << "가격>>";
                        getline(cin, price);
                        cout << "책제목>>";
                        getline(cin, BN);
                        cout << "저자>>";
                        getline(cin, writer);
                        cout << "ISBN>>";
                        getline(cin, ISBN);
                        Book *b = new Book(id, info, pro, price, BN, writer, ISBN);
                        p[id] = b;
                  }
                  if (num == 2)
                  {
                        cout << "상품설명>>";
                        getline(cin, info);
                        cout << "생산자>>";
                        getline(cin, pro);
                        cout << "가격>>";
                        getline(cin, price);
                        cout << "앨범제목>>";
                        getline(cin, AN);
                        cout << "가수>>";
                        getline(cin, singer);
                        CompactDisc *d = new CompactDisc(id, info, pro, price, AN, singer);
                        p[id] = d;
                  }
                  if (num == 3)
                  {
                        cout << "상품설명>>";
                        getline(cin, info);
                        cout << "생산자>>";
                        getline(cin, pro);
                        cout << "가격>>";
                        getline(cin, price);
                        cout << "책제목>>";
                        getline(cin, BN);
                        cout << "저자>>";
                        getline(cin, writer);
                        cout << "언어>>";
                        getline(cin, lan);
                        cout << "ISBN>>";
                        getline(cin, ISBN);
                        ConversationBook *cb = new ConversationBook(id, info, pro, price, BN, writer, ISBN, lan);
                        p[id] = cb;
                  }
                  cout << endl;
                  break;
            case 2:
                  for (int i = 0; i <= id; i++)
                        p[i]->show();
                  cout << endl;
                  break;
            case 3:
                  exit = false;
                  break;
            }
      }
}