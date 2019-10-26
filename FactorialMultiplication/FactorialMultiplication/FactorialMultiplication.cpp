/*
问题描述
　　输入一个正整数n，输出n!的值。
  　其中n!=1*2*3*…*n。
算法描述
	n!可能很大，而计算机能表示的整数范围有限，需要使用高精度计算的方法。
	使用一个数组A来表示一个大整数a，A[0]表示a的个位，A[1]表示a的十位，依次类推。
	将a乘以一个整数k变为将数组A的每一个元素都乘以k，请注意处理相应的进位。
    首先将a设为1，然后乘2，乘3，当乘到n时，即得到了n!的值。
输入格式
	输入包含一个正整数n，n<=1000。
输出格式
	输出n!的准确值。	  
样例输入
	  10

*/
#include<iostream>
using namespace std;
#define N 10000

int main()
{
	int arr[N] = { 1 };
	int size = 1;
	int flag = 0;
	int i = 1;
	int j = 0;
	int n = 0;
	cin >> n;
	while (i <= n)
	{
		for (j = 0; j < size; ++j)
		{
			arr[j] = arr[j] * i + flag;
			flag = arr[j] / 10000;
			arr[j] = arr[j] % 10000;
		}
		if (flag)
		{
			arr[j] = flag;
			size++;
			flag = 0;
		}
		i++;
	}
	cout << arr[size - 1];
	for (i = size - 2; i >= 0; --i)
	{
		cout << arr[i];
	}
	cout << endl;
	cout << size << endl;
	return 0;
}