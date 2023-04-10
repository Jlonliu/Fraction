#ifndef MATHOP_H_
#define MATHOP_H_

#include<iostream>
using namespace std;

#define SIGNIFICANT_FIGURE_LIMIT 18//有效数字位数极限

//获取数值的有效位数
template<class T>
int DigitOfSignificantFigure(const T num) {
	double dMultiple = 1.0;
	int64_t iFigure = 0;
	bool bOverflow = true;//溢出标志
	int iDigit = 0;//数值的有效数字

	for (dMultiple = 1.0; dMultiple < INT64_MAX; dMultiple = dMultiple * 10) {
		if (abs(num * dMultiple) > INT64_MAX) {//如果double数值在小数消除过程中溢出了
			break;
		}

		if (num * dMultiple - int64_t(num * dMultiple) == 0) {//消除double数值的所有小数
			iFigure = int64_t(num * dMultiple);//获取消除小数的double值
			bOverflow = false;//double数值未溢出
			break;
		}
	}

	if (!bOverflow) {//如果数值尚未溢出
		for (int64_t i = 1; iDigit <= SIGNIFICANT_FIGURE_LIMIT; i = i * 10) {
			if (abs(iFigure / i) > 0) {
				iDigit++;//有效数字+1
			}
			else {
				break;
			}
		}
	}
	else {
		//异常处理
		cout << "数值溢出" << endl;
	}
	return iDigit;
}

//获取两个数值的最小公倍数
int64_t LeastCommonMultiple(const int64_t, const int64_t);

//获取两个数值的最大公约数
int64_t GreatestCommonDivisor(const int64_t, const int64_t);

#endif