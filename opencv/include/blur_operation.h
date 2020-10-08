#ifndef BLUR_OPERATION_H
#define BLUR_OPERATION_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

int blur_operation(int flag);


#define Blur_Config 0
#define GaussianBlur_Config 1
#define MedianBlur_Config 2
#define BilateralFilter_Config 3

#endif