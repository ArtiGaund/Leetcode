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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            int prev=level%2==0?0:INT_MAX;
            while(size--)
            {
                auto cur=q.front();
                q.pop();
                if(level%2==0)
                {
                    if(cur->val%2==0 or cur->val<=prev) return false;
                }
                else
                {
                    if(cur->val%2 or cur->val>=prev) return false;
                }
                prev=cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            level++;
        }
        return true;
    }
};