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
    bool lca(TreeNode* root,int target,string &s)
    {
        if(root->val==target) return  true;
        if(root->left)
        {
            s.push_back('L');
            bool ans=lca(root->left,target,s);
            if(ans) return true;
            else s.pop_back();
        }
        if(root->right)
        {
            s.push_back('R');
            bool ans=lca(root->right,target,s);
            if(ans) return true;
            else s.pop_back();
        }
        return  false;
    }
    string getDirections(TreeNode* root, int start, int dest) {
        string s1,s2;
        lca(root,start,s1);
        lca(root,dest,s2);
        int i;
        int common=min(s1.size(),s2.size());
        for(i=0;i<common;i++)
            if(s1[i]!=s2[i]) break;
        string res="";
        for(int j=i;j<s1.size();j++)
            res+="U";
        for(int j=i;j<s2.size();j++)
            res+=s2[j];
        return res;
    }
};