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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        stack<TreeNode*> s;
        TreeNode *prev=nullptr;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *cur=s.top();
            if(prev==nullptr or prev->left==cur or prev->right==cur)
            {
                if(cur->left) s.push(cur->left);
                else if(cur->right) s.push(cur->right);
                else
                {
                    s.pop();
                    res.push_back(cur->val);
                }
            }
            else if(cur->left==prev)
            {
                if(cur->right) s.push(cur->right);
                else
                {
                    s.pop();
                    res.push_back(cur->val);
                }
            }
            else if(cur->right==prev)
            {
                s.pop();
                res.push_back(cur->val);
            }
            prev=cur;
        }
        return res;
    }
};