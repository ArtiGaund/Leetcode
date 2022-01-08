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
    unordered_map<int,int> mp;
    int index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index=0;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        return constructTree(preorder,0,preorder.size()-1);
    }
    TreeNode *constructTree(vector<int> &pre,int left,int right)
    {
        if(left>right) return nullptr;
        int rootval=pre[index++];
        TreeNode *root=new TreeNode(rootval);
        root->left=constructTree(pre,left,mp[rootval]-1);
        root->right=constructTree(pre,mp[rootval]+1,right);
        return root;
    }
};