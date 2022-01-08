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
    void preorder(TreeNode *root,vector<int> &v)
    {
        if(root==nullptr) return;
        preorder(root->left,v);
        v.push_back(root->val);
        preorder(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        vector<int> v;
        preorder(root,v);
        for(int i=1;i<v.size();i++) if(v[i]<=v[i-1]) return false;
        return true;
    }
};