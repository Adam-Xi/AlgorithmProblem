/*
问题描述
　　求出区间[a,b]中所有整数的质因数分解。
输入格式
  　输入两个整数a，b。
输出格式
	每行输出一个数的分解，形如k=a1*a2*a3...(a1<=a2<=a3...，k也是从小到大的)(具体可看样例)
样例输入
	3 10
样例输出
	3=3
	4=2*2
	5=5
	6=2*3
	7=7
	8=2*2*2
	9=3*3
	10=2*5
提示
	先筛出所有素数，然后再分解。
数据规模和约定
	2<=a<=b<=10000
*/

#include<iostream>
using namespace std;

bool IsPrime(int n)
{
	if (n <= 1 || (n != 2 && n % 2 == 0))
	{
		return false;
	}

	for (int i = 3; i < n; i += 2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
#include<cmath>
void Cout_IsNotPrime(int n)
{
	//从2开始，试除尽
	for (int i = 2; i <= sqrt(n) || i == 2; i++)
	{
		if (n % i == 0)  //可以除尽，除以最小的除数
		{
			cout << i;  //输出最小的除数
			if (IsPrime(n / i))  //较大的除数是素数，不可除尽，输出，结束
			{
				cout << "*" << n / i << endl;
				return;
			}
			else  //较大的数不是素数，还可以除尽，递归除尽
			{
				cout << "*";
				Cout_IsNotPrime(n / i);
				return;
			}
		}
	}
	return;
}
void Solution(int first, int last)
{
	first--;
	while (first++ != last)  //还没到边界时，即还没做完时
	{
		cout << first << "=";
		if (IsPrime(first))  //是素数，不可除尽，输出
		{
			cout << first << endl;
		}
		else  //不是素数，可以除尽，进一步处理
		{
			Cout_IsNotPrime(first);
		}

	}
}

int main()
{
	int a, b;
	cin >> a >> b;

	Solution(a, b);

	return 0;
}