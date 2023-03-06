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
    int height(TreeNode *root)
    {
        if(root==nullptr) return 0;
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
    int dia(TreeNode *root)
    {
        if(root==nullptr) return 0;
        int left=height(root->left);
        int right=height(root->right);
        int op1=dia(root->left);
        int op2=dia(root->right);
        int op3=left+right+1;
        return max(op1,max(op2,op3));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=dia(root);
        return res-1;
    }
};