/*
��������:
  ��1+2+3+...+n��ֵ��
�����ʽ:
  �������һ������n��
�����ʽ:
  ���һ�У�����һ����������ʾ1+2+3+...+n��ֵ��
��������:
4
�������:
10
��������:
100
˵����
  ��һЩ������������������������԰�������õ����⡣
  һ�����ύ֮ǰ������Щ��������Ҫ����ͨ�����У�
  ���ⲻ�����⼸���������ݶ���ȷ����ĳ��������ȫ��ȷ�ģ�Ǳ�ڵĴ��������Ȼ������ĵ÷ֽϵ͡�
�������:
5050
���ݹ�ģ��Լ��:
1 <= n <= 1,000,000,000��
˵����
  ��ע����������ݹ�ģ��
  ����ֱ�ӵ��뷨��ֱ��ʹ��һ��ѭ�����ۼӣ�Ȼ���������ݹ�ģ�ܴ�ʱ�����֡��������ķ��������ᵼ�³�ʱ��
  ��ʱ����Ҫ��������������
  �������һ�ԣ����ʹ��1000000000��Ϊ��ĳ�������룬��ĳ����ǲ������ڹ涨������涨��ʱ�������г�����
  ������һ��Ҫֵ��ע��ĵط��Ǵ𰸵Ĵ�С�����������Ĭ�ϵ�����(int)��Χ�ڣ����ʹ�����������������ᵼ�½������
  �����ʹ��C++��C���Զ���׼��ʹ��printf������������ĸ�ʽ�ַ���Ӧ��д��%I64d�����long long���͵�������
*/


#include<iostream>
using namespace std;
#pragma warning (disable:4996)

int main()
{
	long long sum = 0;
	long long n = 0;
	scanf("%d", &n);
	//while (n)  //�ᳬʱ
	//{
	//	sum += n;
	//	n--;
	//}
	sum = (n + 1) * n / 2;  //��͹�ʽ����Ҫע�⹫ʽ����������Ϊ64λ����
	printf("%I64d\n", sum);
	return 0;
}