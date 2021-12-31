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
    int res=0;
    int maxAncestorDiff(TreeNode* root) {
        if(root==nullptr) return 0;
        res=0;
        solve(root,root->val,root->val);
        return res;
    }
    void solve(TreeNode* root,int curMax,int curMin)
    {
        if(root==nullptr) return;
        int cur=max(abs(curMax-root->val),abs(curMin-root->val));
        res=max(res,cur);
        curMax=max(curMax,root->val);
        curMin=min(curMin,root->val);
        solve(root->left,curMax,curMin);
        solve(root->right,curMax,curMin);
        return;
    }
};