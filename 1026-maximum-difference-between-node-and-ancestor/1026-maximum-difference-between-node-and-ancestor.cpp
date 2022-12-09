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
    int maxAncestorDiff(TreeNode* root) {
        if(root==nullptr) return 0;
        return solve(root,root->val,root->val);
    }
    int solve(TreeNode *root,int curMax,int curMin)
    {
        if(root==nullptr) return curMax-curMin;
        curMax=max(curMax,root->val);
        curMin=min(curMin,root->val);
        int left=solve(root->left,curMax,curMin);
        int right=solve(root->right,curMax,curMin);
        return max(left,right);
    }
};