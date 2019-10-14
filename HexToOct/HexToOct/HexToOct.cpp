/*

【问题描述】
给定n个十六进制正整数，输出它们对应的八进制数。
【输入格式】
输入的第一行为一个正整数n （1<=n<=10）。
接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数
每个十六进制数长度不超过100000。
【输出格式】
输出n行，每行为输入对应的八进制正整数。
【注意】
输入的十六进制数不会有前导0，比如012A。
输出的八进制数也不能有前导0。
【样例输入】
2
39
123ABC
【样例输出】
71
4435274

*/
#include<iostream>
using namespace std;
#include<string>
#include<math.h>


//long long hex_to_dec(string s)
//{
//	long long dec = 0;
//	int len = s.length();
//	for (int i = 0; i < len; ++i)
//	{
//		if (s[i] >= 'A')
//		{
//			dec += (s[i] - 'A' + 10) * pow(16, len - i - 1);
//		}
//		else
//		{
//			dec += (s[i] - '0') * pow(16, len - i - 1);
//		}
//	}
//	return dec;
//}
//
//void dec_to_oct(long long dec)
//{
//	char oct[100];
//	long long s = dec;
//	int i = 0;
//	
//	while (s / 8 != 0)
//	{
//		oct[i++] = '0' + s % 8;
//		s = s / 8;
//	}
//	oct[i] = '0' + s;
//	while (i >= 0)
//	{
//		cout << oct[i--];
//	}
//}
//
//int main()
//{
//	string str[10];
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> str[i];
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		dec_to_oct(hex_to_dec(str[i]));
//	}
//	return 0;
//}
//因为题目要求每个十六进制长度不超过100000，所以可能会导致转化为十进制后的long long类型存储不下，导致出错

//为解决这一问题，有以下代码

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
long long hex_to_dec(string hex)
{
	long long dec = 0;
	int len = hex.length();
	for (int i = 0; i<len; i++)
	{
		if (hex[i] >= 'A')
		{
			dec += (hex[i] - 'A' + 10)*pow(16, len - 1 - i);
		}
		else
		{
			dec += (hex[i] - '0')*pow(16, len - 1 - i);
		}
	}
	return dec;
}
void dec_to_oct(long long dec)
{
	char a[100];
	long long s = dec;
	int i = 0;
	while (s / 8 != 0)
	{
		a[i++] = '0' + s % 8;
		s = s / 8;
	}
	a[i] = '0' + s;
	while (i >= 0)
	{
		cout << a[i--];
	}
}
int main()
{
	string str[10];
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> str[i];
	}
	for (int i = 0; i<n; i++)
	{
		dec_to_oct(hex_to_dec(str[i]));
		cout << endl;
	}
	return 0;
}