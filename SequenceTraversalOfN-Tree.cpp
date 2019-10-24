/*
给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。

例如，给定一个 3叉树 :

                   1
                 / | \
                3  2  4
               /\
              5  6

返回其层序遍历:

[
     [1],
     [3,2,4],
     [5,6]
]
 

说明:

树的深度不会超过 1000。
树的节点总数不会超过 5000。

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vv;
        if(!root)
        {
            return vv;
        }
        queue<Node*> q;
        Node* pCur = root;
        q.push(pCur);
        while(!q.empty())
        {
            vector<int> v;
            int len = q.size();
            int i = 0;
            while(i++ < len)
            {
                pCur = q.front();
                q.pop();
                v.push_back(pCur->val);
                
                for(Node* it: pCur->children)
                {
                    q.push(it);
                }
                
            }
            vv.push_back(v);
        }
        return vv;
    }
};