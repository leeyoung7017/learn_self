#ifndef THREHOLD_OPERATION_H
#define THREHOLD_OPERATION_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>


#define threshold_opera 1	/*��ֵ����*/
/********************************************************************************************************************
*	threshold( InputArray src, OutputArray dst, double thresh, double maxval, int type );
*		para:	
*				thresh : �������ֵ
*				maxval : ��ֵ���������ֵ��255�� 
*				type   : ThresholdTypes		THRESH_BINARY				��������ֵ�� -> ������ֵΪ1 С����ֵΪ0
*											THRESH_BINARY_INV			����������ֵ�� -> ������ֵΪ0 С����ֵΪ1
*											THRESH_TRUNC				�ض���ֵ�� -> ������ֵΪ��ֵ��С����ֵ����
*											THRESH_TOZERO				��ֵ��Ϊ0 -> ������ֵ�Ĳ��䣬С����ֵ��ȫΪ0
*											THRESH_TOZERO_INV			����ֵ��Ϊ0 -> ������ֵΪ0��С����ֵ����
*	   										THRESH_MASK      
*											THRESH_OTSU					ʹ��Otsu�㷨ѡ��������ֵ
*											THRESH_TRIANGLE				ʹ���������㷨ѡ�������ֵ
*		return:	double						 
**********************************************************************************************************************/


#define adaptiveThreshold_opera 2	/*����Ӧ��ֵ����*/
/*****************************************************************************************************************************************
*	 adaptiveThreshold( InputArray src, OutputArray dst,double maxValue, int adaptiveMethod,int thresholdType, int blockSize, double C );
*		para:
*				maxValue		: ��ֵ���������ֵ��255��
*				adaptiveMethod	: ����Ӧ��ֵ�㷨��ȷ����ֵ��			ADAPTIVE_THRESH_MEAN_C		��ֵ��ֵ
*																		ADAPTIVE_THRESH_GAUSSIAN_C	��˹��ֵ
*				thresholdType   : ThresholdTypes						THRESH_BINARY				��������ֵ�� -> ������ֵΪ1 С����ֵΪ0
*																		THRESH_BINARY_INV			����������ֵ�� -> ������ֵΪ0 С����ֵΪ1
*																		THRESH_TRUNC				�ض���ֵ�� -> ������ֵΪ��ֵ��С����ֵ����
*																		THRESH_TOZERO				��ֵ��Ϊ0 -> ������ֵ�Ĳ��䣬С����ֵ��ȫΪ0
*																		THRESH_TOZERO_INV			����ֵ��Ϊ0 -> ������ֵΪ0��С����ֵ����
*	   																	THRESH_MASK
*																		THRESH_OTSU					ʹ��Otsu�㷨ѡ��������ֵ
*																		THRESH_TRIANGLE				ʹ���������㷨ѡ�������ֵ
				C: ƫ����ֵ������Ӧ��ֵ�㷨�õ�����ֵ��ȥC������������ֵ
*		return:	void
********************************************************************************************************************************************/


int threhold_operation(int flag);


#endif // !THREHOLD_OPERATION_H

