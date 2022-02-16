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
    //DFS without sort
    vector<vector<int>> res;
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(root==nullptr) return res;
        getheight(root);
        return res;
    }
    int getheight(TreeNode* root)
    {
        if(root==nullptr) return -1;
        int left=getheight(root->left);
        int right=getheight(root->right);
        int curH=max(left,right)+1;
        if(curH==res.size())
            res.push_back({});
        res[curH].push_back(root->val);
        return curH;
    }
};