#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
  cout << "Hello" << endl;

  Mat img_src;
  Mat img_dst;

  VideoCapture capture(0);
  if( !(capture.isOpened()) ){
    cout << "Error" << endl;
  }


  namedWindow("src", WINDOW_AUTOSIZE);
  namedWindow("dst", WINDOW_AUTOSIZE);

  while(1){
    capture >> img_src;
    imshow("src", img_src);
    //imgshow("dst", img_dst);

    if( waitKey(1) == 'q' ) break;
  }


  return 0;
  
  
}
