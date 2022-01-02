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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        queue<TreeNode*> odd;
        queue<TreeNode*> even;
        even.push(root);
        while(!even.empty() or !odd.empty())
        {
            vector<int> level;
            if(odd.empty())
            {
                while(!even.empty())
                {
                    TreeNode *cur=even.front();
                    even.pop();
                    level.push_back(cur->val);
                    if(cur->left) odd.push(cur->left);
                    if(cur->right) odd.push(cur->right);
                }
            }
            else if(even.empty())
            {
                while(!odd.empty())
                {
                    TreeNode* cur=odd.front();
                    odd.pop();
                    level.push_back(cur->val);
                    if(cur->left) even.push(cur->left);
                    if(cur->right) even.push(cur->right);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};