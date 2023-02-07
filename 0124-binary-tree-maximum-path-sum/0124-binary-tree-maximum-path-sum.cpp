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
    int solve(TreeNode *cur,int &maxSum)
    {
        if(cur==nullptr) return 0;
        int leftSum=solve(cur->left,maxSum);
        int rightSum=solve(cur->right,maxSum);
        leftSum=max(leftSum,0);
        rightSum=max(rightSum,0);
        int sum=leftSum+rightSum+cur->val;
        maxSum=max(maxSum,sum);
        return max(leftSum,rightSum)+cur->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        solve(root,maxSum);
        return maxSum;
    }
};