/*

������������
����n��ʮ��������������������Ƕ�Ӧ�İ˽�������
�������ʽ��
����ĵ�һ��Ϊһ��������n ��1<=n<=10����
������n�У�ÿ��һ����0~9����д��ĸA~F��ɵ��ַ�������ʾҪת����ʮ������������
ÿ��ʮ�����������Ȳ�����100000��
�������ʽ��
���n�У�ÿ��Ϊ�����Ӧ�İ˽�����������
��ע�⡿
�����ʮ��������������ǰ��0������012A��
����İ˽�����Ҳ������ǰ��0��
���������롿
2
39
123ABC
�����������
71
4435274

*/
#include<iostream>
using namespace std;
#include<string>
#include<math.h>


//long long hex_to_dec(string s)
//{
//	long long dec = 0;
//	int len = s.length();
//	for (int i = 0; i < len; ++i)
//	{
//		if (s[i] >= 'A')
//		{
//			dec += (s[i] - 'A' + 10) * pow(16, len - i - 1);
//		}
//		else
//		{
//			dec += (s[i] - '0') * pow(16, len - i - 1);
//		}
//	}
//	return dec;
//}
//
//void dec_to_oct(long long dec)
//{
//	char oct[100];
//	long long s = dec;
//	int i = 0;
//	
//	while (s / 8 != 0)
//	{
//		oct[i++] = '0' + s % 8;
//		s = s / 8;
//	}
//	oct[i] = '0' + s;
//	while (i >= 0)
//	{
//		cout << oct[i--];
//	}
//}
//
//int main()
//{
//	string str[10];
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> str[i];
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		dec_to_oct(hex_to_dec(str[i]));
//	}
//	return 0;
//}
//��Ϊ��ĿҪ��ÿ��ʮ�����Ƴ��Ȳ�����100000�����Կ��ܻᵼ��ת��Ϊʮ���ƺ��long long���ʹ洢���£����³���

//Ϊ�����һ���⣬�����´���

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
long long hex_to_dec(string hex)
{
	long long dec = 0;
	int len = hex.length();
	for (int i = 0; i<len; i++)
	{
		if (hex[i] >= 'A')
		{
			dec += (hex[i] - 'A' + 10)*pow(16, len - 1 - i);
		}
		else
		{
			dec += (hex[i] - '0')*pow(16, len - 1 - i);
		}
	}
	return dec;
}
void dec_to_oct(long long dec)
{
	char a[100];
	long long s = dec;
	int i = 0;
	while (s / 8 != 0)
	{
		a[i++] = '0' + s % 8;
		s = s / 8;
	}
	a[i] = '0' + s;
	while (i >= 0)
	{
		cout << a[i--];
	}
}
int main()
{
	string str[10];
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> str[i];
	}
	for (int i = 0; i<n; i++)
	{
		dec_to_oct(hex_to_dec(str[i]));
		cout << endl;
	}
	return 0;
}