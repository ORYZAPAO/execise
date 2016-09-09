#ifndef __ITERATOR_H__
#define __ITERATOR_H__

class Object;

class Iterator{
 public :
  virtual bool    hasNext()=0;
  //virtual Object  next()=0;    
};

#endif  //__ITERATOR_H__
