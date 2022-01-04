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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return traversal(root,subRoot);
    }
    bool traversal(TreeNode *root,TreeNode *sub)
    {
        return (root!=nullptr and (equal(root,sub) or traversal(root->left,sub) or traversal(root->right,sub)));
    }
    bool equal(TreeNode* root,TreeNode *sub)
    {
        if(root==nullptr and sub==nullptr) return true;
        if(root==nullptr or sub==nullptr) return false;
        return (root->val==sub->val and equal(root->left,sub->left) and equal(root->right,sub->right));
    }
};