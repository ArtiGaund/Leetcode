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
    bool flag=false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        int cur=0;
        preorder(root,targetSum,cur);
        if(flag) return true;
        return false;
    }
    void preorder(TreeNode* root,int target,int cur)
    {
        if(root==nullptr) return;
        if(cur+root->val==target and root->left==nullptr and root->right==nullptr)
        {
            flag=true;
            return;
        }
        cur+=root->val;
        preorder(root->left,target,cur);
        preorder(root->right,target,cur);
        return;
    }
};