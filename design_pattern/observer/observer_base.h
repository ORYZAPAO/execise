#ifndef __OBSERVER_BASE_H__
#define __OBSERVER_BASE_H__
/*
 * Observer Interface
 */

namespace myspace{

class Observer_Base {
 public:
  virtual void Update(void) = 0;
};

}; 

#endif //__OBSERVER_BASE_H__
