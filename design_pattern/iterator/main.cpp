#include<iostream>
#include<string>
#include<boost/format.hpp>

#include<vector>
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


//
//
//
class BookIterator : public Iterator{
private :
  Aggregate *m_aggrgate;

public:
  BookIterator(Aggregate *a) : m_aggrgate(a){} 

  virtual bool hasNext(){ return false;}
  //  virtual Object
};


//
//
//
class BookShelf : public Aggregate {
private:
  vector<Book> m_book;

public:
  virtual Iterator* iterator(){
    return new BookIterator(this);
  }

  void addBook(string &name){
    m_book.push_back(name);
  }

  string getBook(int idx){
    if( m_book.size() >= idx ) return nullptr;  
    return m_book[idx].getName();
  }

  

};

int main(){

  return 0;
}

