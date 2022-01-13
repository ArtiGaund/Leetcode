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
    int sumEvenGrandparent(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty())
        {
            TreeNode *cur=q.front();
            if(cur->left)
            {
                q.push(cur->left);
                if(cur->val%2==0)
                {
                    sum+=(cur->left->left?cur->left->left->val:0);
                    sum+=(cur->left->right?cur->left->right->val:0);
                }
            }
            if(cur->right)
            {
                q.push(cur->right);
                if(cur->val%2==0)
                {
                    sum+=(cur->right->left?cur->right->left->val:0);
                    sum+=(cur->right->right?cur->right->right->val:0);
                }
            }
            q.pop();
        }
        return sum;
    }
};