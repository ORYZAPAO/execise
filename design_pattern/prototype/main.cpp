#include<iostream>
#include<vector>
#include<boost/format.hpp>

#include"prototype.h"

using namespace std;

////
class Client{
private:
  std::vector<Prototype> m_plist;

public:
  void addPrototype(Prototype p){
    m_plist.push_back(p);
  }
};


/////
class Stone : public Prototype{
private:
  string  m_str;
public:
  Stone() : m_str(""){}
  Stone(const char *s){
    string str(s);
    m_str = str;
  }
  Stone(string &str) : m_str(str){}

  virtual Prototype createClone(){
    Stone p(m_str);
    return p;
  }

  void use(){    
    cout << "石:" << m_str << endl;
  }
};


class Plant : public Prototype{
private:
  string  m_str;
public:
  Plant() : m_str(""){}
  Plant(const char *s) {
    string str(s);
    m_str = str;
  }
  Plant(string &str) : m_str(str){}

  virtual Prototype createClone(){
    Plant p(m_str);
    return p;
  }

  void use(){    
    cout << "植物:" << m_str << endl;
  }
};


///
int main(){
  Client cri;

  Stone kanran("かんらん石");
  Plant momiji("紅葉");
  Plant asagao("朝顔");

  kanran.use();
  momiji.use();
  asagao.use();

  cri.addPrototype(kanran);
  cri.addPrototype(momiji);
  cri.addPrototype(asagao);
  
  return 0;
}

