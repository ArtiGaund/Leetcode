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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> s;
        TreeNode *dummy,*temp,*root;
        dummy=new TreeNode(1001);
        s.push(dummy);
        for(int i=0;i<nums.size();i++)
        {
            temp=new TreeNode(nums[i]);
            while(!s.empty() and nums[i]>s.top()->val)
            {
                temp->left=s.top();
                s.pop();
            }
            s.top()->right=temp;
            s.push(temp);
        }
        root=dummy->right;
        dummy->right=nullptr;
        return root;
    }
};