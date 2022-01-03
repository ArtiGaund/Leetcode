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
    int max_val=INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        // base case
        if(root==nullptr or (root->left==nullptr and root->right==nullptr)) return 0;
        unordered_map<TreeNode*,int> mp;
        stack<TreeNode*> s;
        mp[root]=0;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *cur=s.top();
            s.pop();
            if(mp.find(cur)!=mp.end() and mp[cur]==0)
            {
                s.push(cur);
                mp[cur]=1;  // indicate we will process children of this node
                if(cur->left)
                {
                    s.push(cur->left);
                    mp[cur->left]=0;
                }
                if(cur->right)
                {
                    s.push(cur->right);
                    mp[cur->right]=0;
                }
            }
            else
            {
                //both children of popped node have been processed already
                int lmax=(cur->left==nullptr?0:mp[cur->left]); //longest path from left subtree
                int rmax=(cur->right==nullptr?0:mp[cur->right]); //longest path from right substrr
                max_val=max(max_val,1+lmax+rmax);
                mp[cur]=max(lmax,rmax)+1; //update the popped value
            }
        }
        return max_val-1; //subtrack 1 since we need edge count, but we stored node count
    }
};