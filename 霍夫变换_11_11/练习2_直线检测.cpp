#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\数图\\元件.jpg");
	cv::Mat grayMat;
	cv::Mat canny;
	
	std::vector<cv::Vec2f> lines; //输出直线

	cv::cvtColor(srcMat, grayMat, COLOR_BGR2GRAY);//转灰度图

	Canny(grayMat, canny, 120, 220); //用canny算子边缘检测 得到二值化图像

	cv::HoughLines(canny, lines, 1, CV_PI / 180,100,0,0); //注意输入图像需要是单通道二值化图

	//绘制直线
	std::vector<cv::Vec2f>::iterator it = lines.begin();
	for (; it != lines.end(); ++it)
	{
		float rho = (*it)[0], theta = (*it)[1];
		cv::Point pt1, pt2;
		double a = cos(theta);
		double b = sin(theta);
		double x0 = a*rho;
		double y0 = b*rho;
		pt1.x = cv::saturate_cast<int>(x0 + 1000 * (-b));
		pt1.y = cv::saturate_cast<int>(y0 + 1000 * (a));
		pt2.x = cv::saturate_cast<int>(x0 - 1000 * (-b));
		pt2.y = cv::saturate_cast<int>(y0 - 1000 * (a));
		cv::line(srcMat, pt1, pt2, cv::Scalar(0, 0, 255), 1, CV_AA);
	}
	
	

	imshow("霍夫变换检测直线", srcMat);
	imshow("灰度图", canny);
	waitKey(0);
}