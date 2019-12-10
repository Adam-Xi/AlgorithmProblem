/*
��Ŀ����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty())
		{
			return 0;
		}
		vector<int>& v = rotateArray;
		int start = 0;
		int end = v.size() - 1;
		int mid = 0;
		while (v[start] >= v[end])
		{
			if (end - start == 1)
			{
				mid = end;
				break;
			}
			int mid = (start + end) / 2;
			if (v[start] == v[mid] && v[mid] == v[end])
			{
				return MinInOrder(v, start, end);
			}

			if (v[mid] >= v[start])
			{
				start = mid;
			}
			else if (v[mid] <= v[end])
			{
				end = mid;
			}
		}
		return v[mid];
	}
	int MinInOrder(vector<int>& v, int start, int end)
	{
		int res = v[start];
		for (int i = start + 1; i <= end; i++)
		{
			if (res > v[i])
			{
				res = v[i];
			}
		}
		return res;
	}
};