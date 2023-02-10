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
    vector<TreeNode*> generateTrees(int n) {
        if(n<=0) return vector<TreeNode*>();
        return solve(1,n);
    }
    vector<TreeNode*> solve(int start,int end)
    {
        vector<TreeNode*> res;
        if(start>end)
        {
            res.push_back(nullptr);
            return res;
        }
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left=solve(start,i-1);
            vector<TreeNode*> right=solve(i+1,end);
            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode *root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};