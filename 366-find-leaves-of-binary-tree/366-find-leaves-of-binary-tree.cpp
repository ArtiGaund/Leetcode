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
    vector<pair<int,int>> pairs;
    int getHeight(TreeNode *root)
    {
        if(root==nullptr) return -1;
        int left=getHeight(root->left);
        int right=getHeight(root->right);
        int curH=max(left,right)+1;
        pairs.push_back({curH,root->val});
        return curH;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(root==nullptr) return{};
        getHeight(root);
        vector<vector<int>> res;
        sort(pairs.begin(),pairs.end());
        int n=pairs.size(),i=0,height=0;
        while(i<n)
        {
            vector<int> temp;
            while(i<n and pairs[i].first==height)
            {
                temp.push_back(pairs[i].second);
                i++;
            }
            res.push_back(temp);
            height++;
        }
        return res;
    }
};