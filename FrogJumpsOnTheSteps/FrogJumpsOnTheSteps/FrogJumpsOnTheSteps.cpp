/*
������̨������
��Ŀ����
һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
*/
class Solution {
public:
	int jumpFloor(int number) {
		int index1 = 1;
		int index2 = 2;
		int index3;
		if (number == 1)
		{
			return index1;
		}
		if (number == 2)
		{
			return index2;
		}
		for (int i = 3; i <= number; i++)
		{
			index3 = index1 + index2;
			index1 = index2;
			index2 = index3;
		}
		return index3;
	}
};

/*
��̬������̨������
��Ŀ����
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
*/
class Solution {
public:
	int jumpFloorII(int number) {
		//����ÿ��һ��̨�׵��ܹ�����������ǰn�׷����ܺ�
		int& n = number;
		vector<int> v(n + 2, 0);
		v[1] = 1;
		v[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			int sum = 1;
			for (int j = 1; j < i; j++)
			{
				sum += v[j];
			}
			v[i] = sum;
		}
		return v[n];
	}
};