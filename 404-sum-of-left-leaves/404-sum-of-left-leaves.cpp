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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr) return 0;
        stack<pair<TreeNode*,bool>> s;
        s.push({root,false});
        int res=0;
        while(!s.empty())
        {
            TreeNode *cur=s.top().first;
            bool isLeaf=s.top().second;
            s.pop();
                if(cur->left==nullptr and cur->right==nullptr and isLeaf) res+=cur->val;
             if(cur->right) s.push({cur->right,false});
                if(cur->left) s.push({cur->left,true});
               
            
        }
        return res;
    }
};