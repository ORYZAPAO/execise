#include<iostream>
#include<fstream>

/////////////////////////////////////
int main()
{
  string buf;  

  ///ifstream aa("Hello.txt");
  ifstream aa;

  aa.open("Hello.txt",ios::in );
  // app	 seek to the end of stream before each write
  // binary	 open in binary mode
  // in	 open for reading
  // out	 open for writing
  // trunc	 discard the contents of the stream when opening
  // ate	 seek to the end of stream immediately after open
  
  while( getline(aa,buf) ){
    cout << buf << endl;
  }

}

