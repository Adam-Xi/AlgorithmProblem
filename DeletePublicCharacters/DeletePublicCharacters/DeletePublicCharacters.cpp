/*
���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��

��������:
ÿ�������������2���ַ���

�������:
���ɾ������ַ���
ʾ����
����
They are students. 
aeiou
���
Thy r stdnts.
*/

#include<iostream>
using namespace std;
#include<string>

int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int i;
	for (i = 0; i < s2.size(); i++)
	{
		int index;
		while ((index = s1.find(s2[i])) != -1)
		{
			s1.erase(index, 1);
		}
	}
	cout << s1 << endl;

	return 0;
}
