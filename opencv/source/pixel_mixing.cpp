#include <pixel_mixing.h>
using namespace cv;
using namespace std;

int pixel_mixing(void)
{
	Mat src1 = imread("E:/opencv/opencv_code/girl.jpg");
	Mat src2 = imread("E:/opencv/opencv_code/dog.jpg");
	Mat dst;
	double alpha = 0.5;
	double gamma = 0.0;
	if (!src1.data)
	{
		printf("connot find the girl picture");
		return -1;
	}

	if (!src2.data)
	{
		printf("connot find the girl picture");
		return -1;
	}

	if ((src1.type() == src2.type()) && (src1.size() == src2.size()))
	{
		addWeighted(src1,alpha,src2,1-alpha, gamma ,dst);/*权重相加*/
		//add(src1, src2, dst);/*直接相加*/
		//multiply(src1, src2, dst);/*像素相乘*/
		namedWindow("girl window", WINDOW_AUTOSIZE);
		imshow("girl window", src1);

		namedWindow("dog window", WINDOW_AUTOSIZE);
		imshow("dog window", src2);

		namedWindow("linear_mixing window", WINDOW_AUTOSIZE);
		imshow("linear_mixing window", dst);

	}
	else 
	{
		cout << "the sizes and types of the pictures are different" << endl;
		return -1;
	}

	waitKey(0);
	return 0;
}


/*
	addWeighted()
		线性混合操作 g(x) = (1-a) * f(x) + a * h(x) + gamma;		
								 1-a 为 beta	a 为 alpha  	gamma 为 gamma
		
		两张图的大小和类型必须一致才可以
*/

