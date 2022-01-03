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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        stack<TreeNode*> s,path;
        s.push(root);
        int depth=0;
        while(!s.empty())
        {
            TreeNode *cur=s.top();
            if(!path.empty() and cur==path.top())
            {
                if(depth<path.size())
                depth=path.size();
                path.pop();
                s.pop();
            }
            else
            {
                path.push(cur);
                if(cur->right) s.push(cur->right);
                if(cur->left) s.push(cur->left);
            }
        }
        return depth;
    }
};