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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==nullptr) return res;
        stack<pair<TreeNode*,string>> s;
        s.push({root,""});
        while(!s.empty())
        {
            pair<TreeNode*,string> cur=s.top();
            s.pop();
            if(cur.first->left==nullptr and cur.first->right==nullptr) res.push_back(cur.second+to_string(cur.first->val));
            if(cur.first->right) s.push({cur.first->right,cur.second+to_string(cur.first->val)+"->"});
            if(cur.first->left) s.push({cur.first->left,cur.second+to_string(cur.first->val)+"->"});
        }
        return res;
    }
};