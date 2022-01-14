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
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==nullptr) return 0;
        vector<int> v(10);
        dfs(root,v);
        return res;
    }
    void dfs(TreeNode* root,vector<int> &v)
    {
        if(root==nullptr) return;
        v[root->val]++;
        if(root->left==nullptr and root->right==nullptr)
        {
            if(check(v)) res++;
            v[root->val]--;
            return;
        }
        if(root->left) dfs(root->left,v);
        if(root->right) dfs(root->right,v);
        v[root->val]--;
    }
    bool check(vector<int> v)
    {
        int odd=0;
        for(int it:v)
            odd+=it&1;
        return (odd==0 or odd==1); 
    }
};