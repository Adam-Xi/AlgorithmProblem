/*
题目标题：

计算两个字符串的最大公共字串的长度，字符不区分大小写

详细描述：

接口说明

原型：

int getCommonStrLength(char * pFirstStr, char * pSecondStr);

输入参数：

char * pFirstStr //第一个字符串

char * pSecondStr//第二个字符串

输入描述:
	输入两个字符串

输出描述:
	输出一个整数

示例1
输入
	asdfas werasdfaswer
输出
	6
*/


#if 0

//方法一：
//常规做法，在较短串中逐字符进行遍历
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int s1_len = s1.size();
		int s2_len = s2.size();
		if (s1_len < s2_len)
		{
			swap(s1, s2);  //保证s1串始终最大
			swap(s1_len, s2_len);
		}
		int max_len = 0;
		for (int i = 0; i < s2_len; i++)
		{
			for (int j = 1; j < s2_len - i + 1; j++)
			{
				string tmp = s2.substr(i, j);
				if (s1.find(tmp) != string::npos && tmp.size() > max_len)
				{
					max_len = tmp.size();
				}
			}

		}
		cout << max_len << endl;
	}
	return 0;
}

#endif


//方法二：动态规划
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int len1 = str1.size();
		int len2 = str2.size();
		int max = 0;

		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

		for (int i = 1; i <= len1; ++i)
		{
			for (int j = 1; j <= len2; ++j)
			{
				if (str1[i - 1] == str2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				if (dp[i][j] > max)
				{
					max = dp[i][j];
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}