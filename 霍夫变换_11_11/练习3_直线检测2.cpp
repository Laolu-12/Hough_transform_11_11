#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\数图\\元件.jpg");
	cv::Mat grayMat;
	cv::Mat canny;

	std::vector<cv::Vec4i> lines;//输出直线

	cv::cvtColor(srcMat, grayMat, COLOR_BGR2GRAY);//转灰度图

	Canny(grayMat, canny, 100, 220); //用canny算子边缘检测 得到二值化图像
	
	cv::HoughLinesP(canny, lines, 1, CV_PI / 180, 30, 10, 20); //阈值为30，最小直线长度为10，点与点之间最大间隔为20

	//绘制直线
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(srcMat, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, CV_AA);
	}

	

	imshow("霍夫变换检测直线", srcMat);
	imshow("二值化图", canny);
	waitKey(0);
}