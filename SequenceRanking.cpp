/*
@Adam-Xi
2019-09-19
��������:
��������һ������Ϊn�����У���������а���С�����˳�����С�1<=n<=200
�����ʽ:
  ����һ��Ϊһ������n��
	�ڶ��а���n��������Ϊ�����������ÿ�������ľ���ֵС��10000��
�����ʽ:
	���һ�У�����С�����˳��������������С�
��������:
	5
	8 3 6 4 9
�������:
	3 4 6 8 9
*/
#include<iostream>
using namespace std;

void sort(int *a, int max)
{
	int m, n;
	for (m = 0; m < max; m++)
	{
		for (n = m + 1; n < max; m++)
		{
			if (a[m] > a[n])
			{
				int tmp = a[m];
				a[m] = a[n];
				a[n] = tmp;
			}
		}
	}
}

int main()
{
	int n = 0;
	int array[201] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
//	sort(array, n);
	int m, j;
	for (m = 0; m < n; m++)
	{
		for (j = m + 1; j < n; j++)
		{
			if (array[m] > array[j])
			{
				int tmp = array[m];
				array[m] = array[j];
				array[j] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}

	return 0;
}
