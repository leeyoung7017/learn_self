#include <basic_operation.h>

using namespace cv;
using namespace std;

int basic_operation(void)
{
	/*将图片复制到Mat对象*/
	Mat input = imread("E:/opencv/opencv_code/dog.jpg");
	if (input.empty())
	{
		printf("cannot find the picture");
		return -1;
	}


	/*转换图像*/
	Mat output;
	cvtColor(input, output, COLOR_BGR2GRAY);



	/*打印Mat对象的各个参数*/
	cout << "行数：" << input.rows << endl;
	cout << "列数：" << input.cols << endl;
	cout << "通道数：" << input.channels() << endl;
	cout << "通道数：" << output.channels() << endl;
	cout << "尺寸：" << input.size << endl;


	/*显示窗口设置*/
	namedWindow("dog window", WINDOW_AUTOSIZE);

	/*展示图片*/
	imshow("dog window", output);

	/*保存图像*/
	imwrite("E:/opencv/opencv_code/dog_gray.png", output);

	/*任意键等待*/
	waitKey(0);
	return 0;
}
