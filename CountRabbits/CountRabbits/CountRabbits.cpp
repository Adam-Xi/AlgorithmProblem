/*
��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ����
�������Ӷ���������ÿ���µ���������Ϊ���٣�

��������:
����int�ͱ�ʾmonth

������� :
�����������int��

ʾ��1
����
9
���
34
*/
#if 0
//��������쳲���������
#include <iostream>
using namespace std;

int Func(int n)
{
	int first = 1;
	int second = 0, third = 0;
	while (n--)
	{
		third = first + second;
		first = second;
		second = third;
	}
	return third;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << Func(n) << endl;
	}
	return 0;
}

#endif

#include <iostream>
using namespace std;

int main(){
	int m;
	while (cin >> m){
		int a = 1, b = 0, c = 0;//a:һ������������b����������������c�����������Ӹ���
		while (--m){//ÿ��һ�����������仯
			c += b;
			b = a;
			a = c;
		}
		cout << a + b + c << endl;
	}
	return 0;
}