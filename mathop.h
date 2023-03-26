#ifndef MATHOP_H_
#define MATHOP_H_

#include<iostream>
using namespace std;

#define SIGNIFICANT_FIGURE_LIMIT 18//��Ч����λ������

//��ȡ��ֵ����Чλ��
template<class T>
int DigitOfSignificantFigure(const T num) {
	double dMultiple = 1.0;
	int64_t iFigure = 0;
	bool bOverflow = true;//�����־
	int iDigit = 0;//��ֵ����Ч����

	for (dMultiple = 1.0; dMultiple < INT64_MAX; dMultiple = dMultiple * 10) {
		if (abs(num * dMultiple) > INT64_MAX) {//���double��ֵ��С�����������������
			break;
		}

		if (num * dMultiple - int64_t(num * dMultiple) == 0) {//����double��ֵ������С��
			iFigure = int64_t(num * dMultiple);//��ȡ����С����doubleֵ
			bOverflow = false;//double��ֵδ���
			break;
		}
	}

	if (!bOverflow) {//�����ֵ��δ���
		for (int64_t i = 1; iDigit <= SIGNIFICANT_FIGURE_LIMIT; i = i * 10) {
			if (abs(iFigure / i) > 0) {
				iDigit++;//��Ч���ּ�1
			}
			else {
				break;
			}
		}
	}
	else {
		//�쳣����
		cout << "��ֵ���" << endl;
	}
	return iDigit;
}

//��ȡ������ֵ����С������
int64_t LeastCommonMultiple(const int64_t, const int64_t);

//��ȡ������ֵ�����Լ��
int64_t GreatestCommonDivisor(const int64_t, const int64_t);

#endif