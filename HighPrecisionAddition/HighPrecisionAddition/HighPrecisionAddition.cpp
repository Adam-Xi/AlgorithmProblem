/*
��������
	������������a��b����������������ĺ͡�a��b��������100λ��
�㷨����
	����a��b���Ƚϴ����Բ���ֱ��ʹ�������еı�׼�����������洢�������������⣬һ��ʹ��������������
	����һ������A��A[0]���ڴ洢a�ĸ�λ��A[1]���ڴ洢a��ʮλ���������ơ�ͬ��������һ������B���洢b��
	����c = a + b��ʱ�����Ƚ�A[0]��B[0]��ӣ�����н�λ��������ѽ�λ�����͵�ʮλ��������r���Ѻ͵ĸ�λ������C[0]����C[0]����(A[0]+B[0])%10��Ȼ�����A[1]��B[1]��ӣ���ʱ��Ӧ����λ��������ֵrҲ����������C[1]Ӧ����A[1]��B[1]��r�������ĺͣ�������н�λ���������Կɽ��µĽ�λ���뵽r�У��͵ĸ�λ�浽C[1]�С��������ƣ��������C������λ��
	���C������ɡ�
�����ʽ
	����������У���һ��Ϊһ���Ǹ�����a���ڶ���Ϊһ���Ǹ�����b������������������100λ�����������λ������0��
�����ʽ
	���һ�У���ʾa + b��ֵ��
��������
	20100122201001221234567890
	2010012220100122
�������
	20100122203011233454668012

*/


#if 0

#pragma warning (disable:4996)
#include<iostream>
using namespace std;
#include<cstring>

//˼�룺
//���봦����
//����һ������һ�е����ݣ����ǲ���֪�����ݵľ��峤�ȣ�û�취ͨ��forѭ����������������Ĵ�С��
//���������辶����һ�ε����뿴��һ���ַ����飬�س�������ֹ������Ȼ���ڸ��ַ������󳤶Ⱦ���һ����������͸���
//Ȼ���ַ������ÿһ���ȥ�ַ�0��ASCII�뼴48���������Ƿֱ��Ӧ��������С����������������ַ�������Ҫʹ��������������ң�λ����������

//�ӷ�������
//���ж�������������Ĵ�С���ý������ĳ��ȵ�����Ĳ���������ĳ��ȣ�Ȼ���Ըó���Ϊ��׼�������λ��ʼ��λ��ӣ��������������0���±꿪ʼ��������±����

//�������
//�������
int main()
{
	int a[401] = { 0 }, alen;
	int b[401] = { 0 }, blen;
	int c[400] = { 0 }, clen;
	char s[400];
	int i;
	scanf("%s", s);
	alen = strlen(s);
	for (i = 1; i <= alen; ++i)
	{
		a[i] = s[alen - i] - 48;
	}
	scanf("%s", s);
	blen = strlen(s);
	for (i = 1; i <= blen; ++i)
	{
		b[i] = s[blen - i] - 48;
	}
	if (alen > blen)
	{
		clen = alen;
	}
	else
	{
		clen = blen;
	}
	for (i = 1; i <= clen; ++i)
	{
		c[i] = a[i] + b[i];
	}
	for (i = 1; i <= clen; ++i)
	{
		if (c[i] >= 10)
		{
			c[i + 1] += (c[i] / 10);
			c[i] %= 10;
		}
	}
	if (c[clen + 1] > 0)
	{
		clen++;
	}
	for (i = clen; i >= 1; --i)
	{
		printf("%d", c[i]);
	}
	printf("\n");

	return 0;
}

#endif


#pragma warning (disable:4996)
#include<iostream>
using namespace std;
#include<cstring>

int main()
{
	int a[401] = { 0 }, alen;
	int b[401] = { 0 }, blen;
	int c[401] = { 0 }, clen;
	char s[400] = { 0 };
	int i;

	scanf("%s", s);  //s�����0���±꿪ʼ���������ֵ,�����ң��Ӹ�λ����λ
	alen = strlen(s);
	for (i = 1; i <= alen; ++i)
	{
		a[i] = s[alen - i] - '0';  //a�����1���±꿪ʼ���������ֵ�������ң��ӵ�λ����λ
	}

	scanf("%s", s);
	blen = strlen(s);
	for (i = 1; i <= blen; ++i)
	{
		b[i] = s[blen - i] - '0';  //b�����1���±꿪ʼ���������ֵ�������ң��ӵ�λ����λ
	}
	
	if (alen > blen)
	{
		clen = alen;
	}
	else
	{
		clen = blen;
	}

	for (i = 1; i <= clen; ++i)
	{
		c[i] = a[i] + b[i];  //�ӷ�������������ӷ���c��
		if (c[i] >= 10)  //����Ƿ���Ҫ��λ
		{
			c[i] = c[i] + c[i] % 10;
			c[i + 1] = c[i] / 10;
		}
	}
	for (i = clen; i > 0; --i)
	{
		cout << c[i];
	}
	cout << endl;

	return 0;
}