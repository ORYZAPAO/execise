#ifndef __AGGREGATE_H__
#define __AGGREGATE_H__

class Iterator;
class Aggregate{
 public:
  virtual Iterator* iterator() =0;  
};

#endif // __AGGREGATE_H__
