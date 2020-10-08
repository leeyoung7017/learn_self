#include <threshold_operation.h>

using namespace cv;
using namespace std;

int threhold_operation(int flag)
{
	Mat src = imread("E:/opencv/opencv_code/dog_gray.png", IMREAD_GRAYSCALE);
	if (src.empty())
	{
		printf("cannot find the picture ...\n");
		return -1;
	}

	Mat dst;

	/*阈值处理*/
	switch (flag)
	{
	case threshold_opera:
		threshold(src, dst, 100, THRESH_BINARY, THRESH_BINARY);
		namedWindow("threshold_opera", WINDOW_AUTOSIZE);
		imshow("threshold_opera",dst);
		break;
	case adaptiveThreshold_opera:
		adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,3,0);
		namedWindow("adaptiveThreshold_opera", WINDOW_AUTOSIZE);
		imshow("adaptiveThreshold_opera", dst);
		break;
	default:
		break;
	}

	waitKey(0);
	return 0;
}