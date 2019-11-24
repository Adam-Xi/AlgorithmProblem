/*
�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��A��������Ҫ���ţ�������Ҫȥ������ѡ���ס����ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ֱܷ�������֡������������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס����ڵ������ǣ�������Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�

������ɫ����n(1��n��13),ͬʱ������������Ϊn������left,right,�ֱ����ÿ����ɫ���������׵����������ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������

����������
4,[0,7,1,6],[1,5,0,6]
���أ�10(���ͣ�������������ȡ2ֻ����������ȡ8ֻ)
*/

//˼·��������һ���� a1<a2<a3<a4<...<an��sѡ�����ٸ��ܹ���֤����n����ɫ��
//���� sum(a1...an)-a1+1�����Ƹ볲ԭ��
//��������������׺��������ı��ܹ�����n����ɫ�����һ����������ף�
//���� min(leftSum-leftMin+1,rightSum-rightMin+1)�����ȷ���Ժ�
//ֻ��Ҫ����һ�����ѡ��һ�����ܹ���֤������һ����ɫƥ����
//����Ҫע��ĳ����ɫ������Ϊ0�����

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int sum = 0;
		int leftSum = 0, rightSum = 0;
		int leftMin = 30, rightMin = 30;
		for (int i = 0; i<n; i++)
		{
			if (left[i] * right[i] == 0)sum += (left[i] + right[i]);
			else{
				leftSum += left[i];
				rightSum += right[i];
				leftMin = min(leftMin, left[i]);
				rightMin = min(rightMin, right[i]);
			}
		}
		return sum + min(leftSum - leftMin + 1, rightSum - rightMin + 1) + 1;
	}
};

int main()
{
	int n;
	cin >> n;
	vector<int> left(n, 0);
	vector<int> right(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> left[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> right[i];
	}

	Gloves g;
	cout << g.findMinimum(n, left, right) << endl;

	return 0;
}