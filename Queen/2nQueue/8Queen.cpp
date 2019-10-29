/*
*********�˻ʺ�����*********
�˻ʺ����⣬��һ�����϶����������⣬�ǻ����㷨�ĵ��Ͱ�����
�������ǹ����������������˹����ɪ����1848�������
	��8��8��Ĺ��������ϰڷŰ˸��ʺ�ʹ�䲻�ܻ��๥���������������ʺ󶼲��ܴ���ͬһ�С�ͬһ�л�ͬһб���ϣ����ж����ְڷ��� 
��˹��Ϊ��76�ַ�����1854���ڰ��ֵ�������־�ϲ�ͬ�����߷�����40�ֲ�ͬ�Ľ⣬����������ͼ�۵ķ������92�ֽ����
������������ж��ּ�������Կ��Խ�������⡣
*/

#if 0

//************�ݹ�+����

#include<iostream>
using namespace std;
#include<cmath>

int queen[8] = { 0 };  //��һά������ά���ʺ����ӵĵ㣬���磬queen[1] = 5��ʾ��2�е�6����һ�����ӵ㣨��0��ʼ��
int _count = 0;

// ����ͻ������ͻ������
//    �� --------- ��
// point_r ----- point_c   Ҫ�����к��У�ȷ���ĵ㣩
//   row ------- queen[row]  ǰn���Ѿ��ҳ����ĵ㣬��point�Ƿ���֮ǰ�ҳ��������г�ͻ
bool IsAttack(int point_r, int point_c)
{
	for (int row = 0; row < point_r; ++row)
	{
		//�������ڰ�ǰn-1����ȷ����ÿ���� �� ��n���е�point����бȽϣ����Բ���Ҫ����ͬһ�е��жϣ��϶������
		//ֻ���� point�� �Ƿ��� ǰn-1���е�ÿ���� �к����   ����  б����ȣ�����ͬһ�Խ�����
		if (point_c == queen[row] || (abs(queen[row] - point_c) == point_r - row))
		{
			return true;
		}
	}
	return false;
}

//�ҵ㣬�ݹ飬����
void find(int row)  //rowΪ�к�
{
	for (int col = 0; col < 8; ++col)  //������row���е�ÿһ�У�ȷ����ǰ��ѡ�е�
	{
		if (!IsAttack(row, col))  //�����ͻʱ
		{
			if (row == 7)  //�Ѿ����е���7�У��ҵ�7���еĵ��Ѿ�ȷ��ʱ������һ������Ѿ�ȷ����������++�����ݣ����ص�6�������������
			{
				_count++;
				return;
			}
			queen[row] = col;  
			find(row + 1);  //�ݹ飬û��β�У����Ѿ�ȷ����ǰ�еľ���㣬������һ�еĲ���
		}
	}
	//���ڲ��ѭ��ȷ�������ݵ������㣬���������������
}

int main()
{
	find(0);
	cout << _count << endl;

	return 0;
}

#endif

#if 0

//************����+����

#include<iostream>
using namespace std;
#include<cmath>

int queen[8] = { -1 };
int _count = 0;


bool IsAttack(int point_r, int point_c)
{
	for (int row = 0; row < point_r; ++row)
	{
		if (point_c == queen[row] || abs(point_c - queen[row]) == point_r - row)
		{
			return true;
		}
	}
	return false;
}

void find()
{
	int row = 0, col = 0;
	while (row < 8)  //������
	{
		while (col < 8)  //������
		{
			if (!IsAttack(row, col))  //��ǰ�ĵ㲻���ͻʱ
			{
				queen[row] = col;  
				if (row == 7)  //��⵱ǰ���Ƿ���β�У����Ƿ��ҵ�һ�������Ľ�
				{
					_count++;  //����������
					col++;  //ѭ����������������������ת��if(col==8)��һ������н��л��ݴ�����ʱ�任����������
//					queen[row] = -1;
				}
				else
				{
					col = 0;  //ȥ��һ��
					break;
				}
			}
			else
			{
				col++;  //��ǰ�㲻���㣬�ҵ�ǰ�е���һ����
			}
		}
		//����
		if (col == 8)  //��ǰ�����ĵ�Խ��
		{
			row--;  //����һ��
			if (row < 0)  //�����ݳ��磬��������н���
			{
				return;
			}
			else
			{
				col = queen[row];  
				col++;  //����һ����ȷ���ĵ�֮�������
//				queen[row] = -1;
				continue;
			}
		}
		row++;  
	}
}

int main()
{
	find();
	cout << _count << endl;

	return 0;
}


#endif