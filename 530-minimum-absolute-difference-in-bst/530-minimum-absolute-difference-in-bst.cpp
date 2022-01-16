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
    int diff=INT_MAX;
    TreeNode* prev=nullptr;
    int getMinimumDifference(TreeNode* root) {
        if(root==nullptr) return 0;
        dfs(root);
        return diff;
    }
    void dfs(TreeNode *root)
    {
        if(root==nullptr) return;
        if(root->left) dfs(root->left);
        if(prev) diff=min(diff,abs(prev->val-root->val));
        prev=root;
        if(root->right) dfs(root->right);
    }
};