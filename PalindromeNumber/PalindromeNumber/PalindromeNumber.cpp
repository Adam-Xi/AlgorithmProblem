#if 0



/*
��������
����123321��һ���ǳ����������������߶��ʹ��ұ߶���һ���ġ�
  ������һ��������n�� �����������������λ����λʮ�������������λ����֮�͵���n ��
�����ʽ
	����һ�У�����һ��������n��
�����ʽ
	����С�����˳���������������������ÿ������ռһ�С�
��������
	52
�������
	899998
	989989
	998899
���ݹ�ģ��Լ��
	1<=n<=54��

*/


#include<iostream>
using namespace std;

void PalindromeNumber(int n)
{
	int a, b, c;
	for (a = 0; a < 10; ++a)
	{
		for (b = 0; b < 10; ++b)
		{
			for (c = 0; c < 10; ++c)
			{
				if (2 * a + 2 * b + c == n)
				{
					cout << a + b * 10 + c * 100 + b * 1000 + a * 10000 << endl;
				}
			}
		}
	}
	for (a = 0; a < 10; ++a)
	{
		for (b = 0; b < 10; ++b)
		{
			for (c = 0; c < 10; ++c)
			{
				if (2 * a + 2 * b + 2 * c == n)
				{
					cout << a + b * 10 + c * 100 + c * 1000 + b * 10000 + a * 100000 << endl;
				}
			}
		}
	}
}
int main()
{
	int n = 0;
	cin >> n;
	PalindromeNumber(n);

	return 0;
}

#endif

/*
��������
����1221��һ���ǳ����������������߶��ʹ��ұ߶���һ���ģ������������������λʮ��������
�����ʽ
  ������С�����˳�����������������λʮ��������

*/

#include<iostream>
using namespace std;

void PalindromeNumber()
{
	for (int num = 1000; num < 10000; ++num)
	{
		if ((num % 10 == num / 1000 % 10) && (num / 100 % 10 == num / 10 % 10))
		{
			cout << num << endl;
		}
	}
}

int main()
{
	PalindromeNumber();

	return 0;
}