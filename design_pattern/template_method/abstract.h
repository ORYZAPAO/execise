#ifndef __ABSTRACT_H__
#define __ABSTRACT_H__

class AbstractClass{
 public:
  virtual void open()=0;
  virtual void print()=0;
  virtual void close()=0;

  void display(){
    open();
    for(int i=0; i<3; i++)  print();
    close();

    std::cout << endl;
  }

  virtual ~AbstractClass(){}
};

#endif // __ABSTRACT_H__
