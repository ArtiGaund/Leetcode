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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        vector<int> temp;
        stack<TreeNode*> s;
        s.push(root);
        int sum=0;
        while(!s.empty())
        {
            TreeNode *cur=s.top();
            s.pop();
            if(cur)
            {
                s.push(nullptr);
                temp.push_back(cur->val);
                sum+=cur->val;
                if(sum==targetSum and cur->left==nullptr and cur->right==nullptr)
                    res.push_back(temp);
                if(cur->left) s.push(cur->left);
                if(cur->right) s.push(cur->right);
            }
            else
            {
                int end=temp[temp.size()-1];
                temp.pop_back();
                sum-=end;
            }
        }
        return res;
    }
};