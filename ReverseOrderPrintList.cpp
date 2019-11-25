/*
��Ŀ����
����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		/*
		//�δ���:���ĳ������δ��󣬿���������Խ�磬��ջ��������磬�ݹ���ò���̫�ࣩ���������
		//--->������ǳ�����ʱ�򣬻ᵼ�º����ĵ��ò㼶����ᵼ�º����ĵ���ջ���
		if(head != nullptr)
		{
		if(head->next != nullptr)
		{
		printListFromTailToHead(head->next);
		}
		v.push_back(head->val);
		}
		*/
		if (head != nullptr)
		{
			stack<int> s;
			vector<int> v;
			while (head)
			{
				s.push(head->val);
				head = head->next;
			}
			while (!s.empty())
			{
				v.push_back(s.top());
				s.pop();
			}
			return v;
		}
	}
};