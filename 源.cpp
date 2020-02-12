#include <iostream>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat img = imread("C:\\Users\\77915\\Desktop\\1.png");
	imshow("原图", img);   //显示原图
	//-------------------------------------------------腐蚀-------------------------------------------------------
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));   //返回特定参数
	Mat img2;
	erode(img, img2, element);    //调用参数来腐蚀
	imshow("腐蚀", img2);        //显示效果图
	//-------------------------------------------------滤波--------------------------------------------------------
	Mat img3;
	blur(img, img3, Size(7, 7));
	imshow("模糊", img3);
	//-------------------------------------------------化线--------------------------------------------------------
	Mat img4, edge, imgt;
	img4.create(img.size(), img.type());  //先保留原img的type和size
	cvtColor(img, imgt, COLOR_BGR2GRAY);  //imgt是img的灰度图像
	imshow("灰度图", imgt);
	blur(imgt, edge, Size(3, 3));          //滤波
	imshow("灰度后滤波", edge);
	Canny(edge, edge, 3, 9, 3);
	imshow("化线", edge);
	//-------------------------------------------------------------------------------------------------------------
	waitKey(0);
	return 0;
}
