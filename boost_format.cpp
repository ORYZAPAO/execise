#include<iostream>
#include<fstream>
#include<boost/format.hpp>

using namespace std;

///
///
struct DATA{
private:
  int dat;

public:
  DATA()        : dat(0){}
  DATA(int _dat): dat(_dat){}

  void print(){
    cout << boost::format("Data=%d\n") % dat << endl; 
  }    

  void set(int _dat){
    dat = _dat;
    cout << boost::format("Set(dat)=%d\n") % dat << endl;
  }
  
};


///
DATA && test(){
  DATA data;

  data.set(2222);  

  return move(data); /// --> Right Reference
}


//////////////////////////////////////
int main()
{
  DATA dat(10);
  DATA dat2;
  
  dat.print();
  dat2 = test();
  dat.print();
  dat2.print();
}
