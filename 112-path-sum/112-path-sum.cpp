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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        stack<pair<TreeNode*,int>> s;
        s.push({root,0});
        while(root and !s.empty())
        {
            pair<TreeNode*,int> p=s.top();
            s.pop();
            if(p.first->left and p.first->right)
            {
                s.push({p.first->right,p.second+p.first->val});
                s.push({p.first->left,p.second+p.first->val});
            }
            else if(p.first->left) s.push({p.first->left,p.second+p.first->val});
            else if(p.first->right) s.push({p.first->right,p.second+p.first->val});
            else
            {
                if(p.second+p.first->val==targetSum) return true;
            }
        }
        return false;
    }
};