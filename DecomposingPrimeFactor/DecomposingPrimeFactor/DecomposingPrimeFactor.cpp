/*
��������
�����������[a,b]�������������������ֽ⡣
�����ʽ
  ��������������a��b��
�����ʽ
	ÿ�����һ�����ķֽ⣬����k=a1*a2*a3...(a1<=a2<=a3...��kҲ�Ǵ�С�����)(����ɿ�����)
��������
	3 10
�������
	3=3
	4=2*2
	5=5
	6=2*3
	7=7
	8=2*2*2
	9=3*3
	10=2*5
��ʾ
	��ɸ������������Ȼ���ٷֽ⡣
���ݹ�ģ��Լ��
	2<=a<=b<=10000
*/

#include<iostream>
using namespace std;

bool IsPrime(int n)
{
	if (n <= 1 || (n != 2 && n % 2 == 0))
	{
		return false;
	}

	for (int i = 3; i < n; i += 2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
#include<cmath>
void Cout_IsNotPrime(int n)
{
	//��2��ʼ���Գ���
	for (int i = 2; i <= sqrt(n) || i == 2; i++)
	{
		if (n % i == 0)  //���Գ�����������С�ĳ���
		{
			cout << i;  //�����С�ĳ���
			if (IsPrime(n / i))  //�ϴ�ĳ��������������ɳ��������������
			{
				cout << "*" << n / i << endl;
				return;
			}
			else  //�ϴ�������������������Գ������ݹ����
			{
				cout << "*";
				Cout_IsNotPrime(n / i);
				return;
			}
		}
	}
	return;
}
void Solution(int first, int last)
{
	first--;
	while (first++ != last)  //��û���߽�ʱ������û����ʱ
	{
		cout << first << "=";
		if (IsPrime(first))  //�����������ɳ��������
		{
			cout << first << endl;
		}
		else  //�������������Գ�������һ������
		{
			Cout_IsNotPrime(first);
		}

	}
}

int main()
{
	int a, b;
	cin >> a >> b;

	Solution(a, b);

	return 0;
}