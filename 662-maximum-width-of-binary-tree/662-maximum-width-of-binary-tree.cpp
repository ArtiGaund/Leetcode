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
   int widthOfBinaryTree(TreeNode* root) {
        vector<long long int> lefts; // left most nodes at each level;
        unsigned long long maxwidth = 0;
        dfs(root, 1, 0, lefts, maxwidth);
        return maxwidth;
    }
private:
    void dfs(TreeNode* node,unsigned long long id,unsigned long long depth, vector<long long int>& lefts, unsigned long long& maxwidth) {
        if (!node) return;
        if (depth >= lefts.size()) lefts.push_back(id);  // add left most node
        maxwidth = max(maxwidth, id + 1 - lefts[depth]);
        dfs(node->left, id * 2, depth + 1, lefts, maxwidth);
        dfs(node->right, id * 2 + 1, depth + 1, lefts, maxwidth);
    }
};