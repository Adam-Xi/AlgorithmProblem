/*
�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
Ҫ��
ʵ������2��ͨ�����
*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0-9��ɣ������ִ�Сд����ͬ��
����ƥ��1���ַ�


���룺
ͨ������ʽ��
һ���ַ�����


�����
����ƥ��Ľ������ȷ���true���������false


��������:
������һ������ͨ������ַ�����������һ����Ҫƥ����ַ���



�������:
����ƥ��Ľ������ȷ���true���������false

ʾ��1
����
te?t*.*
txt12.xls
���
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
		if (s1[i] == '*')  //����*����Խ����λ�ã���¼������һ��λ��
		{
			i++;
			flag = true;  //����־λ��Ϊ��
		}
		else if (flag == true)  //����ѭ�� �����ͨ��������˼���λ��
		{
			while (s1[i] != s2[j])
			{
				j++;
			}
			flag == false;  //����־λ��ԭ
		}
		else if (s1[i] == '?' || s1[i] == s2[j])  //������ֻ�ܴ���һ��λ�ã����ԣ�������һ��λ�õıȽ�
		{
			i++;
			j++;
		}
		else  //���п�����ȵ�������Ѿ������꣬��ʱ����Ļ���Ϊ��ƥ������
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