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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            multiset<pair<int,int>> s;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                pair<TreeNode*,int> p=q.front();
                q.pop();
                int dis=p.second;
                TreeNode *cur=p.first;
                s.insert({dis,cur->val});
                if(cur->left) q.push({cur->left,dis-1});
                if(cur->right) q.push({cur->right,dis+1});
            }
            for(auto it:s)
                mp[it.first].push_back(it.second);
        }
        for(auto it:mp) res.push_back(it.second);
        return res;
    }
};