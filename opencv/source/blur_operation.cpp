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
*	��ֵģ��
*		���ǽ� ��ȡ����	kernel	����������ȡ��ֵ ��Ϊ ���ĵ�����ֵ
*		���ǲ��������׵�ģ��
****************************************************************************/
	case Blur_Config:
		blur(src,dst,Size(11,11));
		namedWindow("blur_dog window", WINDOW_AUTOSIZE);
		imshow("blur_dog window", dst);
		break;


/***************************************************************************
*	��˹ģ��
*		���ǽ� ��ȡ����	kernel	���������ؼ�Ȩȡ��ֵ ��Ϊ ���ĵ������ֵ
*			��ͼ�������Ҳͬ��ģ����
****************************************************************************/
	case GaussianBlur_Config:
		GaussianBlur(src, dst, Size(11, 11), 0);
		namedWindow("GaussianBlur_dog window", WINDOW_AUTOSIZE);
		imshow("GaussianBlur_dog window", dst);
		break;


/***************************************************************************
*	��ֵģ��
*		���ǽ� ��ȡ����	kernel	����������ȡ�м�ֵ ��Ϊ ���ĵ������ֵ
****************************************************************************/
	case MedianBlur_Config:
		medianBlur(src, dst, 3);
		namedWindow("medianBlur_dog window", WINDOW_AUTOSIZE);
		imshow("medianBlur_dog window", dst);
		break;


/***************************************************************************
*	˫���˲�
*		����Ե������������и�˹ģ����
*					һ����������ĥƤ�����ݣ�
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








