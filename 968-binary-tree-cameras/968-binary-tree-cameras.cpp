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
    int status(TreeNode *node,int &ans)
    {
        if(node==nullptr) return 1;
        int l=status(node->left,ans);
        int r=status(node->right,ans);
        if(l==0 or r==0)
        {
            ans++;
            return 2;
        }
        if(l==2 or r==2) return 1;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int ans=0;
        if(status(root,ans)==0) ans++;
        return ans;
    }
};