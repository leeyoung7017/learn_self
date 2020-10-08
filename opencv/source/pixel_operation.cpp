#include <pixel_operation.h>

using namespace cv;

int pixel_operation(void)
{
	Mat src = imread("E:/opencv/opencv_code/dog.jpg");
	if (src.empty())
	{
		printf("cannot find the picture");
		return -1;
	}

	
	int height = src.rows;
	int width = src.cols;
	int channels = src.channels();
	for (int row = 0;row < height;row++)
	{
		for (int col = 0;col < width;col++)
		{
			for (int channel = 0;channel < channels;channel++)
			{
				int pixel = src.ptr(row, col)[channel];//	获取各通道各个像素的具体值
										src.ptr(row, col)[channel] = 255 - pixel;
										//src.ptr<uchar>(row, col)[channel] =  ~pixel;		//两个语句等价
			}
		}
	}
	
	//Mat src_gray;
	//bitwise_not(src, src_gray);//按位取反,操作等同于上方注释


	namedWindow("dog Window", WINDOW_AUTOSIZE);
	imshow("dog Window", src);
	waitKey(0);
	return 0;
}


