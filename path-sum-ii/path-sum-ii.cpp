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
    vector<int> cur;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==nullptr) return res;
        backtrack(root,sum);
        return res;
    }
    void backtrack(TreeNode* root,int sum)
    {
        if(root==nullptr) return;
        cur.push_back(root->val);
        if(root->left==nullptr and root->right==nullptr and sum==root->val)
        {
            res.push_back(cur);
        }
        backtrack(root->left,sum-root->val);
        backtrack(root->right,sum-root->val);
        cur.pop_back();
    }
};