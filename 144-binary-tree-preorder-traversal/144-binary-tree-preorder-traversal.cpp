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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        stack<TreeNode*> s;
        // s.push(root);
        // TreeNode *curr=root;
       while(root!=NULL||!s.empty())
        {
            while(root!=NULL)
            {
                res.push_back(root->val);
                if(root->right!=NULL)
                    s.push(root->right);
                root=root->left;
            }
            if(!s.empty())
            {
                root=s.top();
                s.pop();
            }
        }
        return res;
    }
};