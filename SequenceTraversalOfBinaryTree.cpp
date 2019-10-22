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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)
        {
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* pCur = root;
        while(!q.empty())
        {
            vector<int> cur;
            int len = q.size();
            for(int i = 0; i < len; ++i)
            {
                pCur = q.front();
                cur.push_back(pCur->val);
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
            v.push_back(cur);
        }
        return v;
    }
};

