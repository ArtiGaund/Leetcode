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
        deque<pair<TreeNode*,int>> dq;
        dq.push_back({root,0});
        while(!dq.empty())
        {
            TreeNode* cur=dq.front().first;
            path=dq.front().second;
            dq.pop_front();
            if(cur)
            {
                path=path^(1<<cur->val);
                if(cur->left==nullptr and cur->right==nullptr)
                {
                    if((path&(path-1))==0) res++;
                }
                else
                {
                    if(cur->right) dq.push_back({cur->right,path});
                    if(cur->left) dq.push_back({cur->left,path});
                }
            }
        }
        return res;
    }
};