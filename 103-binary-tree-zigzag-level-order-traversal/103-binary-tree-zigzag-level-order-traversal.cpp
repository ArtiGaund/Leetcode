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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool left=true;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> temp(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=q.front();
                q.pop();
                //insert according to direction
                if(left) temp[i]=cur->val;
                else temp[size-i-1]=cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                
            }
            res.push_back(temp);
            left=!left; //reverse the direction
        }
        return res;
    }
};