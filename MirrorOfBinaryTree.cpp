/*
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
*/

#if 0
//------------------------------方法一
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    void Swap(TreeNode*& pCur)
    {
        TreeNode* tmp = pCur->left;
        pCur->left = pCur->right;
        pCur->right = tmp;
    }
 
    void Mirror(TreeNode *pRoot)
    {
        if(!pRoot)
        {
            return ;
        }
        queue<TreeNode *> q;
        TreeNode *pCur = pRoot;
        q.push(pCur);
        while(!q.empty())
        {
            int len = q.size();
            int i = 0;
            while(i++ < len)
            {
                pCur = q.front();
                q.pop();
                 
                Swap(pCur);
     
                if(pCur->left)
                {
                    q.push(pCur->left);
                }
                if(pCur->right)
                {
                    q.push(pCur->right);
                }
            }
        }
        return ;
    }
};

#endif

#if 0
//改进版

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Swap(TreeNode*& pCur)
    {
        TreeNode* tmp = pCur->left;
        pCur->left = pCur->right;
        pCur->right = tmp;
    }

    void Mirror(TreeNode *pRoot) 
    {
        if(!pRoot)
        {
            return ;
        }
        queue<TreeNode *> q;
        TreeNode *pCur = pRoot;
        q.push(pCur);
        while(!q.empty())
        {
            pCur = q.front();
            q.pop();
            Swap(pCur);
            if(pCur->left)
            {
                q.push(pCur->left);
            }
            if(pCur->right)
            {
                q.push(pCur->right);
            }
        }
    }
};

#endif

//------------------------------方法二
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) 
    {
        if(!pRoot)
        {
            return ;
        }
        
        TreeNode* tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        
        if(pRoot->left)
        {
            Mirror(pRoot->left);
        }
        if(pRoot->right)
        {
            Mirror(pRoot->right);
        }
    }
};