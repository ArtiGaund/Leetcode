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
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxSum=INT_MIN;
        dfs(root,maxSum);
        return maxSum;
    }
    int dfs(TreeNode *root,int &maxSum)
    {
        if(root==nullptr) return 0;
        int left=dfs(root->left,maxSum);
        int right=dfs(root->right,maxSum);
        left=max(left,0);
        right=max(right,0);
        int sum=left+right+root->val;
        maxSum=max(maxSum,sum);
        return max(left,right)+root->val;
    }
};