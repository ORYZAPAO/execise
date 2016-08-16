#include <iostream>
#include <vector>
#include <algorithm>

#include <boost/format.hpp>

using namespace std;

#include"observer_base.h"
#include"subject_base.h"


using namespace myspace;

//
// サブジェクト側を実装
//
class RealSubject : public Subject_Base{
private:
  vector<Observer_Base*> m_ob_list; /// 通知先の各オブザーバーへのポインタ配列

public:
  virtual void RegistObserver(Observer_Base *pOb){
    m_ob_list.push_back(pOb); 
  };

  virtual void RemoveObserver(Observer_Base *pOb){
    auto result = std::find(m_ob_list.begin(), m_ob_list.end() , pOb);
    if( result != m_ob_list.end() ){
      m_ob_list.erase(result);
    }
  };

  virtual void NotifyObserbers(){
    std::for_each(m_ob_list.begin(), m_ob_list.end(),
                  [](Observer_Base *i){ i->Update(); });
  };

};


//
// オブザーバーを実装
//
class RealObserver : public Observer_Base {
public:
  virtual void Update(){}    
};



int main(){

  cout << boost::format("Hello") << endl;
}
