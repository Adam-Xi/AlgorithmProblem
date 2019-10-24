/*
您需要在二叉树的每一行中找到最大的值。

示例：

输入: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

输出: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        if(!root)
        {
            return v;
        }
        queue<TreeNode *> q;
        TreeNode *pCur = root;
        q.push(pCur);

        while(!q.empty())
        {
            int len = q.size();
            int max_n = INT_MIN;
            int i = 0;
            while(i++ < len)
            {
                pCur = q.front();
                q.pop();

                max_n = max(max_n, pCur->val);
                
                if(pCur->left)
                {
                    q.push(pCur->left);
                }
                if(pCur->right)
                {
                    q.push(pCur->right);
                }
            }
            v.push_back(max_n);
        }
        return v;
    }
};