#include <blur_operation.h>

using namespace cv;
using namespace std;

int blur_operation(int flag)
{
	Mat src = imread("E:/opencv/opencv_code/dog.jpg");
	if (src.empty())
	{
		printf("cannot find the picture");
		return -1;
	}

	namedWindow("dog window", WINDOW_AUTOSIZE);
	imshow("dog window", src);


	Mat dst;
	switch (flag)
	{

/***************************************************************************
*	均值模糊
*		就是将 划取区域	kernel	内所有像素取均值 作为 中心点像素值
*		就是不分青红皂白的模糊
****************************************************************************/
	case Blur_Config:
		blur(src,dst,Size(11,11));
		namedWindow("blur_dog window", WINDOW_AUTOSIZE);
		imshow("blur_dog window", dst);
		break;


/***************************************************************************
*	高斯模糊
*		就是将 划取区域	kernel	内所有像素加权取均值 作为 中心点的像素值
*			将图像的轮廓也同样模糊化
****************************************************************************/
	case GaussianBlur_Config:
		GaussianBlur(src, dst, Size(11, 11), 0);
		namedWindow("GaussianBlur_dog window", WINDOW_AUTOSIZE);
		imshow("GaussianBlur_dog window", dst);
		break;


/***************************************************************************
*	中值模糊
*		就是将 划取区域	kernel	内所有像素取中间值 作为 中心点的像素值
****************************************************************************/
	case MedianBlur_Config:
		medianBlur(src, dst, 3);
		namedWindow("medianBlur_dog window", WINDOW_AUTOSIZE);
		imshow("medianBlur_dog window", dst);
		break;


/***************************************************************************
*	双边滤波
*		将边缘保留，其余进行高斯模糊；
*					一般用于人脸磨皮，美容；
****************************************************************************/
	case BilateralFilter_Config:
		bilateralFilter(src, dst, 7, 150, 3);
		namedWindow("bilateralFilter window", WINDOW_AUTOSIZE);
		imshow("bilateralFilter window", dst);
		break;


	default:
		printf("parameter of blur_operation error\n");
		break;
	}

	waitKey(0);
	return 0;
}








