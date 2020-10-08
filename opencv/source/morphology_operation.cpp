#include <morphology_operation.h>
/******************************
*��̬ѧ������
*			���ͣ�Ԫ�������ֵ
*			��ʴ��Ԫ������Сֵ
*******************************/
using namespace cv;
using namespace std;

Mat src = imread("E:/opencv/opencv_code/dog.jpg");
Mat dst;
int size_increment = add_Size;

void dilate_operation(int pos, void* userdata);
void erode_operation(int pos, void* userdata);


int morphologyBase_operation(int flag)
{
	
	
	if (src.empty())
	{
		printf("connot find the picture\n");
		return -1;
	}



	namedWindow("OUT_WIN", WINDOW_AUTOSIZE);
	switch (flag)
	{
	case Dilate_Config:
		createTrackbar("Size_TrackBar","OUT_WIN",&size_increment,MAX_Size, dilate_operation);
		break;
	case Erode_Config:
		createTrackbar("Size_TrackBar", "OUT_WIN", &size_increment, MAX_Size, erode_operation);
		break;
	default:
		printf("parameter of morphology_operation error\n");
		break;
	}
	
	waitKey(0);
	return 0;
}
void dilate_operation(int pos, void* userdata)
{
	src.copyTo(dst);

	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(size_increment + 1, size_increment + 1));

	dilate(src, dst, element);

	imshow("OUT_WIN", dst);

}

void erode_operation(int pos, void* userdata)
{
	src.copyTo(dst);

	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(size_increment + 1, size_increment + 1));
	
	erode(src, dst, element);
		
	imshow("OUT_WIN", dst);

}


int morphologyEx_operation(int flag)
{
	Mat src = imread("E:/opencv/opencv_code/finger.png");
	if (!src.data)
	{
		printf("cannot find the picture\n");
		return -1;
	}
	
	Mat dst;

	/*����Ԫ������*/
	Mat kernel = getStructuringElement( MORPH_ELLIPSE, Size(3,3));			//	MORPH_RECT  MORPH_CROSS  MORPH_ELLIPSE
	/*��̬ѧ�Ĳ���*/
	morphologyEx(src, dst, flag, kernel);


	namedWindow("src_Win", WINDOW_AUTOSIZE);
	imshow("src_Win", dst);

	waitKey(0);
	return 0;

}

int  BinImageEdge_morphologyEx(void)
{
	Mat src = imread("E:/opencv/opencv_code/man.png");
	if (!src.data)
	{
		printf("cannot find the picture\n");
		return -1;
	}

	Mat dst,dst1;

	/*����Ԫ������*/
	Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));			//	MORPH_RECT  MORPH_CROSS  MORPH_ELLIPSE
	/*��̬ѧ�Ĳ���*/
	morphologyEx(src, dst, MORPH_DILATE, kernel);

	absdiff(src, dst, dst1);

	namedWindow("src_Win", WINDOW_AUTOSIZE);
	imshow("src_Win", dst1);

	waitKey(0);
	return 0;
}

int Fingerprint_morphologyEx(void) 
{
	Mat src = imread("E:/opencv/opencv_code/finger.png");
	if (!src.data)
	{
		printf("cannot find the picture\n");
		return -1;
	}

	Mat dst;

	/*����Ԫ������*/
	Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));			//	MORPH_RECT  MORPH_CROSS  MORPH_ELLIPSE

	morphologyEx(src, dst, MORPH_OPEN, kernel); /*��������ȥ��*/

	morphologyEx(dst, dst, MORPH_CLOSE, kernel);/*��ָ���ϵĺ�����ʧ*/

	namedWindow("src_Win", WINDOW_AUTOSIZE);
	imshow("src_Win", dst);
	waitKey(0);
	return 0;
}
