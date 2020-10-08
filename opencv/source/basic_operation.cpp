#include <basic_operation.h>

using namespace cv;
using namespace std;

int basic_operation(void)
{
	/*��ͼƬ���Ƶ�Mat����*/
	Mat input = imread("E:/opencv/opencv_code/dog.jpg");
	if (input.empty())
	{
		printf("cannot find the picture");
		return -1;
	}


	/*ת��ͼ��*/
	Mat output;
	cvtColor(input, output, COLOR_BGR2GRAY);



	/*��ӡMat����ĸ�������*/
	cout << "������" << input.rows << endl;
	cout << "������" << input.cols << endl;
	cout << "ͨ������" << input.channels() << endl;
	cout << "ͨ������" << output.channels() << endl;
	cout << "�ߴ磺" << input.size << endl;


	/*��ʾ��������*/
	namedWindow("dog window", WINDOW_AUTOSIZE);

	/*չʾͼƬ*/
	imshow("dog window", output);

	/*����ͼ��*/
	imwrite("E:/opencv/opencv_code/dog_gray.png", output);

	/*������ȴ�*/
	waitKey(0);
	return 0;
}
