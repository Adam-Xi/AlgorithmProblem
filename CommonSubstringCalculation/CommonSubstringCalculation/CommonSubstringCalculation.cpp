/*
��Ŀ���⣺

���������ַ�������󹫹��ִ��ĳ��ȣ��ַ������ִ�Сд

��ϸ������

�ӿ�˵��

ԭ�ͣ�

int getCommonStrLength(char * pFirstStr, char * pSecondStr);

���������

char * pFirstStr //��һ���ַ���

char * pSecondStr//�ڶ����ַ���

��������:
	���������ַ���

�������:
	���һ������

ʾ��1
����
	asdfas werasdfaswer
���
	6
*/


#if 0

//����һ��
//�����������ڽ϶̴������ַ����б���
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
			swap(s1, s2);  //��֤s1��ʼ�����
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


//����������̬�滮
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