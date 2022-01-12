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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *leftmost=nullptr; //left deepest node
        TreeNode *rightmost=nullptr; // right deepest node
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto cur=q.front();
                q.pop();
                if(i==0) leftmost=cur;
                if(i==size-1) rightmost=cur;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return findLCA(root,leftmost->val,rightmost->val);
    }
    TreeNode *findLCA(TreeNode* root,int x,int y)
    {
        if(root==nullptr) return root;
        if(root->val==x or root->val==y) return root;
        auto left=findLCA(root->left,x,y);
        auto right=findLCA(root->right,x,y);
        if(left==nullptr and right==nullptr) return nullptr;
        if(left and right) return root;
        return left?left:right;
    }
};