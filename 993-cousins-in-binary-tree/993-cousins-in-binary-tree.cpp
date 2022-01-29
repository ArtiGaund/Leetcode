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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==nullptr) return false;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int found=0;
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            if(cur==nullptr)
            {
                if(!q.empty()) q.push(nullptr);
                found=0;
                continue;
            }
            if(cur->left and (cur->left->val==x or cur->left->val==y)) found++;
            else if(cur->right and (cur->right->val==x or cur->right->val==y)) found++;
            if(found==2) return true;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return false;
    }
};