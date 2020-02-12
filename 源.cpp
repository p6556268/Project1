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
	imshow("ԭͼ", img);   //��ʾԭͼ
	//-------------------------------------------------��ʴ-------------------------------------------------------
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));   //�����ض�����
	Mat img2;
	erode(img, img2, element);    //���ò�������ʴ
	imshow("��ʴ", img2);        //��ʾЧ��ͼ
	//-------------------------------------------------�˲�--------------------------------------------------------
	Mat img3;
	blur(img, img3, Size(7, 7));
	imshow("ģ��", img3);
	//-------------------------------------------------����--------------------------------------------------------
	Mat img4, edge, imgt;
	img4.create(img.size(), img.type());  //�ȱ���ԭimg��type��size
	cvtColor(img, imgt, COLOR_BGR2GRAY);  //imgt��img�ĻҶ�ͼ��
	imshow("�Ҷ�ͼ", imgt);
	blur(imgt, edge, Size(3, 3));          //�˲�
	imshow("�ҶȺ��˲�", edge);
	Canny(edge, edge, 3, 9, 3);
	imshow("����", edge);
	//-------------------------------------------------------------------------------------------------------------
	waitKey(0);
	return 0;
}
