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
    int getMinimumDifference(TreeNode* root) {
        if(root==nullptr) return 0;
        stack<TreeNode*> s;
        int diff=INT_MAX,prev=-100001;
        while(root or !s.empty())
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            diff=min(diff,root->val-prev);
            prev=root->val;
            root=root->right;
        }
        return diff;
    }
};