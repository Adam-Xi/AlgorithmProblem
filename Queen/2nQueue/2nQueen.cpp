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
#include<iostream>
using namespace std;
#include<cmath>

int n = 0;  //2n�ʺ�
int m[10][10];  //��ͼ
int blackPos[10], whitePos[10];  //�ڰ׻ʺ��ѡ�㼯���±��ʾ�У�ͨ���±���ʵ�ֵΪ��
int _count = 0;  //����������

bool IsAttack(int pos[], int point_r, int point_c)  //��ǰ���Ƿ��ͻ
{
	for (int row = 0; row < point_r; row++)
	{
		if (point_c == pos[row] || abs(point_c - pos[row]) == point_r - row)
		{
			return true;
		}
	}
	return false;
}

//�ڻʺ�����
void SetBlack(int row)
{
	if (row == n)
	{
		//�ڻʺ�������n���ӣ�������+1
		_count++;
		return;
	}
	//������ȱ������� �ڻʺ�ѡ����������
	for (blackPos[row] = 0; blackPos[row] < n; blackPos[row]++)
	{
		if (!IsAttack(blackPos, row, blackPos[row]) && m[row][blackPos[row]] == 1 && blackPos[row] != whitePos[row])
		{
			SetBlack(row + 1);
		}
	}
}

//�׻ʺ�����
void SetWhite(int row)
{
	if (row == n)
	{
		//�׻ʺ��Ѿ�����n���ӣ����׻ʺ��һ�������Ѿ�ȷ�����ڴ˻����϶Ժڻʺ�����Ӽ��Ͻ�������
		SetBlack(0);
		return;
	}
	//������ȱ������������Ұ׻ʺ����ӵ�����
	for (whitePos[row] = 0; whitePos[row] < n; whitePos[row]++)
	{
		if (!IsAttack(whitePos, row, whitePos[row]) && m[row][whitePos[row]] == 1)
		{
			SetWhite(row + 1);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> m[i][j];
		}
	}
	SetWhite(0);
	cout << _count << endl;
	return 0;
}