#include "opencv2/opencv.hpp"

#include <opencv2/videoio.hpp>
#include "opencv/highgui.h"

#include <iostream>
#include <vector> //追加

using namespace cv;
using namespace std;

using namespace cv;

void test1();
void test2();

int main(int, char**){
  test2();
  return 0;
}

//// http://www.cellstat.net/tracking/

//----------------------------------------
//----------------------------------------
void test2(){
  Mat img;
  Mat gray_img; //追加
  Mat bin_img; //追加

  Mat element = Mat::ones(3, 3, CV_8UC1); //追加　3×3の行列で要素はすべて1　dilate処理に必要な行列

  VideoCapture cap(0);
  if(!cap.isOpened()){  // 成功したかどうかをチェック
    std::cout << "FAIL";
    return;
  }
  namedWindow("Video", WINDOW_AUTOSIZE);
  ///int max_frame = cap.get(CV_CAP_PROP_FRAME_COUNT);
  //for(int i = 0; i<max_frame; i++){
  while(1){
    cap >> img;

    /////////////////////
    cvtColor(img, gray_img, CV_BGR2GRAY);
    threshold(gray_img, bin_img, 70, 255, THRESH_BINARY);
    //追加ここから
    bin_img = ~bin_img; //色反転
    dilate(bin_img, bin_img, element, Point(-1, -1), 3); //膨張処理3回 最後の引数で回数を設定
                                                         //追加ここまで


    ///////面積計算//////////////
    vector<vector<Point> > contours;
    findContours(bin_img, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

    double max_area = 0;
    int max_area_contour = -1;
    for(int j = 0; j<contours.size(); j++){
      double area = contourArea(contours.at(j));
      if(max_area<area){
        max_area = area;
        max_area_contour = j;
      }
    }

    ///// 重心計算 ///////
    int count = contours.at(max_area_contour).size();
    double x = 0;
    double y = 0;
    for(int k = 0; k<count; k++){
      x += contours.at(max_area_contour).at(k).x;
      y += contours.at(max_area_contour).at(k).y;
    }
    x /= count;
    y /= count;

    circle(img, Point(x, y), 50, Scalar(0, 0, 255), 3, 4);
    /////////////////////


    imshow("Video", img);

    if(waitKey(30) >= 0) break;
  }
}


//----------------------------------------
void test1(){
  VideoCapture cap(0); // デフォルトカメラをオープン
  if(!cap.isOpened()){  // 成功したかどうかをチェック
    std::cout << "FAIL";
    return;
  }

  Mat edges;
  namedWindow("edges", WINDOW_AUTOSIZE);
  //namedWindow("in", 1);
  for(;;){
    Mat frame;
    cap >> frame; // カメラから新しいフレームを取得
    cvtColor(frame, edges, CV_BGR2GRAY);
    GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
    Canny(edges, edges, 0, 30, 3);
    imshow("edges", edges);

    //imshow("In", frame);
    if(waitKey(30) >= 0) break;
  }
  // VideoCapture デストラクタにより，カメラは自動的に終了処理されます

}
