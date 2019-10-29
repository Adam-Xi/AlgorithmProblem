/*
��������
��������һ��n*n�����̣���������һЩλ�ò��ܷŻʺ�
    ����Ҫ�������з���n���ڻʺ��n���׻ʺ�
	ʹ����������ڻʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϣ�����������׻ʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϡ�
	���ܹ��ж����ַŷ���nС�ڵ���8��
 �����ʽ
  ������ĵ�һ��Ϊһ������n����ʾ���̵Ĵ�С��
	������n�У�ÿ��n��0��1�����������һ������Ϊ1����ʾ��Ӧ��λ�ÿ��ԷŻʺ����һ������Ϊ0����ʾ��Ӧ��λ�ò����ԷŻʺ�
�����ʽ
	���һ����������ʾ�ܹ��ж����ַŷ���
��������
	4
	1 1 1 1
	1 1 1 1
	1 1 1 1
	1 1 1 1
�������
	2
��������
	4
	1 0 1 1
	1 1 1 1
	1 1 1 1
	1 1 1 1
�������
	0

*/



#include <iostream>
#include<cmath>
using namespace std;

int n;
int m[9][9];
int blackPos[9];
int whitePos[9];
int ans = 0;

// �жϵ�ǰ�ܷ���ûʺ� 
bool isSafe(int pos[], int row) 
{
	for (int i = 0; i < row; i++) 
	{
		if (pos[i] == pos[row] || abs(pos[i] - pos[row]) == abs(i - row)) 
		{
			return false;
		}
	}
	return true;
}

// �Ժڻʺ�ķ��ý������� 
void blackDfs(int row) 
{
	if (row == n) 
	{
		// ����Ѿ����������n���ڻʺ�, ��ô�ڷŵķ�����1 
		ans++;
		return;
	}
	else 
	{
		for (blackPos[row] = 0; blackPos[row] < n; blackPos[row]++) 
		{
			// �����ǰλ��û���������ڻʺ�����ͻ, ��ǰ���Է��úڻʺ���ҵ�ǰ��λ��û�з��ð׻ʺ� 
			if (isSafe(blackPos, row) && m[row][blackPos[row]] == 1 & blackPos[row] != whitePos[row]) 
			{
				blackDfs(row + 1);
			}
		}
	}
}

// �԰׻ʺ�ķ��ý������� 
void whiteDfs(int row) 
{
	if (row == n) 
	{
		// ����Ѿ����������n���׻ʺ�, ����з��úڻʺ� 
		blackDfs(0);
		return;
	}
	else 
	{
		for (whitePos[row] = 0; whitePos[row] < n; whitePos[row]++) 
		{
			// ��ǰλ��û���������׻ʺ��ͻ�ҵ�ǰλ���ܷ��� 
			if (isSafe(whitePos, row) && m[row][whitePos[row]] == 1) 
			{
				whiteDfs(row + 1);
			}
		}
	}
}


int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> m[i][j];
		}
	}
	whiteDfs(0);
	cout << ans << endl;

	return 0;
}

