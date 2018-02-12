#include<iostream>
#include<boost/format.hpp>
#include<utility>
#include<cstring>

using namespace std;

// ----------------------------------------
// 可変個引数テンプレート
// ----------------------------------------

char *func(char *dat1, char *dat2){
  return strcat(dat1,dat2);
}


char *cfunc(char *cdat1, const char *dat2){
  return strcat(cdat1,dat2);
}
          

// ----------------------------------------
// ----------------------------------------
int main(){
  char   a[100], b[100];
  strcpy(a, "Hello,"); strcpy(b,"zosan");
  char   cabuf[100], cbbuf[100];
  strcpy(cabuf, "Hello,"); strcpy(cbbuf,"zosan");
  const char *ca, *cb;

  ca = cabuf;
  cb = cbbuf;

  cout << "func()" << endl;
  cout << func(a,b) << endl;
  cout << a         << endl;

  cout << "cfunc()" << endl;
  cout << cfunc(cabuf, cb) << endl;
  cout << cabuf           << endl;
  
  /*  
  cout << func(10,20) << endl;
  cout << func(a,b) << endl;
  cout << func(ca,cb) << endl;
  cout << endl;
  
  cout << cfunc(10,20) << endl;
  cout << cfunc(a,b) << endl;
  cout << cfunc(ca,cb) << endl;
  */
}
