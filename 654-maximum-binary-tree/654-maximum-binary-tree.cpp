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
        int n=nums.size();
        return construct(nums,0,n);
    }
    TreeNode* construct(vector<int> &nums,int start,int end)
    {
        if(start==end) return nullptr;
        int max_i=max_index(nums,start,end);
        TreeNode *root=new TreeNode(nums[max_i]);
        root->left=construct(nums,start,max_i);
        root->right=construct(nums,max_i+1,end);
        return root;
    }
    int max_index(vector<int> &nums,int start,int end)
    {
        int max_i=start;
        for(int i=start;i<end;i++)
            if(nums[i]>nums[max_i])
                max_i=i;
        return max_i;
    }
};