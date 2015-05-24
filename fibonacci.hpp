#ifndef __FIBONACCI_HPP
#define __FIBONACCI_HPP

namespace oryzalib{

///
template <int num>
int Fibonacci(){
  return Fibonacci<num-1>() + Fibonacci<num-2>();
};

template <>
int Fibonacci<1>(){ return 1; }
template <>
int Fibonacci<2>(){ return 2; }

};

#endif /// __FIBONACCI_HPP
