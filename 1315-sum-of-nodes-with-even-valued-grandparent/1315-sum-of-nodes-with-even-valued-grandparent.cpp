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
        queue<TreeNode*> q,even;
        q.push(root);
        int sum=0;
        while(!q.empty())
        {
            TreeNode *cur=q.front();
            q.pop();
            if(cur->val%2==0) even.push(cur);
            while(!even.empty())
            {
                TreeNode *temp=even.front();
                even.pop();
                if(temp->left)
                {
                    sum+=(temp->left->left?temp->left->left->val:0);
                    sum+=(temp->left->right?temp->left->right->val:0);
                }
                if(temp->right)
                {
                    sum+=(temp->right->left?temp->right->left->val:0);
                    sum+=(temp->right->right?temp->right->right->val:0);
                }
            }
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return sum;
    }
};