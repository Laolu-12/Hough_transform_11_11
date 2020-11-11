#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("C:\\Users\\Lenovo\\Pictures\\数图\\lena.png", 1);
	if (srcMat.empty()) return -1;

	//旋转-10°，缩放尺度为
	float angle = -10.0, scale = 1;

	//旋转中心为图像中心
	cv::Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);


	//获得变换矩阵
	cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);

	//获取外界四边形
	cv::Rect bbox = cv::RotatedRect(center, srcMat.size(), angle).boundingRect();

	//调整仿射矩阵参数
	affine_matrix.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	affine_matrix.at<double>(1, 2) += bbox.height / 2.0 - center.y;

	//仿射变换
	cv::warpAffine(srcMat, dstMat, affine_matrix, bbox.size());

	std::cout << affine_matrix <<std:: endl;

	cv::imshow("src", srcMat);
	cv::imshow("dst", dstMat);
	cv::waitKey(0);

}