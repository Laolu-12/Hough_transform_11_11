#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\��ͼ\\Ԫ��.jpg");
	cv::Mat grayMat;
	cv::Mat canny;
	
	std::vector<cv::Vec2f> lines; //���ֱ��

	cv::cvtColor(srcMat, grayMat, COLOR_BGR2GRAY);//ת�Ҷ�ͼ

	Canny(grayMat, canny, 120, 220); //��canny���ӱ�Ե��� �õ���ֵ��ͼ��

	cv::HoughLines(canny, lines, 1, CV_PI / 180,100,0,0); //ע������ͼ����Ҫ�ǵ�ͨ����ֵ��ͼ

	//����ֱ��
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
	
	

	imshow("����任���ֱ��", srcMat);
	imshow("�Ҷ�ͼ", canny);
	waitKey(0);
}