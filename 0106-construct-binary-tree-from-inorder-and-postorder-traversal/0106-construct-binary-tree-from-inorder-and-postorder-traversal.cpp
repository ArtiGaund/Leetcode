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
    TreeNode *construct(vector<int> &post,int start,int end,int &p,unordered_map<int,int> &mp)
    {
        if(start>end) return nullptr;
        if(start==end) return new TreeNode(post[p--]);
        TreeNode *root=new TreeNode(post[p--]);
        int index=mp[root->val];
        root->right=construct(post,index+1,end,p,mp);
        root->left=construct(post,start,index-1,p,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        int p=n-1;
        return construct(postorder,0,n-1,p,mp);
    }
};