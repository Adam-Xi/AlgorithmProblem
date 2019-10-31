/*
��������
����FJ��ɳ����д������һЩ�ַ�����
  ��A1 = ��A��
	A2 = ��ABA��
	A3 = ��ABACABA��
	A4 = ��ABACABADABACABA��
	�� ��
	�����ҳ����еĹ��ɲ�д���е�����AN��
�����ʽ
	����һ������N �� 26��
�����ʽ
	�������Ӧ���ַ���AN����һ�����з�����������в��ú��ж���Ŀո���С��س�����
��������
	3
�������
	ABACABA
*/

#include<iostream>
using namespace std;
#include<cmath>

void dfs(int total, int n)
{
	if (total == 1)
	{
		cout << (char)('A' + n);
		return;
	}
	dfs(total / 2, n - 1);
	dfs(1, n);
	dfs(total / 2, n - 1);
}

int main()
{
	int n = 0;
	cin >> n;
	int total = (int)pow(2, n) - 1;

	dfs(total, n - 1);

	return 0;
}