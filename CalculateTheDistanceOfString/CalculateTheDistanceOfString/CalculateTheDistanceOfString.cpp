/*
Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。编辑距离的算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。

Ex：

字符串A:abcdefg

字符串B: abcdef

通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。

要求：

给定任意两个字符串，写出一个算法计算它们的编辑距离。


输入描述:
输入两个字符串



输出描述 :
得到计算结果

示例1
输入
abcdefg
abcdef
输出
1
*/

#if 0
//对于两个字符串A和B，我们需要进行插入、删除和修改操作将A串变为B串。
//定义ic，dc，rc分别为三种操作的代价，请设计一个高效算法，求出将A串变为B串所需要的最少代价。
//给定两个字符串A和B，及它们的长度和三种操作代价，请返回将A串变为B串所需要的最小代价。保证两串长度均小于等于300.
//
//
//生成大小为(N + 1)*(M + 1)的矩阵dp.dp[x][y]表示A前x个字符串编辑成 B前y个字符所花费的代价.
//对于第一行来说, dp[0][y]表示将一个空串变为B的前y个字符组成的子串, 花费的代价为ic*y;
//同理, 对于第一列dp[x][0] = x*dc;
//
//对于其他的位置, dp[x][y]可能有以下几种取值:
//dp[x - 1][y - 1] + rc;//A[x-1]!=B[y-1] 将前x-1个字符变为B前y-1个字符,再将最后一个字符替换.
//dp[x - 1][y - 1];//A[x-1]==B[y-1] 将前x-1个字符变为B前y-1个字符,最后一个不用修改.
//dp[x - 1][y] + dc;//删除一个字符,将前x-1个字符变为B的前y个字符
//dp[x][y - 1] + ic;//将A前x-1个字符变为B的前y个字符,再插入一个字符
//dp[x][y]的值就为以上四者最小的一个.
//求解完毕, dp[n][m]即为所求.

class MinCost {
public:
	int findMinCost(string A, int n, string B, int m, int ic, int dc, int rc)
	{
		vector< vector<int> > dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= m; ++i)
			dp[0][i] = ic*i;
		for (int i = 1; i <= n; ++i)
			dp[i][0] = dc*i;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				int case1 = dp[i - 1][j] + dc;
				int case2 = dp[i][j - 1] + ic, case3 = dp[i - 1][j - 1];
				if (A[i - 1] != B[j - 1])
					case3 += rc;
				dp[i][j] = min(min(case1, case2), case3);
			}
		}
		return dp[n][m];
	}
};

#endif

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int Func(string& s1, string& s2)
{
	int len1 = s1.size();
	int len2 = s2.size();
	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; i++)
	{
		dp[i][0] = i;
	}
	for (int i = 1; i <= len2; i++)
	{
		dp[0][i] = i;
	}
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			int case1 = dp[i - 1][j] + 1;
			int case2 = dp[i][j - 1] + 1;
			int case3 = dp[i - 1][j - 1];
			if (s1[i - 1] != s2[j - 1])
			{
				case3 += 1;
			}
			dp[i][j] = min(min(case1, case2), case3);
		}
	}
	return dp[len1][len2];
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << Func(s1, s2) << endl;
	}
	return 0;
}