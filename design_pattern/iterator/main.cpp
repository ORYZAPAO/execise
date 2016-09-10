#include<iostream>
#include<string>
#include<boost/format.hpp>

#include<vector>
#include<memory>

using namespace std;

#include"object.h"
#include"aggregate.h"
#include"iterator.h"

class Book{
private:
  string m_name;
public:
  Book(): m_name(""){}
  Book(string &name): m_name(name){}
  string getName(){
    return m_name;
  };
};


// 本の管理クラス(BookShelf)
//
//
class BookIterator;
class BookShelf : public Aggregate {
private:
  vector<Book> m_book;

public:
  virtual Iterator* iterator(){
    return new BookIterator(this);
  }

  void   addBook(string &&name){
    m_book.push_back(name);
  }

  string getBook(int idx){
    if( m_book.size() >= idx ) return nullptr;  
    return m_book[idx].getName();
  }
};

// イテレータ
// 
//
class BookIterator : public Iterator{
private :
  Aggregate *m_aggrgate;

public:
  BookIterator(Aggregate *a) : m_aggrgate(a){} 

  virtual bool hasNext(){ return false;}

  string operator [](int idx){
    return dynamic_cast<BookShelf*>(m_aggrgate)->getBook(idx);
  }
  //  virtual Object
};



//
//
int main(){
  std::unique_ptr<BookShelf> bs = make_unique<BookShelf>();
  bs->addBook(string("アンナカレーニナ")); 
  bs->addBook(string("戦争と平和")); 
  bs->addBook(string("イワンの馬鹿")); 
  bs->addBook(string("復活")); 

  Iterator *it = bs->iterator(); 

  

  return 0;
}

