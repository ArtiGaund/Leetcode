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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        int d=1;
        while(d<depth-1)
        {
            queue<TreeNode*> temp;
            while(!q.empty())
            {
                TreeNode *cur=q.front();
                q.pop();
                if(cur->left) temp.push(cur->left);
                if(cur->right) temp.push(cur->right);
            }
            q=temp;
            d++;
        }
        while(!q.empty())
        {
            TreeNode *node=q.front();
            q.pop();
            TreeNode* temp=node->left;
            node->left=new TreeNode(val);
            node->left->left=temp;
            temp=node->right;
            node->right=new TreeNode(val);
            node->right->right=temp;
        }
        return root;
    }
};