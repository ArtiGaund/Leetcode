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
    int res=0;
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root,-1);
        return res;
    }
    void dfs(TreeNode* root,int dir)
    {
        if(root==nullptr) return;
        if(root->left==nullptr and root->right==nullptr)
        {
            if(dir==0) res+=root->val;
        }
        dfs(root->left,0); // 0 for left
        dfs(root->right,1); //1 for right
    }
};