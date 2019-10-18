/*
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode* pCur = root;

        while(pCur || s.size())
        {
            while(pCur)
            {
                s.push(pCur->right);
                v.push_back(pCur->val);
                pCur = pCur->left;
            }
            pCur = s.top();
            s.pop();
        }
        return v;
    }
};