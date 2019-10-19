/*
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]

*/

#if 0
//方法一：
//用一个变量记录该节点是否被访问

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode* pCur = root;
        TreeNode* pLast = nullptr;
        
        while(pCur || s.size())
        {
            while(pCur)
            {
                s.push(pCur);
                pCur = pCur->left;
            }
            pCur = s.top();
            if(!pCur->right || pCur->right == pLast)
            {
                s.pop();
                v.push_back(pCur->val);
                pLast = pCur;
                pCur = nullptr;
            }
            else
            {
                pCur = pCur->right;
                pLast = nullptr;
            }
        }
        return v;
    }
};

#endif

//方法二：
//先序遍历的逆
//根->左->右   变为    根->右->左   变为   左->右->根
//        先序的变化形式       对既有的序列求逆(或：头插)
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode* pCur = root;
        while(pCur || s.size())
        {
            while(pCur)
            {
                v.push_back(pCur->val);
                s.push(pCur->left);
                pCur = pCur->right;
            }
            pCur = s.top();
            s.pop();            
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

/*
//方法二也可以改为：
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode* pCur = root;
        while(pCur || s.size())
        {
            while(pCur)
            {
                auto it = v.begin();
                v.insert(it, pCur->val);
                s.push(pCur->left);
                pCur = pCur->right;
            }
            pCur = s.top();
            s.pop();
        }
        return v;
    }
};
*/
