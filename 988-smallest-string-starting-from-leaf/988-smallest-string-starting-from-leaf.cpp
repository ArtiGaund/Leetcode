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
    string res="";
    string smallestFromLeaf(TreeNode* root) {
        if(root==nullptr) return res;
        dfs(root,"");
        return res;
    }
    void dfs(TreeNode *root,string temp)
    {
        temp=(char)(root->val+'a')+temp;
        if(root->left==nullptr and root->right==nullptr)
        {
            if(res=="") res=temp;
            else res=min(res,temp);
        }
        if(root->left) dfs(root->left,temp);
        if(root->right) dfs(root->right,temp);
    }
};