#include "mathop.h"

int64_t LeastCommonMultiple(const int64_t numL, const int64_t numR) {
	int64_t m, n, r, lcm;//gcd为最大公约数变量，lcm为最小公倍数变量

	m = numL;
	n = numR;
	//算法：辗转相除法求最大公约数
	//最小公倍数是两个正整数的乘积除以最大公约数
	//lcm = m * n;//假定最小公倍数即是两个正整数的乘积，后面再修改

	do {//辗转相除法
		r = m % n;//求余数
		m = n;//本次循环的除数n，赋给m，作为下一次循环作为被除数
		n = r;//本次循环的余数r，赋给n，作为下一次循环作为除数
	} while (r > 0);//余数r为0时的m值，即是最大公约数
	lcm = numL / m;//m为最大公约数

	//因为接下来lcm和numR要相乘，如果两者的位数之和大于int64_t所能存储的最大位数，将会溢出
	//所以要先确认两者的位数是否过大
	if (DigitOfSignificantFigure(lcm) + DigitOfSignificantFigure(numR) < SIGNIFICANT_FIGURE_LIMIT) {
		lcm = lcm * numR;//lcm为最小共倍数
	}
	else {
		//Marked
		//异常处理
		cout << "求最大公倍数的函数中数值溢出了" << endl;
	}
	return lcm;//
}

int64_t GreatestCommonDivisor(const int64_t numL, const int64_t numR) {
	int64_t m, n, r;

	m = numL;
	n = numR;
	//算法：辗转相除法求最大公约数
	//最小公倍数是两个正整数的乘积除以最大公约数
	//lcm = m * n;//假定最小公倍数即是两个正整数的乘积，后面再修改

	do {//辗转相除法
		r = m % n;//求余数
		m = n;//本次循环的除数n，赋给m，作为下一次循环作为被除数
		n = r;//本次循环的余数r，赋给n，作为下一次循环作为除数
	} while (r > 0);//余数r为0时的m值，即是最大公约数
	return m;
}