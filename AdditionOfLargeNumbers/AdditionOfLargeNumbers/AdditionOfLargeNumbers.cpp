/*
请设计一个算法完成两个超长正整数的加法。

输入描述:
输入两个字符串数字

输出描述 :
输出相加后的结果，string型

示例1
输入
99999999999999999999999999999999999999999999999999
1
输出
100000000000000000000000000000000000000000000000000

*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		string s; // save reasult
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		int size = s1.size() > s2.size() ? s1.size() : s2.size();
		int flag = 0; //进位
		for (int i = 0; i < size; i++)
		{
			//注意：注释掉的两行不可用
			//int c_s1 = i > s1.size() ? 0 : (s1[i] - '0');
			//int c_s2 = i > s2.size() ? 0 : (s2[i] - '0');
			int c_s1 = i < s1.size() ? (s1[i] - '0') : 0;
			int c_s2 = i < s2.size() ? (s2[i] - '0') : 0;
			int c_sum = (c_s1 + c_s2 + flag) % 10;
			flag = (c_s1 + c_s2 + flag) / 10;
			s.insert(s.begin(), c_sum + '0');
		}
		if (flag == 1)  //当全部相加后，看两个数的最高位的相加结果是否有进位
		{
			s.insert(s.begin(), '1');
		}
		cout << s << endl;
	}
	return 0;
}