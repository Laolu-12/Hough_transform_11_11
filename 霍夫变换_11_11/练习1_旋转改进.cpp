#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("C:\\Users\\Lenovo\\Pictures\\��ͼ\\lena.png", 1);
	if (srcMat.empty()) return -1;

	//��ת-10�㣬���ų߶�Ϊ
	float angle = -10.0, scale = 1;

	//��ת����Ϊͼ������
	cv::Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);


	//��ñ任����
	cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);

	//��ȡ����ı���
	cv::Rect bbox = cv::RotatedRect(center, srcMat.size(), angle).boundingRect();

	//��������������
	affine_matrix.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	affine_matrix.at<double>(1, 2) += bbox.height / 2.0 - center.y;

	//����任
	cv::warpAffine(srcMat, dstMat, affine_matrix, bbox.size());

	std::cout << affine_matrix <<std:: endl;

	cv::imshow("src", srcMat);
	cv::imshow("dst", dstMat);
	cv::waitKey(0);

}