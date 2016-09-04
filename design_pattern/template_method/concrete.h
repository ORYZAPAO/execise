#ifndef __CONCRETECLASS_H__
#define __CONCRETECLASS_H__
class ConcreteClass : public AbstractClass{ 
 public:
  virtual void open(){
    std::cout << "<<";
  }

  virtual void print(){
    std::cout << "A";
  }

  virtual void close(){
    std::cout << ">>";
  }
  
};

#endif // __CONCRETECLASS_H__
