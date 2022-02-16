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
    //DFS to sorting
    vector<pair<int,int>> pairs;
    int getheight(TreeNode* root)
    {
        if(root==nullptr) return -1;
        int left=getheight(root->left);
        int right=getheight(root->right);
        int curH=max(left,right)+1;
        this->pairs.push_back({curH,root->val});
        return curH;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        this->pairs.clear();
        getheight(root);
        sort(this->pairs.begin(),this->pairs.end());
        vector<vector<int>> res;
        int n=this->pairs.size(),height=0,i=0;
        while(i<n)
        {
            vector<int> temp;
            while(i<n and this->pairs[i].first==height)
            {
                temp.push_back(this->pairs[i].second);
                i++;
            }
            res.push_back(temp);
            height++;
        }
        return res;
        
    }
};