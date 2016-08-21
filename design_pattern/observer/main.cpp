#include <iostream>
#include <vector>
#include <algorithm>
#include<string>

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
  int                    m_base;
public:
  vector<int>            m_dat_list;
  
public:

  RealSubject(int d=0):m_base(d){ }

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
  virtual void NotifyObserbers(void){
    std::for_each(m_ob_list.begin(), m_ob_list.end(),
　　　　　　　　　　// オブザーバーの Update()メソッドを呼出す
                  [](Observer_Base *i){ i->Update(); });
  };

  /// 通知用の値を生成
  void UpdateData(){
    for(int i=0; i<10; i++){ m_dat_list.push_back(i+m_base); };

    NotifyObserbers();
  }    
  
};


//
// オブザーバーを実装
//
class RealObserver : public Observer_Base {
private:
  RealSubject *m_pSubject;
  std::string  m_name;
  
public:
  RealObserver(string str):m_name(str){}
  
  virtual void Update(void){
    cout << boost::format("Detect(%s)") % m_name << endl;      

    auto datlist = m_pSubject->m_dat_list;
    for_each(datlist.begin(), datlist.end(),
             [=](int i){ cout << boost::format("%d ") % i;  });
    cout << "\n\n";
  }    
  
  void SetSubject(RealSubject *pSub){
    m_pSubject = pSub;
  }
  
};


//------------------------------------------------------------
int main(){

  RealSubject sub(0);

  RealObserver obs("Observer-1");
  RealObserver obs2("Observer-2");

  obs.SetSubject(&sub);
  obs2.SetSubject(&sub);
  
  sub.RegistObserver(&obs);
  sub.RegistObserver(&obs2);
  
  sub.UpdateData();

}
