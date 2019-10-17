/*
问题描述
　　123321是一个非常特殊的数，它从左边读和从右边读是一样的。
  　输入一个正整数n， 编程求所有这样的五位和六位十进制数，满足各位数字之和等于n 。
输入格式
	输入一行，包含一个正整数n。
输出格式
	按从小到大的顺序输出满足条件的整数，每个整数占一行。
样例输入
	52
样例输出
	899998
	989989
	998899
数据规模和约定
	1<=n<=54。

*/


#include<iostream>
using namespace std;

void PalindromeNumber(int n)
{
	int a, b, c;
	for (a = 0; a < 10; ++a)
	{
		for (b = 0; b < 10; ++b)
		{
			for (c = 0; c < 10; ++c)
			{
				if (2 * a + 2 * b + c == n)
				{
					cout << a + b * 10 + c * 100 + b * 1000 + a * 10000 << endl;
				}
			}
		}
	}
	for (a = 0; a < 10; ++a)
	{
		for (b = 0; b < 10; ++b)
		{
			for (c = 0; c < 10; ++c)
			{
				if (2 * a + 2 * b + 2 * c == n)
				{
					cout << a + b * 10 + c * 100 + c * 1000 + b * 10000 + a * 100000 << endl;
				}
			}
		}
	}
}
int main()
{
	int n = 0;
	cin >> n;
	PalindromeNumber(n);

	return 0;
}