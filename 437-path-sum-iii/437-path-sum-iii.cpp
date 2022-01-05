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
    int res=0,sum;
    int seen[1001];
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return 0;
        sum=targetSum;
        dfs(root);
        return res;
    }
    void dfs(TreeNode *root,int partialSum=0,int pos=1)
    {
        partialSum+=root->val;
        for(int i=0;i<pos;i++) if(seen[i]==partialSum-sum) res++;
        seen[pos]=partialSum;
        if(root->left) dfs(root->left,partialSum,pos+1);
        if(root->right) dfs(root->right,partialSum,pos+1);
    }
};