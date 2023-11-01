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
    TreeNode *prev=nullptr;
    int c=1,max=0;
    void inorder(TreeNode *cur,vector<int> &res)
    {
        if(cur==nullptr) return;
        inorder(cur->left,res);
        if(prev!=nullptr)
        {
            if(prev->val==cur->val) c++;
            else c=1;
        }
        prev=cur;
        if(c>max)
        {
            max=c;
            res.clear();
            res.push_back(prev->val);
        } else if(c==max){
            res.push_back(prev->val);
        }
        inorder(cur->right,res);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        inorder(root,res);
        return res;
    }
};