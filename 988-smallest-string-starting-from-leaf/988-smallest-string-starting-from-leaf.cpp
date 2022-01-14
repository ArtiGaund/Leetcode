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
    string smallestFromLeaf(TreeNode* root) {
        if(root==nullptr) return "";
        stack<pair<TreeNode*,bool>> s;
        string temp="",res="";
        s.push({root,false});
        while(!s.empty())
        {
            TreeNode *cur=s.top().first;
            bool vis=s.top().second;
            s.pop();
            if(vis)
            {
                if(cur->left==nullptr and cur->right==nullptr)
                {
                    if(res.empty())
                        res.insert(res.begin(),temp.rbegin(),temp.rend());
                    else
                    {
                        string rev(temp.rbegin(),temp.rend());;
                        res=min(rev,res);
                    }
                }
                temp.pop_back();
            }
            else
            {
                temp.push_back('a'+cur->val);
                s.push({cur,true});
                if(cur->right) s.push({cur->right,false});
                if(cur->left) s.push({cur->left,false});
            }
        }
        return res;
    }
};