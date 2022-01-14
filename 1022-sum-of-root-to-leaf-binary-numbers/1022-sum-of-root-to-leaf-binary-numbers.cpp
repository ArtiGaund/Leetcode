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
    int sumRootToLeaf(TreeNode* root) {
        if(root==nullptr) return 0;
        stack<pair<TreeNode*,int>> s;
        s.push({root,0});
        int res=0,curNo=0;
        while(!s.empty())
        {
            TreeNode *cur=s.top().first;
            curNo=s.top().second;
            s.pop();
            if(cur)
            {
                curNo=(curNo<<1)|cur->val;
                if(cur->left==nullptr and cur->right==nullptr) res+=curNo;
                else
                {
                    if(cur->right) s.push({cur->right,curNo});
                    if(cur->left) s.push({cur->left,curNo});
                }
            }
        }
        return res;
    }
};