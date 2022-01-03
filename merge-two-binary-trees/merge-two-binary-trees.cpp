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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==nullptr) return t2;
        if(t2==nullptr) return t1;
        stack<pair<TreeNode*,TreeNode*>> s;
        s.push({t1,t2});
        while(!s.empty())
        {
            auto cur=s.top();
            s.pop();
            if(cur.first==nullptr or cur.second==nullptr) continue;
            cur.first->val+=cur.second->val;
            if(cur.first->left==nullptr) cur.first->left=cur.second->left;
            else 
            {
                s.push({cur.first->left,cur.second->left});
            }
            if(cur.first->right==nullptr) cur.first->right=cur.second->right;
            else s.push({cur.first->right,cur.second->right});
        }
        return t1;
    }
};