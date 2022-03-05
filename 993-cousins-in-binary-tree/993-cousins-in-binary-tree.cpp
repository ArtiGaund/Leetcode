/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> level(2,-1),par(2,-1);
        TreeNode *cur=new TreeNode(-1);
        findNode(root,x,y,level,par,0,cur);
        if(level[0]==level[1] and par[0]!=par[1])
            return true;
        return false;
    }
    void findNode(TreeNode* root,int x,int y,vector<int> &level,vector<int> &par,int curlevel,TreeNode *cur)
    {
        if(root==nullptr) return;
        if(root->val==x)
        {
            level[0]=curlevel;
            par[0]=cur->val;
        }
        if(root->val==y)
        {
            level[1]=curlevel;
            par[1]=cur->val;
        }
        findNode(root->left,x,y,level,par,curlevel+1,root);
        findNode(root->right,x,y,level,par,curlevel+1,root);
    }
};