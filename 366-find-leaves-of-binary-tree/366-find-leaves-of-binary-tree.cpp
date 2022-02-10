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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        queue<TreeNode*> q;
        while(root->left or root->right)
        {
            q.push(root);
            vector<int> temp;
            while(!q.empty())
            {
                int size=q.size();
                for(int i=0;i<size;i++)
                {
                    TreeNode *cur=q.front();
                    q.pop();
                    if(cur->left and cur->left->left==nullptr and cur->left->right==nullptr)
                    {
                        temp.push_back(cur->left->val);
                        cur->left=nullptr;
                    }
                    else if(cur->left) q.push(cur->left);
                    if(cur->right and cur->right->left==nullptr and cur->right->right==nullptr)
                    {
                        temp.push_back(cur->right->val);
                        cur->right=nullptr;
                    }
                    else if(cur->right) q.push(cur->right);
                }
            }
            res.push_back(temp);
        }
        vector<int> temp;
        temp.push_back(root->val);
        res.push_back(temp);
        return res;
    }
};