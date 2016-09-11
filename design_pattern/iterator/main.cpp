#include<iostream>
#include<string>
#include<boost/format.hpp>

#include<vector>
#include<memory>
#include<algorithm>

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


// イテレータ
// 
//
class BookShelf;
class BookIterator : public Iterator{
private :
  Aggregate *m_aggrgate;

public:
  BookIterator(Aggregate *a) : m_aggrgate(a){} 
  virtual bool hasNext(){ return false;}

  string get(int idx);
  string operator [](int idx);
};


// 本の管理クラス(BookShelf)
//
//
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
    if( m_book.size() <= idx ) return nullptr;  
    return m_book[idx].getName();
  }

  void printList(){
    for_each(m_book.begin(), m_book.end(), [](Book &bk){ cout << bk.getName() << endl; });
  }
  
};



string BookIterator::get(int idx){
  ///return dynamic_cast<BookShelf*>(m_aggrgate)->getBook(idx);
  return dynamic_cast<BookShelf*>(m_aggrgate)->getBook(idx);
}
string BookIterator::operator [](int idx){
  return dynamic_cast<BookShelf*>(m_aggrgate)->getBook(idx);
}


//
//
int main(){
  std::unique_ptr<BookShelf> bs = make_unique<BookShelf>();
  bs->addBook(string("アンナカレーニナ")); 
  bs->addBook(string("戦争と平和")); 
  bs->addBook(string("イワンの馬鹿")); 
  bs->addBook(string("復活")); 

  unique_ptr<Iterator> it(bs->iterator());
  
  std::cout << (*it)[0] << endl;
  std::cout << (*it)[1] << endl;
  std::cout << (*it)[2] << endl;
  std::cout << (*it)[3] << endl;  
  
  return 0;
}

