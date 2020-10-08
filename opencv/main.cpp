#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include <mask_operation.h>
#include <basic_operation.h>
#include <pixel_operation.h>
#include <pixel_mixing.h>
#include <attribute_operation.h>
#include <add_operation.h>
#include <blur_operation.h>
#include <morphology_operation.h>
#include <threshold_operation.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	//basic_operation();						/*基本操作*/
	//mask_operation();							/*掩膜操作*/
	//pixel_operation();						/*像素操作,获取像素值*/
	//pixel_mixing();							/*像素混合，叠加图片*/
	//attribute_operation();					/*属性操作：亮度;对比度*/
	//add_operation();							/*添加图形，文字*/
	//add_random_operation();					/*随意添加*/
	//blur_operation(Blur_Config);				/*模糊滤波操作*//*Blur_Config均值模糊*//*GaussianBlur_Config高斯模糊*//*MedianBlur_Config中值滤波*//*BilateralFilter_Config双边滤波*/
	//morphologyBase_operation(Erode_Config);	/*形态学操作*//*Dilate_Config膨胀*//*Erode_Config腐蚀*/	/*在形态学操作中加入了	kernel	变化的跟踪条trackbar*/
	//morphologyEx_operation(MORPH_OPEN);		/*形态学常见操作*/
	//BinImageEdge_morphologyEx();				/*二值图像边缘操作*/
	//Fingerprint_morphologyEx();				/*指纹操作*/
	threhold_operation(adaptiveThreshold_opera);		/*二值化处理*//*threshold_opera阈值化处理*//*adaptiveThreshold_opera自适应阈值化处理*/
	return 0;
}