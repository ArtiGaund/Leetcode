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
    int pseudoPalindromicPaths (TreeNode* root) {
        int res=0,path=0;
        stack<pair<TreeNode*,int>> dq;
        dq.push({root,0});
        while(!dq.empty())
        {
            TreeNode* cur=dq.top().first;
            path=dq.top().second;
            dq.pop();
            if(cur)
            {
                path=path^(1<<cur->val);
                if(cur->left==nullptr and cur->right==nullptr)
                {
                    if((path&(path-1))==0) res++;
                }
                else
                {
                    if(cur->right) dq.push({cur->right,path});
                    if(cur->left) dq.push({cur->left,path});
                }
            }
        }
        return res;
    }
};