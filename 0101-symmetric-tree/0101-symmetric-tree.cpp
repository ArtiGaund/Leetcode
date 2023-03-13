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
    bool isMirror(TreeNode *p,TreeNode *q)
    {
        if(p==nullptr and q==nullptr) return true;
        else if(p==nullptr or q==nullptr) return false;
        else if(p->val==q->val)
            return (isMirror(p->left,q->right) and isMirror(p->right,q->left));
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
};