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
  // 通知先のオブザーバーを登録
  virtual void RegistObserver(Observer_Base *pOb){
    m_ob_list.push_back(pOb); 
  };

  // 登録したオブザーバーを削除
  virtual void RemoveObserver(Observer_Base *pOb){
    auto result = std::find(m_ob_list.begin(), m_ob_list.end() , pOb);
    if( result != m_ob_list.end() ){
      m_ob_list.erase(result);
    }
  };

  // 各オブザーバーへ通知
  virtual void NotifyObserbers(){
    std::for_each(m_ob_list.begin(), m_ob_list.end(),
                  [](Observer_Base *i){ i->Update(); });
  };

  /// 通知用の値を生成
  void UpdateData(){
    vector<int> val = {0,1,2,3,4,5,6,7,8,9 }; 
  }    
  
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
