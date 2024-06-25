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
    void inorder(TreeNode* root,vector<int> &v){
        if(root==nullptr) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    void solveBST(TreeNode *root,vector<int> &v){
        if(root==nullptr) return;
        solveBST(root->left,v);
        int sum=0;
        for(int i=0;i<v.size();i++){
            if(root->val<=v[i]) sum+=v[i];
        }
        root->val=sum;
        solveBST(root->right,v);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==nullptr) return root;
        vector<int> v;
        inorder(root,v);
        solveBST(root,v);
        return root;
    }
};