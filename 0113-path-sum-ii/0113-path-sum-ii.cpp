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
    void solve(TreeNode *node,int target,vector<vector<int>> &res,vector<int> &cur)
    {
        if(node==nullptr) return;
        cur.push_back(node->val);
        if(node->val==target and node->left==nullptr and node->right==nullptr) 
            res.push_back(cur);
        else
        {
            solve(node->left,target-node->val,res,cur);
            solve(node->right,target-node->val,res,cur);
        }
        cur.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> cur;
        solve(root,targetSum,res,cur);
        return res;
    }
};