#ifndef MORPHOLOGY_OPERATION_H
#define MORPHOLOGY_OPERATION_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

/*应用trackbar实现腐蚀膨胀*/
int morphologyBase_operation(int flag);
int morphologyEx_operation(int flag);
/********************************************************************************************************************************
*parameter：int flag	主要作为二值图像的操作（或是针对高亮部分的操作）
*					MORPH_ERODE		腐蚀操作		：高亮部分减少						：区域内的最小值
*					MORPH_DILATE	膨胀操作		：高亮部分增加						：区域内的最大值
*					MORPH_OPEN		开操作			：小的高亮部分消失					：先腐蚀后膨胀(与腐蚀的区别就是大的高亮部分不会减小)
*					MORPH_CLOSE		闭操作			：小的暗瑕疵消失					：先膨胀后腐蚀(与膨胀的区别就是大的高亮部分不会扩大)
*					MORPH_GRADIENT	形态学梯度		：						：膨胀图与腐蚀图的差值
*					MORPH_TOPHAT	顶帽操作		：						：原图像与开操作图像的差值
*					MORPH_BLACKHAT	黑帽操作		：						：原图像与闭操作图像的差值
*					MORPH_HITMISS
*********************************************************************************************************************************/

/********************************************************************
*		二值图像边缘提取
*				原图像与腐蚀图像或膨胀图像的像素相减
*********************************************************************/
int  BinImageEdge_morphologyEx(void);
/********************************************************************
*		指纹图像杂质处理操作
					MORPH_OPEN		开操作			
*					MORPH_CLOSE		闭操作	
				
*********************************************************************/
int Fingerprint_morphologyEx(void);



#define Dilate_Config 0
#define Erode_Config 1  
#define add_Size 2
#define MAX_Size 21

#endif


