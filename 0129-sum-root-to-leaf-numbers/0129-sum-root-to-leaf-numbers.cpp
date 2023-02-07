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
    int solve(TreeNode *root,int pathSum)
    {
        if(root==nullptr) return 0;
        pathSum=pathSum*10+root->val;
        if(root->left==nullptr and root->right==nullptr) return pathSum;
        return (solve(root->left,pathSum)+solve(root->right,pathSum));
    }
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};