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
        int max_sum=INT_MIN;
        dfs(root,max_sum);
        return max_sum;
    }
    int dfs(TreeNode* root,int &max_sum)
    {
        if(root==nullptr) return 0;
        int maxLeft=dfs(root->left,max_sum);
        int maxRight=dfs(root->right,max_sum);
        maxLeft=max(maxLeft,0);
        maxRight=max(maxRight,0);
        int sum=maxLeft+maxRight+root->val;
        max_sum=max(max_sum,sum);
        return max(maxLeft,maxRight)+root->val;
    }
};