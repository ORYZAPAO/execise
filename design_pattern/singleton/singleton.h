#ifndef __SINGLETON_H__
#define  __SINGLETON_H__


class Singleton{
 private:
  Singleton()  = default;  // コンストラクタを private に置く
  ~Singleton() = default;  // デストラクタを
 public:
  Singleton(const Singleton&)              = delete; // コピーコンストラクタ 削除
  Singleton& operator =(const Singleton&)  = delete; // コピー代入演算子     削除
  Singleton(Singleton&&) 　　　　　　　　　　 = delete; // ムーブコンストラクタ 削除
  Singleton& operator =(const Singleton&&) = delete; // ムーブ代入演算子     削除

  static Singleton &getInstance(){
    static Singleton inst;
    return inst;
  }
  
};

#endif // __SINGLETON_H__
