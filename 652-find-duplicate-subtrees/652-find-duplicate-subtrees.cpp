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
    string dfs(TreeNode *root,unordered_map<string,int> &mp,vector<TreeNode*> &res)
    {
        if(root==nullptr) return "#";
        string left=dfs(root->left,mp,res);
        string right=dfs(root->right,mp,res);
        string path=left+"-"+right+"-"+to_string(root->val);
        if(mp.count(path))
        {
            mp[path]++;
            if(mp[path]==1) res.push_back(root);
        }
        else mp[path]=0;
        return path;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> res;
        dfs(root,mp,res);
        return res;
    }
};