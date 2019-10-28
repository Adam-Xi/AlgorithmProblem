#include<iostream>
#include<cmath>
using namespace std;

int queen[8] = { 0 };
int res = 0;

// ����ͻ������ͻ������
//    �� -------- ��
// point_r ---- point_c   Ҫ�����к��У�ȷ���ĵ㣩
//    i ------- queen[i]  ǰn���Ѿ��ҳ����ĵ㣬��point�Ƿ���֮ǰ�ҳ��������г�ͻ
bool IsAttack(int point_r, int point_c)  
{
	for (int i = 0; i < point_r; ++i)
	{
		//�������ڰ�ǰn-1����ȷ����ÿ���� �� ��n���е�point����бȽϣ����Բ���Ҫ����ͬһ�е��жϣ��϶������
		//ֻ���� point�� �Ƿ��� ǰn-1���е�ÿ���� �к����   ����б����ȣ�����ͬһ�Խ�����
		if (point_c == queen[i] || (abs(point_c - queen[i]) == point_r - i))  
		{
			return true;
		}
	}
	return false;
}

//�ҵ㣬�ݹ飬����
void find_queen(int n)  //nΪ�к�
{
	for (int i = 0; i < 8; ++i)  //������n���е�ÿһ�У�ȷ����ǰ��ѡ�е�
	{
		if (!IsAttack(n, i))  //�����ͻʱ
		{
			queen[n] = i;
			if (n == 7)  //�Ѿ����е���7�У��ҵ�7���еĵ��Ѿ�ȷ��ʱ������һ������Ѿ�ȷ����������++�����ݣ����ص�6�������������
			{
				res++;
				return;
			}
			find_queen(n + 1);  //�ݹ飬û��β�У����Ѿ�ȷ����ǰ�еľ���㣬������һ�еĲ���
		}
	}
	return;  //���ڲ��ѭ��ȷ�������ݵ������㣬���������������
}

int main()
{
	find_queen(0);
	cout << res << endl;

	return 0;
}