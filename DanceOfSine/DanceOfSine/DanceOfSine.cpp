/*
��������
�������FJΪ������ţ�ǿ�������ѧ�����Σ�FJ֪����Ҫѧ�����ſΣ�������һ���õ����Ǻ�����������
    ������׼������ţ����һ����Sine֮�衱����Ϸ��Ԣ�����֣������ţ�ǵļ���������
  ��	������
	 	An=sin(1�Csin(2+sin(3�Csin(4+...sin(n))...)
		Sn=(...(A1+n)A2+n-1)A3+...+2)An+1
	FJ������ţ�Ǽ���Sn��ֵ���������FJ��ӡ��Sn���������ʽ���Է�����ţ�����⡣
�����ʽ
	����һ������N<201��
�����ʽ
	�������Ӧ�ı��ʽSn����һ�����з�����������в��ú��ж���Ŀո���С��س�����
��������
	3
�������
	((sin(1)+3)sin(1�Csin(2))+2)sin(1�Csin(2+sin(3)))+1

*/

#include<iostream>
using namespace std;

int n = 0;

void An(int total, int t)
{
	cout << "sin(" << t;
	if (t == total)
	{
		cout << ")";
		return;
	}

	if ((t & 1) == 1)
	{
		cout << "-";
	}
	else
	{
		cout << "+";
	}
	An(total, ++t);
	cout << ")";
}

void Sn(int total, int t)
{
	if (n < t)
	{
		return;
	}
	if (t != 1)
	{
		cout << "(";
	}
	Sn(total - 1, t + 1);
	An(total, 1);

	cout << "+" << t;
	if (t != 1)
	{
		cout << ")";
	}
}

int main()
{
	cin >> n;

//	An(n, 1);  //����An����

	Sn(n, 1);

	return 0;
}