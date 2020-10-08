#include <mask_operation.h>

using namespace cv;

int mask_operation(void)
{
	Mat src = imread("E:/opencv/opencv_code/dog.jpg");
	if (!src.data)
	{
		printf("connot find the picture");
		return -1;
	}
	
	Mat dst;
	Mat kernel = ( Mat_ <char>(3,3)<< 0, -1, 0,
									 -1, 5, -1, 
									  0, -1, 0);
	
	/*ͨ���˲���������Ĥ����*/
	filter2D(src,dst,src.depth(),kernel);
	
	namedWindow("girl Window",WINDOW_AUTOSIZE);
	imshow("girl Window", dst);
	waitKey(0);
	return 0;
}
/*��Ĥ��mask��Ҳ����Ϊkernel��ͨ����Ĥ��������ʵ��ͼ��Աȶ����*/
/* I(i,j) = 5 * I(i,j) - I(i-1,j) - I(i+1,j) - I(i,j-1) - I(i,j+1); */
