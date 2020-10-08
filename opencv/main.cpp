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
	//basic_operation();						/*��������*/
	//mask_operation();							/*��Ĥ����*/
	//pixel_operation();						/*���ز���,��ȡ����ֵ*/
	//pixel_mixing();							/*���ػ�ϣ�����ͼƬ*/
	//attribute_operation();					/*���Բ���������;�Աȶ�*/
	//add_operation();							/*���ͼ�Σ�����*/
	//add_random_operation();					/*�������*/
	//blur_operation(Blur_Config);				/*ģ���˲�����*//*Blur_Config��ֵģ��*//*GaussianBlur_Config��˹ģ��*//*MedianBlur_Config��ֵ�˲�*//*BilateralFilter_Config˫���˲�*/
	//morphologyBase_operation(Erode_Config);	/*��̬ѧ����*//*Dilate_Config����*//*Erode_Config��ʴ*/	/*����̬ѧ�����м�����	kernel	�仯�ĸ�����trackbar*/
	//morphologyEx_operation(MORPH_OPEN);		/*��̬ѧ��������*/
	//BinImageEdge_morphologyEx();				/*��ֵͼ���Ե����*/
	//Fingerprint_morphologyEx();				/*ָ�Ʋ���*/
	threhold_operation(adaptiveThreshold_opera);		/*��ֵ������*//*threshold_opera��ֵ������*//*adaptiveThreshold_opera����Ӧ��ֵ������*/
	return 0;
}