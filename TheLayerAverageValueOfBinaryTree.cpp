/*
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.

示例 1:

输入:
    3
   / \
  9  20
    /  \
   15   7
输出: [3, 14.5, 11]
解释:
第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
注意：

节点值的范围在32位有符号整数范围内

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        if(!root)
        {
            return v;
        }
        queue<TreeNode*> q;
        TreeNode* pCur = root;
        q.push(pCur);
        while(!q.empty())
        {
            double avg = 0;
            int len = q.size();
            int i = 0;
            for(; i < len; ++i)
            {
                pCur = q.front();
                avg += (double)pCur->val;
                q.pop();
                if(pCur->left)
                {
                    q.push(pCur->left);
                }
                if(pCur->right)
                {
                    q.push(pCur->right);
                }
            }
            v.push_back(avg / (double)i);
        }
        return v;
    }
};