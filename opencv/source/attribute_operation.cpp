#include <attribute_operation.h>

using namespace cv;
using namespace std;

int attribute_operation(void)
{
	Mat src, dst1,dst2;
	src = imread("E:/opencv/opencv_code/girl.jpg");
	
	if (!src.data)
	{
		printf("connot find the girl picture");
		return -1;
	}

	//dst1 = Mat(src.size(),src.type());
	//dst1 = Scalar(255,255,255);
	//dst1 = Mat::zeros(src.size(), src.type());

	//int height = src.rows;
	//int width = src.cols;
	//int channels = src.channels();
	//for (int row = 0;row < height;row++)
	//{
	//	for (int col = 0;col < width;col++)
	//	{
	//		for (int channel = 0;channel < channels;channel++)
	//		{
	//			int pixel = src.ptr(row, col)[channel];//	��ȡ��ͨ���������صľ���ֵ
	//			dst1.ptr(row, col)[channel] =saturate_cast<uchar>(1.2*pixel+30);
	//			//src.ptr<uchar>(row, col)[channel] =  ~pixel;		//�������ȼ�
	//		}
	//	}
	//}
	//namedWindow("girl1 window", WINDOW_AUTOSIZE);
	//imshow("girl1 window", dst1);
	
	src.convertTo(dst2,src.type(),1.2,30);

	namedWindow("girl window", WINDOW_AUTOSIZE);
	imshow("girl window", src);
	namedWindow("girl2 window", WINDOW_AUTOSIZE);
	imshow("girl2 window", dst2);
	
	waitKey(0);
	return 0;
}
/*ͼ�������
			���� �Աȶ�	�����
			g(i,j) = a * f(i,j) +  b;   a > 0; b �� �������;

			convertTO() Ҳ����ʵ������ �ԱȶȵĲ���
*/