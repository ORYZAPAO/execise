#include<iostream>
#include<string>
#include<utility>
#include<boost/format.hpp>


using namespace std;

namespace My{
  template<typename T>
  class unique_ptr{
  public:
    T *_ptr;

    unique_ptr(T *p):_ptr(p){}

    unique_ptr(const unique_ptr &src) = delete;
    unique_ptr(const unique_ptr &&src):_ptr(src._ptr){
      src._ptr = nullptr;      
    }
    unique_ptr& operator=(unique_ptr &src)=delete;
    unique_ptr& operator=(unique_ptr &&src){      
      this->_ptr =  src._ptr;
      src._ptr = nullptr;
      //cout << "[= l-ref]" << endl;
      return(*this);
    }        

    friend ostream& operator<<(ostream& os, const unique_ptr& dt){
      os << *(dt._ptr);
      return os;
    }
    
    
    ~unique_ptr(){
      delete(_ptr);
      cout << "[Destractor]" << endl; }    
  };
}; // namespace My{


int main(){
  cout << "my_memory.cpp" << endl;

  My::unique_ptr<string> str0(new string("ちびぱお"));
  My::unique_ptr<string> str1(new string("カピ"));

  cout << boost::format("%s, %s") % str0 % str1 << endl;

  //str0 = str1;
  str0 = std::move(str1);
}
