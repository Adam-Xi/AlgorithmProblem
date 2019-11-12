/*
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0

输入描述:
输入一个字符串,包括数字字母符号,可以为空


输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入
+2147483647
1a33
输出
2147483647
0
*/

#include<iostream>
using namespace std;
#include<string>

#if 0
class Solution {
public:
	int StrToInt(string str) {
		int num = 0;
		for (auto &e : str)
		{
			if (e >= 'A' && e <= 'z')
			{
				return 0;
			}
		}
		reverse(str.begin(), str.end());
		int time = 1;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				num += (str[i] - '0') * time;
				time *= 10;
			}
		}

		return num;
	}
};
#endif
class Solution {
public:
	int StrToInt(string str) {
		int n = str.size(), s = 1;
		long long res = 0;
		if (!n)
		{
			return 0;
		}
		if (str[0] == '-')
		{
			s = -1;
		}
		int i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
		for (; i < n; i++)
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
			{
				return 0;
			}
			//res = res * 10 + (str[i] - '0');
			//      res * 2  +  res * 8 + ...
			res = (res << 1) + (res << 3) + (str[i] & 0xf);
		}
		res *= s;
		return res;
	}
};
int main()
{
	string str;
	getline(cin, str);

	Solution s;
	cout << s.StrToInt(str) << endl;

	return 0;
}

