#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	return(*(int*)a - *(int*)b);//��С��������
}

void quik(int a[], int n)
{
	qsort(a, n, sizeof(a[0]), cmp);
}

int main()
{
	int a[100];
	int n;
	scanf("%d", &n);
	int charge = 0;  //chargeΪ����

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	while (n>1)
	{
		quik(a, n);
		charge = charge + a[0] + a[1];

		a[1] = a[0] + a[1];

		for (int j = 1; j < n; j++)//��a[1]��Ԫ�ؿ�ʼ��������ǰ�ƶ�һλ
		{
			a[j - 1] = a[j];
		}

		n--;

	}

	printf("charge:%d", charge);//��ӡ

	return 0;
}
