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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        vector<int> path;
        int sum=0;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *cur=s.top();
            s.pop();
            if(cur)
            {
                s.push(nullptr);
                path.push_back(cur->val);
                sum+=cur->val;
                if(cur->left==nullptr and cur->right==nullptr and sum==targetSum)
                    res.push_back(path);
                if(cur->left) s.push(cur->left);
                if(cur->right) s.push(cur->right);
            }
            else
            {
                int end=path[path.size()-1];
                path.pop_back();
                sum-=end;
            }
        }
        return res;
    }
};