/*
��������
��������һ��������n�����n!��ֵ��
  ������n!=1*2*3*��*n��
�㷨����
	n!���ܴܺ󣬶�������ܱ�ʾ��������Χ���ޣ���Ҫʹ�ø߾��ȼ���ķ�����
	ʹ��һ������A����ʾһ��������a��A[0]��ʾa�ĸ�λ��A[1]��ʾa��ʮλ���������ơ�
	��a����һ������k��Ϊ������A��ÿһ��Ԫ�ض�����k����ע�⴦����Ӧ�Ľ�λ��
    ���Ƚ�a��Ϊ1��Ȼ���2����3�����˵�nʱ�����õ���n!��ֵ��
�����ʽ
	�������һ��������n��n<=1000��
�����ʽ
	���n!��׼ȷֵ��	  
��������
	  10

*/
#include<iostream>
using namespace std;
#define N 10000

int main()
{
	int arr[N] = { 1 };
	int size = 1;
	int flag = 0;
	int i = 1;
	int j = 0;
	int n = 0;
	cin >> n;
	while (i <= n)
	{
		for (j = 0; j < size; ++j)
		{
			arr[j] = arr[j] * i + flag;
			flag = arr[j] / 10000;
			arr[j] = arr[j] % 10000;
		}
		if (flag)
		{
			arr[j] = flag;
			size++;
			flag = 0;
		}
		i++;
	}
	cout << arr[size - 1];
	for (i = size - 2; i >= 0; --i)
	{
		cout << arr[i];
	}
	cout << endl;
	cout << size << endl;
	return 0;
}