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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,int>> q;
        int res=1;
        q.push({root,0});
        while(!q.empty())
        {
            int size=q.size();
            int start=q.front().second;
            int end=q.back().second;
            res=max(res,end-start+1);
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                int index=temp.second-start;
                if(temp.first->left)
                    q.push({temp.first->left,(long long)2*index+1});
                if(temp.first->right)
                    q.push({temp.first->right,(long long)2*index+2});
            }
        }
        return res;
    }
};