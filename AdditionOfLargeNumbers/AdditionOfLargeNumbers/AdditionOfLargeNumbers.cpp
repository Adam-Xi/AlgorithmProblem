/*
�����һ���㷨������������������ļӷ���

��������:
���������ַ�������

������� :
�����Ӻ�Ľ����string��

ʾ��1
����
99999999999999999999999999999999999999999999999999
1
���
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
		int flag = 0; //��λ
		for (int i = 0; i < size; i++)
		{
			//ע�⣺ע�͵������в�����
			//int c_s1 = i > s1.size() ? 0 : (s1[i] - '0');
			//int c_s2 = i > s2.size() ? 0 : (s2[i] - '0');
			int c_s1 = i < s1.size() ? (s1[i] - '0') : 0;
			int c_s2 = i < s2.size() ? (s2[i] - '0') : 0;
			int c_sum = (c_s1 + c_s2 + flag) % 10;
			flag = (c_s1 + c_s2 + flag) / 10;
			s.insert(s.begin(), c_sum + '0');
		}
		if (flag == 1)  //��ȫ����Ӻ󣬿������������λ����ӽ���Ƿ��н�λ
		{
			s.insert(s.begin(), '1');
		}
		cout << s << endl;
	}
	return 0;
}