#include<sys/prctl.h>
#include<iostream>
#include<boost/format.hpp>

using namespace std;

/** プロセス名を，変更　prctl() PR_SET_NAME で変更 
 **
 ** > ps -aux 
 **     ps コマンドでは変わらないらしい
 ** 
 ** > cat /proc/928/stat
 **
 ** 928 (ZZOSAN) R 788 928 776 34821 928 4194304 153 0 0 0 4557 0 0 0 20 0 1 0 184882 13737984 400 18446744073709551615 94108538859520 94108538862920 140734456237152 0 0 0 0 0 0 0 0 0 17 1 0 0 0 0 0 94108540960144 94108540960848 94108555558912 140734456240463 140734456240476 140734456240476 140734456242160 0
 **
 **/

int main(){
  prctl(PR_SET_NAME, "ZZOSAN");
  cout << "Hello" << endl;
  while(1);                     
}
