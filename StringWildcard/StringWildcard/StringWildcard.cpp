/*
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
？：匹配1个字符


输入：
通配符表达式；
一组字符串。


输出：
返回匹配的结果，正确输出true，错误输出false


输入描述:
先输入一个带有通配符的字符串，再输入一个需要匹配的字符串



输出描述:
返回匹配的结果，正确输出true，错误输出false

示例1
输入
te?t*.*
txt12.xls
输出
false
*/

#if 0
#include <iostream>
#include <string>
using namespace std;

void Func(string& s1, string& s2)
{
	int i = 0;
	int j = 0;
	bool flag = false;
	while (s1[i] != '\0' || s2[j] != '\0')
	{
		if (s1[i] == '*')  //遇到*，先越过该位置，记录他的下一个位置
		{
			i++;
			flag = true;  //将标志位置为真
		}
		else if (flag == true)  //内置循环 ，检查通配符代替了几个位置
		{
			while (s1[i] != s2[j])
			{
				j++;
			}
			flag == false;  //将标志位还原
		}
		else if (s1[i] == '?' || s1[i] == s2[j])  //？能且只能代替一个位置，忽略，进入下一个位置的比较
		{
			i++;
			j++;
		}
		else  //所有可能相等的情况都已经处理完，此时进入的话就为不匹配的情况
		{
			cout << "false" << endl;
			return;
		}
	}
	if (s1[i] == '\0' && s2[j] == '\0')
	{
		cout << "true" << endl;
	}
}

int main()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		Func(s1, s2);
	}
	return 0;
}
#endif

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int Func(string s1, string s2)
{
	int s1_len = s1.size();
	int s2_len = s2.size();
	vector<vector<int> > vv(s2_len + 1, vector<int>(s1_len + 1, 0));
	
	vv[0][0] = 1;
	for (int i = 1; i <= s2_len; i++)
	{
		char ch = s2[i - 1];
		
		vv[i][0] = vv[i - 1][0] && (ch == '*');
		for (int j = 1; j <= s1_len; j++)
		{
			char _ch = s1[j - 1];
			if (ch == '*')
			{
				vv[i][j] = vv[i - 1][j] || vv[i][j - 1];
			}
			else
			{
				vv[i][j] = vv[i - 1][j - 1] && (ch == '?' || _ch == ch);
			}
		}
	}
	return vv[s2_len][s1_len];
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (Func(s2, s1))
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}

	return 0;
}