#include<iostream>
#include<boost/format.hpp>
#include<string>

#include"coffee_base.h"

using namespace std;

/// 
class coffee_black : public coffer_base{
private:
  string m_name = "Black Coffee";
  int    m_cost = 10;
public:
  string getName(){ return m_name; }
  int    cost()   { return m_cost; }
};

///
class coffee_with_sugger : public coffer_base{
private:
  string m_name = "Coffee";
  int    m_cost = 5;
public:
  string getName(){ return m_name; }
  int    cost()   { return m_cost; }
};





///
int main(){
}

