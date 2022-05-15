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
    int deepestLeavesSum(TreeNode* root) {
        if(root==nullptr) return 0;
        vector<int> sum;
        stack<pair<TreeNode*,int>> s;
        s.push({root,0});
        while(!s.empty())
        {
            TreeNode *cur=s.top().first;
            int level=s.top().second;
            s.pop();
            if(level==sum.size()) sum.push_back(cur->val);
            else sum[level]+=cur->val;
            if(cur->left) s.push({cur->left,level+1});
            if(cur->right) s.push({cur->right,level+1});
        }
        return sum.back();
    }
};