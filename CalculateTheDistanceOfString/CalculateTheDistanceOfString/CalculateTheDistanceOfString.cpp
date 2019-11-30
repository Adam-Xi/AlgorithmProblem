/*
Levenshtein ���룬�ֳƱ༭���룬ָ���������ַ���֮�䣬��һ��ת������һ����������ٱ༭������������ɵı༭����������һ���ַ��滻����һ���ַ�������һ���ַ���ɾ��һ���ַ����༭������㷨�������ɶ����ѧ��Levenshtein����ģ����ֽ�Levenshtein Distance��

Ex��

�ַ���A:abcdefg

�ַ���B: abcdef

ͨ�����ӻ���ɾ���ַ���g���ķ�ʽ�ﵽĿ�ġ������ַ�������Ҫһ�β������������������Ҫ�Ĵ�������Ϊ�����ַ����ľ��롣

Ҫ��

�������������ַ�����д��һ���㷨�������ǵı༭���롣


��������:
���������ַ���



������� :
�õ�������

ʾ��1
����
abcdefg
abcdef
���
1
*/

#if 0
//���������ַ���A��B��������Ҫ���в��롢ɾ�����޸Ĳ�����A����ΪB����
//����ic��dc��rc�ֱ�Ϊ���ֲ����Ĵ��ۣ������һ����Ч�㷨�������A����ΪB������Ҫ�����ٴ��ۡ�
//���������ַ���A��B�������ǵĳ��Ⱥ����ֲ������ۣ��뷵�ؽ�A����ΪB������Ҫ����С���ۡ���֤�������Ⱦ�С�ڵ���300.
//
//
//���ɴ�СΪ(N + 1)*(M + 1)�ľ���dp.dp[x][y]��ʾAǰx���ַ����༭�� Bǰy���ַ������ѵĴ���.
//���ڵ�һ����˵, dp[0][y]��ʾ��һ���մ���ΪB��ǰy���ַ���ɵ��Ӵ�, ���ѵĴ���Ϊic*y;
//ͬ��, ���ڵ�һ��dp[x][0] = x*dc;
//
//����������λ��, dp[x][y]���������¼���ȡֵ:
//dp[x - 1][y - 1] + rc;//A[x-1]!=B[y-1] ��ǰx-1���ַ���ΪBǰy-1���ַ�,�ٽ����һ���ַ��滻.
//dp[x - 1][y - 1];//A[x-1]==B[y-1] ��ǰx-1���ַ���ΪBǰy-1���ַ�,���һ�������޸�.
//dp[x - 1][y] + dc;//ɾ��һ���ַ�,��ǰx-1���ַ���ΪB��ǰy���ַ�
//dp[x][y - 1] + ic;//��Aǰx-1���ַ���ΪB��ǰy���ַ�,�ٲ���һ���ַ�
//dp[x][y]��ֵ��Ϊ����������С��һ��.
//������, dp[n][m]��Ϊ����.

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