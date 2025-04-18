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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr and root2==nullptr) return true;
        if(root1==nullptr or root2==nullptr or root1->val!=root2->val) return false;
        bool a = flipEquiv(root1->left,root2->left) and flipEquiv(root1->right,root2->right);
        bool b = flipEquiv(root1->left,root2->right) and flipEquiv(root1->right,root2->left);
        return a or b;
    }
};