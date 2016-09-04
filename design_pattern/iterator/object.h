#ifndef __OBJECT_H__
#define __OBJECT_H__

class Object{
private:
  string m_name;

public:
  Object():m_name(){}
  Object(string name) : m_name(name){};
  ~Object(){}
  
  string GetName(){
    return m_name;
  }

  void SetName(string name){
    m_name = name;
  }  
};

#endif // __OBJECT_H__
