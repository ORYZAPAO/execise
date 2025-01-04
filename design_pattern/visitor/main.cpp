// ================================================================================
// == Visitor パターン
// ==
// == 
// ================================================================================

#include <iostream>
#include<string>
#include <boost/format.hpp>
//------------------------------------------------------------
// 処理対象のオブジェクト
//------------------------------------------------------------
class obj_base{
  public:
};

class cat : public obj_base{
  public:
    cat() : value("CAT"){};
    std::string value;
};

class dog : public obj_base{
  public:
    dog(): value("DOG"){}
    std::string value;
};

//------------------------------------------------------------
// オブジェクトに対する処理内容
//------------------------------------------------------------
class func_base{
  public:
    virtual void visit(cat &obj)=0;
    virtual void visit(dog &obj)=0;
};

// オブジェクトを画面に表示
class func_print :public func_base{
  public:
    func_print(){}

    virtual void visit(cat  &obj){ // "catクラスに対する処理"
      std::cout << boost::format("-- %s --") % obj.value << std::endl;
    }
    virtual void visit(dog  &obj){ // "dogクラスに対する処理"
      std::cout << boost::format("-- %s --") % obj.value << std::endl;
    }
};

// オブジェクトを加工
class func_modify : virtual public func_base{
  public:
    func_modify(){}

    virtual void visit(cat  &obj){
       obj.value  = "**** " + obj.value;
       obj.value  += " ****";
    }
    virtual void visit(dog  &obj){
       obj.value  = "**** " + obj.value;
       obj.value  += " ****";
    }
};

//------------------------------------------------------------
int main(){
  func_print fp;
  func_modify fm;

  dog d_dog;
  cat d_cat;

  // 値を表示
  fp.visit(d_cat);
  fp.visit(d_dog);


  // 処理
  fm.visit(d_cat);
  fm.visit(d_dog);

  // 値を表示
  fp.visit(d_cat);
  fp.visit(d_dog);



}
