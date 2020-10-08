#ifndef THREHOLD_OPERATION_H
#define THREHOLD_OPERATION_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>


#define threshold_opera 1	/*阈值操作*/
/********************************************************************************************************************
*	threshold( InputArray src, OutputArray dst, double thresh, double maxval, int type );
*		para:	
*				thresh : 具体的阈值
*				maxval : 二值化后的像素值（255） 
*				type   : ThresholdTypes		THRESH_BINARY				二进制阈值化 -> 大于阈值为1 小于阈值为0
*											THRESH_BINARY_INV			反二进制阈值化 -> 大于阈值为0 小于阈值为1
*											THRESH_TRUNC				截断阈值化 -> 大于阈值为阈值，小于阈值不变
*											THRESH_TOZERO				阈值化为0 -> 大于阈值的不变，小于阈值的全为0
*											THRESH_TOZERO_INV			反阈值化为0 -> 大于阈值为0，小于阈值不变
*	   										THRESH_MASK      
*											THRESH_OTSU					使用Otsu算法选择最优阈值
*											THRESH_TRIANGLE				使用三角形算法选择最佳阈值
*		return:	double						 
**********************************************************************************************************************/


#define adaptiveThreshold_opera 2	/*自适应阈值操作*/
/*****************************************************************************************************************************************
*	 adaptiveThreshold( InputArray src, OutputArray dst,double maxValue, int adaptiveMethod,int thresholdType, int blockSize, double C );
*		para:
*				maxValue		: 二值化后的像素值（255）
*				adaptiveMethod	: 自适应阈值算法（确定阈值）			ADAPTIVE_THRESH_MEAN_C		均值阈值
*																		ADAPTIVE_THRESH_GAUSSIAN_C	高斯阈值
*				thresholdType   : ThresholdTypes						THRESH_BINARY				二进制阈值化 -> 大于阈值为1 小于阈值为0
*																		THRESH_BINARY_INV			反二进制阈值化 -> 大于阈值为0 小于阈值为1
*																		THRESH_TRUNC				截断阈值化 -> 大于阈值为阈值，小于阈值不变
*																		THRESH_TOZERO				阈值化为0 -> 大于阈值的不变，小于阈值的全为0
*																		THRESH_TOZERO_INV			反阈值化为0 -> 大于阈值为0，小于阈值不变
*	   																	THRESH_MASK
*																		THRESH_OTSU					使用Otsu算法选择最优阈值
*																		THRESH_TRIANGLE				使用三角形算法选择最佳阈值
				C: 偏离阈值，自适应阈值算法得到的阈值减去C才是真正的阈值
*		return:	void
********************************************************************************************************************************************/


int threhold_operation(int flag);


#endif // !THREHOLD_OPERATION_H

