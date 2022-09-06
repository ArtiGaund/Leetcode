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
    bool containOne(TreeNode* node)
    {
        if(node==nullptr) return false;
        bool left=containOne(node->left);
        bool right=containOne(node->right);
        if(!left) node->left=nullptr;
        if(!right) node->right=nullptr;
        return (node->val==1 or left or right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        return containOne(root)?root:nullptr;
    }
};