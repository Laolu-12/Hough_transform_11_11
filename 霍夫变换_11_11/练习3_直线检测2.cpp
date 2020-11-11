#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\��ͼ\\Ԫ��.jpg");
	cv::Mat grayMat;
	cv::Mat canny;

	std::vector<cv::Vec4i> lines;//���ֱ��

	cv::cvtColor(srcMat, grayMat, COLOR_BGR2GRAY);//ת�Ҷ�ͼ

	Canny(grayMat, canny, 100, 220); //��canny���ӱ�Ե��� �õ���ֵ��ͼ��
	
	cv::HoughLinesP(canny, lines, 1, CV_PI / 180, 30, 10, 20); //��ֵΪ30����Сֱ�߳���Ϊ10�������֮�������Ϊ20

	//����ֱ��
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(srcMat, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, CV_AA);
	}

	

	imshow("����任���ֱ��", srcMat);
	imshow("��ֵ��ͼ", canny);
	waitKey(0);
}