/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode* pCur = root;
        while(pCur || s.size())
        {
            while(pCur)
            {
                s.push(pCur);
                pCur = pCur->left;
            }
            pCur = s.top();
            v.push_back(pCur->val);
            s.pop();
            pCur = pCur->right;
        }
        return v;
    }
};
