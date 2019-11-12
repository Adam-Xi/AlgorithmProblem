/*
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0

��������:
����һ���ַ���,����������ĸ����,����Ϊ��


�������:
����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0
ʾ��1
����
+2147483647
1a33
���
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

