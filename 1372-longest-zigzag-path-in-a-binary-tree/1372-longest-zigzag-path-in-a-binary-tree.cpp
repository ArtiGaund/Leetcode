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
    int pathLen=0;
    void dfs(TreeNode* root,int left,int right)
    {
        if(root==nullptr) return;
        pathLen=max(pathLen,max(left,right));
        if(root->left) dfs(root->left,right+1,0);
        if(root->right) dfs(root->right,0,left+1);
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,0,0);
        return pathLen;
    }
};