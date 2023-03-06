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
    pair<int,int> dia(TreeNode *root)
    {
        pair<int,int> p{0,0};
        if(root==nullptr) return p;
        pair<int,int> left=dia(root->left);
        pair<int,int> right=dia(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=1+left.second+right.second;
        p.first=max(op1,max(op2,op3));
        p.second=1+max(left.second,right.second);
        return p;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=dia(root).first;
        return res-1;
    }
};