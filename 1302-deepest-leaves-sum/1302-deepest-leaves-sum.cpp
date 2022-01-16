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
    vector<int> sum;
    int deepestLeavesSum(TreeNode* root) {
        if(root==nullptr) return 0;
        dfs(root,0);
        return sum.back();
    }
    void dfs(TreeNode* root,int level)
    {
        if(level==sum.size()) sum.push_back(root->val);
        else sum[level]+=root->val;
        if(root->left) dfs(root->left,level+1);
        if(root->right) dfs(root->right,level+1);
    }
};