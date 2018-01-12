#include<iostream>
#include<fstream>
#include<string>

using namespace std;

/////////////////////////////////////
int main()
{
  string buf;  

  ///ofstream aa("Hello.txt");
  ofstream aa;

  aa.open("Hello.txt",ios::out );
  // app	 seek to the end of stream before each write
  // binary	 open in binary mode
  // in	 open for reading
  // out	 open for writing
  // trunc	 discard the contents of the stream when opening
  // ate	 seek to the end of stream immediately after open

  aa << "Hello" << endl;
  aa << "Elephant" << endl;
  

  //  cout << buf << endl;
  //}

}

