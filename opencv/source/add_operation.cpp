#include <add_operation.h>

using namespace cv;
using namespace std;

int add_operation(void)
{
	Mat src = imread("E:/opencv/opencv_code/dog.jpg");
	if (src.empty())
	{
		printf("cannot find the picture");
		return -1;
	}

	Mat dst = Mat(src.size(), src.type());
	dst = Scalar(255, 255, 255);

	line(dst, Point(50, 50), Point(250, 250), Scalar(0, 0, 0), 2, 4);

	rectangle(dst, Rect(50, 50, 200, 200), Scalar(0, 0, 255), 2, 4);

	circle(dst, Point(150, 150), 100, Scalar(0, 255, 0), 2, 4);

	ellipse(dst, Point(150, 150), Size(100, 50), 0, 0, 360, Scalar(255, 0, 0), 2, 4);

	Point ptr[1][3] = { Point(150,50),Point(50,250),Point(250,250) };
	int nps[] = { 3 };
	const Point* ppt[] = { ptr[0] };
	fillPoly(dst,ppt,nps,1, Scalar(255, 0, 0),4);

	putText(dst, "Lee Young", Point(50, 50), FONT_HERSHEY_SCRIPT_SIMPLEX, 1.0, Scalar(255, 0, 0),1,4);
	
	namedWindow("add window", WINDOW_AUTOSIZE);
	
	imshow("add window", dst);

	waitKey(0);
	return 0;
}
/*绘制图形，文字*/
int add_random_operation(void)
{
	Mat src = imread("E:/opencv/opencv_code/dog.jpg");
	if (src.empty())
	{
		printf("cannot find the picture");
		return -1;
	}

	Mat dst = Mat(src.rows/2,src.cols/2, src.type());
	dst = Scalar(0, 0, 0);
	
	RNG rng;/*产生随机数的对象*/
	
	Point P1, P2;
	
	for(int i = 0;1;i++)
	{
		P1.y = rng.uniform(0, src.rows/2);
		P1.x = rng.uniform(0, src.cols/2);
		P2.y = rng.uniform(0, src.rows/2);
		P2.x = rng.uniform(0, src.cols/2);
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));

		if (((P1.y + P2.y) / 2 == src.rows / 4) && (((P1.x + P2.x) / 2 == src.cols / 4)))
		{
			line(dst, P1, P2, color, 1, 16, 0);
			if(waitKey(100)>0)
				return 0;
			namedWindow("add window", WINDOW_AUTOSIZE);
			imshow("add window", dst);
		}
	}
	return 0;
}
