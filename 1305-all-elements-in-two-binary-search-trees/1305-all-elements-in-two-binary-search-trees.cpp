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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1,tree2;
        inorder(root1,tree1);
        inorder(root2,tree2);
        vector<int> res(tree1.size()+tree2.size());
        merge(tree1,tree2,res);
        return res;
    }
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(root==nullptr) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    void merge(vector<int> &v1,vector<int> &v2,vector<int> &res)
    {
        int i=0,j=0,k=0;
        while(i<v1.size() and j<v2.size())
        {
            if(v1[i]<v2[j])
                res[k++]=v1[i++];
            else
                res[k++]=v2[j++];
        }
        while(i<v1.size()) res[k++]=v1[i++];
        while(j<v2.size()) res[k++]=v2[j++];
    }
};