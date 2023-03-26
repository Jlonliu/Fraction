#include "fraction.h"
#include<iostream>

using namespace std;
using namespace myFraction;

void Fraction::__fraction_simplify(void) {
	Ftype gcd = GreatestCommonDivisor(numer_, denomin_);// ���Լ������
	numer_ = numer_/gcd;
	denomin_ = denomin_/gcd;
}

Fraction::Fraction(float num) {
	bool bOverflow = true;//double��ֵ�����־
	double denomin = 1.0;//��ĸ
	int i = 0;
	//double�ͽ����ṩ16λ��׼��Ч����
	//�����ܹ��ṩ18λ��׼��Ч���֣�������double֮��
	//����double���������������洢���ٴ��ݵľ޴����֣�����Ҫ��֤���ȣ�ֻ�ܴ洢18���ݵ��������
	//�������ȵ͵ľ޴�double���֣������ܿ����޷��洢������Ҫ�ȼ��double��ֵת��Ϊ�����Ƿ�����
	for (denomin = 1.0; denomin < INT64_MAX; denomin = denomin * 10) {
		if (abs(num * denomin) > INT64_MAX) {//���double��ֵ��С�����������������
			break;
		}
		if (num * denomin - Ftype(num * denomin) == 0) {//����double��ֵ������С��
			bOverflow = false;//double��ֵδ���
			break;
		}
	}

	if (bOverflow) {//double��ֵ����
		//Marked
		//�쳣����
		//��ʱ�ȱ�����
		cout << "ת��Ϊ��������ֵ����" << endl;

	}
	else {
		numer_ = Ftype(num * denomin);
		denomin_ = Ftype(denomin);
		__fraction_simplify();//����Լ��
	}
}

Fraction::Fraction(double num) {
	bool bOverflow = true;//double��ֵ�����־
	double denomin = 1.0;//��ĸ
	int i = 0;
	//double�ͽ����ṩ16λ��׼��Ч����
	//�����ܹ��ṩ18λ��׼��Ч���֣�������double֮��
	//����double���������������洢���ٴ��ݵľ޴����֣�����Ҫ��֤���ȣ�ֻ�ܴ洢18���ݵ��������
	//�������ȵ͵ľ޴�double���֣������ܿ����޷��洢������Ҫ�ȼ��double��ֵת��Ϊ�����Ƿ�����
	for (denomin = 1.0; denomin < INT64_MAX; denomin = denomin * 10) {
		if (abs(num * denomin) > INT64_MAX) {//���double��ֵ��С�����������������
			break;
		}
		if (num * denomin - Ftype(num * denomin) == 0) {//����double��ֵ������С��
			bOverflow = false;//double��ֵδ���
			break;
		}
	}

	if (bOverflow) {//double��ֵ����
		//Marked
		//�쳣����
		//��ʱ�ȱ�����
		cout << "ת��Ϊ��������ֵ����" << endl;

	}
	else {
		numer_ = Ftype(num * denomin);
		denomin_ = Ftype(denomin);
		__fraction_simplify();//����Լ��
	}
}

Fraction::Fraction(Ftype numer, Ftype denomin) {
	if (denomin == 0) {//�����ĸΪ0
		//Marked
		//�쳣����
		//��ʱ�ȱ�����
		cout << "���󣺷�ĸ����Ϊ��0" << endl;
	}
	else {
		numer_ = numer;
		denomin_ = denomin;
		__fraction_simplify();//����Լ��
	}
}

void Fraction::SetNumerator(const Ftype num) {
	numer_ = num;
}

void Fraction::SetDenominator(const Ftype num) {
	denomin_ = num;
}

Ftype Fraction::Denominator(void)const {
	return denomin_;
}

Ftype Fraction::Numerator(void)const {
	return numer_;
}

Ftype Fraction::Int64(void)const {
	return numer_ / denomin_;
}

double Fraction::Double(void)const {
	return double(double(numer_) / double(denomin_));
}

void Fraction::operator=(const Fraction& frac) {
	numer_ = frac.Numerator();
	denomin_ = frac.Denominator();
}

Fraction Fraction::operator+(const Fraction& frac)const {
	Fraction fracThis = *this;
	Ftype lcm = LeastCommonMultiple(fracThis.Denominator(), frac.Denominator());//��ȡ��ĸ���Լ��
	Ftype fracThisMultiple = lcm / fracThis.Denominator();//���ӳ��ӣ���С���������Է�ĸ
	Ftype fracMultiple = lcm / frac.Denominator();//���ӳ��ӣ���С���������Է�ĸ
	fracThis.SetNumerator(fracThis.Numerator() * fracThisMultiple
		+ frac.Numerator() * fracMultiple);//���ӳ˳��Ӻ����
	//fracThis.SetDenominator(fracThis.Denominator() * frac.Denominator());//��ĸ���
	fracThis.SetDenominator(lcm);//��ȡ��ĸ
	return fracThis;
}

Fraction Fraction::operator-(const Fraction& frac)const {
	Fraction fracThis = *this;
	Ftype lcm = LeastCommonMultiple(fracThis.Denominator(), frac.Denominator());//��ȡ��ĸ���Լ��
	Ftype fracThisMultiple = lcm / fracThis.Denominator();//���ӳ��ӣ���С���������Է�ĸ
	Ftype fracMultiple = lcm / frac.Denominator();//���ӳ��ӣ���С���������Է�ĸ
	fracThis.SetNumerator(fracThis.Numerator() * fracThisMultiple
		- frac.Numerator() * fracMultiple);//���ӳ˳��Ӻ����
	//fracThis.SetDenominator(fracThis.Denominator() * frac.Denominator());//��ĸ���
	fracThis.SetDenominator(lcm);//��ȡ��ĸ
	return fracThis;
}

Fraction Fraction::operator*(const Fraction& frac)const {
	Fraction fracThis = *this;
	fracThis.SetNumerator(fracThis.Numerator() * frac.Numerator());//�������
	fracThis.SetDenominator(fracThis.Denominator() * frac.Denominator());//��ĸ���
	return fracThis;
}

Fraction Fraction::operator/(const Fraction& frac)const {
	Fraction fracThis = *this;
	fracThis.SetNumerator(fracThis.Numerator() * frac.Denominator());//���ӳ˷�ĸ
	fracThis.SetDenominator(fracThis.Denominator() * frac.Numerator());//��ĸ�˷���
	return fracThis;
}

// ostream& operator<<(ostream& os, const Fraction& frac) {
// 	if (frac.Denominator() == 1) {//�����ĸΪ1
// 		cout << frac.Numerator();//ֱ���������
// 	}
// 	else {
// 		cout << frac.Numerator() << "/" << frac.Denominator();
// 	}
	
// 	return os;
// }
