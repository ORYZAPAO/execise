#ifndef __FACTORY_H__
#define __FACTORY_H__

class Product;
class Factory{
 public:
  virtual Product *createProduct(){
    return new Product();
  }
};

#endif // __FACTORY_H__
