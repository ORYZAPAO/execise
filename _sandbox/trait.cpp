#include<iostream>
#include<boost/format.hpp>
#include<utility>  // pair

////////////////////
struct tint{
  using dat_type = int;
  dat_type _dat;

  tint():_dat(0){}
  tint(dat_type d):_dat(d){}

  dat_type get(){ return _dat; }
};


struct tvector{
  using dat_type = std::pair<int, int>;
  dat_type _dat;
  
  tvector():_dat(0,0){}
  tvector(dat_type d): _dat(d){}

  dat_type &get(){ return _dat; }  
  tvector &operator+ (tvector &a){
    this->_dat.first  += a.get().first;
    this->_dat.second += a.get().second;    
    
    return(*this);
  }

  // cout 
  friend std::ostream& operator<<(std::ostream& os, tvector& my){
    std::cout << boost::format("(%d,%d)") % my._dat.first % my._dat.second;
    return(os);
  }
};

////////////////////
//これ経由で、アクセスする
template<class T>
struct get_trait{ 
  get_trait(){}
  
  static typename T::dat_type getVal(T &a){ return(a.get()); }
};


/// add
template<class T>
constexpr T add(T &a, T &b){
  T ret( a + b );
  return(ret);  
};


////////////////////
int main(){
  //tint a(100), b(200);
  //tint aa = add(a,b);
  //std::cout << aa.get() << std::endl;  

  tvector av(std::make_pair(1,2));
  tvector bv(std::make_pair(9,3));
  std::cout << typeid( get_trait<tvector>::getVal(av) ).name() << std::endl; 

  auto aav = add(av,bv);
  //auto aav = av+bv;
  std::cout << aav  << std::endl;  
  /*
  */
}
