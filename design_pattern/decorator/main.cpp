#include<iostream>
#include<boost/format.hpp>
#include<string>

#include"component.h"
#include"decorator.h"

using namespace std;

/// Concrete Component 
class coffee_black : public coffee_component{
private:
  string m_name = "Black Coffee";
  int    m_cost = 10;
public:
  string getName(){ return m_name; }
  int    cost()   { return m_cost; }
};

/// Concrete Decorator
class coffee_with_sugger : public coffee_decorator{
public:
  coffee_with_sugger(coffee_component *pbase):coffee_decorator(pbase){}

  string getName(){ 
    return m_pcomp->getName()+" with Sugger"; 
  }
  
  int cost() {
    return m_pcomp->cost()+5; 
  }
};


///
int main(){
  coffee_black       cf;
  coffee_with_sugger cfs(new coffee_black);


  cout << cf.getName()  << endl; /// "Black Coffee"
  cout << cf.cost()     << endl; /// "10"

  cout << cfs.getName() << endl; /// "Black Coffee with Sugger"
  cout << cfs.cost()    << endl; /// "15"
}

