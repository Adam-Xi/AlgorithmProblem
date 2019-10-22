/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
                 3
             /       \
           5           1
         /     \     /  \
        6       2   0    8
               / \
              7   4

示例 

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
示例 2:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。

*/



//方法一：
//递归：


#if 0
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
        {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left == nullptr)
        {
            return right;
        }
        else if(right == nullptr)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
};

#endif

//方法二：
//迭代

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int LCA_stack_index = 0;  //from 1 to stack.size()
        TreeNode *LCA = nullptr, *cur = root;
        stack<TreeNode*> st;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                if (st.size() < LCA_stack_index) {
                    LCA_stack_index = st.size();
                    LCA = cur;
                }
                if (cur == q || cur == p) {
                    if (!LCA) {
                        LCA = cur;
                        LCA_stack_index = st.size();
                    } else return LCA;
                }
                st.pop();
                cur = cur->right;
            }
        }
        return nullptr;
    }


