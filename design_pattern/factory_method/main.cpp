#include<iostream>
#include<boost/format.hpp>

#include<product.h>
#include<factory.h>

using namespace std;

//
class Juice : public Product{
public:
  Juice():Product(nullptr){
    cout << boost::format("ジュース\n");
  };
  
  ~Juice(){};  
};

//
class Milk : public Product{
public:
  Milk():Product(nullptr){
    cout << boost::format("牛乳\n");
  };
  
  ~Milk(){};  
};


//
class MilkFactory : public Factory{
 public:
  virtual Product *createProduct(){
    cout << boost::format("牛乳を製造\n");
    return( new Milk() );    
  }
};


//
class JuiceFactory : public Factory{
 public:
  virtual Product *createProduct(){
    cout << boost::format("ジュースを製造\n");
    return( new Juice() );    
  }
};


int main(){
  JuiceFactory  fj;
  MilkFactory   fm;

  Product      *p1;
  Product      *p2;

  p1 = fj.createProduct();
  p2 = fm.createProduct();
}
