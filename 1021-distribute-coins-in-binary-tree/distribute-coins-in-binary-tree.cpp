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
    int moves;
    int dfs(TreeNode* cur){
        if(cur==nullptr) return 0;
        int left=dfs(cur->left);
        int right=dfs(cur->right);
        moves+=abs(left)+abs(right);
        return (cur->val-1)+left+right;
    }
    int distributeCoins(TreeNode* root) {
        moves=0;
        dfs(root);
        return moves;
    }
};