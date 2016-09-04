#ifndef __PRODUCT_H__
#define __PRODUCT_H__

class Factory;
class Product{
  Factory *m_owner;

 public:
  Product(){}
  
  Product(Factory *owner){
    m_owner = owner;      
  }

  virtual ~Product(){
  }   
  
};

#endif // __PRODUCT_H__
