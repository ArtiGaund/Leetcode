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
    int widthOfBinaryTree(TreeNode* root) {
        vector<long long int> left;
        unsigned long long int widthmax=0;
        dfs(root,1,0,left,widthmax);
        return widthmax;
    }
    void dfs(TreeNode *root,unsigned long long int index,unsigned long long int depth,vector<long long int> &left,unsigned long long int &widthmax)
    {
        if(root==nullptr) return;
        if(depth>=left.size()) left.push_back(index);
        widthmax=max(widthmax,index+1-left[depth]);
        dfs(root->left,2*index,depth+1,left,widthmax);
        dfs(root->right,2*index+1,depth+1,left,widthmax);
    }
};