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
    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        stack<TreeNode*> s;
        s.push(root);
        int res=0,sum=0;
        while(!s.empty())
        {
            TreeNode *cur=s.top();
            s.pop();
            if(cur->left==nullptr and cur->right==nullptr) res+=cur->val;
            if(cur->right)
            {
                cur->right->val+=cur->val*10;
                s.push(cur->right);
            }
            if(cur->left)
            {
                cur->left->val+=cur->val*10;
                s.push(cur->left);
            }
        }
        return res;
    }
};