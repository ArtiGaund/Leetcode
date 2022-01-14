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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root==nullptr) return root;
        if(root->left==nullptr and root->right==nullptr)
            return root->val<limit?nullptr:root;
        if(root->left)
            root->left=sufficientSubset(root->left,limit-root->val);
        if(root->right)
            root->right=sufficientSubset(root->right,limit-root->val);
        return (root->left==nullptr and root->right==nullptr ? nullptr: root);
    }
};