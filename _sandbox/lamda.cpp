#include<iostream>
#include<boost/format.hpp>

template<class A>
struct HALO{
  A x;
  HALO(A x_):x(x_){}
};

template<int N>
void FF(){
  std::cout << N << std::endl;
  FF<N-1>();
}

template<> void FF<0>(){
  std::cout << "FIN." << std::endl;
}


int main(){
  std::cout << "Hello" << std::endl;

  auto ff=[](int x){
            struct ABC{
              int d;
              ABC(int _d):d(_d){}
              void pri(){
                std::cout << "d=" << this->d << std::endl;
              }
            };
            
            ABC abc(999);
            abc.pri();

            FF<10>();              


            auto ff = [](int y) -> int{
                        return y*10;
                      };

            std::cout << boost::format("%d\n") %  ff(29);
            
            return x*100;
          };

  std::function<int(int)> func = ff;

  std::cout << func(2) << std::endl;
}
