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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return res;
        vector<int> temp;
        dfs(root,temp,targetSum);
        return res;
    }
    void dfs(TreeNode *root,vector<int> &temp,int sum)
    {
        if(root==nullptr) return;
        temp.push_back(root->val);
        if(root->val==sum and root->left==nullptr and root->right==nullptr)
        {
            res.push_back(temp);
        }
        else
        {
            dfs(root->left,temp,sum-root->val);
            dfs(root->right,temp,sum-root->val);
        }
        temp.pop_back();
    }
};