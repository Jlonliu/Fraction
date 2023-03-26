#include "mathop.h"

int64_t LeastCommonMultiple(const int64_t numL, const int64_t numR) {
	int64_t m, n, r, lcm;//gcdΪ���Լ��������lcmΪ��С����������

	m = numL;
	n = numR;
	//�㷨��շת����������Լ��
	//��С�������������������ĳ˻��������Լ��
	//lcm = m * n;//�ٶ���С���������������������ĳ˻����������޸�

	do {//շת�����
		r = m % n;//������
		m = n;//����ѭ���ĳ���n������m����Ϊ��һ��ѭ����Ϊ������
		n = r;//����ѭ��������r������n����Ϊ��һ��ѭ����Ϊ����
	} while (r > 0);//����rΪ0ʱ��mֵ���������Լ��
	lcm = numL / m;//mΪ���Լ��

	//��Ϊ������lcm��numRҪ��ˣ�������ߵ�λ��֮�ʹ���int64_t���ܴ洢�����λ�����������
	//����Ҫ��ȷ�����ߵ�λ���Ƿ����
	if (DigitOfSignificantFigure(lcm) + DigitOfSignificantFigure(numR) < SIGNIFICANT_FIGURE_LIMIT) {
		lcm = lcm * numR;//lcmΪ��С������
	}
	else {
		//Marked
		//�쳣����
		cout << "����󹫱����ĺ�������ֵ�����" << endl;
	}
	return lcm;//
}

int64_t GreatestCommonDivisor(const int64_t numL, const int64_t numR) {
	int64_t m, n, r;

	m = numL;
	n = numR;
	//�㷨��շת����������Լ��
	//��С�������������������ĳ˻��������Լ��
	//lcm = m * n;//�ٶ���С���������������������ĳ˻����������޸�

	do {//շת�����
		r = m % n;//������
		m = n;//����ѭ���ĳ���n������m����Ϊ��һ��ѭ����Ϊ������
		n = r;//����ѭ��������r������n����Ϊ��һ��ѭ����Ϊ����
	} while (r > 0);//����rΪ0ʱ��mֵ���������Լ��
	return m;
}