/*
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

#if 0
//程序运行不通过，内存超出限制
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int vin_len = vin.size();
		if (vin_len == 0)
		{
			return nullptr;
		}
		vector<int> pre_left, pre_right, vin_left, vin_right;
		TreeNode* root = new TreeNode(pre[0]);
		int root_pos = 0;
		while (vin[root_pos++] != root->val);
		for (int i = 0; i < root_pos; i++)
		{
			vin_left.push_back(vin[i]);
			pre_left.push_back(pre[i + 1]);
		}
		for (int i = root_pos + 1; i < vin_len; i++)
		{
			vin_right.push_back(vin[i]);
			pre_right.push_back(pre[i]);
		}
		root->left = reConstructBinaryTree(pre_left, vin_left);
		root->right = reConstructBinaryTree(pre_right, vin_right);
		return root;
	}
};

#endif

#if 0
//程序运行不通过，内存超出限制
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		return Constructor(&(pre[0]), &(pre[pre.size() - 1]), &(vin[0]), &(vin[vin.size() - 1]));
	}

	TreeNode* Constructor(int* pre_left, int* pre_right, int* vin_left, int* vin_right)
	{
		int pre_len = pre_right - pre_left + 1;
		int vin_len = vin_right - vin_left + 1;
		if (pre_len == 0 || vin_len == 0)
		{
			return nullptr;
		}
		TreeNode* root = new TreeNode(*pre_left);
		//int root_pos = 0;
		//while (*(vin_left + root_pos++) != root->val);
		for (int i = 0; i < vin_len; i++)
		{
			if (*(vin_left + i) == root->val)
			{
				root->left = Constructor(pre_left + 1, pre_right + i + 1, vin_left, vin_right + i);
				root->right = Constructor(pre_left + i + 1, pre_left + pre_len, vin_left + i + 1, vin_right + vin_len);
			}
		}
		return root;
	}
}

#endif 

//正确代码
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

/*
思路：
1、在前序序列中把首元素并作为当前根的值，在中序序列中找该值对应的下标位置flag
2、分别将先序序列、中序序列以flag为基准划分为两个子序列，左子序列、右子序列
3、递归，分别实现左右子节点的查找
*/
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() < 1 || vin.size() < 1)
		{
			return nullptr;
		}
		vector<int> pre_left;
		vector<int> pre_right;
		vector<int> vin_left;
		vector<int> vin_right;

		TreeNode *head = new TreeNode(pre[0]);
		int flag = 0;
		for (int i = 0; i < vin.size(); i++)
		{
			if (vin[i] == head->val)
			{
				flag = i;
				break;
			}
		}
		for (int i = 0; i < flag; i++)
		{
			pre_left.push_back(pre[i + 1]);
			vin_left.push_back(vin[i]);
		}
		for (int i = flag + 1; i < vin.size(); i++)
		{
			pre_right.push_back(pre[i]);
			vin_right.push_back(vin[i]);
		}
		head->left = reConstructBinaryTree(pre_left, vin_left);
		head->right = reConstructBinaryTree(pre_right, vin_right);

		return head;
	}
};