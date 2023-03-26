#ifndef FRACTIONAL_H_
#define FRACTIONAL_H_
//�����ࣺ�÷�������С�����м��㣬����С�����18λ�ľ���
//������ľ��Ƚ�����double������λ�������ڴ��Сȴ���˱��������޷���doubleһ���洢����
//��ô�ұ�д�������������ڣ�
//�ұ�д�����������Ҫ��һ����Ϊ���ܹ��õ����µ����֣�
//����Ҫ��������10.0������9.999999999999999999
//��Ҳ���뿴��������һ��0.0000000000000001��Ϊ��һ��������˵õ���0.1������Ӱ����ֵ��������
#include "mathop.h"
#include<iostream>
using namespace std;

namespace myFraction{

#define FRACTIONAL_PERCISION_LIMIT (1E18)
typedef long long Ftype;

class Fraction {
private:
	Ftype numer_ = 0;//����
	Ftype denomin_ = 1;//��ĸ
	void __fraction_simplify(void);//����Լ��

public:
	Fraction() {}
	~Fraction() {}
	template<class T>
	Fraction(T num) { numer_ = num; }//����int����char��ֱ�Ӹ�ֵ������
	Fraction(float num);//����float
	Fraction(double num);//	doubleʱ�����������ת��Ϊ����
	Fraction(Ftype numer, Ftype denomin);//���������湹������

	void SetNumerator(const Ftype);//���÷���
	void SetDenominator(const Ftype);//���÷�ĸ
	Ftype Denominator(void)const;//���ط�ĸ
	Ftype Numerator(void)const;//���ط���
	Ftype Int64(void)const;//����int���ķ���
	double Double(void)const;//����double���ķ���
	
	void operator=(const Fraction&);
	template<class T>
	void operator=(const T num) { *this = Fraction(num); }

	Fraction operator+(const Fraction&)const;
	Fraction operator-(const Fraction&)const;
	Fraction operator*(const Fraction&)const;
	Fraction operator/(const Fraction&)const;

	template<class T>
	Fraction operator+(const T num)const { return *this + Fraction(num); }
	template<class T>
	Fraction operator-(const T num)const { return *this - Fraction(num); }
	template<class T>
	Fraction operator*(const T num)const { return *this * Fraction(num); }
	template<class T>
	Fraction operator/(const T num)const { return *this / Fraction(num); }
	
	template<class T>
	friend Fraction operator+(const T num,const Fraction& frac){ return Fraction(num) + frac; }
	template<class T>
	friend Fraction operator-(const T num, const Fraction& frac) { return Fraction(num) - frac; }
	template<class T>
	friend Fraction operator*(const T num, const Fraction& frac) { return Fraction(num) * frac; }
	template<class T>
	friend Fraction operator/(const T num, const Fraction& frac) { return Fraction(num) / frac; }

	//���˸��ڵ�
	//ģ�庯�������붨�岻�ֿܷ���ͷ�۵���
	//linux����Ԫ���������붨�嶼���ֿܷ���
	//�������˸��ڵģ�C++�и�ƨ����
	//ֱ����python����
	friend ostream& operator<<(ostream& os, const Fraction& frac){
		if (frac.Denominator() == 1) {//�����ĸΪ1
		cout << frac.Numerator();//ֱ���������
		}
		else {
		cout << frac.Numerator() << "/" << frac.Denominator();
		}
	
	return os;
	}
};

}

#endif