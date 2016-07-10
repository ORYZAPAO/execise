#ifndef __MAKE_UNIQUE__H__
#define __MAKE_UNIQUE__H__

/// How to Use
//
//  std::unique_ptr<AAAClass> p = make_unique<AAAClass>();
//  or
//  auto p = make_unique<AAAClass>();

template<class T>
std::unique_ptr<T> make_unique()
{ return std::unique_ptr<T>( new T );  }

#endif /// __MAKE_UNIQUE__H__

