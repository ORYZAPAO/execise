#ifndef __BUILDER_H__
#define __BUILDER_H__

class Builder{
 public:
  virtual void buildPart1() = 0;
  virtual void buildPart2() = 0;
  virtual bool getResult()  = 0;
};

#endif //__BUILDER_H__
