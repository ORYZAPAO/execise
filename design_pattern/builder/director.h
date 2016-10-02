#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

//
// Directorクラス
//
class Director{
 private:
  Builder *m_pbld;
 public:
  Director() : m_pbld(nullptr){ }  
  Director(Builder &bld) : m_pbld(&bld){ }
  void SetBuilder(Builder &bld);      
  bool Build();
};

#endif // __DIRECTOR_H__
